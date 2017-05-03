#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFSIZE 65507

#define PORT 50040
#define DESTINATION "192.168.2.60"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1



int main(int argc, char* argv[])
{


	struct sockaddr_in self, other;
	int s;
	int n;
	int len;
	int res=0;
	int client_s;
	int send_res=0;
	char buf[BUFFSIZE];

	len=sizeof(struct sockaddr_in);

	printf("Creating socket listening...\n");
	s = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (s == -1){
		perror("Errore creazione socket!");
		exit(EXIT_FAILURE);
	}
	printf("Listening socket created...\n");
	

	//port=atoi(arvg[1]);

	//inizializzo la memoria
	bzero((char *) &self, sizeof(self));

	

	self.sin_family=AF_INET;
	self.sin_port=htons(PORT);
	self.sin_addr.s_addr= htonl(INADDR_ANY);

	printf("Binding to port %d...\n",PORT);

	res = bind(s,&self,sizeof(self));
	if (res==-1){
		perror("Errore bind socket");
		exit(EXIT_FAILURE);
	}
	printf("Listening to %d...\n",PORT);
	//fflush(stdout);

	///// SOCKET PER REINVIARE I PACCHETTI

	printf("Creating serving socket...\n");
	client_s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (client_s == -1){
		perror("Errore creazione socket!");
		exit(EXIT_FAILURE);
	}
	printf("Serving socket created...\n");
	bzero((char *) &other, sizeof(other));

	other.sin_family=AF_INET;
	other.sin_port=htons(PORT); //poi la porta sarà la stessa di ricezione, diversa solo per provare su stesso pc
	other.sin_addr.s_addr = inet_addr(DESTINATION);

	//// 

	while(1){
		bzero(buf, sizeof(buf));
		n=recv(s,buf,BUFFSIZE,0);//,(struct sockaddr_in *) &other,&len);
		if (n==-1){
			perror("Errore recvfrom");
			exit(EXIT_FAILURE);
		}
		printf("Received data:%d\n",n);
		printf("sending data...\n");
		fflush(stdout);
		send_res=sendto(client_s, buf, n, 0, &other, len);
		if(send_res<0){
			perror("Error on sendto");
		} else {
			//printf("Sended &d data\n",send_res);
		}




	}

	return 0;
}
