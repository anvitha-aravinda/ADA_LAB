#include <stdlib.h>
#include<stdio.h>
#include<time.h>
//time complexity-worst(nlogn);best(log n)
clock_t start,end;
double cpu_time_used;
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
void heapify(int arr[], int n, int i) {
    
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
   
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
  }
  

  void heapSort(int arr[], int n) {
 
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
 
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      
      heapify(arr, i, 0);
    }
  }
  

  void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
  }
  
  
  int main() {
    int i, count,n;
    printf("Enter no of elemnts ");
    scanf("%d",&count);
    int arr[count];
    //printf("Enter %d elements: ", count);
    for(i=0;i<count;i++){
    //scanf("  %d",&arr[i]);
   arr[i] = rand() % 100 + 1;
    }
    n=count;
    printf("Array before sorting:\n");
    printArray(arr, n);
    start = clock();
  
    heapSort(arr, n);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Array has been sorted successfully taking %f\n",cpu_time_used);
  
    printf("Sorted array is \n");
    printArray(arr, n);
  }