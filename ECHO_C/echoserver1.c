#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#define MYPORT 35555 /*well know port */
#define BACKLOG 10 /* how many pending connection queue will hold */
#define MAXLINE 100



int str_echo(int new_fd)
{	char str[100],buffer[100];
	int val=0;
	while(1)
	{	
		while(val<100)
		{
			buffer[val]='\0';
			str[val]='\0';
                       val++;
		}
		val=0;
		printf("\nEnter Your Message :");
		gets(str);
		if(strcmp(str,"exit")==0)
		break;
               
		send(new_fd , str , strlen(str) , 0 );
		val = read( new_fd , buffer, 100);
		
    		printf("Client :%s\n",buffer );
		//printf("\nMessage sent....");
	}
	



}

main()
{
int sockfd , new_fd ; /* listen on sock_fd ,new connection on new_fd */
struct sockaddr_in my_addr; /* my address */
struct sockaddr_in their_addr; 
int clilen;
int childpid;
if ((sockfd = socket (AF_INET, SOCK_STREAM ,0))==-1)
{
perror("soket");
exit(1);
}
my_addr.sin_family= AF_INET;
/*
little endian: LSB byte comes first
big endian: MSB byte is made first

**network by default use big endian
htons- host to network short
htonl-host to network long
ntohs-network to host short
ntohl-network to host long

*/
my_addr.sin_port= htons(MYPORT);
//INADDR_ANY means server is capable of getting request from many clients
my_addr.sin_addr.s_addr= htonl(INADDR_ANY);
bzero(&(my_addr.sin_zero),8);	//it will assign everything to zero ,the remaining 2 bytes will become 0
if (bind(sockfd, (struct sockaddr *)&my_addr,sizeof(struct sockaddr)) == -1){
perror("bind");
exit(1);
}
//listen to requests
// backlog means queue length 
printf("\nListening for requests...");
if(listen(sockfd,BACKLOG) == -1) {
perror("listen");
exit(1);
}
printf("\nListening for requests...");
for( ; ; )
{
clilen =  sizeof(their_addr);
//accepting the clients requests
if ((new_fd =accept(sockfd, (struct sockaddr*)&their_addr,&clilen)) == -1)
{
perror("accept");
continue;
}
printf("\nAccepted client....");
// fork() is a system call which will create child process
	if ( ( childpid = fork() ) == 0)
	{
		close(sockfd);
		str_echo(new_fd);
		//printf("Client exited");
                exit(0);
	}
	close(new_fd);	
   }
}
  

