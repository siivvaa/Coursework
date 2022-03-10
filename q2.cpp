#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int fd[2];
	int n;
	int arr[10];
	pid_t f;
	
	if(pipe(fd) == -1) {
		printf("Error: Pipe failed");
		exit(0);
	}
	
	f = fork();	
	if(f < 0) 
	{
		printf("Error: Fork failed");
		exit(0);
	}	
	else if (f ==0) //Child
	{
		close(fd[0]);
		printf("enter array elements :\n");		
		for(int i=0;i<10;i++)
            scanf("%d", &arr[i]);		
		write(fd[1], arr, sizeof(arr));
		close(fd[1]);
	}	
	else 
	{
        int a[10];
		close(fd[1]);
		read(fd[0], a, sizeof(arr));
		int vow = 0;
		int sum=0;
        for(int i=0;i<10;i++)
		{
            sum += a[i];
		}
		printf("Sum of all elements = %d\n", sum);
	}	
	return 0;
}