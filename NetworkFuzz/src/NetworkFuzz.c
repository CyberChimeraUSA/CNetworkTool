
#include <stdlib.h>
#include <stdio.h>
#include "controller_DNS.h"

int main(void) {

	int input,status;
	printf("Welcome to NetDebFuzz \n");
	printf("\n\n\nPlease enter a number : \n");
	printf("1:DNS Lookup \n");
	printf("2:Web Server Lookup \n");
	printf("3:Dump Raw Sockets \n");
	printf("4:Dump Stream Sockets \n");
	scanf("%d",&input);

	status = 0;
	switch(input){

	case 1:
		printf("Entered one \n");
		dns_query ();
		if (status != 0)
			printf("DNS Lookup Failed \n");
		break;
	case 2:
		printf("Entered two \n");
		web_server_id();
		if (status != 0)
			printf("Function Failed \n");
		break;
	case 3:
		//FIX ME
		printf("Entered three \n");
		//raw_socket_dump();

		break;
	case 4:
		//FIX ME
		printf("Entered four \n");
		//stream_socket_dump();
		break;
	default:
		printf("Error-Enter Valid Input \n");
		break;

	}
	return 0;

}
