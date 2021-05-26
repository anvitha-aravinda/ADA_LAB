#include<stdio.h>
#include<stdbool.h>



int binarysearch(int a[],int n,int k,bool searchfirst){
    int result=-1;
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==k)  {
              result=mid;
           if(searchfirst)
              high=mid-1;
            else
              low=mid+1;
    }
    else if(k<a[mid])  high=mid-1;
    else low=mid+1;
    }
    return result;
}
void sorting(int a[],int n)
{
    int i,j,temp;
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
            while ( j > 0 && a[j-1] > a[j])
            {
                temp     = a[j];
                a[j]   = a[j-1];
                a[j-1] = temp;
                j--;
            }
    }
}
void display(int a[],int size)
    {
         printf(" Displaying entered array");
        for(int k=0;k<size;k++)
        {
            printf(" %d ",a[k]);
        }
        printf("\n");
    }
int main(){
    int size,key;
    printf("Enter the number of elements for an array: \t\n");
    scanf("%d",&size);
    int a[size];
    printf("enter the %d elements in the array.\n",size);
    for(int i=0;i<size;i++)
    {
        scanf("%d",&a[i]);

    }
    display(a,size);

     sorting(a,size);
     printf(" After sorting array ..\n");
     display(a,size);
    int n=sizeof(a)/sizeof(a[0]);
    int x;
    printf("Enter the  key  element:\t\n");
    scanf("%d",&x);
    int f=binarysearch(a,n,x,true);
    printf("first occurence at %d index \n",f);
    if(f==-1){
        printf("elment not found in the array:\n ");
    }
    else {
        int l=binarysearch(a,n,x,false);
        printf("last occurence at %d index\n",l);
        printf("count is = %d\n", l-f+1);
    }
  printf("Time complexity, O(Logn) In case of recursive Binary implementation\n");

}
