
#include "PersonFileReader.h"

int main()
{
	string filePath;
	cin >> filePath;
	cout << "\n\n";

	PersonFileReader personsParsers(filePath);

	//PersonFileReader personsParsers("testinput.txt");

	personsParsers.PrintPersons();

}
