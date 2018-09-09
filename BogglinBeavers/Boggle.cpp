#include "Boggle.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
#include <fstream>

using namespace std;

// default constructor is 4x4 board
Boggle::Boggle(){
    numRows = 4;
    numCols = 4;
    int r;
    wordCount = 0;
    score = 0;

    srand(time(NULL));
    for(int i = 0; i < numRows; i++){
        vector<char> row;
        for(int j = 0; j < numCols; j++){
            r = rand() % 26;
            c = 'A' + r;
            row.push_back(c);
        }
        board.push_back(row);
    }
    resetUsed();
}

// constructor takes int arguments for board size
Boggle::Boggle(int rows, int columns){
    numRows = rows;
    numCols = columns;
    int r;
    wordCount = 0;
    score = 0;

    // random seed
    srand(time(NULL));
        for(int i = 0; i < numRows; i++){
            vector<char> row;
            for(int j = 0; j < numCols; j++){
                r = rand() % 26;
                c = 'A' + r;
                row.push_back(c);
            }
            board.push_back(row);
        }

    resetUsed();
}

void Boggle::printBoard(){

    // column labels
    cout << "  ";
    for(int i = 0; i < numCols; i++){
        cout << " " << setw(2) << i;
    }
    cout << endl;

    for(unsigned int i = 0; i < numRows; i++){
        // row labels
        cout << setw(2) << i << "  ";
        for(unsigned int j = 0; j < numCols; j++){
           cout << board[i][j];
           	if (board[i][j] == 'Q'){
			    cout << "u ";
			}
            else{
				std::cout << "  ";
			}
       }
       cout << endl;
   }
}

int Boggle::getScore(){
    return score;
}

int Boggle::getWordCount(){
    return wordCount;
}

// check string to dictionary text file
bool Boggle::isWord(string word){
    int offset; 
    string line;
    ifstream Myfile;
    Myfile.open("dictionary.txt");

    if(Myfile.is_open()){
        while(!Myfile.eof()){
            getline(Myfile, line);
            if((line.find(word)) != string::npos){
                return true;
            }
        }
        Myfile.close();
    }
    else
        return false;
}

void Boggle::resetUsed(){
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            if(board[i][j] == used){
                board[i][j] = !used;
            }
        }
    }
}

// check bounds and if letter is used
bool Boggle::isValid(int x, int y, string word){
    // copy string into array for checking
    int n = word.length();
    char arr[n];
    strcpy(arr, word.c_str());

    int i = 0;
    int row = x;
    int col = y - 1;
 
    while(board[row][col] == arr[i] && i < n){
        // play not on edge of board
        if(row != 0 && row != numRows - 1 && col != 0 && col != numCols - 1){
            i++;
            if(board[--row][col] == arr[i] && board[--row][col] != used){
                board[row][col] = used;
                row--;
                continue;
            }
            else if(board[--row][--col] == arr[i] && board[--row][--col] != used){
                board[row][col] = used;
                row--;
                col--;
                continue;
            }
            else if(board[--row][++col] == arr[i] && board[--row][++col] != used){
                board[row][col] = used;
                row--;
                col++;
                continue;
            }
            else if(board[row][++col] == arr[i] && board[row][++col] != used){
                board[row][col] = used;
                col++;
                continue;
            }
            else if(board[++row][++col] == arr[i] && board[++row][++col] != used){
                board[row][col] = used;
                row++;
                col++;
                continue;
            }
            else if(board[++row][col] == arr[i] && board[++row][col] != used){
                board[row][col] = used;
                row++;
                continue;
            }
            else if(board[++row][--col] == arr[i] && board[++row][--col] != used){
                board[row][col] = used;
                row++;
                col--;
                continue;
            }
            else if(board[row][--col] == arr[i] && board[row][--col] != used){
                board[row][col] = used;
                col--;
                continue;
            }
            else
                return false;
        }
        // play is in row 0 and not a corner
        else if(row == 0 && col != 0 && col != (numCols - 1)){
            i++;
            if(board[row][++col] == arr[i] && board[row][++col] != used){
                board[row][col] = used;
                col++;
                continue;
            }
            else if(board[++row][++col] == arr[i] && board[++row][++col] != used){
                board[row][col] = used;
                row++;
                col++;
                continue;
            }
            else if(board[++row][col] == arr[i] && board[++row][col] != used){
                board[row][col] = used;
                row++;
                continue;
            }
            else if(board[++row][--col] == arr[i] && board[++row][--col] != used){
                board[row][col] = used;
                row++;
                col--;
                continue;
            }
            else if(board[row][--col] == arr[i] && board[row][--col] != used){
                board[row][col] = used;
                col--;
                continue;
            }
            else
                return false;
        }
        // play is in col 0 and not a corner
        else if(row != 0 && row != (numRows - 1) && col == 0){
            i++;
            if(board[--row][col] == arr[i] && board[--row][col] != used){
                board[row][col] = used;
                row--;
                continue;
            }
            else if(board[--row][++col] == arr[i] && board[--row][++col] != used){
                board[row][col] = used;
                row--;
                col++;
                continue;
            }
            else if(board[row][++col] == arr[i] && board[row][++col] != used){
                board[row][col] = used;
                col++;
                continue;
            }
            else if(board[++row][++col] == arr[i] && board[++row][++col] != used){
                board[row][col] = used;
                row++;
                col++;
                continue;
            }
            else if(board[++row][col] == arr[i] && board[++row][col] != used){
                board[row][col] = used;
                row++;
                continue;
            }
            else
                return false;
        }
        // play is in last row and not a corner
        else if(row == (numRows - 1) && col != 0 && col != (numCols - 1)){
            i++;
            if(board[--row][col] == arr[i] && board[--row][col] != used){
                board[row][col] = used;
                row--;
                continue;
            }
            else if(board[--row][--col] == arr[i] && board[--row][--col] != used){
                board[row][col] = used;
                row--;
                col--;
                continue;
            }
            else if(board[--row][++col] == arr[i] && board[--row][++col] != used){
                board[row][col] = used;
                row--;
                col++;
                continue;
            }
            else if(board[row][++col] == arr[i] && board[row][++col] != used){
                board[row][col] = used;
                col++;
                continue;
            }
            else if(board[row][--col] == arr[i] && board[row][--col] != used){
                board[row][col] = used;
                col--;
                continue;
            }
            else
                return false;
        }
        // play is in last col and not a corner
        else if(row != 0 && row != (numRows - 1) && col == (numCols - 1)){
            i++;
            if(board[--row][col] == arr[i] && board[--row][col] != used){
                board[row][col] = used;
                row--;
                continue;
            }
            else if(board[--row][--col] == arr[i] && board[--row][--col] != used){
                board[row][col] = used;
                row--;
                col--;
                continue;
            }
            else if(board[++row][col] == arr[i] && board[++row][col] != used){
                board[row][col] = used;
                row++;
                continue;
            }
            else if(board[++row][--col] == arr[i] && board[++row][--col] != used){
                board[row][col] = used;
                row++;
                col--;
                continue;
            }
            else if(board[row][--col] == arr[i] && board[row][--col] != used){
                board[row][col] = used;
                col--;
                continue;
            }
            else
                return false;
        }
        // while a play is in the top left corner
        else if(row == 0 && col == 0){
            i++;
            if(board[row][++col] == arr[i] && board[row][++col] != used){
                board[row][col] = used;
                col++;
                continue;
            }
            else if(board[++row][++col] == arr[i] && board[++row][++col] != used){
                board[row][col] = used;
                row++;
                col++;
                continue;
            }
            else if(board[++row][col] == arr[i] && board[++row][col] != used){
                board[row][col] = used;
                row++;
                continue;
            }
            else
                return false;
        }
        // while play is in the top right corner
        else if(row == 0 && col == (numCols - 1)){
            i++;
            if(board[++row][col] == arr[i] && board[++row][col] != used){
                board[row][col] = used;
                row++;
                continue;
            }
            else if(board[++row][--col] == arr[i] && board[++row][--col] != used){
                board[x][y] = used;
                row++;
                col--;
                continue;
            }
            else if(board[row][--col] == arr[i] && board[row][--col] != used){
                board[row][col] = used;
                col--;
                continue;
            }
            else
                return false;
        }
        // while play is in the bottom left corner
        else if(row == (numRows - 1) && col == 0){
            i++;
            if(board[--row][col] == arr[i] && board[--row][col] != used){
                board[row][col] = used;
                row--;
                continue;
            }
            else if(board[--row][++col] == arr[i] && board[--row][++col] != used){
                board[row][col] = used;
                row--;
                col++;
                continue;
            }
            else if(board[row][++col] == arr[i] && board[row][++col] != used){
                board[row][col] = used;
                col++;
                continue;
            }
            else
                return false;
        }
        // while a play is in the bottom right corner
        else if(row == (numRows - 1) && col == (numCols - 1)){
            i++;
            if(board[--row][col] == arr[i] && board[--row][col] != used){
                board[row][col] = used;
                row--;
                continue;
            }
            else if(board[--row][--col] == arr[i] && board[--row][--col] != used){
                board[x][y] = used;
                row--;
                col--;
                continue;
            }
            else if(board[row][--col] == arr[i] && board[row][--col] != used){
                board[row][col] = used;
                col--;
                continue;
            }
            else
                return false;
        }
        else if(row >= numRows || row < 0 || col >= numCols || col < 0){
            return false;
        }
    }
    return true;
}

bool Boggle::findWord(int x, int y, string word){
    int minWordLen = 4;
    int n = word.length();
    
    // must be 4 letters
    if(n < minWordLen){
        cout << "Input word is not long enough." << endl;
        return false;
    }
    if(isWord(word) && isValid(x, y, word)){
        resetUsed();
        score = score + n * 10;
        wordCount++;
        cout << "Congratulations, you've found a word!" << endl;
        cout << "Your score is " << getScore() << endl;
        return true;
    }
    else if(!isWord(word)){
        cout << "Sorry, you did not find a word." << endl;
        return false;
    }
    else if(!isValid(x, y, word)){
        cout << "Sorry, that combination of letters does not match the board." << endl;
        return false;
    }
}