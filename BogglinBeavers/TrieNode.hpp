/*******************************************************************************
** Project:      Bogglin' Beavers
** Date:         9 Sept 2018
** Description:  Specification for TrieNode class that holds dictionary words
*******************************************************************************/

#ifndef TRIE_NODE_HPP
#define TRIE_NODE_HPP

#include <vector>
#include <string>
using namespace std;

class TrieNode {
private:
	int numLetters;
	// number of rows and cols in the board
	TrieNode** nextLetters;
	// true if the node is the end of a word
	bool wordEnd;
	int convertLetterToIndex(char letter);
public:
	// constructors
	TrieNode();
	TrieNode* addNextLetter(char letter);
	TrieNode* getNextLetter(char letter);
	bool isWord() { return wordEnd; }
	void setWordEnd(bool isWordEnd) { wordEnd = isWordEnd; }
};
#endif
