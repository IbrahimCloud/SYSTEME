#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){

int f,p,s;
printf("Pere pid %d\n",getpid());
f=fork();
if(f==0){
  printf("Fils pid %d \n",getpid());
  execl("./sortie","nomdansps",NULL);
}
p=wait(&s);
printf("Pere : fin PID %d, code retour %d\n",p,s);
return 1;
}
