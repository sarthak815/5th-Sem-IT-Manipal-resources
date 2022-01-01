#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define MAXSIZE 50

struct data_set{
    int number[MAXSIZE];
    int no;
}data,ans;
int choice;
int pos;
int num_found;

void bubble_sort(struct data_set *data)
{
    int c, d, t;
	int n = data->no;
  
    for (c = 0; c < (n - 1); c++) {
        for (d = 0; d < n - c - 1; d++) {
            if (data->number[d] > data->number[d + 1]) {
  
                /* Swapping */
                t = data->number[d];
                data->number[d] = data->number[d + 1];
                data->number[d + 1] = t;
            }
        }
    }
}

void split_array(struct data_set *data) {
	int N = data->no;

	int even[N], odd[N], i, k1 = 0, k2 = 0;  

    for(i = 0; i < N; i++)  
    {   
        if(data->number[i] % 2 == 0)  
            even[k1++] = data->number[i];  
        else  
            odd[k2++] = data->number[i];  
    } 
	for(i=0; i<k1; i++) {
		data->number[i] = even[i];
	}
	for(; i-k1<k2; i++) {
		data->number[i] = odd[i-k1];
	}
}


main()
{
	int sockfd,newsockfd,retval,i;
	socklen_t actuallen;
	int recedbytes,sentbytes, recedbytes1,sentbytes1, recedbytes2,sentbytes2;
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
	if(newsockfd == -1)
	{
		close(sockfd);
	}
	
	for (i = 0; ; i+=1)
	{
		
		recedbytes=recv(newsockfd, (void *) &data,sizeof(data),0);
        recedbytes1 = recv(newsockfd, &choice,sizeof(choice),0);
		if(recedbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		// perform action
		if(choice == 1) {
			bubble_sort(&data);
		}
		if(choice == 2) {
			split_array(&data);
		}
        if(choice==3){
            recedbytes2 = recv(newsockfd, &num_found,sizeof(num_found),0);
            pos = -1;
            for(int i=0;i<data.no;i++){
                if(data.number[i]==num_found){
                    pos = i;
                    break;
                }
            }
        }
		sentbytes=send(newsockfd,(void *) &data,sizeof(data),0);
        if(choice==3)
            sentbytes1=send(newsockfd,&pos,sizeof(pos),0);
		if(sentbytes==-1)
		{
			close(sockfd);
			close(newsockfd);
		}
		
	}
	close(sockfd);
	close(newsockfd);
}

