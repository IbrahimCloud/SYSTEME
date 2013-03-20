#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	printf("Coucou %d\n",getpid());
	fork();
	fork();
	printf("Hé %d:%d\n",getpid(),getppid());
}
