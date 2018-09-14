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
	
	float a[3];
	
	
	while(1)
	{	
		printf("\nMenu\n1.sin\n2.cos\n3.tan\n4.inverse\n5.log\n6.Exit");
		scanf("%f",&a[0]);
		if((int)a[0]==6)
		{	
			send(sockfd , a, sizeof(float)*3 , 0 );
				return;
		}
			
		printf("Enter Number:");
		scanf("%f",&a[1]);
		send(sockfd , a, sizeof(float)*3 , 0 );
		
		recv( sockfd , a,sizeof(float)*3,0);
		if(a[0]<1 || a[0]>6)
			printf("\nWrong choice..");
    		else printf("Result is : %f",a[2]);
		



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


