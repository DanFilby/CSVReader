#pragma once

#include "Common.h"
#include "CSVParser.h"

#include <algorithm>

class PersonFileReader
{
public:
	PersonFileReader(string filePath);

	void Sort();
	void PrintPersons();

private:

	CSVParser mCSVReader;

	CSV mCurCSV{};
};

