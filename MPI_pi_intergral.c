/* Kurt Borgsmiller
   432 Lab2 pt. 2
   9/28/2018

   -Program that will calculate pi using n integrals entered by user
   -Returns the percentage error to given Pi and Eval time of program
   -The Higher the number of integrals used, the higher the accuracy to given pi
   -The greater the intervals the more accurate, however it requires more run time by processor
*/

#include <stdio.h>
#include "mpi.h"
#include <math.h>

int main() {
   int n, my_rank, comm_sz;
   double givenPi=3.141592653589793238462643, myPi, x, h,i,pi,sum = 0.0, start, finish, elapsed;

   /* Let the system do what it needs to start up MPI */
   MPI_Init(NULL, NULL);
   /* Get my process rank */
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
   /* Find out how many processes are being used */
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

if (my_rank==0)
{
	printf("Please enter n number of desired integrals \n");
	scanf("%d",&n);
}

start = MPI_Wtime();

MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

h = 1.0/(double)n;

for (i = my_rank+.5; i<n; i+=comm_sz)
{	
	x = i * h;
	sum += 1.0 / (1.0 + x *x);
}

myPi = 4.0 *h *sum;

MPI_Reduce(&myPi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

finish = MPI_Wtime();
elapsed = finish - start;

if (my_rank==0)
{
	printf("Pi approximated to %.24lf, error percentage is %.2lf percent\n", pi, (pi-givenPi)/givenPi*100);

	printf("Elapsed time: %f \n\n", elapsed);
	
}

  MPI_Finalize();

   return 0;
}

