#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  if(argc<=1){
    fprintf(2, "error: you should input 2 argument !\n");
  }
  else if(argc==2){
    int time=atoi(argv[1]);
    if(time<=0){
        fprintf(2, "error:please input valid time\n");
    }
    else{
        sleep(time);
        exit(0);
    }
  }
  else{
         fprintf(2, "error:please input no more than one time value\n");
    }
  exit(0);
}
