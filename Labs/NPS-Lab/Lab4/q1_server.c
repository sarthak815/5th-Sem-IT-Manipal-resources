#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include <signal.h>

#define MAXSIZE 150
struct student{
    char regno[10];
	char name[10];
	char subjects[10][10];
	char marks[10][10];
	char add[20];
	char sem[5];
	char department[10];
	char section[5];
};
struct subject{
	char code[10];
	char sub_name[10];
	char dept[10];
};

main()
{
	int sockfd,newsockfd,retval,i;
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
	printf("Socket created\n");
	serveraddr.sin_family=AF_INET;
	serveraddr.sin_port=htons(3388);
	serveraddr.sin_addr.s_addr=htons(INADDR_ANY);
	retval=bind(sockfd,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
	if(retval==-1)
	{
		printf("Binding error");
		close(sockfd);
	}

	retval=listen(sockfd,1);
	if(retval==-1)
	{
	close(sockfd);
	}
	printf("\nSocket listening.");
	actuallen=sizeof(clientaddr);
	newsockfd=accept(sockfd,(struct sockaddr*)&clientaddr,&actuallen);
	if(newsockfd==-1)
	{
		close(sockfd);
	}
	printf("\nSocket accepting.\n");
    struct student stu[2];
	struct subject sub[4];
	strcpy(stu[0].regno,"123");
	strcpy(stu[1].regno,"456");
	strcpy(stu[0].name,"Ram");
	strcpy(stu[1].name,"Sam");
	strcpy(stu[0].add,"Manipal");
	strcpy(stu[1].add,"Bangalore");
	strcpy(stu[0].sem,"4");
	strcpy(stu[1].sem,"2");
	strcpy(stu[0].department,"ICT");
	strcpy(stu[1].department,"CSE");
	strcpy(stu[0].section,"A");
	strcpy(stu[1].section,"B");
	strcpy(sub[0].code,"ICT111");
	strcpy(sub[1].code,"ICT222");
	strcpy(sub[2].code,"HUM000");
	strcpy(sub[3].code,"CSE123");
	strcpy(sub[0].sub_name,"OOPS");
	strcpy(sub[1].sub_name,"DS");
	strcpy(sub[2].sub_name,"EEFM");
	strcpy(sub[3].sub_name,"COD");
	strcpy(sub[0].dept,"ICT");
	strcpy(sub[1].dept,"ICT");
	strcpy(sub[2].dept,"HUMANTITY");
	strcpy(sub[3].dept,"CSE");
	strcpy(stu[0].subjects[0],"ICT111");
	strcpy(stu[0].subjects[1],"ICT222");
	strcpy(stu[1].subjects[0],"CSE123");
	strcpy(stu[1].subjects[1],"ICT222");
	strcpy(stu[0].marks[0],"15");
	strcpy(stu[0].marks[1],"15");
	strcpy(stu[1].marks[0],"12");
	strcpy(stu[1].marks[1],"17");

	
	while(1){
		recedbytes=recv(newsockfd,buff,sizeof(buff),0);
		if(recedbytes==-1){
			printf("Error receiving bytes\n");
			close(sockfd);
			close(newsockfd);
		}
        int ch = buff[0];
        int n = buff[1];
        if(ch==4){
			break;
		}
        char buff2[MAXSIZE];
		if(ch==1){
				int pid;
				pid = fork();
				if(pid==0){
					char regno1[20];
					char temp[MAXSIZE];
					for(i=0;i<n;i++){
						regno1[i] = buff[i+2];
					}
					strcpy(buff,"");
					for(i=0;i<2;i++){
						if(strcmp(regno1,stu[i].regno)==0){
							strcpy(buff,"");
							strcpy(buff,"Name of student is: ");
							strcat(buff,stu[0].name);
							strcat(buff," Adress is: ");
							strcat(buff,stu[0].add);
							strcat(buff," PID is: 0");
							
							break;
						}
					}
					if(buff==""){
						strcpy(buff,"Student not found");
					}
					printf("%s",buff);
					sentbytes=send(newsockfd,buff,sizeof(buff),0);
					if(sentbytes==-1)
					{
						printf("\nMessage Sending Failed");
						close(sockfd);
						close(newsockfd);
						exit(0);
					}
				}
				
			}
			else if(ch==2){
				int pid2;
				pid2 = fork();
				if(pid2==0){
					char name1[50];
					for(i=0;i<n;i++){
						name1[i]=buff[i+2];
					}
					name1[i]='\0';
					for(i=0;i<2;i++){
						if(strcmp(name1,stu[i].name)==0){
							printf("Found..\n");
							strcpy(buff,"");
							strcpy(buff,"\nDept: ");
							strcat(buff,stu[i].department);
							strcat(buff,"\nSemester: ");
							strcat(buff,stu[i].sem);
							strcat(buff,"\nSection: ");
							strcat(buff,stu[i].section);
							strcat(buff,"\nCourses: ");
							strcat(buff,stu[i].subjects[0]);
							strcat(buff,",");
							strcat(buff,stu[i].subjects[1]);
							break;
						}
					}
					printf("%s\n",buff);
					sentbytes=send(newsockfd,buff,sizeof(buff),0);
					if(sentbytes==-1)
					{
						printf("\nMessage Sending Failed");
						close(sockfd);
						close(newsockfd);
						exit(0);
					}
					break;

				}
				
				
			}
			else if(ch==3)
			{
				int pid3;
				pid3 = fork();
				if(pid3==0){
					char subject1[50];
					for(i=0;i<n;i++){
						subject1[i]=buff[i+2];
					}
					strcpy(buff,"Marks obtained:\n");
					for(i=0;i<2;i++){
						for(int j=0;j<2;j++)
							if(strcmp(stu[i].subjects[j],subject1)==0){
							
								strcat(buff,stu[i].marks[j]);
								strcat(buff,"\n");
							}
					}
					printf("%s\n",buff);
					sentbytes=send(newsockfd,buff,sizeof(buff),0);
					if(sentbytes==-1)
					{
						printf("\nMessage Sending Failed");
						close(sockfd);
						close(newsockfd);
						exit(0);
					}
				
				}
				
			}
			else{
				break;
			}
			

		}
		
    
	close(sockfd);
	close(newsockfd);
}

