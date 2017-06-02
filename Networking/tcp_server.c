#include"header.h"
int main(int argc, char **argv)
{
	if(argc != 2 )
	{
		printf("Inavalid input format \nexecutable_name portno\n");
		return;
	}

	perror("1");

	int socket_fd;
	
	socket_fd = socket (AF_INET, SOCK_STREAM, 0);

	if(socket_fd < 0)
	{
		perror("socket\n");
		return;
	}
	
	printf("Socket Created Successfully\n");

	printf("Binding. . .\n");

	struct sockaddr_in SAddr;
	
	SAddr.sin_family = AF_INET;
	SAddr.sin_port = htons(atoi(argv[1]));
	SAddr.sin_addr.s_addr = inet_addr("172.16.5.191");

	bind(socket_fd,(const struct sockaddr *) &SAddr,sizeof(SAddr));

	if(bind < 0)
	{
		perror("bind\n");
		return;
	}

	printf("Bind Successfully\n");

	printf("Listening\n");
	
	listen(socket_fd,1);
	
	if(listen < 0)
	{
		perror("listen\n");
		return;
	}
	
	printf("Listen Success\n");


	int new_fd;
	
	struct sockaddr_in CAddr;
	
	int size = sizeof(CAddr);
	
	new_fd = accept(socket_fd,(struct sockaddr *)&CAddr, &size);

	if(new_fd < 0)
	{
		perror("accept\n");
		return;
	}

	printf("Server accepted connection from client\n");

	unsigned int port_no;
	char *ip;

	port_no = ntohs(CAddr.sin_port);
	ip = inet_ntoa(CAddr.sin_addr);

	printf("Port_No is %d\n",port_no);
	printf("In address: %s\n",ip);
	printf("File Descriptor on server side: %d\n",new_fd);

	while(1)
	{

		char *buf = NULL;
		int status;

		buf = (char*) malloc (SIZE);

		if(buf == NULL)
		{
			perror("malloc\n");
			return;
		}
	
		status = recv(new_fd,buf,SIZE,0);

		if(status < 0)
		{
			perror("status");
			return ;
		}

		else if(status == 0)
		{
			printf("Client abnormally terminated\n");
			return;
		}
		else
		{
			printf("Message received:%s\n",buf);
	
			if(send(new_fd,buf,SIZE,0) < 0)
				{
					perror("send\n");
					return;
				}
			printf("Send back:%s\n",buf);
		}
	}

	close(new_fd);
	close(socket_fd);

}
