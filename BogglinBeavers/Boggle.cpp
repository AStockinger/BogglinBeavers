/*******************************************************************************
 ** Project:      Bogglin' Beavers
 ** Date:         9 Sept 2018
 ** Description:  Boggle class implementation file
 *******************************************************************************/

#include "Boggle.hpp"
#include <iostream>
#include <string>
#include <cstring>
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
    wordCount = 0;
    score = 0;
    // random seed
    srand(time(NULL));
	
    for(int i = 0; i < numRows; i++){
        vector<char> row;
        for(int j = 0; j < numCols; j++){
            row.push_back(randomChar(rand() % 100));
        }
        board.push_back(row);
    }
}

// constructor takes int arguments for board size
Boggle::Boggle(int rows, int columns){
    numRows = rows;
    numCols = columns;
    wordCount = 0;
    score = 0;
    // random seed
    srand(time(NULL));
	
    for(int i = 0; i < numRows; i++){
        vector<char> row;
        for(int j = 0; j < numCols; j++){
            row.push_back(randomChar(rand() % 100));
            }
            board.push_back(row);
        }
}

char Boggle::randomChar(int val){
    int random;
	
    // chars based on desired distribution
    char rare[] = {'J', 'Q', 'X', 'Z'};
    char uncommon[] = {'B', 'D', 'F', 'G', 'K', 'V', 'W'};
    char common[] = {'C', 'H', 'L', 'M', 'N', 'P', 'R', 'S', 'T', 'Y'};
    char vowel[] = {'A', 'E', 'I', 'O', 'U'};

    // input val should be rand() % 100 for desired results
    if(val < 5){
        random = rand() % 4;
        return rare[random];
    }
    else if(val < 30){
        random = rand() % 7;
        return uncommon[random];
    }
    else if(val < 65){
        random = rand() % 10;
        return common[random];
    }
    else{  
        random = rand() % 5;
        return vowel[random];
    }
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
			cout << "  ";
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
    string line;
    ifstream Myfile;
    bool found = false;
    Myfile.open("dictionary.txt");

    if(Myfile.is_open()){
        while(getline(Myfile, line) && !found){
            if((line.find(word)) != string::npos){
                found = true;
            }
        }
        if(found){
            return true;
        }
        else{
            return false;
        }
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
    char* arr = new char[n];
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

    delete arr;
}

bool Boggle::findWord(int x, int y, string word){
    int minWordLen = 4;
    int n = word.length();
    
    // must be 4 letters
    if(n < minWordLen){
        cout << "Input word is not long enough." << endl;
        return false;
    }
    // if word is in dictionary and word is on board, then true
    if(isWord(word) && isValid(x, y, word) && checkWord(word)){
        resetUsed();
        score = score + n * 10;
        wordCount++;
        cout << "Congratulations, you've found a word!" << endl;
        cout << "Your score is " << getScore() << endl;
        return true;
    }
    else if(!checkWord(word)){
        cout << "You have used that word already!" << endl;
        return false;
    }
    else if(!isWord(word)){
        cout << "Sorry, you did not find a word." << endl;
        return false;
    }
    else if(!isValid(x, y, word)){
        cout << "Sorry, that combination of letters does not match the board." << endl;
        return false;
    }
    else
        return false;
}

bool Boggle::checkWord(string word){
    int n = usedWords.size();
    bool wordFound = false;

    for(int i = 0; i < n; i++){
        if(usedWords[i] == word){
            wordFound = true;
        }
    }
    if(wordFound == true){
        return false;
    }
    else{
        usedWords.push_back(word);
        return true;
    }
}
