/*
OBJECTIVE - Create a Hangman game that uses a text file to store at least 10 words to choose from.

Requirements.

A menu that allows a player to choose to play, get help, or quit ** GOOD**
When a user asks for help, print how to play the game and how to use your program ** GOOD**
When the user selects quit - quit the program. **GOOD*
When a user selects play, start your game **GOOD**
Be sure the input is valid - ask again if it is not ** GOOD **
You need to draw the hangman as the user makes incorrect guesses ** OK BUT WORKS ** 
You need local variables to store the number of guesses 
You will need to use loop constructs to enable continued guessing
You will use methods to group logical actions
You will need to use arrays or vectors and possibly C-strings

Your code should be commented appropriately including appropriate header comment
Submission

Submit all code files
Submit a document that describes the rules to the game, 
how to use the program, summarize how the program works


 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

#include "hangmanHeader.h"

int main() {

    int wrongGuesses;
    char menuSelection;
    vector<char> allGuesses;//originalay had as a string (changed to meet criteria of assignment)
    string wordToGuess;
    string correctGuesses;
    
    do { //looops until the user selects 'q'

        Menu(menuSelection);
        //enter menu and selections here
        switch (menuSelection) {

            case 'p':
                
                //resets everything
                Reset(wrongGuesses, wordToGuess, allGuesses, correctGuesses);
                
                //plays until the player guesses the word or is out of guesses
                do{              
                    
                 Play(wrongGuesses, wordToGuess, allGuesses, correctGuesses);
                 
                }while (wrongGuesses < 9 && correctGuesses != wordToGuess );
                
                //displays the hangman again
                TheHangman(wrongGuesses);
                cout << "WORD WAS \"" << wordToGuess  << "\"" << endl;
                
                //displays if you are a winner or a loser...
                if (correctGuesses == wordToGuess){
                    YouWin();
                }
                else{
                    YouLose();
                }
                
                break;

            case 'h':
                Help();
                
                break;

            default://lets you know that the input wasnt valid (also not q)
                if (menuSelection != 'q'){
                    cout << "NOT A VALID SELECTION!!" << endl;
                }
            break;

        }
    } while (menuSelection != 'q');

    cout << "GOODBYE!!" << endl << "PROGRAM END" << endl;


}