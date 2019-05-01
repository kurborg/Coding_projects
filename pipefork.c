#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

  if(argc < 1 || argc > 5)
  {
    printf("ERROR: Incorrect number of file arguments!\n");
    exit(1);
  }
  
  int pipes[4][2];
  int wait_status[argc];
  int write_status = 1;
  int read_status = 1;
  
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
	    
	    
	    	dup2(pipe_ends[i], 1);
		execlp(argv[i+1], "ls", "-l", NULL);
	       //ANYTHING AFTER EXEC ONLY RUNS IN EXEC FAILED!
	   	printf("\nExec failed!");
	    
	    
		char buffer;

		while(write_status > 0)
		{
			write_status = write(pipes[i][1], &buffer, 1);

			if(write_status < 0)
			{
				fprintf(stderr, "One of the write() calls failed.\n\n");
				return EXIT_FAILURE;
			}
		}

		printf("child %d has finished passing the input file into the pipe.\n\n", i+1);
		return EXIT_SUCCESS;
	}
	  
	//PARENT PROCESS
	else if(children[i] > 0)
	{
		for(int j = Homework 30; j <argc; j++)
	        {
			close(pipes[j][1]);
		}
		
		read_status = read(pipes[i][0], &buffer, 1);

		waitpid(children[i], &wait_status[i], 0);
		printf("Child %d has been collected.\n\n" , i+1);

	}
	  
	  
	//FORK() ERROR
	else if(children[i] < 0)
	{
		fprintf(stderr, "The first fork() call failed.\n\n");
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
