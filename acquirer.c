#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFSIZE 512

#define PORT 8080

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1


int main(int argc, char* argv[])
{


	struct sockaddr_in self, other;
	int s;
	int n;
	int len;
	int res=0;
	char buf[BUFFSIZE];

	len=sizeof(struct sockaddr_in);

	printf("Creating socket...\n");
	s = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (s == -1){
		perror("Errore creazione socket!");
		exit(EXIT_FAILURE);
	}
	printf("Socket created...\n");
	

	//port=atoi(arvg[1]);

	//inizializzo la memoria
	memset((char *) &self, 0, sizeof(struct sockaddr_in));

	

	self.sin_family=AF_INET;
	self.sin_port=PORT;
	self.sin_addr.s_addr= htonl(INADDR_ANY);

	printf("Binding to port %d...",PORT);

	res = bind(s,&self,sizeof(self));
	if (res==-1){
		perror("Errore bind socket");
		exit(EXIT_FAILURE);
	}
	printf("Listening to %d...",PORT);


	while(1){
		n=recvfrom(s,buf,BUFFSIZE,0,(struct sockaddr_in *) &other,&len);
		if (n==-1){
			perror("Errore recvfrom");
			exit(EXIT_FAILURE);
		}
		printf("\nReceived data:");
		write(1,buf,n);
	}

	return 0;
}