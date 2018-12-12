/* Kurt Borgsmiller
   432 Lab2 pt. 1
   9/28/2018

   -Program that calculates the square of x using integrals
   -Must only use MPI communicative functions (MPI_Reduce & MPI_Bcast)
   -User must enter values for a, b, and n

*/

#include <stdio.h>
#include <mpi.h>

/* Calculate local integral  */
double Trap(double left_endpt, double right_endpt, int trap_count, 
   double base_len);    

double f(double x); 

int main(void) {
   int my_rank, comm_sz, n, local_n;
   double a, b, h, local_a, local_b, local_int, total_int;

   /* Let the system do what it needs to start up MPI */
   MPI_Init(NULL, NULL);
   /* Get my process rank */
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
   /* Find out how many processes are being used */
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);


   if (my_rank == 0) { 
  printf("Enter values for a, b and n \n");
  scanf("%lf %lf %d", &a, &b, &n); }


	MPI_Bcast(&a, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
 	MPI_Bcast(&b, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
 	MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

   h = (b-a)/n;          /* h is the same for all processes */
   local_n = n/comm_sz;  /* So is the number of trapezoids  */

   /* Length of each process' interval of
    * integration = local_n*h.  So my interval
    * starts at: */
   local_a = a + my_rank*local_n*h;
   local_b = local_a + local_n*h;
   local_int = Trap(local_a, local_b, local_n, h);

 	MPI_Reduce(&local_int, &total_int, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

   /* Print the result */
   if (my_rank == 0) {
      printf("With n = %d trapezoids, our estimate\n", n);
      printf("of the integral from %lf to %lf = %.15e\n",
          a, b, total_int);
   }

   /* Shut down MPI */
   MPI_Finalize();

   return 0;
} /*  main  */


/*------------------------------------------------------------------
 * Function:     Trap
 * Purpose:      Serial function for estimating a definite integral 
 *               using the trapezoidal rule
 * Input args:   left_endpt
 *               right_endpt
 *               trap_count 
 *               base_len
 * Return val:   Trapezoidal rule estimate of integral from
 *               left_endpt to right_endpt using trap_count
 *               trapezoids
 */
double Trap(
      double left_endpt  /* in */, 
      double right_endpt /* in */, 
      int    trap_count  /* in */, 
      double base_len    /* in */) {
   double estimate, x; 
   int i;

   estimate = (f(left_endpt) + f(right_endpt))/2.0;
   for (i = 1; i <= trap_count-1; i++) {
      x = left_endpt + i*base_len;
      estimate += f(x);
   }
   estimate = estimate*base_len;

   return estimate;
} /*  Trap  */


/*------------------------------------------------------------------
 * Function:    f
 * Purpose:     Compute value of function to be integrated
 * Input args:  x
 */
double f(double x) {
   return x*x*x;
} /* f */
