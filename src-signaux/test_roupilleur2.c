#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>





void fonction_fils(){

	signal(SIGUSR2,go);
	while(1);

}

void go(){
	
	printf("C'est repartie !\n");
	kill(getppid(),SIGUSR1);
}


void done(){
	
	printf("C'est fait !\n");
}


int main(){
	
	int k,pid,status;
	signal(SIGUSR1,done);

	if (k=fork!=0){

	for(i=0;i < 5, i++){
		printf("Trompette pour les dormeurs\n");
		pause();
		kill(k,SIGUSR2);

	}
	
	pid=wait(&status)

	}
	else{ 

	fonction_fils();

	}


	return;
}