#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/mman.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(int argc, char*argv[])
{
   int n = argc;
   const int SIZE = n * 2048;
   const char *name = "/COLLATZ";
   int  shm_fd;
   void *ptr;
   int count = 1;
   
   /* Setup shared memory */
   shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);
   ftruncate(shm_fd, SIZE);
   ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
   for (int i=0 ;i<argc;i++)
    {
 
       ptr += i*sizeof(int);
       
       int value = atoi(argv[i]);
 
       pid_t pid;
       pid = fork();
 
 
       if (pid < 0)
       {
          fprintf(stderr, "FORK FAILED\n");
          return 1;
       }
       else if (pid > 0) // parent process
       {
          wait(NULL);
          printf("\n");
     
 
          while (atoi((char *)ptr) != 0)
          {
            printf("%s", (char *)ptr);
            ptr += sizeof(int);
            if (atoi((char *)ptr) != 0)
                    printf(", ");
          }
       
          printf("\n");
          shm_unlink(name);
 
       }
       else if (pid == 0)   // child process
       {  
 
          sprintf(ptr, "%d", value);
          ptr += sizeof(value);
 
          while (value != 1)
          {
            if (value % 2 == 0)
              value /= 2;
            else
              value = value * 3 + 1;
 
            sprintf(ptr, "%d", value);
            ptr += sizeof(value);
          }
          sprintf(ptr,"0");
          ptr += sizeof(value);
          return 0;
       }
    }
   return 0;
}