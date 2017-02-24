#include <stdio.h>
#include <rpc/rpc.h>
#include "msg.h"

int main(int argc, char const *argv[]) {

  CLIENT *cl;
  int *result;
  char *server;
  char *message;

  if (argc != 3) {
    fprintf(stderr, "usage %s host message\n", argv[0] );
  }

  server = argv[1];
  message = argv[2];

  cl = clnt_create(server, MESSAGEPROG, MESSAGEVERS, "tcp");

  if ( cl == NULL) {
    clnt_pcreateerror( server );
    exit(1);
  }

  result = printmessage_1(&message, cl);

  if (result == NULL) {
    clnt_perror(cl, server);
    exit(1);
  }

  if (*result == 0) {
    fprintf(stderr, "%s : %s couldn't print your message\n", argv[0], server );
    exit(1);
  }

  printf("Message delivered to %s!\n", server );
  exit(0);

}
