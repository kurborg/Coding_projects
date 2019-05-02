#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

  if(argc < 2 || argc > 5)
  {
    printf("ERROR: Incorrect number of file arguments!\n");
    exit(1);
  }
  
  int pipes[4][2];
  int wait_status[argc];
  int write_status[argc] = 1;
  int read_status[argc] = 1;
  char buffer;
  
  pipe(pipes);
  
  pid_t children[numArgs];
	
  
  
  for(int i = 0; i <argc; i++)
  {
    children[i] = fork();
    
    //CHILD PROCESSES
    if(children[i] == 0)
	{
	     for(int j = 0; j <argc; j++)
	     {
		if (i == j)
		   close(pipes[j][0]);
		else
		{
		close(pipes[j][0]);
		close(pipes[j][1]);
		}
	     }
	    
	    
	    	dup2(pipes[i][1], 1);
		execlp(argv[i+1],argv[i+1],"ls", "-l", NULL);
	       //ANYTHING AFTER EXEC ONLY RUNS IN EXEC FAILED!
	   	printf("\nExec failed!");
	
	}
	  
	//PARENT PROCESS
	else if(children[i] > 0)
	{
		close(pipes[i][1]);
		
		while(read_status[i] > 0)
		{
			read_status[i] = read(pipes[i][0], &buffer, 1);
			write_status[i] = write(1, &buffer, 1);

			if(write_status[i] < 0)
			{
				fprintf(stderr, "write() call %d failed.\n\n", i+1);
				return EXIT_FAILURE;
			}
		}
		
		if(read_status[i] < 0)
		{
			fprintf(stderr, "read() call %d failed.\n\n", i+1);
			return EXIT_FAILURE;
		}
		
		

		waitpid(children[i], &wait_status[i], 0);
		printf("Child %d has been collected.\n\n" , i+1);

	}
	  
	  
	//FORK() ERROR
	else if(children[i] < 0)
	{
		fprintf(stderr, "fork() %d call failed.\n\n", i+1);
		return EXIT_FAILURE;
	}  
	  
  
  }
  	
    
printf("All children have been collected. Program exiting\n\n");
return EXIT_SUCCESS;

}



/*
NOTES FROM CLASS

for (int i = 0; i < argc; i++)
	close(pipe[i][1];



*/
