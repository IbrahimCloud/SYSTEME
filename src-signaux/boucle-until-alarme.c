#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

volatile sig_atomic_t keep_going = 1;

void catch_alarm (int sig) {
	keep_going = 0;
	signal (sig, catch_alarm);
}

void do_stuff (void) {
	puts ("Faire quelque chose en attendant l'alarme ...");
}

int main (void) {
	signal (SIGALRM, catch_alarm);
	alarm (2);
	while( keep_going)
		do_stuff ();
	return EXIT_SUCCESS;
}
