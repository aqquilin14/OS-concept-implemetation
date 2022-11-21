#include <stdio.h>
#include <stdlib.h>

struct node {
    int id, at, bt, ct, tat, wt, vis, bt2, in_queue;
};

void sort(struct node arr[], int size){
    for (int i = 0; i < size;i++){
        for (int j = 0; j < size - i - 1; j++){
            if(arr[j].at > arr[j + 1].at){
                struct node temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int num_process;
    scanf("%d",&num_process);
    struct node arr[num_process];
    for (int i = 0;i<num_process;i++){
        scanf("%d %d", &arr[i].at, &arr[i].bt);
        arr[i].id = i;
        arr[i].ct = 0;
        arr[i].tat = 0;
        arr[i].wt = 0;
        arr[i].vis = 0;
        arr[i].bt2 = arr[i].bt;
        arr[i].in_queue = 0;
    }
    struct node queue[50];
    sort(arr, num_process); // arrival time pe sort kar lena.
    int curtime = arr[0].at;
    int time_quantum = 4;
    int index = 0;
    int count = num_process;
    int curptr = 0;
    queue[curptr] = arr[0]; // p1 process presenet in ready queue.
    int var = curptr + 1;
    arr[0].in_queue = 1;
    while (count)
    {
        if(queue[curptr].bt <= time_quantum){
            int id1 = queue[curptr].id;
            for (int i = 0; i < num_process; i++){
                if(arr[i].id == id1){
                    arr[i].vis = 1;
                    curtime += arr[i].bt;
                    arr[i].bt = 0;
                    arr[i].ct = curtime;
                    arr[i].tat = arr[i].ct - arr[i].at;
                    arr[i].wt = arr[i].tat - arr[i].bt2;
                    arr[i].in_queue = 0;
                    count--;
                    break;
                }
            }
            // copy process into queue.
            for (int i = 0; i < num_process; i++)
            {
                if(arr[i].vis == 0 && arr[i].at <= curtime && arr[i].in_queue == 0){
                    queue[var] = arr[i];
                    var++;
                    arr[i].in_queue = 1;
                }
            }
        }else{
            int id1 = queue[curptr].id;
            for (int i = 0;i<num_process; i++){
                if(arr[i].id == id1){
                    curtime += time_quantum;
                    arr[i].bt -= time_quantum;
                    break;
                }
            }
            for (int i = 0;i<num_process; i++){
                if(arr[i].id != id1 && arr[i].at <= curtime && arr[i].in_queue == 0 && arr[i].vis == 0){
                    queue[var] = arr[i];
                    arr[i].in_queue = 1;
                    var++;
                }
            }
            // copy curptr wali process.
            for (int i = 0;i< num_process; i++){
                if(id1 == arr[i].id){
                    queue[var] = arr[i];
                    var++;
                    break;
                }
            }
        }
        curptr++;
    }
    printf("%d", var);
    printf("\nid\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < num_process; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", arr[i].id, arr[i].at, arr[i].bt2, arr[i].ct, arr[i].tat, arr[i].wt);
    }
}

/*
6
0 5
1 6
2 3
3 1
4 5
6 4
*/
