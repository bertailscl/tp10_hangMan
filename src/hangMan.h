/*!
* \file hangMan.h
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 05/01/2022
* \brief file containing hangMan.c headers
* \remarks None
*/

#ifndef HANGMAN_H
#define HANGMAN_H

/*! Importation of librairies and headers*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/*!
* \fn char* randomWord(char* filePath)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/01/2022
* \brief Return a random word from a file
* \remarks None
* \param filePath Path to the file
* \return A random word form file
*/
char* randomWord(char* filePath);

/*!
* \fn long long int countFileWords(char* filePath)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/01/2022
* \brief Count number of lines in a file
* \remarks None
* \param filePath Path to the file
* \return Number of lines
*/
long long int countFileWords(char* filePath);

/*!
* \fn int lenFileWord(char* filePath, long long int llint_word)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/01/2022
* \brief Count the length of a specify word in a file
* \remarks None
* \param filePath File
* \param llint_word
* \return length of llint_word
*/
int lenFileWord(char* filePath, long long int llint_word);

/*!
* \fn void playHangMan(char* pchar_toFind)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/01/2022
* \brief Play to hang man
* \remarks None
* \param pchar_toFind Word to find
*/
void playHangMan(char* pchar_toFind);

/*!
* \fn int tryLetter(char* pchar_toFind, char* pchar_toFindCpy, int int_toFindLen)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/01/2022
* \brief Inuput letter and try if it is in the word to find
* \remarks None
* \param pchar_toFind Word to find
* \param pchar_toFindCpy Copy word to find
* \param int_toFindLen Length of word
* \return 0 if letter is not in the word, 1 if letter is in the word
*/
int tryLetter(char* pchar_toFind, char* pchar_toFindCpy, int int_toFindLen);

/*!
* \fn void saveScore(char* pchar_word, int remainingTry)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/01/2022
* \brief Save on a file name save.txt the name of player, the word to find and the remaining try, if score exist keep the best.
* \remarks None
* \param pchar_word Word to print
* \param remainingTry Remaining try
*/
void saveScore(char* pchar_word, int remainingTry);

/*!
* \fn int isOnFile(char* pchar_name)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  21/01/2022
* \brief Check in score.txt if player is already register
* \remarks None
* \param pchar_name Player's name
* \return -1 if is not on file, lastScore else else
*/
int isOnFile(char* pchar_name);

/*!
* \fn void deleteScore(char* pchar_name)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  21/01/2022
* \brief Delete line where player is already register
* \remarks None
* \param pchar_name Player's name
*/
void deleteScore(char* pchar_name);

/*!
* \fn void writeScore(char* pchar_name, char* pchar_word, int remainingTry)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  21/01/2022
* \brief Write sore of player in score.txt
* \remarks None
* \param pchar_name Player's name
* \param pchar_word Word to find
* \param remainingTry Remaining Try
*/
void writeScore(char* pchar_name, char* pchar_word, int remainingTry);

#endif // !HANGMAN_H