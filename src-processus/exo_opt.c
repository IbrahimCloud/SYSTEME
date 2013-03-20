/*Exercice : fork() (optionel)
On imagine un père qui va vivre de 0 à 40 ans. Et qui aura 3 fils à l’âge de 25, 30 et 35 ans.*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void main(){
int i;
int f1,f2,f3;
int p=getpid();
for(i=1;i<=40;i++){
  //printf("Je suis Père = %d j'ai %d ans \n",getpid(),i);
  if(i==25){ 
	f1=fork();
        printf("i= %d getpid= %d ? %d\n",i,getpid(),f1);
        if(getpid()==f1){
          printf("Fils 1 = %d \n",getpid()); 
	  printf("Fin Fils 1\n");
          exit(0);
	}
  }
  if(i==30){ 
	f2=fork();
	printf("i= %d getpid= %d ? %d\n",i,getpid(),f2); 
	if(getpid()==f2){
	  printf("Fils 2 = %d \n",getpid()); 
	  printf("Fin Fils 2\n");
          exit(0);
	}
  }
  if(i==35){
	f3=fork();
        printf("i= %d getpid= %d ? %d\n",i,getpid(),f3); 
        if(getpid()==f3){
	  printf("Fils 3 = %d \n",getpid());
	  printf("Fin Fils 3\n");
	  exit(0);
        }	
  }
}
}
