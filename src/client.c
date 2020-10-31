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

// void *get_server_messages(void *arg)
// {
//     pthread_t id = pthread_self();
//     int network_socket = *((int *) arg);
//     int msg_status;
//     char server_response[256];
 	
//     while (connected)
// 	{
// 		printf("test\n");

// 		msg_status = recv(network_socket, 
// 			&server_response, 
// 			sizeof(server_response), 
// 			0);

// 		if (msg_status != -1)
// 		{
// 			printf("%s\n", server_response);
// 		}

// 		printf("wut\n");
// 	}
// 	printf("??????\n");
    
//     for(int i=0; i<(0xFFFFFFFF);i++);
//     return NULL;
// }

void *get_server_messages(int network_socket)
{
    // pthread_t id = pthread_self();
    // int network_socket = *((int *) arg);
    int msg_status;
    char server_response[256];
 	
    while (connected)
	{
		printf("test\n");

		msg_status = recv(network_socket, 
			&server_response, 
			sizeof(server_response), 
			0);

		if (msg_status != -1)
		{
			printf("%s\n", server_response);
		}

		printf("wut\n");
	}
	printf("??????\n");
    
    // for(int i=0; i<(0xFFFFFFFF);i++);
    return NULL;
}

int main(int argc, char const *argv[])
{
	struct sockaddr_in server_address;
	int network_socket, 
		connection_status, 
		server_socket,
		input_length,
		pid;
	
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY; // ip address of the socket.
		
	connection_status = connect(network_socket, 
		(struct sockaddr*) &server_address,
		sizeof(server_address));

	if (connection_status == -1)
	{
		connected = 0;
		printf("there was an error\n");
	}
	else
	{
		connected = 1;
		server_socket = accept(network_socket, NULL, NULL);

		pid = fork();
		if (pid == 0)
		{
			if (connection_est)
				get_server_messages(network_socket); // return connection status.
		}
		else
		{
			printf("%d\n", pid);
			while (connected)
			{
				sleep(2);
				char user_input[256];
				
				// fork process for scanf();	
						
						// printf("a\n");   

						// pthread_create(&thread, 
						// 	NULL, 
						// 	&get_server_messages, 
						// 	&network_socket);

						connection_est = 0;

	    		
	    		// printf("here\n");
		    	// printf("sent\n\n");

	    		// scanf("%256s", user_input);
				send(server_socket, 
					user_input, 
					sizeof(user_input), 
					0);
			}			
		}
	}

	close(network_socket);
	return 0;
}