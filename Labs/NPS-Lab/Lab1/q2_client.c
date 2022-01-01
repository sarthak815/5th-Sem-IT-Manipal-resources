#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 50

struct data_set
{
	char s[MAXSIZE];
} data;

struct ans
{
	int a, e, i, o, u;
	int len;
	int isPal;
} response;

main()
{
	int sockfd,retval,i,k;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr, clientaddr;
	char buff[MAXSIZE];
	sockfd=socket(AF_INET,SOCK_DGRAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
		return;

	}
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3389);
	clientaddr.sin_addr.s_addr=inet_addr("127.0.0.1");

	retval=bind(sockfd,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}

	char resp[10] = "\0";	
	while(strcmp(resp, "halt") != 0) {
		printf("enter the text\n");
		gets(data.s);
		sentbytes=sendto(sockfd,(void *) &data,sizeof(data),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
		if(sentbytes==-1)
		{
		printf("sending error");
		close(sockfd);
		}
		
		int size=sizeof(serveraddr);
		recedbytes=recvfrom(sockfd,(void *) &response,sizeof(response),0,(struct sockaddr*)&serveraddr,&size);
		printf("\n");
        if(response.isPal==1){
            printf("It is a pallindrome\n");
        }
        if(response.isPal==0){
            printf("It is not a pallindrome\n");
        }
        printf("The length of the string is: %d\n",response.len);
        printf("Vowels present:\nA:%d\nE:%d\nI:%d\nO:%d\nU:%d",response.a, response.e, response.i, response.o, response.u);
        printf("\n");
	    printf("\nDo you want to proceed(Enter halt to exit)?\n"); 
	
		gets(resp);
	
    }	
	close(sockfd);
}