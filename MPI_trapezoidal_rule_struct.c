/* Kurt Borgsmiller
   10/8/2018
   ECE 432

-Use MPI to implement a parallel version of the trapezoidal rule.
-Using Build_mpi_type we get the input and create a struct and broadcast struct to all other processes using only one message.
 */

#include <stdio.h>
#include <mpi.h>

/* Get the input values */
void Get_input(int my_rank, int comm_sz, double* a_p, double* b_p,
      int* n_p);

/* Calculate local integral  */
double Trap(double left_endpt, double right_endpt, int trap_count, 
   double base_len);    


void Build_mpi_type(
	double* a_p,
	double* b_p,
	int* 	n_p,
	MPI_Datatype* input_mpi_t);

/* Function we're integrating */
double f(double x); 

int main(void) {
   int my_rank, comm_sz, n, local_n;   
   double a, b, h, local_a, local_b;
   double local_int, total_int, start = 0, finish = 0, elapsed = 0;


   MPI_Init(NULL, NULL);
   MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
   MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);

   Get_input(my_rank, comm_sz, &a, &b, &n);

start = MPI_Wtime();

   h = (b-a)/n;          /* h is the same for all processes */
   local_n = n/comm_sz;  /* So is the number of trapezoids  */

   /* Length of each process' interval of
    * integration = local_n*h.  */
   local_a = a + my_rank*local_n*h;
   local_b = local_a + local_n*h;
   local_int = Trap(local_a, local_b, local_n, h);

   /* Add up the integrals calculated by each process */
   MPI_Reduce(&local_int, &total_int, 1, MPI_DOUBLE, MPI_SUM, 0,
         MPI_COMM_WORLD);


finish = MPI_Wtime();
elapsed = finish - start;
	
   if (my_rank == 0) 
{
      printf("\n\nWith n = %d trapezoids, our estimate\n", n);
      printf("of the integral from %f to %f = %.15e\n\n",
          a, b, total_int);


	printf("Elapsed time: %f \n\n", elapsed);
   }

   MPI_Finalize();

   return 0;
} /*  main  */

/*------------------------------------------------------------------
 * Function:     Get_input
 * Purpose:      Get the user input:  the left and right endpoints
 *               and the number of trapezoids
 * Input args:   my_rank:  process rank in MPI_COMM_WORLD
 *               comm_sz:  number of processes in MPI_COMM_WORLD
 * Output args:  a_p:  pointer to left endpoint               
 *               b_p:  pointer to right endpoint               
 *               n_p:  pointer to number of trapezoids
 */
void Get_input(int my_rank, int comm_sz, double* a_p, double* b_p,
      int* n_p) {

MPI_Datatype input_mpi_t;

   if (my_rank == 0) {
      printf("Enter a, b, and n\n");
      scanf("%lf %lf %d", a_p, b_p, n_p);
   }

Build_mpi_type(a_p, b_p, n_p, &input_mpi_t);

MPI_Bcast(a_p, 1, input_mpi_t, 0, MPI_COMM_WORLD);

MPI_Type_free(&input_mpi_t);

}  /* Get_input */





void Build_mpi_type(
	double* a_p,
	double* b_p,
	int* 	n_p,
	MPI_Datatype* input_mpi_t)
{

int array_of_blocklengths[3] = {1,1,1};
MPI_Datatype array_of_types[3] = {MPI_DOUBLE, MPI_DOUBLE, MPI_INT};
MPI_Aint a_addr, b_addr, n_addr;
MPI_Aint array_of_displacements[3] = {0};

MPI_Get_address(a_p, &a_addr);
MPI_Get_address(b_p, &b_addr);
MPI_Get_address(n_p, &n_addr);

array_of_displacements[1] = b_addr - a_addr;
array_of_displacements[2] = n_addr - a_addr;

MPI_Type_create_struct(3, array_of_blocklengths, array_of_displacements, array_of_types, input_mpi_t);

MPI_Type_commit(input_mpi_t);

}

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
   return x*x;
} /* f */
