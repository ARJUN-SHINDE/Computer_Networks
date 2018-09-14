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
	float num1,num2,result;
	int op;
	float a[4];
	printf("Enter First Number:");
	scanf("%f",&a[0]);
	printf("Enter Second Number:");
	scanf("%f",&a[1]);
	while(1)
	{	
		printf("\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Exit");
		scanf("%f",&a[2]);
		send(sockfd , a, sizeof(float)*4 , 0 );
		if(a[2]==5)
			return;
		recv( sockfd , a,sizeof(float)*4,0);
		if(a[3]==-9999)
		printf("Divisor cannot be zero..");
    		else printf("Result is : %.2f",a[3]);
		



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


