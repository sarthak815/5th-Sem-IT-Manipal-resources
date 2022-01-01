#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 150


main()
{
	char buff[MAXSIZE],buff2[MAXSIZE];
	int sockfd,retval,i,s;
	int recedbytes,sentbytes;
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
    int ch=0;
    while(ch!=4){
        printf("Enter\n1.Registration Number\n2.Name of student\n3.Subject code\n4.Exit\n");
        
        scanf("%d",&ch);
        int len;
        char temp[MAXSIZE];
        switch(ch){
            case 1:
                printf("Enter registration number: ");
                scanf("%s",temp);
                buff[0] = 1;
                buff[1] = strlen(temp);
                for(i=0;i<buff[1];i++){
                    buff[i+2] = temp[i];
                }
                buff[strlen(buff)] = '\0';
                s = strlen(buff) * sizeof(char);
                sentbytes=send(sockfd,buff,s,0);
                if(sentbytes==-1)
                {
                    printf("!!");
                    close(sockfd);
                }
                recedbytes = recv(sockfd,buff2,sizeof(buff2),0);
                if(recedbytes==-1)
                {
                    printf("\nMessage Recieving Failed");	
                    close(sockfd);
                    exit(0);
                }
                printf("\nChecK: %s\n", buff2);
                break;
            case 2:
                printf("Enter name of student: ");
                scanf("%s",temp);
                buff[0]=2;
                buff[1] = strlen(temp);
                for(i=0;i<buff[1];i++){
                    buff[i+2] = temp[i];
                }
                buff[strlen(buff)] = '\0';
                s = strlen(buff) * sizeof(char);
                sentbytes=send(sockfd,buff,s,0);
                if(sentbytes==-1)
                {
                    printf("!!");
                    close(sockfd);
                }
                recedbytes = recv(sockfd,buff,sizeof(buff),0);
                if(recedbytes==-1)
                {
                    printf("\nMessage Recieving Failed");	
                    close(sockfd);
                    exit(0);
                }
                printf("\n%s\n", buff);
                break;
            case 3:
                printf("Enter subject code: ");
                scanf("%s",temp);
                buff[0]=3;
                buff[1] = strlen(temp);
                for(i=0;i<buff[1];i++){
                    buff[i+2] = temp[i];
                }
                buff[strlen(buff)] = '\0';
                s = strlen(buff) * sizeof(char);
                sentbytes=send(sockfd,buff,s,0);
                if(sentbytes==-1)
                {
                    printf("!!");
                    close(sockfd);
                }
                recedbytes = recv(sockfd,buff,sizeof(buff),0);
                if(recedbytes==-1)
                {
                    printf("\nMessage Recieving Failed");	
                    close(sockfd);
                    exit(0);
                }
                printf("\n%s\n", buff);
                break;
            default:
                buff[0]=4;
                s = strlen(buff) * sizeof(char);
                sentbytes=send(sockfd,buff,s,0);
                break;

        } 
        
    }
	close(sockfd);
}
