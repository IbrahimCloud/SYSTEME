/*Modifier le programme pour que le père affiche à la suite de la phrase précédente
“barcelona arizona”.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
int k;
int p;
printf("Je suis le père %d de père %d et je commence\n",getpid(),getppid());
p= (int) getpid();
k=fork();
if(k==0){
	printf("Je suis le Fils %d de père %d commence\n",getpid(),getppid());
}
printf("Je suis %d et je dis la sagrada familia\n",getpid());
if(getpid() == p){
	printf("Je suis %d et je dis barcelona arizona\n",getpid());
}

}

/* Alternative 1
h=fork();
if(k==0){
  printf("Fils ...");
  printf("La sagrada familia");
  exit(0);
}
printf("Sagrada familia");
printf("Barcelona arizona");
*/

/* Alternative 2
h=fork();
if(k==0){
  printf("Fils ...");
  printf("La sagrada familia");

}
else{
  printf("Sagrada familia");
  printf("Barcelona arizona");
}
*/
