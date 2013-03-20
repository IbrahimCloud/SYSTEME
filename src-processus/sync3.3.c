#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main(){

int n=5;
int u,v;
int tab[n];
int i;
int elu;
int s,p;
srand(time(NULL));

for(i=0;i<n;i++){
  u=(rand()%10)+1;
  v=rand()%2;
  tab[i]=fork();
  if(tab[i]==0){
    printf("Fils %d commence \n",getpid());
    sleep(u);
    printf("Fils %d fini apres %d retour %d \n",getpid(),u,v);
    exit(v);
  }
}

do{
  p=wait(&s);
  if(p==tab[elu-1]){
    printf("Mon fils préféré %d vient de finir avec retour %d \n",p,s);
  }
  else{
    if(p!=-1){
      printf("Un gueux %d vient de se finir\n",p);
      if(s==0){
        printf("Fils renie beuhh\n");
      }
      else{
        printf("Fils tolerer mais non renie\n");
      }
    }
  }
}while(p!=-1);
printf("Fin");
return 0;
}
