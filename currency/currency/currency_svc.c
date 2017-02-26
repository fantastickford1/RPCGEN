#include <stdio.h>
#include "currency.h"

static void divisasprog_1(svc_request *, HSERVER );

int server_proc (int numthreads)
{
	HSERVER transp;

	(void)pmap_unset(DIVISASPROG, DIVISASVERS);

	transp = svcudp_create (RPC_ANYSOCK, 0);
	if (transp == NULL) {
		(void)fprintf(stderr, "cannot create udp service.\n");
		return (1);
	}
	if (!svc_register(transp, DIVISASPROG, DIVISASVERS, (dispatch) divisasprog_1, IPPROTO_UDP)) {
		(void)fprintf(stderr, "unable to register (DIVISASPROG, DIVISASVERS, udp).\n");
		return (1);
	}

	transp = svctcp_create (RPC_ANYSOCK, 0, 0, 0);
	if (transp == NULL) {
		(void)fprintf(stderr, "cannot create tcp service.\n");
		return (1);
	}
	if (!svc_register(transp, DIVISASPROG, DIVISASVERS, (dispatch) divisasprog_1, IPPROTO_TCP)) {
		(void)fprintf(stderr, "unable to register (DIVISASPROG, DIVISASVERS, tcp).\n");
		return (1);
	}
	svc_run_ex(numthreads);
	(void)fprintf(stderr, "svc_run_ex returned\n");
	return (0) ;
}

static void
divisasprog_1(svc_request *rqstp, HSERVER transp)
{
	union {
		int getusd_1_arg;
		int geteuro_1_arg;
		int getyen_1_arg;
	} argument;
	char *result;
	xdr_proc xdr_argument;
	xdr_proc xdr_result;
	local_proc local;

	switch (rqstp->proc) {
	case NULLPROC:
		(void)svc_sendreply(transp, (xdr_proc) xdr_void, (char *)NULL);
		return;

	case GETUSD:
		xdr_argument = (xdr_proc) xdr_int;
		xdr_result = (xdr_proc) xdr_wrapstring;
		local = (local_proc) getusd_1;
		break;

	case GETEURO:
		xdr_argument = (xdr_proc) xdr_int;
		xdr_result = (xdr_proc) xdr_wrapstring;
		local = (local_proc) geteuro_1;
		break;

	case GETYEN:
		xdr_argument = (xdr_proc) xdr_int;
		xdr_result = (xdr_proc) xdr_wrapstring;
		local = (local_proc) getyen_1;
		break;

	default:
		svcerr_noproc(transp);
		return;
	}
	memset((char *) &argument, 0x0,sizeof(argument));
	if (!svc_getargs(transp, xdr_argument, &argument)) {
		svcerr_decode(transp);
		return;
	}
	result = (*local)(&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, xdr_result, result)) {
		svcerr_systemerr(transp);
	}
	if (!svc_freeargs(transp, xdr_argument, &argument)) {
		(void)fprintf(stderr, "unable to free arguments\n");
		exit(1);
	}
	/* free the memory allocated for the result, do NOT use xdr_free here */
	server_freeresult (rqstp, transp, xdr_result, (void *) &result);
}

