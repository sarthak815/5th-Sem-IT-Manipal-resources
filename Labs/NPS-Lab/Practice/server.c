#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
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
    int sockfd,newsockfd,retval;
    socklen_t actuallen;
    int recedbytes,sentbytes;
    struct sockaddr_in serveraddr,clientaddr;

    char buff[MAXSIZE];
    int a=0;
    sockfd=socket(AF_INET,SOCK_STREAM,0);

    if(sockfd==-1)
    {
    printf("\nSocket creation error");
    }

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(3388);
    serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
    retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
    if(retval==1)
    {
        printf("Binding error");
        close(sockfd);
    }

    retval=listen(sockfd,1);
    if(retval==-1)
    {
        close(sockfd);
    }

    actuallen=sizeof(clientaddr);
    newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);


    if(newsockfd==-1)
    {
        close(sockfd);
    }
    struct student temp[10];
    struct student st[10];
    int size_st = 3;
    strcpy(st[0].name,"Ram");
    strcpy(st[0].regno, "12001");
    strcpy(st[0].mobile, "12345678");
    st[0].size_struct=3;
    strcpy(st[1].name,"Sam");
    strcpy(st[1].regno, "12002");
    strcpy(st[1].mobile, "12345678");
    strcpy(st[2].name,"Tom");
    strcpy(st[2].regno, "12003");
    strcpy(st[2].mobile, "12345678");
    int j;
    for(j=0;;j++){
        recedbytes=recv(newsockfd,(struct student*)&temp,sizeof(temp),0);
        
        if(recedbytes==-1)
        {
            close(sockfd);
            close(newsockfd);
        }
        int ch;
        ch = temp[0].option;
        if(ch==4)
            break;
        switch(ch){
            case 1:
                sentbytes=send(newsockfd,(struct student*)&st,sizeof(st),0);
                if(sentbytes==-1)
                {
                    close(sockfd);
                    close(newsockfd);
                }
                break;
            case 2:
                strcpy(st[size_st].name,temp[0].name);
                strcpy(st[size_st].regno,temp[0].regno);
                strcpy(st[size_st].mobile, temp[0].mobile);
                size_st++;
                printf("Size_st:%d\n",size_st);
                st[0].size_struct = size_st;
                
                break;
            default:
                break;

        }
        
    }

    close(sockfd);
    close(newsockfd);
}

