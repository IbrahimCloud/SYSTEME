#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){

printf(" Je suis %d et mon père est %d\n",getpid(),getppid());

return 2;
}
