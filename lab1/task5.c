#include<stdio.h>
#include<stdlib.h>
#define LEN 32 // 256 bits


void bi(int k){
	int x=0,a[10];
	for(int i = 0; i < 8; i++)
	{
	a[x++]=k%2; 
	k/=2;
	}
	--x;
	while(x>=0)
	printf("%d",a[x--]);


}


void main(){
	unsigned char *key = (unsigned char *)malloc(sizeof(unsigned char)*LEN); 
	FILE* random = fopen("/dev/urandom", "r"); 
	fread(key, sizeof(unsigned char)*LEN, 1, random); 
	fclose(random);
	for( int i = 0; i < LEN; i++ ) 
	{   int k = key[i];
		bi(k);
	}
}


