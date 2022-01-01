#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 90

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

void isPalindrome(struct data_set *data)
{
    // Start from leftmost and rightmost corners of str
    int l = 0;
    int h = strlen(data->s) - 1;
 
    // Keep comparing characters while they are same
    response.isPal = 1;
    while (h > l)
    {
        if (data->s[l++] != data->s[h--])
        {
            response.isPal = 0;
        }
    }


}
void count_vowels(struct data_set *data) {
    response.len = strlen(data->s);
    int i;
    response.a = response.e = response.i = response.o = response.u = 0;
    for(i=0; i<response.len; i++) {
        switch (data->s[i])
        {
        case 'a':
        case 'A': response.a++;
            break;
        case 'e':
        case 'E': response.e++;
            break;
        case 'i':
        case 'I': response.i++;
            break;
        case 'o':
        case 'O': response.o++;
            break;
        case 'u':
        case 'U': response.u++;
            break;
        default:
            break;
        }
    }
}
main()
{
	int sockfd,newsockfd,retval,i;
	socklen_t actuallen;
	int recedbytes,sentbytes;
	struct sockaddr_in serveraddr,clientaddr;

	char buff[MAXSIZE];
	int a=0;
	sockfd=socket(AF_INET,SOCK_DGRAM,0);

	if(sockfd==-1)
	{
		printf("\nSocket creation error");
	}
	clientaddr.sin_family=AF_INET;
	clientaddr.sin_port=htons(3389);
	clientaddr.sin_addr.s_addr=htons(INADDR_ANY);


	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);

	retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==1)
	{
		printf("Binding error");
		close(sockfd);
	}
	
	for (i = 0; ; i+=1)
	{
		
		
		actuallen=sizeof(clientaddr);
		recedbytes=recvfrom(sockfd,(void *) &data,sizeof(data),0,(struct sockaddr*)&clientaddr,&actuallen);

		if(recedbytes==-1)
		{
			printf("Reciving error\n");
			close(sockfd);
		}
        isPalindrome(&data);
        count_vowels(&data);
	
		sentbytes=sendto(sockfd,(void *) &response,sizeof(response),0,(struct sockaddr*)&clientaddr,sizeof(clientaddr));
		if(sentbytes==-1)
		{
			printf("sending error");
			close(sockfd);
            break;
		}
	}

	close(sockfd);
	close(newsockfd);
}