#ifndef GROCERHELPER_H
#define GROCERHELPER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <map>


class Groceries {
	public:

		// Getters and setters
		std::map<std::string, int> getGroceriesList();
		void setGroceriesList(std::map<std::string, int> groceriesList);

		// Print functions
		void printItem(std::string userInput);
		void printList();
		void printChart();

		// File functions
		void readData(std::ifstream& fileStream, std::string fileName);
		void writeData(std::ofstream& ofileStream, std::string fileName);

	private:
		std::map<std::string, int> groceriesList;
};

#endif // !1