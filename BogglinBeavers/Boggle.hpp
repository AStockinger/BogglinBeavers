#ifndef BOGGLE_HPP
#define BOGGLE_HPP

#include <vector>
#include <string>
using namespace std;


class Boggle{
    private:
        int numRows, numCols;
        vector< vector <char> > board;
        char c;
        // score depends on word size, wordCount for total words guessed
        int score, wordCount;
        // marks a char as used
        bool used;
    public:
        Boggle();
        Boggle(int, int);
        void printBoard();
        int getScore();
        int getWordCount();
        // check dictionary.txt
        bool isWord(string);
        void resetUsed();
        bool isValid(int, int, string);
        bool findWord(int, int, string);
};
#endif