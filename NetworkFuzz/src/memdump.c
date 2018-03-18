/*
 * memdump.c
 *
 *  Created on: Mar 18, 2018
 *      Author: Isaac
 */

#include "controller_DNS.h"

void memdump(const unsigned char *data, const unsigned int length)
{

unsigned char byte;
unsigned int i, j;

 for(i=0; i < length; i++) {
  byte = data[i];
  printf("%02x ", data[i]); // Display byte in hex.
   if(((i%16)==15) || (i==length-1)) {
	for(j=0; j < 15-(i%16); j++)
	printf(" ");
	printf("|| ");
     for(j=(i-(i%16)); j <= i; j++) { // Display printable bytes from line.
      byte = data[j];
        if((byte > 31) && (byte < 127)) // Outside printable char range
        printf("%c", byte);
        else
    printf(".");
    }
printf("\n"); // End of the dump line (each line is 16 bytes)
  } // End if
 }
}
