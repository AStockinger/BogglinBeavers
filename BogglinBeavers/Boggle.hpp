/*******************************************************************************
 ** Project:      Bogglin' Beavers
 ** Date:         9 Sept 2018
 ** Description:  Specification file for Boggle class
 *******************************************************************************/

#ifndef BOGGLE_HPP
#define BOGGLE_HPP

#include "TrieNode.hpp"
#include <vector>
#include <string>
using namespace std;

class Boggle{
    private:
		// min length that a word can be
		const int MIN_WORD_LEN = 4;
		// dictionary of all valid words
		TrieNode* dict;
        // number of rows and cols in the board
        int numRows, numCols;
        // vector game board
        vector< vector <char> > board;
        // score depends on word size, wordCount for total words guessed
        int score, wordCount;
        // marks a char as used
        bool used;
        // stores inputted words
        vector<string> usedWords;
		// create a trie from the dictionary
		TrieNode* createTrieFromDict();
    public:
        // constructors
        Boggle();
        Boggle(int, int);
        // random char generator with varying distributions
        char randomChar(int);
        void printBoard();
        // get score and word count for user stats
        int getScore();
        int getWordCount();
        // check dictionary.txt
        bool isWord(string);
        // unmark prviously used chars
        void resetUsed();
        // validate char combinations on board
        bool isValid(int, int, string);
        // compbine isWord and isValid to keep score/count
        bool findWord(int, int, string);
        // keeps track of user inputs
        bool checkWord(string);
};
#endif
