/*

Kurt Borgsmiller

1. If the user enters a negative number, we get the out of memory allocation error 'libgomp'
2. If the user enters a 0, The system will create N number of threads which will be equal to the
	amount of processors the system has. (In our case the system spawned 8 threads)

-Asks N from user
-Spawns N omp threads
-Each thread prints random number 1-9
-Master thread prints the global sum of threads
-If the system is not using OPENMP, then the rank and threadcount will default to 0 and 1

*/


#include <stdio.h>
#include<stdlib.h>

#if defined(_OPENMP)
	#include <omp.h>
#else 
	int my_rank = 0;
	int N = 1;
#endif



// rand numb function
void randPrint(int rank, int thread_count, int* global)
{
	
	int rando = rand() % 10;

	printf("Number from thread %d of %d: %d \n", rank, thread_count, rando);


	#if defined(_OPENMP)
		#pragma omp critical
			*global += rando;
	#else 
		*global = rando;
	#endif
}




int main ()
{
	int N;
	int global_result = 0;
	printf("Please enter N \n");
	scanf("%d", &N);

	#if defined(_OPENMP)
		#pragma omp parallel num_threads(N)
			{
				int my_rank = omp_get_thread_num();
				int N = omp_get_num_threads();
				randPrint(my_rank,N, &global_result);
			}
	#else
		randPrint(my_rank, N, &global_result);

	#endif


	printf("\n\nGlobal sum: %d \n" , global_result);


return 0;
}

