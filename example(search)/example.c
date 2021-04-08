#include<stdio.h>
#include<stdlib.h>
void binary_s(int x);
void linear_s(int x);
int arr[100],n;
int main()
{
	int ch;
   do{
    int x;
	//n = rand() % 5 + 1;
	printf("enter how many elements to be present in the array\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	arr[i]=rand()%100+1;
	printf("the elements in the array are\n");
	for(int i=0;i<n;i++)
	printf("%d\n",arr[i]);
    printf("Enter the elem to be searched\n");
	scanf("%d",&x);
	do{
	printf("1.linearSearch  2.BinarySeacrh\n");
	printf("Enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	linear_s(x);
	break;
	case 2:
	binary_s(x);
	break;
	default:
	printf("Wrong entry\n");
	}
	printf("if you want to continue with same array press 1 else 2;to exit 3\n");
	scanf("%d",&ch);
	}while(ch==1);
}while(ch==2);



}

void linear_s(int x)
{
	int flag=0;
	int pos;
	for(int i=0;i<n;i++)
	{
	if(arr[i]==x)
	{
	flag=1;
	pos=i+1;
	break;
	}
	}
	if(flag==0)
	printf("element is not present in the list\n");
	else if(flag==1)
	printf("element is present in the list at %d\n",pos);

}
void binary_s(int x)
{
int swap,low,high,mid;
for(int i = 0 ; i < n - 1; i++)
{
for(int j = 0 ; j < n-i-1; j++)
{
if(arr[j] > arr[j+1]) 
{
swap=arr[j];
arr[j]=arr[j+1];
arr[j+1]=swap;
}
}
}
printf("array after sorting\n");
for(int i=0;i<n;i++)
printf("%d\n",arr[i]);
printf("\n");
 low = 0;
 high = n - 1;
 mid = (low+high)/2;
while (low <= high) {
if(arr[mid] < x)
low = mid + 1;
else if (arr[mid] == x) {
printf("%d found at loctaion %d\n", x,mid+1);
break;
}
else
high = mid - 1;
mid = (low + high)/2;
}
if(low > high)
printf("Not found! %d isn't present in the list\n", x);
}
