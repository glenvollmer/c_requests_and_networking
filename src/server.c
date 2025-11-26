#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	// create socket
	char server_connect_msg[] = "You have connected";
	char server_response[256];
	int server_socket, socket_bind, socket_listen, client_socket, msg_status;
	struct sockaddr_in server_address;
	
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	if (server_socket == -1)
	{
		printf("Server socket failed to create!\n");
		return 0;
	}

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY; // ip address of the socket.

	// bind socket to localhose:9002
	socket_bind = bind(
		server_socket, 
		(struct sockaddr*) &server_address,
		sizeof(server_address)
	);

	if (socket_bind == -1)
	{
		printf("Server socket failed to bind!\n");
		return 0;
	}

	socket_listen = listen(server_socket, 5);
	if (socket_listen == -1)
	{
		printf("Server socket failed to listen!\n");
		return 0;
	}
	printf("Server running...\n");

	client_socket = accept(
		server_socket,
		(struct sockaddr*)&server_address,
		(socklen_t*)&server_address
	);
	if (client_socket == -1)
	{
		printf("Server socket failed to accept new connections!\n");
		return 0;
	}

	printf("client socket accepted: %d\n", client_socket);
	
	send(
		client_socket, 
		server_connect_msg, 
		sizeof(server_connect_msg), 
		0
	);

	while(1) 
	{
		msg_status = read(
			client_socket, 
			server_response, 
			sizeof(server_response) 
		);
		
		if(msg_status != -1)
		{
			printf("Client message: %s\n", server_response);
			send(
				client_socket, 
				server_response, 
				sizeof(server_response), 
				0
			);
		}
	}

	close(server_socket);
	return 0;
}