/*
 * controller_DNC.c
 *
 *  Created on: Mar 11, 2018
 *      Author: Geoffrey
 */
#include "controller_DNS.h"

int dns_query (void)
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


    struct addrinfo hints, *results, *p;
    struct sockaddr_in *ip_access;
    int rv;
	char inputVal[100];
	printf("Enter a Domain Name: \n");
	scanf("%s",inputVal);

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ( (rv = getaddrinfo( inputVal , "domain" , &hints , &results)) != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for(p = results; p != NULL; p = p->ai_next)
    {
        ip_access = (struct sockaddr_in *) p->ai_addr;
		printf("IP address is %s: \n",inet_ntoa( ip_access->sin_addr ) );

    }

    freeaddrinfo(results);

    printf("\n");
    return 0;

}
