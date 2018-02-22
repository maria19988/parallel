#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void jacobi()
{
int x1, x2, x3, number;
int i, j;
float difference;
float answer;
float temp, temp1;


printf("Please enter the number of variables: \n");
scanf("%d", &number);
int array [number][number+1];
for(i=0; i<number; i++)
{
	printf("Please enter the coefficients and r for equation number %d\n", i+1);
	for(j=0; j<number+1; j++)
	{
		scanf("%d\n", &array[i][j]);
	}
}
float error;
printf("Please enter the relative error: \n");
scanf("%f\n", &error);
float iterations[100];

for(i=0; i<100; i++)
 iterations[i]=0;
printf("Initiation done\n");

for(i=0; i<100; i++)
{
difference=0;
for(j=0; j<number; j++)
{
	if(i!=j)
	{
		answer=answer + array[i][j]*iterations[j];
	}
}
temp=(array[i][number+1]-answer)/array[i][i];
temp1=fabs((iterations[i]-temp)/temp);
if(temp1>difference)
	difference=temp1;
iterations[i]=temp;
}
if(difference<=error)
{
printf("done");
exit (0);
}


}

int main()
{
	jacobi();
	return 0;
}
