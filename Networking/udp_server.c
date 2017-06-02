#include"header.h"
int main(int argc ,char ** argv)
{
	if(argc != 2)
	{
		printf("Input Format:\n./exec_name portno\n");
		return ;
	}

	printf("Creating Socket\n");

	int socket_fd;

	socket_fd = socket(AF_INET,SOCK_DGRAM, 0);

	if(socket_fd < 0)
	{
		perror("socket");
		return;
	}

	printf("Socket Created Sucessfully\n");

	struct sockaddr_in SAddr,CAddr;
	SAddr.sin_family = AF_INET;
	SAddr.sin_port = htons(atoi(argv[1]));
	SAddr.sin_addr.s_addr = inet_addr("0.0.0.0");

	bind(socket_fd,(const struct sockaddr *)&SAddr , sizeof(SAddr));

	if(bind < 0)
	{
		perror("BIND\n");
		return;
	}

	while(1)
	{

	char *buf= NULL;
	int status;

	buf = (char*)malloc(SIZE);
	
	if(buf == NULL)
	{
		perror("malloc");
		return;
	}	

	int length = sizeof(CAddr);

	status = recvfrom(socket_fd, buf, SIZE, 0, (struct sockaddr*)&CAddr,&length);

	if(status < 0)
	{
		perror("recvfrom\n");
		return;
	}

	else if(status == 0)
	{
		printf("Client Abnormally Terminated\n");
		return;
	}
	else
	{
	//	if(strcmp(buf,"quit\n")== 0)
	//	{
		//	exit(0);
		//	break;	
	//	}
		printf("Message received %s\n",buf);
	//	char str[100];
	//	scanf("%s",str);

		if (sendto(socket_fd, buf, SIZE, 0, (struct sockaddr*)&CAddr,length) < 0)
		{
			perror("sendto\n");
			return;
		}	
		printf("Send Back: %s\n",buf);
	}

	}

	close(socket_fd);

	return 0;
}


