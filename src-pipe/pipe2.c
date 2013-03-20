#include <unistd.h>
#include <stdio.h>

main() {

int p[2]; 
char ch[50];
pipe(p);

if(fork()==0){
   close(p[0]);
   printf("fils ecrit\n");
   sprintf(ch,"ca va papa?\n");
   write(p[1],ch,sizeof(ch));
} 
else{
   close(p[1]);
   read(p[0],ch,sizeof(ch));
   printf("je suis le pere\n");
   printf("fils dit %s",ch);
   }
}
