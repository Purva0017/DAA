#include<stdio.h>

void merge(int a[],int low,int mid,int high)
{
    int i,j,k,b[100];
    i=low;
    j=mid+1;
    k=low;

    while(i<=mid && j<=high)
    {
        if(a[i]<a[j])
        {
            b[k]=a[i];
            k++,i++;
        }
        else
        {
            b[k]=a[j];
            k++,j++;
        }
    }
    while(i<=mid)
    {
        b[k]=a[i];
        k++,i++;
    }
    while(j<=high)
    {
        b[k]=a[j];
        k++,j++;
    }
    for(int i=low;i<=high;i++)
    {
        a[i]=b[i];
    }
}

void mergeSort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int size, i;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int a[size];
    printf("Enter the elements: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    mergeSort(a,0,size-1);
    printArray(a,size);
}