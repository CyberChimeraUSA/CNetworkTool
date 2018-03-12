/*
 * controller_DNS.h
 *
 *  Created on: Mar 11, 2018
 *      Author: Geoffrey
 */

#ifndef CONTROLLER_DNS_H_
#define CONTROLLER_DNS_H_
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void dns_query (void);


#endif /* CONTROLLER_DNS_H_ */
