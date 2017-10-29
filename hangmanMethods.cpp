
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>
#include <cstdlib>

using namespace std;

void Menu(char& menuSelection){//takes: selection(for case),

    string menuSelectTemp = " ";
    
    //displays the menu until user enters quit
    cout << "WELCOME TO " << endl;
    cout <<"________________________________________________________________________________" << endl;
    cout << endl;
    cout << "()    ()   ()()    ())   ()   ())))             ())    (()    ()()    ())   () " << endl;
    cout << "()    ()  ()  ()   ()()  ()  ()   ())           ()()  ()()   ()  ()   ()()  () " << endl;
    cout << "()(())() ()(())()  () () ()  ()         ((()))  () ()() ()  ()(())()  () () () " << endl;
    cout << "()    () ()    ()  ()  ()()  ()  ((((           ()  ()  ()  ()    ()  ()  ()() " << endl;
    cout << "()    () ()    ()  ()   ())   ()))))            ()      ()  ()    ()  ()   ()) " << endl;
    cout << "______________________________________________________________________________" << endl;
    cout << "ENTER SELECTION:   [P]LAY HANGMAN   [H]ELP  [Q]UIT                     VER 1.0" << endl;
    
    menuSelection = ' '; // resets the value in case the user just hits enter
    getline(cin, menuSelectTemp); //takes in a string as a choice

    //error checking user input
    //checks for the user to enter a NULL value (), then converts to a char
    if (!menuSelectTemp.empty()) {
        menuSelection = menuSelectTemp.at(0);
        menuSelection = tolower(menuSelection);
    }
   
}//end menu

//grabs a random word from the file to use
string GetWord(){

    srand(time(NULL));

    int wordChoice = 0; //gets a random iteration for a loop
    string wordToGuess; //stores the word from file
    ifstream hangmanWords;

    hangmanWords.open("hangmanWords.txt");
    
    //error checking for a valid file
    if (!hangmanWords.is_open()){
        cout << "ERROR READING FILE. CHECK AND COME BACK AGAIN SOON" << endl;
    }
    
    // cant be zero, will not iterate the loop
    wordChoice = (rand() % 10) + 1; 
    
    //this grabs the word from the file
    for (int i = 0; i < wordChoice; ++i){
        getline(hangmanWords, wordToGuess);
    }

    //converts all words to lower case if there are caps
    for (int i = 0; i < wordToGuess.length(); ++i){
        wordToGuess.at(i) = tolower(wordToGuess.at(i));
    }

    return wordToGuess;
}//end word selection


void  Help(){
    
    //general overview of game<-------------------------FIXX clean up
    cout << " HANG-MAN HELP" << endl;
    cout << "THE OBJECT OF THE GAME IS TO GUESS A WORD" << endl;
    cout << "THE SHELL OF THE WORD WILL BE DISPLAYED AS [--------]" << endl;
    cout << "AS YOU GUESS CORRECTLY, THE WORDS WILL APPEAR IN ORDER " << endl;
    cout << "AND THE MAN WILL BE SPARED (FOR NOW)." << endl;
    cout << "GET AN INCORRECT GUESS, AND THE HANGED MAN WILL BE INCRIMENTED." << endl;
    cout << "THE GAME WILL END WHEN EITHER THE WORD IS GUESSED CORRECTLY," << endl;
    cout << "OR THE MAN GETS HANGED!!" << endl;
    cout << "DO YOUR BEST, THIER FATE RESTS IN YOUR HANDS...." << endl;
    cout << endl;
}//end help


//takes the users guess
char TakeGuess(){
    
    
    string guessTemp;
    char guess = ' ';
    
    //takes the guess as a string then to a char(for input validation) 
    //also forces to lowercase 
    cout << "ENTER A LETTER TO GUESS: ";
    
    getline(cin, guessTemp);
    
    //checsk for an empty string(no input)keeps the program running
    if (!guessTemp.empty()) {
        guess = guessTemp.at(0);
        guess = tolower(guess);
    }
    
    return guess;
}//end take guesses

//checks the guess with the word selected
void CheckGuess(int& wrongGuesses,char guess,
                string wordToGuess, vector<char>& allGuesses, 
                string& correctGuesses){
    
    int correct = 0;
    
    //iterates through the sting fo find the index of the correct char
    for (int i = 0; i < wordToGuess.length(); ++i){

        if (guess == wordToGuess.at(i)){   
            correctGuesses.at(i) = guess;
            ++ correct;
        }
    }
    
    //will only increse the wrongGuesses if the letter wasnt found
    if (correct == 0){
        ++wrongGuesses;
    }
    
    //adds the letters guessed to a vector 
    allGuesses.push_back(guess);
    allGuesses.push_back('-');

}//end check guess


//resets all the values when a new game is played
void Reset(int& wrongGuesses,string& wordToGuess, 
           vector<char>& allGuesses,string& correctGuesses){
    
        wrongGuesses = 0;
        wordToGuess = GetWord();
        allGuesses.clear();
        correctGuesses.clear();
        
}//end reset

//draws the crappy hanggman
void TheHangman(int wrongGuesses){
    
    string one   	= " [[[][][][+] ";
    string two   	= "  !      [+] ";
    string three 	= "         [+] ";
    string four 	= "         [+] ";
    string five 	= "         [+] ";
    string six   	= "         [+] ";
    string seven 	= "         [+] ";
    string eight 	= "============ ";

    //these modifty the strings to incriment the dude
    if (wrongGuesses > 0){
        three.replace(0, 5, "(o o)" );
    }
    if (wrongGuesses > 1){
        four.replace(2, 1, "|");
    }
    if (wrongGuesses > 2){
        four.replace(1, 1, "-"); 
    }
    if (wrongGuesses > 3){
	four.replace(3, 1, "-");
    }
    if (wrongGuesses > 4){
        four.replace(4, 1, "<");
    }
    if (wrongGuesses > 5){
        four.replace(0, 1, ">");
    }
    if (wrongGuesses > 6){
        five.replace(2, 1, "|");
    }
    if (wrongGuesses > 7){
        six.replace(1, 1, "/");
    }
    if (wrongGuesses > 8){
        six.replace(3, 1, "\\");
        three.replace(1, 1, "x");
        three.replace(3, 1, "X");
    }
    
    //prints the hangman after each modifier
    cout << one << endl;
    cout << two << endl;
    cout << three << endl;
    cout << four << endl; 
    cout << five << endl; 
    cout << six << endl;  
    cout << seven << endl; 
    cout << eight << endl; 

}//end hangman

//win or lose functions
void YouWin(){
    cout << "WINNRER IS YOU!!" << endl;
}

void YouLose(){
    cout << "YOU LOSE. MAN IS DEAD!!" << endl;
}

//this is where most of the function call are
void Play(int& wrongGuesses,string wordToGuess, 
        vector<char>& allGuesses, string& correctGuesses){
    
    char guess;
     
    //resizes the string of correct guesses (only if they are diffent sizes) 
    if (correctGuesses.length() != wordToGuess.length()){
        for (int i = 0; i < wordToGuess.length(); ++i){
            correctGuesses.push_back('-');
        }
    }
    
    //calls the hangman function
    TheHangman(wrongGuesses);
    
    //displays the progress of play
    cout << "PROGRESS        [ " << correctGuesses << " ]" << endl;
    cout << "LETTERS GUESSED [";
    for (int i = 0; i < allGuesses.size(); ++i){//prints the elements of the vector
        cout << allGuesses.at(i);
    }
    cout << " ]" << endl;
    
    //allows user to guess a letter
    guess = TakeGuess();
   
    
    //clears the terminal screen
    if (system("CLS")) system("clear"); // I understand that this is system heavy, but make it look nicer 
//    cout << string(25, '\n'); // use this to be more secure and less system heavy

    //checks the guess with the word
    CheckGuess(wrongGuesses, guess, wordToGuess, allGuesses, correctGuesses);
    
}//end play
