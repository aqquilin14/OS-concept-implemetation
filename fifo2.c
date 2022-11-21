#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
 FILE * tfd;
 int fd1, fd2; //fd is file descriptor
 char * f1loc = "myfifo1";
 char * f2loc = "myfifo2";
 char buffer[100], tempstr[200];
 fd1 = open(f1loc, O_RDONLY);
 if (read(fd1, buffer, 100) == -1) {
 printf("Error while reading from fifo 1 from process 2\n");
 return 1;
 }
 close(fd1);
 printf("Message in FIFO 1 from Process 1:\n%s\n", buffer);
 int p = 0, l = 1, w = 1, c = 0;
 while (buffer[p] != '\0') {
 if (buffer[p] == '.') {
 l++;
 } else if (buffer[p] == ' ') {
 w++;
 }
 c++;
 p++;
 }
 c--; //to delete the read '\0'character
 printf("Information about the entered string\n");
 printf("No of lines: %d\n", l);
 printf("No of words: %d\n", w);
 printf("No of characters: %d\n", c);
 //preforming write on text file using high level system calls
 tfd = fopen("textfile.txt", "w");
 fprintf(tfd, "Data written in txt file\nInformation about the entered string\n");
 fprintf(tfd, "No of lines: %d\n", l);
 fprintf(tfd, "No of words: %d\n", w);
 fprintf(tfd, "No of characters: %d\n", c);
 fclose(tfd);
 //performing read from text file using high level system calls
 tfd = fopen("textfile.txt", "r");
 int i = 0;
 while (1) {
 if (feof(tfd)) //if chararacter is equal to end of file(EOF) break from the loop
 {
 break;
 }
 tempstr[i++] = fgetc(tfd);
 }
 tempstr[i++] = '\0';
 fclose(tfd);
 //creating and writting into second fifo file
 mkfifo(f2loc, 0666);
 fd2 = open(f2loc, O_WRONLY);
 if (write(fd2, tempstr, strlen(tempstr) + 1) == -1) //1 to include the /0 terminating character
 {
 printf("Error while writting to fifo 2 from process 2\n");
 return 1;
 }
 close(fd2);
 return 0;
}
