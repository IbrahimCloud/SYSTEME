#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int secondes;

void handler_alarm() {
	alarm(1);
	secondes++;
	signal(SIGALRM,handler_alarm);
}


void handler_int_fin() {
	printf("Le nombre de secondes est %d\n",secondes);
	exit(1);
}

void handler_int_dep() {
	printf("\nDebut\n");
	alarm(1);
	signal(SIGALRM,handler_alarm);
	signal(SIGINT,handler_int_fin);
}

void handler_usr1() {
	signal(SIGALRM,SIG_IGN);
	printf("STOP : Le nombre de secondes est %d\n",secondes);
	signal(SIGUSR1,handler_usr1);

}
void handler_usr2() {
	signal(SIGALRM,handler_alarm);
	alarm(1);
	printf("RESTART : Le nombre de secondes est %d\n",secondes);
	signal(SIGUSR2,handler_usr2);

}



int main() {

	secondes = 0;

	printf("Moi %d\n",getpid());
	fflush(stdout);
	signal(SIGINT,handler_int_dep);
	signal(SIGUSR1,handler_usr1);
	signal(SIGUSR2,handler_usr2);
	while(1);
return(0);
}
