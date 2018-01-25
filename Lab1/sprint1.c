#include <stdio.h>
main()
{
int array[5];
int i=0;
int num;
for(i=0; i<5; i++)
{printf("Enter a number");
scanf("%d", &num);
array[i]=num;}
int j=5;
for(j=5; j>0; j--)
{
printf("%d\n", array[j]);
}

}
