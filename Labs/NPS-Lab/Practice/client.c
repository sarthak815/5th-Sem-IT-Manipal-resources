#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#define MAXSIZE 90
struct student{
    char name[30];
    char regno[30];
    char mobile[10];
    int option;
    int size_struct;
}
main()
{
int sockfd,retval;
int recedbytes,sentbytes;
struct sockaddr_in serveraddr;
char buff[MAXSIZE];
sockfd=socket(AF_INET,SOCK_STREAM,0);
if(sockfd==-1)
{
printf("\nSocket Creation Error");

}
printf("%i",sockfd);
serveraddr.sin_family=AF_INET;
serveraddr.sin_port=htons(3388);
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
retval=connect(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
if(retval==-1)
{
printf("Connection error");

}
int j;
for(j=0;;j++){
    printf("Enter the following:\n1.Display\n2.Insert\n");
    int ch,size_st,i;
    struct student st[10];
    scanf("%d",&ch);
    if(ch==4){
            st[0].option=4;
            sentbytes=send(sockfd,(struct student *)&st,sizeof(st),0);
            if(sentbytes==-1)
            {
            printf("!!");
            close(sockfd);
            }
        break;
    }
    switch(ch){
        case 1:
            st[0].option=1;
            sentbytes=send(sockfd,(struct student *)&st,sizeof(st),0);
            if(sentbytes==-1)
            {
            printf("!!");
            close(sockfd);
            }
            recedbytes=recv(sockfd,(struct student *)&st,sizeof(st),0);
            size_st = st[0].size_struct;
            for(i=0;i<size_st;i++){
                printf("%s\n%s\n%s\n",st[i].name,st[i].regno,st[i].mobile);
            }
            break;
        case 2:
            st[0].option=2;
            printf("Enter values to be entered:\1.Name\n2.RegNo\n3.Mobile\n");
            scanf("%s",st[0].name);
            scanf("%s",st[0].regno);
            scanf("%s",st[0].mobile);
            sentbytes=send(sockfd,(struct student *)&st,sizeof(st),0);
            if(sentbytes==-1)
            {
            printf("!!");
            close(sockfd);
            }
        default:
            break;

    }

}



close(sockfd);
}
