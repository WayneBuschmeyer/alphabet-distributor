#include "distribute_alphabet.h"
#include <random>

// Function to distribute the alphabet among friends
// This function assigns each letter of the alphabet to a specified number of friends randomly,
// ensuring no two consecutive letters are assigned to the same friend when possible.
std::pair<std::vector<std::pair<char, int>>, std::map<int, int>> distributeAlphabet(int numberOfFriends)
{
	// Define the alphabet as a constant string
	// The alphabet is the set of characters to be distributed among friends
	const std::string alphabet{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

	// Store the length of the alphabet
	// We need to know the total number of letters to iterate over and assign
	const int alphabetLength{ static_cast<int>(alphabet.length()) };

	// Create a vector to store pairs of letter and assigned friend number
	// 'assignments' will hold each letter and the friend it is assigned to
	std::vector<std::pair<char, int>> assignments(alphabetLength);

	// Create a map to store how many letters each friend has received
	// 'letterCount' keeps track of the number of letters assigned to each friend
	std::map<int, int> letterCount;

	// Initialize letter count for each friend
	// Set each friend's letter count to zero initially
	for (int i = 1; i <= numberOfFriends; ++i)
	{
		letterCount[i] = 0; // Initialize each friend's letter count to zero
	}

	// Set up the random number generator for shuffling
	// 'std::random_device' provides entropy, and 'std::mt19937' is a Mersenne Twister RNG used for shuffling
	std::random_device rd;
	std::mt19937 g(rd());

	// Create a vector of friend indices
	// This vector contains indices of friends to facilitate random assignment of letters
	std::vector<int> friendIndices(numberOfFriends);
	for (int i = 0; i < numberOfFriends; ++i)
	{
		friendIndices[i] = i + 1; // Friends are numbered starting from 1
	}

	// Variable to store the last assigned friend to avoid consecutive assignments
	int lastAssignedFriend{ -1 };

	// Loop over each letter in the alphabet to assign it to a friend
	// Iterate over each letter and randomly assign it, ensuring no consecutive letters go to the same friend if possible
	for (int i = 0; i < alphabetLength; ++i)
	{
		// Shuffle the friend indices to randomize selection
		// Shuffle before each assignment to ensure randomness in selection
		std::shuffle(friendIndices.begin(), friendIndices.end(), g);

		// Initialize currentFriend as -1 for selecting a friend
		int currentFriend{ -1 };

		// Select a friend who was not the last assigned friend
		// Find a friend index that differs from the previous one, and also favors the friend with fewer letters
		for (int friendIndex : friendIndices)
		{
			// Ensure the selected friend is not the same as the last assigned one
			// Also prefer friends with fewer assigned letters to balance distribution
			if (friendIndex != lastAssignedFriend &&
				(currentFriend == -1 || letterCount[friendIndex] < letterCount[currentFriend]))
			{
				currentFriend = friendIndex; // Choose this friend
			}
		}

		// Assign the current letter to the selected friend
		assignments[i] = std::make_pair(alphabet[i], currentFriend);

		// Update the letter count for the current friend
		// Keep track of how many letters this friend has received
		letterCount[currentFriend]++;

		// Update the last assigned friend to the current friend
		// To ensure the next iteration does not assign to the same friend again if possible
		lastAssignedFriend = currentFriend;
	}

	// Sort the assignments by letter to display in alphabetical order
	// Sorting helps to display the results in a predictable and readable way, i.e., A-Z
	std::sort(assignments.begin(), assignments.end(),
		[](const std::pair<char, int>& a, const std::pair<char, int>& b)
		{
			return a.first < b.first;
		});

	// Return the assignment of letters and the letter count
	// Return both the assignments for each letter and the count of letters per friend
	return std::make_pair(assignments, letterCount);
} // end distributeAlphabet
