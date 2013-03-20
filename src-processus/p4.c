#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
	int k ;
	printf("Je suis seul au monde\n");
	k=fork();
	if (k==-1) { printf("Erreur fork()"); exit(1);}
	if (k== 0) { /* code du fils */
		printf("Je suis le processus fils\n");
		exit(0);
	} else
		printf("Je suis le processus pere\n");
		printf("Et la qui suis-je %d\n",getpid());
}
