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

	client_fd = socket (AF_INET, SOCK_DGRAM, 0);

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


	printf("connect Successfully\n");

	char *buf = NULL;
	int status;

	while(1)
	{
	
		buf = (char*) malloc(SIZE);

		if(buf == NULL)
		{
			perror("malloc\n");
			return;
		}

		printf("ENTER UR MESSAGE\n");
		fgets(buf,SIZE,stdin);

		int len = sizeof(CAddr);

		if(sendto(client_fd,buf,SIZE,0,(struct sockaddr *)&CAddr, len) < 0)
		{
			perror("send\n");
			return ;
		}

		memset(buf,0,SIZE);

	status = recvfrom(client_fd,buf,SIZE,0,( struct sockaddr *)&CAddr, &len);

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




