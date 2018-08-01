#include<stdio.h>
#include<stdlib.h>

void print(int test) {
	printf("printing int \n");
}

void print(char test) {
	printf("printing char \n");

}

int main(int argc, char const * argv[]){
	print('A');
return EXIT_SUCCESS;
}

