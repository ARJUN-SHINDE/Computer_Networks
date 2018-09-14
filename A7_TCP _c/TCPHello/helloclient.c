// Hello Client Side

#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h> 
#include<arpa/inet.h> // definitions for internet operations
#include<stdlib.h>

#define buffsize  150

int main(void)
{
  struct sockaddr_in clientaddr; 
  char recvline[buffsize];
  int sockfd,n;
  if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
	  perror("Socket Creation Error.\n");
  else
	  printf("Socket Created Successfully\n");
// Information like IP address of the remote host and its port is bundled up in a structure and a call to function connect() is made which tries to connect this socket with the socket (IP address and port) of the remote host.

// Note that here we have not bind our client socket on a particular port as client generally use port assigned by kernel as client can have its socket associated with any port but In case of server it has to be a well known socket, so known servers bind to a specific port like HTTP server runs on port 80 etc while there is no such restrictions on clients.
  bzero((char *) &clientaddr, sizeof(clientaddr));
  clientaddr.sin_family=AF_INET;
  clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");//192.168.107.162
  clientaddr.sin_port=htons(5000);
  if(connect(sockfd,(struct sockaddr *) &clientaddr, sizeof(clientaddr)) < 0 )		  	  
	perror("Connect error\n");
  else
	printf("Connected successfully\n");
// Once the sockets are connected, the server sends the data (date+time) on clients socket through clients socket descriptor and client can read it through normal read call on the its socket descriptor.
  while(( n = read(sockfd,recvline,buffsize)) > 0 )
  { 
	recvline[n]=0;
	if(fputs(recvline,stdout)==EOF)	
	  perror("fputs Error.\n");
  }
  if(n < 0)
    perror("Read Error\n");
  exit(0);  
}
