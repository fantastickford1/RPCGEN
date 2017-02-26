
#ifndef _CURRENCY_H_RPCGEN32
#define _CURRENCY_H_RPCGEN32

#include <windows.h>
#include <d32-rpc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define DIVISASPROG ((u_long)0x20000099)
#define DIVISASVERS ((u_long)1)
#define GETUSD ((u_long)1)
char ** getusd_1(int *,  void *);
#define GETEURO ((u_long)1)
char ** geteuro_1(int *,  void *);
#define GETYEN ((u_long)1)
char ** getyen_1(int *,  void *);


/* used by server main(), provided in server stub */
int server_proc (int);

/* free the memory allocated in procedure functions if any */
void server_freeresult (svc_request *, HSERVER, xdr_proc, void *);

#ifdef __cplusplus
}
#endif

#endif /* !_CURRENCY_H_RPCGEN32 */
