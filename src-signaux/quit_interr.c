#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>


void handler_int() {
	printf("\nHey tu as déclenché une INTERUPTION\n");
	signal(SIGINT,handler_int);	
}

void handler_quit() {
	printf("\nHey le programme va ce termine à cause d'un SIGQUIT\n");
	signal(SIGQUIT,handler_quit);	
	exit(0);
}


int main(){

printf("Je suis %d et Exécutez une action!\n",getpid());
signal(SIGINT,handler_int);
signal(SIGQUIT,handler_quit);
while(1);

return(0);
}
