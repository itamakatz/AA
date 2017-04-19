//
// Created by itamar on 4/18/17.
//

#ifndef PROTEIN_MATCHING_CSV_H
#define PROTEIN_MATCHING_CSV_H

// Code source:
// http://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c

#include <iterator>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

class CSVRow {
private:
	std::vector<std::string> _m_data;

public:
	std::string const& operator[](std::size_t index) const {
		return _m_data[index];
	}

	std::size_t size() const {
		return _m_data.size();
	}

	void readNextRow(std::istream& str) {
		std::string line;
		std::getline(str, line);

		std::stringstream lineStream(line);
		std::string cell;

		_m_data.clear();
		while(std::getline(lineStream, cell, ',')) {
			_m_data.push_back(cell);
		}

		// This checks for a trailing comma with no data after it.
		if (!lineStream && cell.empty()) {
			// If there was a trailing comma then add an empty element.
			_m_data.push_back("");
		}
	}

	std::vector<std::string> get_m_data(){
		return _m_data;
	}
};

std::istream& operator>>(std::istream& str, CSVRow& data) {
	data.readNextRow(str);
	return str;
}

//int main()
//{
//	std::ifstream       file("plop.csv");
//
//	CSVRow              row;
//	while(file >> row)
//	{
//		std::cout << "4th Element(" << row[3] << ")\n";
//	}
//}


#endif //PROTEIN_MATCHING_CSV_H
