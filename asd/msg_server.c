/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "msg.h"

char **
getusd_1_svc(int *argp, struct svc_req *rqstp)
{
	static char * result;

	



	return &result;
}

char **
geteuro_1_svc(int *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return &result;
}

char **
getyen_1_svc(int *argp, struct svc_req *rqstp)
{
	static char * result;

	/*
	 * insert server code here
	 */

	return &result;
}


char[] leer(int pst){

	FILE *F;
	char d[50];
	char datas [100];

	int money[5];

	F=fopen("moneyStatus.txt","rw+");
    if(F==NULL){
        printf("no se pudo abrir\n");
        exit(1);
    }else{
        printf("open Ok\n");
        while(fgets(datas,100,F) != NULL){
            for(int i=0;i<=100;i=i+1){
                if(datas[i] == EOF) break;
                
                if(isdigit(datas[i])){
                    d &datas[i];
                }
            }
            printf("%s\n",d);
            //int m = atoi(datas[1]);
            //printf("%d \n",m);
        }
        fclose(F);
        return(datas[pst]);
}