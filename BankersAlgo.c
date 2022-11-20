/*
Name: Shraddha Pawar
Batch N10
*/

// Banker's Algorithm
#include <stdio.h>
int main()
{
	

	int n, m, i, j, k;
	printf("Enter the number of processes: ");
	scanf("%d", &n);
	printf("Enter the number of resources: ");
	scanf("%d", &m);
	
	int alloc[n][m];
	for(int i=0; i<n; i++){
	  printf("Enter the allocated resources to Process%d: \n", i+1);
	   for(int j =0; j<m; j++){
	       scanf("%d", &alloc[i][j]);
	   }
	}
	
      int max[n][m];
      for(int i=0; i<n; i++){
	  printf("Enter the Maximum resources required by Process%d: \n", i+1);
	   for(int j =0; j<m; j++){
	       scanf("%d", &max[i][j]);
	   }
	}

    int avail[m];
    printf("Enter the available resources:\n");
    for(int i=0; i<m; i++){
    printf("Resource %d: ", i+1);
       scanf("%d", &avail[i]);
    }
    
    
    int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = max[i][j] - alloc[i][j];
	}
	
	
    //printing
    printf("Allocated Resources: \n");
    for(int i=0; i<n; i++){
	  
	   for(int j =0; j<m; j++){
	       printf(" %d ", alloc[i][j]);
	   }
	   printf("\n");
	}
    
    printf("Maximum Resources: \n");
      for(int i=0; i<n; i++){
	  
	   for(int j =0; j<m; j++){
	       printf(" %d ", max[i][j]);
	   }
	   printf("\n");
	}
	
	
	
	 printf("Needed Resources: \n");
	for(int i=0; i<n; i++){
	   for(int j =0; j<m; j++){
	       printf(" %d ", need[i][j]);
	   }
	   printf("\n");
	}
	
	printf("Available Resources: \n");
	for(int i=0; i<m; i++){
          printf(" %d ", avail[i]);
    }
printf("\n");
	
	
	
	int finish[n], ans[n], ind = 0;
	for (k = 0; k < n; k++) {
		finish[k] = 0;
	}
	 
	 
	int y = 0;
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			if (finish[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > avail[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					ans[ind++] = i+1;
					for (y = 0; y < m; y++)
						avail[y] += alloc[i][y];
					finish[i] = 1;
				}
			}
		}
	}

	int flag = 1;
	
	for(int i=0;i<n;i++)
	{
	if(finish[i]==0)
	{
		flag=0;
		printf("The following system is not safe");
		break;
	}
	}
	
	if(flag==1)
	{
	printf("Following is the SAFE Sequence\n");
	for (i = 0; i < n - 1; i++)
		printf(" P%d ->", ans[i]);
	printf(" P%d\n", ans[n - 1]);
	}
	

	return (0);

}

/*

Processes Allocation A B C Max A B C Available A B C
P0        1 1 2            4 3 3        2 1 0
P1        2 1 2            3 2 2
P2        4 0 1            9 0 2
P3        0 2 0            7 5 3
P4        1 1 2            1 1 2

Safe sequence: < P1, P4, P2, P3, P0>
*/
