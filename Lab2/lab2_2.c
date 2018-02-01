#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int counter=256;

int counting(pid_t array[], int start, int end)
{
	int i=0;
	int count=0;
	for(i=start; i<end+1; i++)
	{
		if(array[i]==3)
		 count++;
	}
	return count;
}

int main()
{
	int c=0;
	int array[1024];
	int i, j;
	pid_t pid[4];
	int n=4;
	int count=0;
	int num=0;

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
	
	count=0;
	for(i=0;i<4;i++)
	{
	printf("child\n");
	if((pid[count]=fork())<0){
		printf("No child");
		abort();
	}else if(pid[count]==0){
		exit(counting(array ,counter*count, (count+1)*counter));
	}printf("child %d\n", c++);
	count++;
	}
	int status;
	long sum=0;
	pid_t pids;
	while(n>0){
		pids=wait(&status)/255;
		sum=(long)(sum+pids);
		n--;
	}
	printf("Count:%ld\n",sum);
	return 0;
}
