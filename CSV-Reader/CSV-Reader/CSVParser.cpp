#include "CSVParser.h"

CSVParser::CSVParser(string filePath): mfilePath(filePath)
{
}

CSV CSVParser::ReadCSV()
{
	return ReadCSV(mfilePath);	
}

CSV CSVParser::ReadCSV(string filePath)
{
	ifstream fileStream = ifstream(filePath, std::ios::in);

	//if (fileStream.bad()) { throw "ERROR: Cannot open file"; }

	vector<vector<string>> fileContents;

	vector<string> lineContents;
	string lineBuf, wordBuf;

	if (fileStream.is_open()) {
		while (fileStream.good()) {
			lineContents.clear();

			std::getline(fileStream, lineBuf);
			std::stringstream streamBuffer(lineBuf);

			while (getline(streamBuffer, wordBuf, ',')) {
				lineContents.push_back(wordBuf);
			}

			fileContents.push_back(lineContents);
		}
	}

	return CSV(fileContents);
}
