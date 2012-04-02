#include <stdio.h>
#include <stdlib.h>
#include <String.h>

typedef struct { 
	char id[15];
	char name[80]; 	
	char email[80]; 
	char morada[80];
} My_Data;

int compara (void *a, void *b) { 
	My_Data *aa, *bb;
aa = (My_Data*) a;
bb = (My_Data*) b;
return strcmp(aa->id , bb->id); }


int main (int argc, char **argv) { 
	int op, LL;
	My_Data d;
	FILE * f;
	char *buffer,*b; buffer=malloc(200*sizeof(char)); b=buffer;
	if(argc <2){
	printf("Missing argument <filename>"); exit(-1);
}
f=fopen(argv[1],"r"); if(f==NULL){
perror("open");
exit(-1); }

fgets(buffer,6000,f);
	 int t=strlen(buffer); buffer[t-2]='\0';
	buffer[t-1]='\0';
	printf("%s\n",buffer);
	/*
	My_Data *usr=(My_Data*)malloc(sizeof(My_Data)); char *token;
	//printf("%s----\n",buffer); 
	token=strsep(&buffer,"\t"); memcpy(usr->id,token,strlen(token)+1);
	//printf("%s----%s\n",buffer,token); 
	token=strsep(&buffer,"\t"); memcpy(usr->name,token,strlen(token)+1);
	//printf("%s----\n",buffer); 
	 token=strsep(&buffer,"\t"); memcpy(usr->email,token,strlen(token)+1);
	//printf("%s----\n",buffer);  
	token=strsep(&buffer,"\t"); memcpy(usr->morada,token,strlen(token)+1);
	//printf("%s---\n",buffer);  
	//insert(LL,usr);
buffer=b;
memset(b,0,200*sizeof(char));
}*/
//write_to(LL,"usr.db");
return 1; }