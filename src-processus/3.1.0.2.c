/*Ecrivez le programme qui fait créer un processus fils par un père. Le père indique
qu’il est le père et affiche son pid. Le fils indique qu’il est le fils et affiche son pid et le pid de son père.
Père et fils affichent également la phrase “La sagrada familia” avec leur pid juste avant de
se terminer.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
int k;
printf("Je suis le père %d de père %d et je commence\n",getpid(),getppid());
k=fork();
if(k==0){
	printf("Je suis le Fils %d de père %d commence\n",getpid(),getppid());
}
printf("Je suis %d et je dis la sagrada familia\n",getpid());

}
