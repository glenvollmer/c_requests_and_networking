#include <curl/curl.h>


 //  CURL *curl;
 //  CURLcode res;
 
 //  curl_global_init(CURL_GLOBAL_DEFAULT);
 
 //  curl = curl_easy_init();
 //  if(curl) {
 //    curl_easy_setopt(
 //    	curl, 
 //    	CURLOPT_URL, 
 //    	"https://api.kraken.com/0/public/");

	// #ifdef SKIP_PEER_VERIFICATION
 //    	printf("SKIP_PEER_VERIFICATION\n");
	//     /*
	//      * If you want to connect to a site who isn't using a certificate that is
	//      * signed by one of the certs in the CA bundle you have, you can skip the
	//      * verification of the server's certificate. This makes the connection
	//      * A LOT LESS SECURE.
	//      *
	//      * If you have a CA cert for the server stored someplace else than in the
	//      * default bundle, then the CURLOPT_CAPATH option might come handy for
	//      * you.
	//      */
	//     curl_easy_setopt(
	//     	curl, 
	//     	CURLOPT_SSL_VERIFYPEER, 
	//     	0L);
	// #endif
	 
	// #ifdef SKIP_HOSTNAME_VERIFICATION
 //    	printf("SKIP_HOSTNAME_VERIFICATION\n");
	//     /*
	//      * If the site you're connecting to uses a different host name that what
	//      * they have mentioned in their server certificate's commonName (or
	//      * subjectAltName) fields, libcurl will refuse to connect. You can skip
	//      * this check, but this will make the connection less secure.
	//      */

	//     curl_easy_setopt(
	//     	curl, 
	//     	CURLOPT_SSL_VERIFYHOST, 
	//     	0L);
	// #endif
 
 //    /* Perform the request, res will get the return code */ 
 //    res = curl_easy_perform(curl);
    
 //    /* Check for errors */ 
 //    if(res != CURLE_OK)
 //    {
 //    	printf("???????\n");

	//     fprintf(
	//     	stderr,
	//       	"curl_easy_perform() failed: %s\n", 
	//       	curl_easy_strerror(res));    	
 //    }
 //    printf("???????\n");
 
 //    /* always cleanup */ 
 //    curl_easy_cleanup(curl);
 //  }
 
 //  curl_global_cleanup();
 

 // int tri_arb_exists(float a, float b, float c)
// {
// 	if (a * b != c)
// 		return 1;
// 	else
// 		return 0;
// }

	// float EUR_USD, EUR_GBP, GBP_USD;
	// int tri_arb;

	// EUR_USD = 1.1837;
	// EUR_GBP = 0.7231;
	// GBP_USD = 1.6388;

	// tri_arb = tri_arb_exists(
	// 	EUR_USD / 1, 
	// 	1 / EUR_GBP, 
	// 	GBP_USD / 1);

	// if (tri_arb)
	// {
	// 	printf("%f", (EUR_USD / 1) * (1 / EUR_GBP));
	// 	printf(" %f\n", GBP_USD / 1);
	// 	printf("arb op\n");
	// } 
	// else
	// 	printf("no arb\n");





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
