/*******************************************************************************
 ** Project:      Bogglin' Beavers
 ** Date:         9 Sept 2018
 ** Description:  Specification file for Boggle class
 *******************************************************************************/

#ifndef BOGGLE_HPP
#define BOGGLE_HPP

#include <vector>
#include <string>
using namespace std;

class Boggle{
    private:
        // number of rows and cols in the board
        int numRows, numCols;
        // vector game board
        vector< vector <char> > board;
        // score depends on word size, wordCount for total words guessed
        int score, wordCount;
        // marks a char as used
        bool used;
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
};
#endif
