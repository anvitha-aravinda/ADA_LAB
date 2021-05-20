#include <stdlib.h>
#include<stdio.h>
#include<time.h>
//time complexity:best(o(n)),avg(o(nlogn)),worst(o(n^2))
clock_t start,end;
double cpu_time_used;
void quicksort(int number[25],int first,int last){
int i, j, pivot, temp;
if(first<last){
pivot=first;
i=first;
j=last;
while(i<j){
while(number[i]<=number[pivot]&&i<last)
i++;
while(number[j]>number[pivot])
j--;
if(i<j){
temp=number[i];
number[i]=number[j];
number[j]=temp;
}
}
temp=number[pivot];
number[pivot]=number[j];
number[j]=temp;
quicksort(number,first,j-1);
quicksort(number,j+1,last);
}
}
int main(){
int i, count,n;
printf("Enter no of elemnts ");
scanf("%d",&count);
int number[count];
printf("Enter %d elements: ", count);
for(i=0;i<count;i++){
scanf("  %d",&number[i]);
};
start = clock();
quicksort(number,0,count-1);
end=clock();
cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
printf("Array has been sorted successfully taking %f\n",cpu_time_used);
printf("The Sorted Order is: ");
for(i=0;i<count;i++)
printf(" %d",number[i]);
return 0;
}