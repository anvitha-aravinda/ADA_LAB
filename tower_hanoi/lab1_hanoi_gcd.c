#include <stdio.h>
 
void towers(int, char, char, char);
int gcd(int a, int b);
 
int main()
{
    int num,a,b;
 
    printf("Enter the number of disks : \n");
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    printf("\n");
     printf("\n");
    printf("Enter 2 nos\n");
    scanf("%d",&a);
    scanf("%d",&b);
    printf("GCD of %d and %d is %d \n", a, b, gcd(a, b));
    return 0;
}
void towers(int num, char frompeg, char topeg, char auxpeg)
{
    if (num == 1)
    {
        printf(" \nMove disk 1 from peg %c to peg %c", frompeg, topeg);
        return;
    }
    towers(num - 1, frompeg, auxpeg, topeg);
    printf("\nMove disk %d from peg %c to peg %c", num, frompeg, topeg);
    towers(num - 1, auxpeg, topeg, frompeg);
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}