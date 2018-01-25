#include <stdio.h>
int add(int n);
main()
{
int num;
printf("Enter a number");
scanf("%d", &num);
printf("Sum = %d",add(num));
return 0;
}
int add(int n)
{
if(n != 0)
    return n + add(n-1);
else
    return n;
}
