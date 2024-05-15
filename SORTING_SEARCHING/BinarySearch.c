#include<stdio.h>

int binarySearch(int arr[],int size,int element)
{
    int low,mid,high;
    low=0;
    high=arr[size-1];
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==element)
        return mid;
        if(arr[mid]<element)
        low=mid+1;
        else
        high=mid-1;
    }
    return -1;
}

int main()
{
    int n,i,element;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d",&element);
    int result = binarySearch(arr,n,element);
    if(result==-1)
    printf("Element found at index -1");
    else 
    printf("Element fount at index %d",result);
}