#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv){
    //char* buf[1024];
    char* from = argv[1];
    char* to = argv[2];
    struct stat sb;
    if (stat(from, &sb) == -1){
        printf("%s dose not exist", from);
        return 0;
    }
   
   
    printf("%s %s", from, to); 
    int fd1 = open(from, O_RDONLY);
    int fd2 = open(to, O_CREAT | O_WRONLY);
    printf("%d %d", fd1, fd2);
   
    if(fd1 == -1 || fd2 == -1){
        printf("Can't open the file");
        return 0;
    }
    struct stat b;
    int fileStatus = fstat(fd1,&b);
    int file_size = b.st_size;
    //printf("\n%d",file_size);
    //int bytes = read(fd1,buf,file_size);
    char** buf = malloc(file_size);
    if (read(fd1,buf,file_size) == -1){
        printf("Read Error");
        return 0;
    }
    //printf("\n%d", bytes);
   
    if (write(fd2,buf, file_size) == -1){
        printf("Write Eror");
        return 0;
    }
    close(fd1);
    close(fd2);
    return 0;
}