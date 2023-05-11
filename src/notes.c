#include <curl/curl.h>

int main(int argc, char const *argv[])
{
	/* code */
	struct sock_address_in, server_address;
	int network_socket, connection_status;
	
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	connection_status = connect(network_socket, (struct sock_addr*) &server_address, size_of(server_address));

	if (connection_status == -1)
	{
		printf("there was an error\n");
	}

	return 0;
}
