/*
 * socket_handler.c
 *
 *  Created on: Mar 18, 2018
 *      Author: Isaac
 */

#include "controller_DNS.h"
int raw_socket_dump(void)
{
	int i, recv_length, sockfd;
	u_char buffer[9000];
	if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP)) == -1)
	perror("in socket");
	for(i=0; i < 1; i++) {

	  recv_length = recv(sockfd, buffer, 8000, 0);
	  printf("Got a %d byte packet\n", recv_length);
	  memdump(buffer, recv_length);
	}
	return 0;
}
int stream_socket_dump(void)
{
	int i, recv_length, sockfd;
	u_char buffer[9000];
	if ((sockfd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
	perror("in socket");
	for(i=0; i < 1; i++) {

	  recv_length = recv(sockfd, buffer, 8000, 0);
	  printf("Got a %d byte packet\n", recv_length);
	  memdump(buffer, recv_length);
	}
	return 0;
}
