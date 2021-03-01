#include "kernel/types.h"
#include "kernel/stat.h"
//#include "kernel/sysproc.c"
#include "user/user.h"
//#include <stdlib.h>

int 
main(int argc, char *argv[]){
{
  if(argc > 2){
    printf("Usage: sleep n...\n");
    exit(1);
  } 

  sleep(atoi(argv[1]));
}
exit(0);
} 
