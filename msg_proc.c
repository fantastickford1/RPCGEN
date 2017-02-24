#include <stdio.h>
#include <rpc/rpc.h>
#include "msg.h"

int * printmessage_1 (char **msg, CLIENT *clnt)
{
  static int result;

  printf("%s\n", *msg );

  result = 1;

  return(&result);
}


int * printmessage_1_svc(char **msg, struct svc_req *req)
{
  static int result;

  printf("%s\n", *msg );

  result = 1;

  return(&result);
}
