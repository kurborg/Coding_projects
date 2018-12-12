#include <stdio.h>
#include "mpi.h"

int argc;
char **argv;

int main(argc, argv)
{

	int rank , size;
	double start, finish;

	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);	

	int w1 = 0, w2 = 0, w3 = 0, w4 = 0;

/////////////////////////////////////////////
	/* 
	int w[4] = {};
	string phrases[4] = {"Helloworld", "howareyou", "ferrari", "whotheman"};
	*/
/////////////////////////////////////////////

	string phrase_one ("Helloworld");
	string phrase_two ("howareyou");
	string phrase_three ("ferrari");
	string phrase_four ("whotheman");


	string words;

	if (rank == 0)
	{
		start = MPI_Wtime();

		ifstream file("input.txt");

		if (file.is_open())
		{
			getline(file, words, '\0');

			cout << words << "\n\n";

			file.close();
			
		}

		else
		{
			printf("error opening file. \n");
			exit(1);
		}
	}


MPI_Bcast(&words, words.length() + 1, MPI_CHAR, 0, MPI_COMM_WORLD);


////////////////////////////////////////////////////////////////////////////////
/*

if (rank != 0)
{
	for ( int i = 0; i < 4; i++)
	{
		size_t nPos = words.find(phrases[i], 0); // first occurrence

		while (nPos != string::npos)
		{
			w[i]++;
			nPos = words.find(phrases[i], nPos + 1);
		}
	
		MPI_Send(&w[i], 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
	}

}

*/
////////////////////////////////////////////////////////////////////////////////

if (rank == 1)
{
	size_t nPos = words.find(phrase_one, 0); // first occurrence
	while (nPos != string::npos)
	{
		w1++;
		nPos = words.find(phrase_one, nPos + 1);
	}
	
	MPI_Send(&w1, 1 MPI_INT, 0, 0, MPI_COMM_WORLD);
}



if (rank == 2)
{
	nPos = words.find(phrase_two, 0);
	while (nPos != string::npos)
	{
		w2++;
		nPos = words.find(phrase_two, nPos + 1);
	}
	
	MPI_Send(&w2, 1 MPI_INT, 0, 0, MPI_COMM_WORLD);
}



if (rank == 3)
{
	nPos = words.find(phrase_three, 0);
	while (nPos != string::npos)
	{
		w3++;
		nPos = words.find(phrase_three, nPos + 1);
	}
	
	MPI_Send(&w3, 1 MPI_INT, 0, 0, MPI_COMM_WORLD);
}



if (rank == 4)
{
	nPos = words.find(phrase_four, 0);
	while (nPos != string::npos)
	{
		w4++;
		nPos = words.find(phrase_four, nPos + 1);
	}
	
	MPI_Send(&w4, 1 MPI_INT, 0, 0, MPI_COMM_WORLD);
}



if (rank == 0)
{
	MPI_Recv(&w1, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	MPI_Recv(&w2, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	MPI_Recv(&w3, 1, MPI_INT, 3, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	MPI_Recv(&w4, 1, MPI_INT, 4, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	
////////////////////////////////////////////////////////////////////////////////

/*
	finish = MPI_Wtime();
	cout << "Program duration: %d" << finish - start << "\n\n";

for (i = 0; i <4; i++)
	{
	MPI_Recv(&w[i], 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

	cout << "Phrase '" << phrases[i] << "' was found " << w[i] << " times \n";
	}
*/
	
////////////////////////////////////////////////////////////////////////////////

	finish = MPI_Wtime();
	cout << "Program duration: %d" << finish - start << "\n\n";

	cout << "Phrase '" << phrase_one << "' was found " << w1 << " times \n";
	cout << "Phrase '" << phrase_two << "' was found " << w2 << " times \n";
	cout << "Phrase '" << phrase_three << "' was found " << w3 << " times \n";
	cout << "Phrase '" << phrase_four << "' was found " << w4 << " times \n\n\n";

	MPI_Finalize();
	return 0;
}
