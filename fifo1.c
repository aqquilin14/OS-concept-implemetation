#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
int main() {
 int fd1, fd2; //fd is file descriptor
 char * f1loc = "myfifo1";
 char * f2loc = "myfifo2";
 char str[100], buffer[200];
 mkfifo(f1loc, 0666);
 printf("Enter a string: ");
 fgets(str, 100, stdin); //as string may contain spaces so to include that too
 fd1 = open(f1loc, O_WRONLY);
 if (write(fd1, str, strlen(str) + 1) == -1) //1 to include the /0 terminating character
 {
 printf("Error while writting to fifo 1 from process 1\n");
 return 1;
 }
 close(fd1);
 fd2 = open(f2loc, O_RDONLY);
 if (read(fd2, buffer, 150) == -1) {
 printf("Error while reading from fifo 2 from process 1\n");
 return 1;
 }
 close(fd2);
 printf("Message in FIFO 2 from Process 2:\n%s\n", buffer);
 return 0;
}

