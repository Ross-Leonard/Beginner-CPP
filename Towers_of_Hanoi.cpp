//John Ross Leonard
//CS 372
//Towers of Hanoi

#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

int move(int n, char source, char destination, char spare, int count)
{
	
	if (n == 1)
	{
		cout << "Move the top disk from " << source << " to " << destination << endl;
		count++;		
		return count;
	}	
	move(n - 1, source, spare, destination, ++count);	
	cout << "Move disk " << n << " from " << source << " to " << destination << endl;
	count++;
	move(n - 1, spare, destination, source,++count);	
}

int main()
{	
	const char PEG1 = 'A';
	const char PEG2 = 'B';
	const char PEG3 = 'C';
	int count = 0;		
	cout << "This program solves the Hanoi Towers puzzle. \n\n";
	cout << "Enter the number of disks: ";
	int numDisks;
	cin >> numDisks;
	cout << endl;
	int nummoves;
	nummoves=move(numDisks, PEG1, PEG2, PEG3, count);
	cout << "There were a total of: " << nummoves << " made." << endl;	
	system("pause");
	return 0;
}