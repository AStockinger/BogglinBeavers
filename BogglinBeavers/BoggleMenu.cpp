/*******************************************************************************
 ** Project:      Bogglin' Beavers
 ** Date:         9 Sept 2018
 ** Description:  BoggleMenu is where the user interacts with the program by
 **               setting the board and inputting words
 **               input validation included
 *******************************************************************************/

#include <iostream>
#include <time.h>
#include "Boggle.hpp"
#include "Boggle.cpp"
using namespace std;

int main(){
    // variables for user input
    int cols, rows;
    int x, y;
    string guess;

    // if timer runs out, gameOver is true and the program should stop
    bool gamePlay = true;

    // intro
    cout << "Welcome to Boggle. In this game, you will be given a grid of randomized letters. " <<
    "You must find words by picking a starting letter and then choosing a second letter from the " <<
    "letters directly surrounding that initial letter. " << endl;
    cout << "Some additional rules are that you may not use the same exact letter twice, and each word must " <<
    "be more than 3 letters in length." << endl;

    // choose rows and cols
        cout << "How many rows of letters would you like? Please enter an integer value greater than 3 and less than 100." << endl;
    cin >> rows;
    while(rows > 100 || rows < 4){
        cin.fail();
        cin.ignore();
        cout << "Invalid input. Please enter an integer greater than 3 and less than 100." << endl;
        cin >> rows;
    }
    cout << "How many columns of letters would you like? Please enter an integer value greater than 3 and less than 100." << endl;
    cin >> cols;
    while(cols > 100 || cols < 4){
        cin.fail();
        cin.ignore();
        cout << "Invalid input. Please enter an integer greater than 3 and less than 100." << endl;
        cin >> cols;
    }

    // set up and print board
    Boggle bboard(rows, cols);
    bboard.printBoard();

    // while the game is going, accept a guessWord
    while(gamePlay){
        cout << "Enter a row number for the first letter or enter -1 to exit." << endl;
        cin >> x;
        if(x == -1){
            gamePlay = false;
            break;
        }
        while(x < 0 || x > rows - 1){
            cin.fail();
            cin.ignore();
            cout << "Please enter a valid row number." << endl;
            cin >> x;
        }
        cout << " Now enter a column number for the first letter." << endl;
        cin >> y;
        while(y < 0 || y > cols - 1){
            cin.fail();
            cin.ignore();
            cout << "Please enter a valid column number." << endl;
            cin >> y;
        }
        cout << "Now enter the word, in all CAPS." << endl;
        cin >> guess;

            bboard.findWord(x, y, guess);
    }

    while(gamePlay == false){
        cout << "Game Over! You found " << bboard.getWordCount() << " words!" << endl;
        cout << "Your final score is " << bboard.getScore() << endl;
        return 0;
        exit(0);
    }
}
