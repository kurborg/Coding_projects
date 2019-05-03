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
  int numArgs = argc -1;
  int wait_status[numArgs];
  int write_status = 1;
  int read_status = 1;
  char buffer;

  for(int i = 0; i < numArgs; i++)
  	pipe(pipes[i]);

  pid_t children[numArgs];



  for(int i = 0; i <numArgs; i++)
  {
    children[i] = fork();

    //CHILD PROCESSES
    if(children[i] == 0)
	{
	     for(int j = 0; j <numArgs; j++)
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
	execlp("ls", "ls", "-l", argv[i+1], NULL);
	//ANYTHING AFTER EXEC ONLY RUNS IN EXEC FAILED!
	printf("\nExec failed!");

	}

	//PARENT PROCESS
	else if(children[i] > 0)
	{
		close(pipes[i][1]);

		while(read_status > 0)
		{
			read_status = read(pipes[i][0], &buffer, 1);
			write_status = write(1, &buffer, 1);

			if(write_status < 0)
			{
				fprintf(stderr, "write() call %d failed.\n\n", i+1);
				return EXIT_FAILURE;
			}
		}

		if(read_status < 0)
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
