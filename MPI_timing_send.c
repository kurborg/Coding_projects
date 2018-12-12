/* Kurt Borgsmiller
   432 Lab3 pt. A
   9/29/2018

   -A program that calculates the time needed to send n messages 
    that contain one double number each, from process 0 to process

*/

#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>


int main(void) {
   int my_rank, comm_sz, n, i = 0;
   double start = 0, finish = 0, elapsed = 0;


   MPI_Init(NULL, NULL);
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

	start = MPI_Wtime();


	double * array = (double*)malloc (n * sizeof(double));

if (my_rank == 0) 
{ 
  printf("Enter value for n \n");
  scanf("%d", &n); 

	for (i = 0; i < n ; i++)
		array[i] = rand();

	for (i = 0; i < n ; i++)
		MPI_Send(&array[i], 1, MPI_DOUBLE, 1, 0, MPI_COMM_WORLD);
}


else 
{
	for (i = 0; i < n ; i++)
		MPI_Recv(&array[i], 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}


 	finish = MPI_Wtime();
	elapsed = finish - start;
	
   if (my_rank == 0) 
   {
	printf("Elapsed time: %f \n\n", elapsed);
	
   }


   MPI_Finalize();

   return 0;
}

