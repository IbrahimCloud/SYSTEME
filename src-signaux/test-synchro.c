#include <signal.h>
#include <stdio.h>
#include <fcntl.h>


char min='a', maj='A';
int d;

void pere(){
  write(d,&maj,1); 
  maj++;
}

void fils(){
  write(d,&min,1); min++;
}


void main(){
  int i, PID, PPID;
  d=open("toto",O_RDWR,0);
/* installe son handler d'interception de SIGUSR1*/
  signal(SIGUSR1,pere);
  if((PID=fork()) == -1){
    perror("erreur sur fork");
    exit(1);
  }
  else if (PID==0) /* processus fils */
  { /*installe son handler d'interception de SIGUSR2*/
  signal(SIGUSR2,fils);
  PPID=getppid();
    for(i=0; i<25; i++) {
      pause();
      usleep(100000); /* unite en micro-secondes)
      kill(PPID,SIGUSR1); /* envoie SIGUSR1 a son pere */
    }
    exit(0);
  }
  else /* processus pere */
  { for (i=0; i<25; i++) {
      usleep(100000);
      kill(PID,SIGUSR2); /* envoie SIGUSR2 a son fils PID*/
      pause();
    }
    close(d); system("cat toto");
    exit(0);
  }
}
