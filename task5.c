#include<stdio.h>
#include<stdlib.h>
#define LEN 32 // 256 bits
void main(){
	unsigned char *key = (unsigned char *)malloc(sizeof(unsigned char)*LEN); 
	FILE* random = fopen("/dev/urandom", "r"); 
	fread(key, sizeof(unsigned char)*LEN, 1, random); 
	fclose(random);
	for( int i = 0; i < LEN; i++ ) 
	{
		printf( "%d", key[i] );
	}
}