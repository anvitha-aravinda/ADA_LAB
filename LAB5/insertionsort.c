#include<stdio.h>
#include<stdlib.h>
int main(){
   int i, j, count, temp, number[25];
   printf("How many numbers u are going to enter: ");
   scanf("%d",&count);
   for(i=0;i<count;i++)
    number[i] = rand() % 100 + 1;
   printf("Elements before swapping\n");
   for(i=0;i<count;i++)
   printf("%d\n",number[i]);
   for(i=1;i<count;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }


   printf("Sorted elements: \n");
   for(i=0;i<count;i++)
      printf("%d\n",number[i]);

   return 0;
}
