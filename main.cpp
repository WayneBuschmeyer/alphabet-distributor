#include "distribute_alphabet.h"
#include <iostream>
#include <vector>
#include <map>

// Main function to demonstrate the distribution of alphabet letters among friends
int main()
{
	int numberOfFriends{}; // Number of friends to whom letters will be distributed

	// Prompt user for the number of friends
	// Get input from the user regarding how many friends are involved in the distribution
	std::cout << "Enter the number of friends: ";
	std::cin >> numberOfFriends;

	// Handle invalid input case
	// Ensure that the number of friends is at least 1, otherwise exit with an error message
	if (numberOfFriends < 1)
	{
		std::cout << "Number of friends must be at least 1." << std::endl;
		return 1; // Exit with an error code to indicate failure
	}

	// Get the assignments and counts from distributeAlphabet function
	// Call the function to distribute the alphabet letters, receiving both the assignments and a letter count per friend
	auto [assignments, letterCount] = distributeAlphabet(numberOfFriends);

	// Display the assignment of letters to friends
	// Iterate over the assignments vector to print which letter was assigned to which friend
	for (const auto& assignment : assignments)
	{
		std::cout << "Friend " << assignment.second << ": " << assignment.first << std::endl;
	}

	// Display how many letters each friend got
	// Print out a summary of how many letters each friend has received
	std::cout << "\nNumber of letters each friend got:" << std::endl;
	for (const auto& count : letterCount)
	{
		std::cout << "Friend " << count.first << ": " << count.second << " letters" << std::endl;
	}

    	// Pause the program to prevent the console window from closing immediately
    	std::cout << "\nPress Enter to exit...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear out the input buffer
    	std::cin.get(); // Wait for the user to press Enter

    	return 0;
	
} // end main
