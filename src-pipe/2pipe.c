#include <unistd.h>

main() {

int p1[2],p2[2];

char ch;
pipe(p1);
pipe(p2);
if (fork()==0){
  close(p1[1]);
  close(p2[0]);
  read(p1[0],ch,sizeof(ch));
  write(p2[1],ch,sizeof(ch));
} 
 else{
    close(p1[0]);
    close(p2[1]);
    read(p2[0],ch,sizeof(ch));
    write(p1[1],ch,sizeof(ch));
  } 
}
