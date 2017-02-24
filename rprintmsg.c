#include <stdio.h>
#include "msg.h"

int main(int argc, char const *argv[]) {
  CLIENT *clnt;
  int *result;
  char *server;
  char *message;

  if (argc != 3) {
    fprintf(stderr, "usage: %s host message \n", argv[0] );
    exit(1);
  }
  server = argv[1];
  message = argv[2];

  //manejador de cliente
  clnt = clnt_create(server, MESSAGEPROG,PRINTMESSAGEVERS, "visible"); //RPC rutina

  if (clnt == (CLIENT *) NULL) {
    //NO SE PUDO CONECTAR AL SERVER
    clnt_pcreateerror(server);
    exit(1);
  }
  //Llamada del proceso remoto en el servidor
  result = printmessage_1(&message, clnt);
  if (result == (int *)NULL) {
    //un error ocurrio al momento de llamar al server
    clnt_perror(clnt,server);
    exit(1);
  }

  if (*result == 0) {
    fprintf(stderr, "%s: no se pudo imprimir el mensaje\n", argv[0] );
    exit(1);
  }

  printf("Mensaje entregado a %s\n", server );
  clnt_destroy( clnt );
  exit(0);
  return 0;
}
