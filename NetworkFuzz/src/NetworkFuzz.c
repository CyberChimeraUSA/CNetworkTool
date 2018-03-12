
#include <stdlib.h>
#include <stdio.h>
#include "controller_DNS.h"

int main(void) {

	int input;
	printf("Welcome to NetDebFuzz \n");
	printf("\n\n\nPlease enter a number : \n");
	printf("1:DNS Lookup ");
	scanf("%d",&input);
	switch(input){

	case 1:
		printf("Entered one \n");
		dns_query ();
		break;
	default:
		break;

	}
	return 0;

}
