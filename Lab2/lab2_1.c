#include <stdio.h>

int main()
{
	int array[1024];
	int i;
	int count=0;
	for(i=0;i<1024;i++)
	{
		array[i]=rand()%11;
	}
	for(i=0;i<1024;i++)
	{
		if(array[i]==3)
		count++;
	}
	printf("Count of 3s is:%d\n", count);
	return 0;
}

