/*
* Project 3 - Corner Grocer Inventory App
* Created for: CS 210 Programming Languages - SNHU
* Developer: Tyler C Anderson
* Date: 12/10/2023
* Purpose: This program is designed to read in a list of items from a file and
* store them in a map. The program will then allow the user to search for an item
* in the map, print the list of items in the map, print a histogram of the items
* in the map, or exit the program.
* 
*/

#include "GrocerHelper.h"

int main() {

	
	Groceries myGroceries; // Create an instance of the Groceries class

	// Create file streams for input and output
	std::ifstream inFile; 
	std::ofstream outFile;

	// Create strings for file names
	std::string inFileName = "CS210_Project_Three_Input_File.txt";
	std::string outFileName = "frequency.dat";

	std::string userInput = "";

	// Read in data from file and write data to output file
	myGroceries.readData(inFile, inFileName);
	myGroceries.writeData(outFile, outFileName);

	// Loop through menu until user chooses to exit
	while (userInput != "4") {

		// Display menu
		std::cout << "\n---------  Corner Grocer Inventory App  ---------" << "\n"
		 << "           Created by: Tyler C Anderson" << "\n"
		 << "            Developed on: 12/10/2023" << "\n"
		 << "=================================================\n" << std::endl;

		std::cout <<
			"Please type a number from one of the following options:\n\n" <<
			"1 - Search for an item in data by name.\n" <<
			"2 - Print list and frequency of each item in data.\n" <<
			"3 - Print histogram of each item in data.\n" <<
			"4 - Exit program.\n\n - ";

		// Accept input from user
		std::cin >> userInput;
		std::cout << std::endl;

		// Validate input
		try {
			int testInt = stoi(userInput);
		}
		catch (std::invalid_argument) {
			// If input is not an integer (all valid menu options are integers)
			// clear the input stream and display error message
			std::cout << "I'm sorry, that is not a valid option\n" <<
				"Please try again.\n" << std::endl;
			std::cin.clear();
		}

		// If input is valid, call appropriate function
		if (userInput == "1") { myGroceries.printItem(userInput); }
		else if (userInput == "2") { myGroceries.printList(); }
		else if (userInput == "3") { myGroceries.printChart(); }
		else if (userInput == "4") { std::cout << "Thank you! Good bye.\n\n" << std::endl; }
	}
	return 0;
}