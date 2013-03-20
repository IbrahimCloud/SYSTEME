#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>



int main(){

int desc, sauve;
printf("Je commence\n");
sauve=dup(1);
close(1);
desc=open("fichier.txt",O_WRONLY|O_CREAT,0777);
//on redirige la sortie
printf("Ca écrit dans le fichier\n");
printf("La encore \n");
close(desc);
dup(sauve);
printf("Tout est revenue comme avant\n");
close(sauve);
return 0;
}
