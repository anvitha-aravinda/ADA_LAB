#include<stdio.h>
#include<stdlib.h>
int main(){
   int i, j, count, temp;
   printf("How many numbers u are going to enter: ");
   scanf("%d",&count);
   int number[count];
   for(i=0;i<count;i++)
    number[i] = rand() % 100 + 1;
   printf("Elements before swapping\n");
   for(i=0;i<count;i++)
   printf("%d\n",number[i]);
   for(i=0;i<count;i++){
      for(j=i+1;j<count;j++){
         if(number[i]>number[j]){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
   }

   printf("Sorted elements: \n");
   for(i=0;i<count;i++)
      printf("%d\n",number[i]);

   return 0;
}
