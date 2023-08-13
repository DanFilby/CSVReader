#include "PersonFileReader.h"

PersonFileReader::PersonFileReader(string filePath)
	:mCSVReader(filePath)
{
	mCurCSV = mCSVReader.ReadCSV();
	Sort();
}

void PersonFileReader::Sort()
{
	//sort by last names
	std::sort(mCurCSV.csvContents.begin(), mCurCSV.csvContents.end(), [](vector<string>& a, vector<string>& b) {
		return (a[1] == b[1])? a[0] < b[0] : a[1] < b[1]; }
	);
}

void PersonFileReader::PrintPersons()
{
	for (const auto& row : mCurCSV.csvContents) {
		cout << "First Name:  " << row[0] << "\n";
		cout << "Last Name:  " << row[1] << "\n";
		cout << "Age:        " << row[2] << "\n";
		cout << "==================" << "\n";
	}
}
