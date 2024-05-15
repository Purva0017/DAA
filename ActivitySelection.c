#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void select_Activity(int start[],int end[],int n){
    int i=0;
    printf("Activity selected:%d",i+1);
    for(int j=1;j<n;j++){
        if(start[j]>=end[i]){
            printf("->%d",j+1);
            i=j;
        }
    }
}

int main(){
    int n;
    printf("Enter the number of activities:");
    scanf("%d",&n);
    int start[n],end[n];
    
    for(int i=0;i<n;i++){
        printf("Enter the start and finish time of the %d activity:",i+1);
        scanf("%d %d",&start[i],&end[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(start[i]<start[j])
            {
                int temp = start[j];
                start[j]= start[i];
                start[i]= temp;

                int temp1 = end[j];
                end[j]=end[i];
                end[i]=temp1;
            }
        }
    }
    printf("Activities after sorting: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d: %d %d\n",i+1,start[i],end[i]);
    }
    
    select_Activity(start,end,n);
}

