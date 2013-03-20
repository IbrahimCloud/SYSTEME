#include <signal.h>
#include <sys/wait.h>


void handler(int sig){
printf("Je veux
rester dormir\n");
exit(0);
}
void fonction_fils(){
signal(SIGUSR,handler);
while(1);
}

int main(){
int k,pid,status;
if (k=fork!=0){
printf("Trompette pour
les dormeurs\n");
kill(k,SIGUSR);
pid=wait(&status)
}
else{
fonction_fils();
}
return;
