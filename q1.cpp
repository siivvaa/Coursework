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
	char str[50];
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
		printf("enter string :\n");		
		scanf("%d", &n);		
		fgets(str, sizeof(str), stdin);
		write(fd[1], str, strlen(str)+1);
		close(fd[1]);
	}	
	else 
	{
		close(fd[1]);
		read(fd[0], str, sizeof(str));
		int vow = 0;
		for(int i=0; i<strlen(str); i++) 
		{
			if(isupper(str[i]))
				str[i]=tolower(str[i]);
			if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
				vow++;
		}
		printf("Number of vowels = %d\n", vow);
	}	
	return 0;
}