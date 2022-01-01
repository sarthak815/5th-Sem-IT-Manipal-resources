#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 50
struct data_set{
    int number[MAXSIZE];
    int no;
}data,ans;
int choice;
int pos;
int num_found;

main()
{
	char buff[MAXSIZE];
	int sockfd,retval,i;
	int recedbytes,sentbytes, recedbytes1,sentbytes1, recedbytes2,sentbytes2;
	struct sockaddr_in serveraddr;
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(sockfd==-1)
	{
		printf("\nSocket Creation Error");
		return;
	}

	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==-1)
	{
		printf("Connection error");
		return;
	}
	
	char resp[10] = "\0";	
	while(strcmp(resp, "exit") != 0) {
		printf("Enter choice:\n1 To sort\n2 To find odd even\n3 To search for a number\n");
        scanf("%d", &choice);
        printf("Enter number of elements to be entered: ");
        scanf("%d", &data.no);
        printf("Enter the numbers: ");
        for(int i=0;i<data.no;i++)
            scanf("%d", &data.number[i]);
        if(choice==3){
            printf("Enter number to be found: ");
            scanf("%d",&num_found);
        }
        
		sentbytes=send(sockfd, (void *) &data,sizeof(data),0);
        sentbytes1=send(sockfd, &choice,sizeof(choice),0);
        if(choice==3){
            sentbytes2=send(sockfd, &num_found,sizeof(num_found),0);
        }
		if(sentbytes==-1)
		{
			printf("Error in Sending the array");
			close(sockfd);
		}
		recedbytes=recv(sockfd,(void *) &ans,sizeof(ans),0);
		if(recedbytes < 0) {
			printf("Error in receiving");
		}
		printf("The answer received is: ");
		for(i=0; i<ans.no; i++) {
			printf("%d ", ans.number[i]);
		}
        if(choice==3){
            recedbytes1=recv(sockfd,&pos,sizeof(pos),0);
            if(pos==-1){
                printf("Element not found");
            }
            else{
                printf("\nElement found at: %d", pos);
            }
        }
		printf("\nDo you want to proceed(Enter exit to exit)?\n"); 
		getchar();
		gets(resp);
		
	}
	close(sockfd);
}