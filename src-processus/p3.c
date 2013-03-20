#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
	int r;
	printf("Coucou %d\n",getpid());
	if ( (r=fork())==0 )
		printf("Fils %d\n",getpid());
	else
		printf("Père %d\n",getpid());
	printf("Tous %d\n",getpid());
}
