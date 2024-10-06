#ifndef DISTRIBUTE_ALPHABET_H
#define DISTRIBUTE_ALPHABET_H

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <utility>

// This header file declares the function to distribute the alphabet among friends.

// The function `distributeAlphabet` takes an integer representing the number of friends.
// It returns a pair:
// - A vector of pairs, where each pair consists of a character (a letter from the alphabet) and an integer (the friend number to whom the letter is assigned).
// - A map, where the key is a friend's number and the value is the count of letters assigned to that friend.
// The function ensures that the distribution is balanced and avoids assigning consecutive letters to the same friend where possible.

std::pair<std::vector<std::pair<char, int>>, std::map<int, int>> distributeAlphabet(int numberOfFriends);

#endif // DISTRIBUTE_ALPHABET_H
