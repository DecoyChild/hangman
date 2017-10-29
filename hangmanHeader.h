/*
 *Shayne Greene
 *hangmanHeader
 *October 26, 2017, 5:54 PM
 */

#ifndef HANGMANHEADER_H
#define HANGMANHEADER_H

void Menu(char&);
string GetWord();
void Help();
void Reset(int&, string&, vector<char>&, string&);
char TakeGuess();
void CheckGuess(int&, char, string, vector<char>&, string&);
void TheHangman(int);
void YouWin();
void YouLose();
void Play(int& , string , vector<char>& , string& );


#endif /* HANGMANHEADER_H */

