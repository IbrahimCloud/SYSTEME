#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
int k,l,m,n;
k=-10;l=-11;m=-12;n=-13;
printf("Je suis le pére et je %d \n",getpid());
k=fork(); //je crée le pére 
if(k!=0){ //le pére entre et crée le fils 2
	l=fork();
}
printf("Je suis %d de père %d mes valeur k:%d l:%d m:%d n:%d \n\n",getpid(),getppid(),k,l,m,n);
if((k==0) || (l==0)){
	printf("Je suis dans un fil %d \n",getpid());
	m=fork();
	if(m!=0){
		n=fork();
	}
	printf("Je suis %d de père %d mes valeur k:%d l:%d m:%d n:%d \n\n",getpid(),getppid(),k,l,m,n);
	if((k==0)&&(m==0)){
		printf("PF11");
	}
	if((l==0)&&(n==0)){
		printf("PF22");
	}
}
else{
	printf("Je suis dans le pére %d \n\n",getpid());
	sleep(2);
}
printf("Qui va éxécuter l'instruction \n\n");
return 0;
}
