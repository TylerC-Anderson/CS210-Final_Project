#include "GrocerHelper.h"

// Getters and setters
std::map<std::string, int> Groceries::getGroceriesList() {
	return groceriesList;
}
void Groceries::setGroceriesList(std::map<std::string, int> groceriesList) {
	this->groceriesList = groceriesList;
}

void Groceries::printItem(std::string userInput) {
	/*
	* This function will search for an item in the map and print the item
	* and its frequency if it is found. If the item is not found, the user
	* will be prompted to try again.
	* 	
	* @param userInput - The item the user is searching for
	* @return - void
	* 
	*/
	bool searchSucceeded = false;  // Flag to determine if search was successful
	std::map<std::string, int> items = groceriesList;


	while (!searchSucceeded) {
		
		std::cout << "What item would you like to search for today?\n"
			<< "Be sure to capitalize the first letter.\n - ";
		std::cin >> userInput;
		std::cout << std::endl;

		// Search for item in map within the try-catch block
		try {
			std::cout << userInput << " " << items.at(userInput) << std::endl;
			std::cout << std::endl;
		}
		catch (std::out_of_range) {
			std::cout << "I'm sorry, it appears that item is not in the list.\n" <<
				"Please try again.\n\n" << std::endl;
			std::cin.clear();
		}

		searchSucceeded = true; // Set flag to true to exit loop
	}
	userInput = "";  // Reset userInput to empty string

	
}

void Groceries::printList() {
	/*
	* This function will print the list of items in the map and their
	* frequencies.
	* 
	* @param - none
	* @return - void
	*/
	std::map<std::string, int> items = groceriesList;

	// Loop through map and print each item and its frequency
	for (auto const& list : items) {
		std::cout << std::setw(3) << std::right  << list.second << " -- " <<
			std::setw(3) << std::right << list.first << std::endl;
	}
}

void Groceries::printChart() {
	/*
	* This function will print a histogram of the items in the map.
	* 
	* @param - none
	* @return - void
	*/
	std::map<std::string, int> items = groceriesList;

	for (auto const& list : items)  {
		std::cout << std::setw(15) << std::left << list.first;
	
		// This loop prints the number of asterisks equal to the frequency of the item
		// to construct the histogram
		for (int i = 0; i < list.second; ++i) {
			std::cout << '*';
		}
		std::cout << std::endl;

	}
}

void Groceries::readData(std::ifstream& fileStream, std::string fileName) {
	/*
	* This function will read in data from a file and store it in a map.
	* 
	* @param fileStream - The file stream to read from
	* @param fileName - The name of the file to read from
	* @return - void
	*/
	std::string fileData;
	std::map<std::string, int> items = groceriesList;
	
	// Open file and read in data
	fileStream.open(fileName);

	// If file cannot be opened, display error message
	if (!fileStream.is_open()) {
		std::cout << "Could not open file " << fileName << std::endl;
		return;
	}

	// If file is opened successfully, read in data and store in map
	else
	{
		while (std::getline(fileStream, fileData)) {
			if (items.count(fileData) == 0) {
				items.emplace(fileData, 1);
			}

			else {
				++items.at(fileData);
			}
		}

		fileStream.close();
	}

	// Set the map in the Groceries class to the map created in this function
	setGroceriesList(items);
}

void Groceries::writeData(std::ofstream& fileStream, std::string fileName) {
	/*
	* This function will write data to a file.
	* 
	* @param fileStream - The file stream to write to
	* @param fileName - The name of the file to write to
	* @return - void
	* 	
	*/

	// Open file and write data
	fileStream.open(fileName);

	// If file cannot be opened, display error message
	if (!fileStream.is_open()) {
		std::cout << "Could not open file " << fileName << std::endl;
		return;
	}

	else
	{
		// Loop through map and write each item and its frequency to the file
		std::map<std::string, int> items = groceriesList;

		for (auto const& list : items) {
			fileStream << std::setw(3) << std::right << list.second << " -- " <<
				std::setw(3) << std::right << list.first << std::endl;
		}

		fileStream.close();
	}
}