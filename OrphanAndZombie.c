#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
void printArray(int arr[], int size)
{
int i;
printf("Sorted array is : ");
for (i = 0; i < size; i++)
printf("%d ",arr[i]);
printf("\n");
}
void swap(int* xp, int* yp)
{
int temp = *xp;
*xp = *yp;
*yp = temp;
}
void selectionSort(int arr[], int n)
{
int i, j, min_idx;
// One by one move boundary of unsorted subarray
for (i = 0; i < n-1; i++)
{
// Find the minimum element in unsorted array
min_idx = i;
for (j = i+1; j < n; j++)
if (arr[j] < arr[min_idx])
min_idx = j;
if(min_idx != i)
swap(&arr[min_idx], &arr[i]);
}
printArray(arr, n);
printf("Job done by Selection_sort.\n");
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
int i, j;
for (i = 0; i < n - 1; i++)
// Last i elements are already in place
for (j = 0; j < n - i - 1; j++)
if (arr[j] > arr[j + 1])
swap(&arr[j], &arr[j + 1]);
printArray(arr, n);
printf("Job done by Bubble_sort.\n");
}
int main(){
int n ;
char buffer[25];
printf("Enter the size of Array: ");
scanf("%d", &n);
int arr[n];
for(int i=0; i<n; i++){
printf("Enter the %dth element: ",i+1);
scanf("%d",&arr[i]);
printf("\n");
}
int choice;
printf("Select the process type number you want to demonstrate: \n1.Orphan\n2.Zombie\n3.Exit\n");
scanf("%d", &choice);
pid_t proc = fork();
switch(choice){
case 1:
if(proc==0){
printf("I'm a child process.\n");
sleep(7);
printf("My process id is: %d\n", proc);
printf("My pid is: %d\n", getpid());
printf("My parent id is: %d\n", getppid());
bubbleSort(arr, n);
sleep(3);
printf("Process status: ");
snprintf(buffer, 25, "ps -elf | grep %d", getpid());
system(buffer);
printf("\n\n\n");
}else if(proc<0){
printf("Fork failed.\n");
printf("\n\n\n");
}else{
printf("I'm a parent process.\n");
//sleep(2);
printf("My process id is: %d\n", proc);
printf("My pid is: %d\n", getpid());
printf("My parent id is: %d\n", getppid());
selectionSort(arr, n);
//snprintf(buffer, 25, "ps -ef | grep %d", getpid());
// system(buffer);
printf("\n\n\n");
}
break;
case 2:
if(proc==0){
printf("I'm a child process.\n");
//sleep(2);
printf("My process id is: %d\n", proc);
printf("My pid is: %d\n", getpid());
printf("My parent id is: %d\n", getppid());
bubbleSort(arr, n);
//printf("Process status: ");
sleep(3);
//snprintf(buffer, 25, "ps -ef | grep %d", getpid());
//system(buffer);
printf("\n\n\n");
}else if(proc<0){
printf("Fork failed.\n");
printf("\n\n\n");
}else{
printf("I'm a parent process.\n");
sleep(7);
printf("My process id is: %d\n", proc);
printf("My pid is: %d\n", getpid());
printf("My parent id is: %d\n", getppid());
selectionSort(arr, n);
printf("Process status: ");
snprintf(buffer, 25, "ps -elf | grep %d", getpid());
system(buffer);
printf("\n\n\n");
}
break;
case 3:
exit(0);
default: printf("Invalid choice...");
break;
}
}