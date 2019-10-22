#include<stdio.h>
#include<stdlib.h>
#define LEN 32 // 256 bits


void bi(int k){
	int l = sizeof(k)*8;
    int i;
    if(i == 0)
    {
         printf("0");
         return;
     }

    for(i = l-1; i >= 0; i --)
    {
        if(k&(1<<i)) break;
    }
	p = 8-i
	for(;p>=0; p --){
        printf("%d", 0);

}
    for(;i>=0; i --){
        printf("%d", (k&(1<<i)) != 0);

}
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


