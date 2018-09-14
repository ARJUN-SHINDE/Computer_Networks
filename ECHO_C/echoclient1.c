#include<stdio.h>
#include<stdlib.h>
#include<error.h>
#include<string.h>
#include<netdb.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#define PORT 35555 /*well know port */
#define MAXLINE 100 /* how many pending connection queue will hold */

void str_cli(int sockfd)
{
	
	char buffer[100],str[100];
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
		val = read( sockfd , buffer, 100);
    		printf("Server : %s\n",buffer );
		printf("\nEnter Your Message :");
		gets(str);
		send(sockfd , str , strlen(str) , 0 );
		if(strcmp(str,"exit")==0)
		break;



	}

}
int main (int argc,char* argv[])
{
	int sockfd;
	struct sockaddr_in their_addr;
        struct sockaddr_in my_addr;
if (argc != 2)
	{
		fprintf(stderr, "usage:client <hostname>\n");
		exit(1);
	}

if ((sockfd = socket (AF_INET, SOCK_STREAM ,0))==-1)
	{
		perror("socket");
		exit(1);
	}
		my_addr.sin_family= AF_INET;
		my_addr.sin_port= htons(PORT);
		bzero(&(my_addr.sin_zero),8);
                inet_pton(AF_INET, argv[1], &my_addr.sin_addr);
if (connect (sockfd, (struct sockaddr *)&my_addr,sizeof(struct sockaddr)) == -1)
	{
		perror("connect");
		exit(1);
	}
         str_cli(sockfd);
          exit(0);
}


