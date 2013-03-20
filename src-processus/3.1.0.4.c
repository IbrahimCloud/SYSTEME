#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
int k;
k=fork();
 if(k==0){
    printf("Fils ...\n");
    printf("La sagrada familia\n");
    sleep(2);
    printf("Fin fils\n");
 }
 else{
    printf("Sagrada familia\n");
    printf("Barcelona arizona\n");
    sleep(5);
    printf("Fin père\n");
 }
}
