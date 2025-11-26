#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

int connected;
int connection_est = 1;
pthread_t thread;

void *get_server_messages(int network_socket)
{
    int msg_status;
    char server_response[256];
 	
    while (connected)
	{
		msg_status = recv(network_socket, 
			&server_response, 
			sizeof(server_response), 
			0);

		if (msg_status != -1)
		{
			printf("Server message: %s\n", server_response);
		} else {
			printf("There was an error recieving a message from the server!\n");
		}
	}    
    return NULL;
}

int main(int argc, char const *argv[])
{
	pid_t pid;
	
	struct sockaddr_in server_address;
	
	char user_input[256];
	
	int network_socket, 
	connection_status, 
	server_socket,
	input_length,
	input_status;
	
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY; // ip address of the socket.
		
	connection_status = connect(
		network_socket, 
		(struct sockaddr*) &server_address,
		sizeof(server_address)
	);

	if (connection_status == -1)
	{
		connected = 0;
		printf("There was an error connecting to the server!\n");
		return 0;
	}
	else
	{
		connected = 1;		
		pid = fork();
		if (pid == 0)
		{
			if (connection_est)
				get_server_messages(network_socket); // return connection status.
		}
		else
		{
			while (connected)
			{
	    		input_status = scanf("%256s", user_input);
				if (input_status < 0) {
					printf("There was an error accepting client input!");
					return 0;
				}

				send(network_socket, 
					user_input, 
					sizeof(user_input), 
					0);
			}			
		}
	}

	close(network_socket);
	return 0;
}