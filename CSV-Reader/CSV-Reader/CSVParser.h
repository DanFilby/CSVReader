#pragma once

#include "Common.h"

struct CSV {
	vector<vector<string>> csvContents;

	CSV(): csvContents() {}
	CSV(vector<vector<string>> _csvContents){
		csvContents = _csvContents;
	}

	vector<string> GetRow(int index) {
		if (!(index >= 0 && index <= csvContents.size())) { return vector<string>(NULL); }
		return csvContents[index];
	}

	vector<string> GetColumn(int index) {	
		vector<string> column;

		for (auto row : csvContents) {
			if (!(index >= 0 && index <= row.size())) { continue; }

			column.push_back(row[index]);
		}
	}
};

class CSVParser
{

public:
	CSVParser(string filePath);

	CSV ReadCSV();
	CSV ReadCSV(string filePath);

private:
	string mfilePath;

};

