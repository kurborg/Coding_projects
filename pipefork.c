#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{

  if(argc < 1 || argc >4)
  {
    printf("ERROR: Incorrect number of file arguments!\n");
    exit(1);
  }
  
  int numArgs = argc;
  int pipes[4][2];
  
  pipe(numArgs);
  
  pid_t children[numArgs];
  
  
  for(int i = 0; i <argc; i++)
  {
    
    if(children[i] == 0)
	{
		close (pipes[i]);
		int input_fd = open(argv[i+1], O_RDONLY);
		char buffer;
		int read_status = 1;
		int write_status = 1;

		while(read_status > 0)
		{
			read_status = read(input_fd, &buffer, 1);
			write_status = write(pipe_ends[i], &buffer, 1);

			if(write_status < 0)
			{
				fprintf(stderr, "One of the write() calls failed.\n\n");
				return EXIT_FAILURE;
			}
		}

		if(read_status < 0)
		{
			fprintf(stderr, "One of the read() calls failed.\n\n");
			return EXIT_FAILURE;
		}

		printf("child %d has finished passing the input file into the pipe.\n\n", i+1);
		return EXIT_SUCCESS;
	}
	//fork() error
	else if(children[i] < 0)
	{
		fprintf(stderr, "The first fork() call failed.\n\n");
		return EXIT_FAILURE;
	}  
  
  }
  
  
  for(int i = 0; i <numArgs; i++)
    close(pipes[i]);

	//For the sake of this example, the wait status of the children is not checked.
	int wait_status[numArgs];
  for(int i = 0; i <numArgs; i++)
  {
	  waitpid(child[i], &wait_status[i], 0);
	  printf("Child %d has been collected.\n\n" , i+1);
  }
  
    printf("All children have been collected. Program exiting\n\n");
	  return EXIT_SUCCESS;
  
  }
