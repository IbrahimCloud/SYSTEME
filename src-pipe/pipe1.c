#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

int p[2],res;
res=pipe(p);
if(res == -1){
 printf("pas de pipe cree. fin programme"); 
 exit(1);
}
if(fork()==0){
   close(p[0]);
   printf("Fils : peux ecrire mais pas lire\n");
   fflush(stdout);
   close(p[1]); 
   exit(0);
}
else{
    close(p[1]);
    printf("Pere: peux lire mais pas ecrire\n");
    close(p[0]); 
    exit(0);
   }
}
