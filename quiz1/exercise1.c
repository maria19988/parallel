#include <stdio.h>
#include <stdlib.h>

#define women 5

/*char deliver()
{
	printf("Hello sweetie! Here's your gift from Thomas. Happy Valentines's");
}*/

int main()
{
	pid_t pids[women];
	int i;
	for(i=0; i<women; i++)
	{
		pids[i]=fork();
		if(pids[i]<0)
		{printf("Error delivering");}
		else {
		//char x [50]= deliver();
		char x [50]="Hello sweetie! Here's your gift from Thomas. Happy Valentines's";
		exit(x);
		}
	}
	pid_t pid;
	int n=women;
	while (n>0){
	char status[50]="";
	pid=wait(&status);
	printf("%s\n",status);
	n--;
	}
	return 0;
}
