#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main() {
int k,l,m,n;
l=fork(); // FILS 1
if(l==0){
	//printf("Je suis F1 %d de père %d \n",getpid(),getppid());
	k=fork(); 
	if(k!=0){ 
		printf("Je suis F1 %d de père %d \n",getpid(),getppid());
		m=fork();
		if(m==0){
			printf("Je suis PF1.2 %d de père %d \n",getpid(),getppid());
		}
		else{
			//printf("Je suis F1 %d de père %d \n",getpid(),getppid());
		}
	}	
	else{
		printf("Je suis PF1.1 %d de père %d \n",getpid(),getppid());
	}
}
else{
	printf("Je suis LE PERE %d \n",getpid());
	n=fork(); // FILS 2
	if(n==0){ 
		//printf("Je suis F2 %d de père %d \n",getpid(),getppid());
		k=fork();
		if(k!=0){ 
			printf("Je suis F2 %d de père %d \n",getpid(),getppid());
			m=fork();
			if(m==0){
				printf("Je suis PF2.2 %d de père %d \n",getpid(),getppid());
			}
			else{
				//printf("Je suis F2 %d de père %d \n",getpid(),getppid());
			}
		}
		else{
			printf("Je suis PF2.1 %d de père %d \n",getpid(),getppid());
		}
	}
}
sleep(1);
return 0;
}
