#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
//一个进程在由 pipe() 创建管道后，一般再 fork() 一个子进程，然后通过管道实现父子进程间的通信
int
main(int argc, char *argv[])
{
  if(argc!=1){
    exit(1);
    }
  int p[2],c[2];
  if(pipe(p)==-1||pipe(c)==-1){//fd[0]为管道的读出端，fd[1]则为管道的写入端。若成功则返回零，否则返回-1
    exit(2);//管道创建失败
  }
  int pid=fork();//Create a process, return child’s PID.
  if(pid<0){
    exit(3);//创建子进程失败
  }
  else if(pid>0){
    int p_pid = getpid();// Return the current process’s PID.
    char msg[1];
    write(p[1],"H",1);//Write n bytes from buf to file descriptor p; returns n.
    read(c[0],msg,1);
    fprintf(1,"%d: received pong\n",p_pid);
    
  }
  else{
    int c_pid = getpid();// Return the current process’s PID.
    char msg[1];
    read(p[0],msg,1);
    fprintf(1,"%d: received ping\n",c_pid);
    write(c[1],"H",1);
  }
  close(p[0]);
  close(p[1]);
  close(c[0]);
  close(c[1]);
  exit(0);
}
