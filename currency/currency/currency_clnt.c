#include "currency.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = {25, 0};

char ** getusd_1(int *argp, void *clnt)
{
	static char *res;
	memset((char *)&res, 0x0, sizeof(res));
	if (clnt_call ((HCLIENT *)clnt, GETUSD, 
		(xdr_proc) xdr_int, argp,
		(xdr_proc) xdr_wrapstring, &res, 
		TIMEOUT) != RPC_SUCCESS) 
	{
		return (NULL);
	}
	return (&res);
}


char ** geteuro_1(int *argp, void *clnt)
{
	static char *res;
	memset((char *)&res, 0x0, sizeof(res));
	if (clnt_call ((HCLIENT *)clnt, GETEURO, 
		(xdr_proc) xdr_int, argp,
		(xdr_proc) xdr_wrapstring, &res, 
		TIMEOUT) != RPC_SUCCESS) 
	{
		return (NULL);
	}
	return (&res);
}


char ** getyen_1(int *argp, void *clnt)
{
	static char *res;
	memset((char *)&res, 0x0, sizeof(res));
	if (clnt_call ((HCLIENT *)clnt, GETYEN, 
		(xdr_proc) xdr_int, argp,
		(xdr_proc) xdr_wrapstring, &res, 
		TIMEOUT) != RPC_SUCCESS) 
	{
		return (NULL);
	}
	return (&res);
}

