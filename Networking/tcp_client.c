#include"header.h"
int main(int argc, char **argv)
{
	if(argc != 3 )
	{
		printf("Inavalid input format \nexecutable_name portno\n");
		return;
	}

	printf("Creating Client\n");

	int client_fd;

	client_fd = socket (AF_INET, SOCK_STREAM, 0);

	if(client_fd < 0)
	{
		perror("socket\n");
		return;
	}

	printf("Client Created Successfully\n");

	printf("connecting. . .\n");

	struct sockaddr_in CAddr;

	CAddr.sin_family = AF_INET;
	CAddr.sin_port = htons(atoi(argv[1]));
	CAddr.sin_addr.s_addr = inet_addr(argv[2]);


	connect(client_fd,(const struct sockaddr *) &CAddr,sizeof(CAddr));

	if(connect < 0)
	{
		perror("connect\n");
		return;
	}

	printf("connect Successfully\n");

	while(1)
	{
	
	char *buf = NULL;
	int status;

	buf = (char*) malloc(SIZE);

	if(buf == NULL)
	{
		perror("malloc\n");
		return;
	}

	printf("ENTER UR MESSAGE\n");
	fgets(buf,SIZE,stdin);

	

		if(send(client_fd,buf,SIZE,0) < 0)
		{
			perror("send\n");
			return ;
		}

		memset(buf,0,SIZE);
		status = recv(client_fd,buf,SIZE,0);

		if(status < 0)
		{
			perror("recv");
			return ;
		}

		else if (status == 0)
		{
			printf("Server abnormally terminated\n");
			return;
		}
		else
		{
			printf("message received:%s\n",buf);
		}
	}		
	close(client_fd);
	
}




