#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	clock_t start, finish;

	int w1 = 0, w2 = 0, w3 = 0, w4 = 0;
	string phrase_one ("Helloworld");
	string phrase_two ("howareyou");
	string phrase_three ("ferrari");
	string phrase_four ("whotheman");

	string words;
	
	start = clock();

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

	size_t nPos = words.find(phrase_one, 0); // first occurrence
	while (nPos != string::npos)
	{
		w1++;
		nPos = words.find(phrase_one, nPos + 1);
	}

	nPos = words.find(phrase_two, 0);
	while (nPos != string::npos)
	{
		w2++;
		nPos = words.find(phrase_two, nPos + 1);
	}

	nPos = words.find(phrase_three, 0);
	while (nPos != string::npos)
	{
		w3++;
		nPos = words.find(phrase_three, nPos + 1);
	}

	nPos = words.find(phrase_four, 0);
	while (nPos != string::npos)
	{
		w4++;
		nPos = words.find(phrase_four, nPos + 1);
	}

	finish = clock();

	cout << "Program duration: %d" << finish - start << "\n\n";
	cout << "Phrase '" << phrase_one << "' was found " << w1 << " times \n";
	cout << "Phrase '" << phrase_two << "' was found " << w2 << " times \n";
	cout << "Phrase '" << phrase_three << "' was found " << w3 << " times \n";
	cout << "Phrase '" << phrase_four << "' was found " << w4 << " times \n\n\n";


	system("pause");
	return 0;
}
