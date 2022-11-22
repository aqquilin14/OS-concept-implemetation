#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
int main() {
 key_t key = ftok("shmfile", 65); //returns same key value in diffrent process when used
with
 //same file name and id
 int shmid;
 void * shmaddr;
 char str[100];
 shmid = shmget(key, 100, 0666 | IPC_CREAT);
 printf("shmid of the shared memory is %d\n", shmid);
 shmaddr = shmat(shmid, NULL, 0);
 printf("the shared memory is attached to the address %p\n", shmaddr);
 printf("Enter a string:\n");
 fgets(str, 100, stdin);
 strcpy(shmaddr, str);
printf("Data written in shared memory is:\n%s", (char * ) shmaddr);
 return 0;
}
