/*
 * controller_DNC.c
 *
 *  Created on: Mar 11, 2018
 *      Author: Geoffrey
 */
#include "controller_DNS.h"

int web_server_id (void)
{

	//works but depreciated
#if 0
	struct hostent *host_info;
	struct in_addr *address;

	//struct addrinfo *address_info, hints, *p, i;

	char input[20];

	//not secure but just for demo, use strncpy
	//strcpy(input,argv[1]);
	char inputVal[100];
	printf("Enter a Domain Name: \n");
	scanf("%s",inputVal);
	//not good practice
	strcpy(input,inputVal);
	printf("Will do a DNS query on : %s \n",input);

	host_info = gethostbyname(input);
	address = (struct in_addr *) (host_info->h_addr);
	printf("%s has address %s \n", input, inet_ntoa(*address));

	printf("out with the old in with the new \n");
#endif


    struct addrinfo hints, *results;
    //struct sockaddr_in *ip_access_temp;
    int rv;
    int sockfd;
	char inputVal[100];
	unsigned char buffer[4096];
	printf("Enter a Domain Name: \n");
	scanf("%s",inputVal);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ( (rv = getaddrinfo( inputVal , "80" , &hints , &results)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    sockfd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);

    // connect!

    connect(sockfd, results->ai_addr, results->ai_addrlen);
    printf("made it \n");

    send(sockfd, "HEAD / HTTP/1.0\r\n\r\n", 23, 0);
        int recv_length = 1;
        recv_length = recv(sockfd, &buffer, 1024, 0);
        while(recv_length > 0) {
          printf("The web server is %s\n", buffer+8);
          freeaddrinfo(results);
         return 0;
         }

        printf("Server line not found\n");



    freeaddrinfo(results);

    printf("\n");

    return 1;

}




