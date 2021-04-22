#include<stdio.h>
#include <stdlib.h>
int RecursiveLS(int arr[], int value, int index, int n)
{
    int pos = 0;
 
    if(index >= n)
    {
        return 0;
    }
 
    else if (arr[index] == value)
    {
        pos = index + 1;
        return pos;
    }
 
    else
    {
        return RecursiveLS(arr, value, index+1, n);
    }
    return pos;
}
int RecursiveBS(int a[], int x, int low, int high) {
int mid,swap;
    if (high >= low){
       mid = low + (high - low)/2;
      if (a[mid] == x)
         return mid;
      if (a[mid] > x)
         return RecursiveBS(a,x, low, mid-1);
      if(a[mid]<x)
      return RecursiveBS(a,x, mid+1, high);
   }
   return -1;
}
int main()
{
    int arr[100],t,x,pos,low,high,position,a[100],swap;
    printf("enter the no of elems you want to enter in the array\n");
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    arr[i] = rand() % 100 + 1;
    for(int i=0;i<t;i++)
    printf("%d\n",arr[i]) ;
    printf("Enter the elem to be searched\n");
    scanf("%d",&x);
    printf("\n----------LINEAR SEARCH-----------\n");
    pos =  RecursiveLS(arr, x, 0, t);
    if (pos != 0)
    {
        printf("Element found at pos %d ", pos);
    }
    else
    {
        printf("Element not found");
    }
    printf("\n----------BINARY SEARCH-----------\n");
    low = 0;
    high = t - 1;
    for(int i=0;i<t;i++)
    a[i]=arr[i];
    for(int i = 0 ; i < t-1; i++)
    {
    for(int j = 0 ; j < t-i-1; j++)
    {
    if(a[j] > a[j+1]) 
    {
    swap=a[j];
    a[j]=a[j+1];
    a[j+1]=swap;
    }
    }
    }
    printf("array after sorting\n");
    for(int i=0;i<t;i++)
    printf("%d\n",a[i]);
    printf("\n");
    position = RecursiveBS(a, x, low, high);
    if (position != -1) {
    printf("\nNumber present at %d", (position + 1));
    } else
    printf("\n The number is not present in the list");

    return 0;
}
