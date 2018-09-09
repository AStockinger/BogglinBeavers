/*******************************************************************************
** Project:      Bogglin' Beavers
** Date:         9 Sept 2018
** Description:  Implementation for TrieNode class that holds dictionary words
*******************************************************************************/

#include "TrieNode.hpp"

int TrieNode::convertLetterToIndex(char letter) {
	letter = toupper(letter);
	letter -= 65;
	return letter;
}

TrieNode::TrieNode() {
	numLetters = 26;

	nextLetters = new TrieNode*[26];
	for (int i = 0; i < numLetters; i++) {
		nextLetters[i] = nullptr;
	}

	wordEnd = false;
}

TrieNode* TrieNode::addNextLetter(char letter) {
	int letterIndex = convertLetterToIndex(letter);

	if (letterIndex >= 0 && letterIndex <= 25) {
		if (nextLetters[letterIndex] == nullptr) {
			nextLetters[letterIndex] = new TrieNode();
		}
		return nextLetters[letterIndex];
	}
	return nullptr;
}

TrieNode* TrieNode::getNextLetter(char letter) {
	int letterIndex = convertLetterToIndex(letter);

	if (letterIndex >= 0 && letterIndex <= 25) {
		return nextLetters[letterIndex];
	}

	return nullptr;
}
