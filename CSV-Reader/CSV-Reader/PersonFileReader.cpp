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
		return a[1] < b[1]; }
	);

	//create list of row with the same last name
	vector<vector<vector<string>>> listOfSameLastNames;
	vector<vector<string>> listBuf;

	string prevLastName = "";

	for (auto row : mCurCSV.csvContents) {
		if (prevLastName.empty() || prevLastName != row[1]) {
			listOfSameLastNames.push_back(listBuf);

			listBuf.clear();
			listBuf.push_back(row);
			prevLastName = row[1];
		}
		else {
			listBuf.push_back(row);
		}
	}
	listOfSameLastNames.push_back(listBuf);

	//sort lists of mathcing last names by first name
	for (auto& lastNameList : listOfSameLastNames) {
		std::sort(lastNameList.begin(), lastNameList.end(), [](vector<string>& a, vector<string>& b) {
			return a[0] < b[0]; }
		);
	}

	//new vector with sorted values
	vector<vector<string>> sortedNames;

	for (auto lastNameList : listOfSameLastNames) {
		for (auto row : lastNameList) {
			sortedNames.push_back(row);
		}
	}

	mCurCSV = CSV(sortedNames);
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
