#include <stdio.h>
#include <stdlib.h>


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	char server_connect_msg[] = "You have connected";
	int server_socket, client_socket, msg_status;
	struct sockaddr_in server_address;
	
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY; // ip address of the socket.

	bind(server_socket, 
		(struct sockaddr*) &server_address,
		sizeof(server_address));

	while(1) 
	{
		printf("1\n");
		char server_response[256];
		
		printf("2\n");
		listen(server_socket, 5);



		client_socket = accept(server_socket, NULL, NULL);
		// needs to fork the process for each connection.
		printf("3\n");
		
		msg_status = recv(server_socket, 
			&server_response, 
			sizeof(server_response), 
			0);

		if(client_socket != -1)
		{
			printf("%d\n", client_socket);
			send(client_socket, 
				server_connect_msg, 
				sizeof(server_connect_msg), 
				0);
		} 
		else 
		{
			printf("No connections \n");
		}
		
		printf("%d\n", msg_status);

		if(msg_status != -1)
		{
			printf("\ntest\n");
			printf("%s\n", server_response);
			printf("\ntest\n");

			printf("%s\n", server_response);
			send(client_socket, 
				server_response, 
				sizeof(server_response), 
				0);
		}
			
	}

	close(server_socket);
	return 0;
}