/*!
* \file hangMan.c
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 05/01/2022
* \brief file containing hang man functions
* \remarks None
*/

/*! Importation of librairies and headers*/
#include "hangMan.h"
#include "utils.h"

char* randomWord(char* filePath)
{
    int int_numbreOfWord; // line of random word in the file
    int int_sizeOfWord; // length of random word in the file
    int int_lenWord; // length of each word in file
    long long int llint_numberLines = countFileWords(filePath); // number of lines in the file
    long long int llint_countWords = 0; // number of words passed in file
    char char_car;
    char* pchar_word = NULL; // word chosen
    FILE* file; // file

    // random line
    int_numbreOfWord = randomInt(0, llint_numberLines);
    // get word size
    int_sizeOfWord = lenFileWord(filePath, int_numbreOfWord);
    // allocate memory size for pchar_word
    pchar_word = malloc1DCharArray(int_sizeOfWord + 1);

    if ((file = fopen(filePath,"r")) == NULL)
    {
        // error file doesn't load correct
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    do
    {
        char_car = fgetc(file);
        if ((char_car == EOF || isspace(char_car)) && int_lenWord > 0)
        {
            llint_countWords++;
            int_lenWord = 0;
        }
        else if (!isspace(char_car))
        {
            int_lenWord++;
        }
    } while ((llint_countWords != int_numbreOfWord-1) && char_car != EOF);
    if (char_car == EOF)
    {
        exit(ERROR_MESSAGE("ERROR : Word out of range"));
    }
    for (int i = 0; i < int_sizeOfWord; i++)
    {
        char_car = fgetc(file);
        while (isspace(char_car) && char_car != EOF)
        {
            char_car = fgetc(file);
        }
        pchar_word[i] = char_car;
    }
    pchar_word[int_sizeOfWord] = '\0';
    fclose(file);
    return (pchar_word);
}

long long int countFileWords(char* filePath)
{
    int int_lenWord = 0; // length of line
    long long int llint_count = 0; // number of lines
    char char_car; // actual caracter
    FILE* file; // file

    if ((file = fopen(filePath,"r")) == NULL)
    {
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    do
    {
        // get caractere
        char_car = fgetc(file);
        if ((char_car == EOF || isspace(char_car)) && int_lenWord > 0)
        {
            // end of word
            llint_count++;
            int_lenWord = 0;
        }
        else if (!isspace(char_car))
        {
            // add one len to word
            int_lenWord++;
        }
    } while (char_car != EOF);
    fclose(file);
    return (llint_count);
}

int lenFileWord(char* filePath, long long int llint_word)
{
    int int_len = 0;
    int int_lenWord = 0;
    long long int llint_count = 0;
    char char_car;
    FILE* file;

    if ((file = fopen(filePath,"r")) == NULL)
    {
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    do
    {
        // get caractere
        char_car = fgetc(file);
        if ((char_car == EOF || isspace(char_car)) && int_lenWord > 0)
        {
            // end of word
            llint_count++;
            int_len = int_lenWord;
            int_lenWord = 0;
        }
        else if (!isspace(char_car))
        {
            // add one len to word
            int_lenWord++;
        }
    }while ((llint_count != llint_word) && char_car != EOF);
    if (int_len == 0)
    {
        exit(ERROR_MESSAGE("ERROR : Line does not exist in this file"));
    }
    fclose(file);
    return(int_len);
}

void playHangMan(char* pchar_toFind)
{
    int int_win = 0;
    int int_remainingTry = 10; // remaining try
    int int_toFindLen = strlen(pchar_toFind); // word length
    char* pchar_toFindCpy = malloc1DCharArray(int_toFindLen+1); // play word
    for (int i = 0; i < int_toFindLen; i++)
    {
        pchar_toFindCpy[i] = '_';
    }
    pchar_toFindCpy[int_toFindLen] = '\0';
    // printf("Word %s\n", pchar_toFind);
    while (int_remainingTry > 0 && !int_win)
    {
        printf("%s\n", pchar_toFind);
        printf("Word : %s \t Remaining try : %d\n\n", pchar_toFindCpy, int_remainingTry);
        if(!tryLetter(pchar_toFind, pchar_toFindCpy, int_toFindLen))
        {
            int_remainingTry--;
        }
        int_win = 1;
        for (int i = 0; i < int_toFindLen; i++)
        {
            if (pchar_toFindCpy[i] == '_')
            {
                int_win = 0;
            }            
        }
    }
    if (int_win)
    {
        printf("Word : %s \t Remaining try : %d\n\n", pchar_toFindCpy, int_remainingTry);
        printf("You Win !\n");
        saveScore(pchar_toFind, int_remainingTry);
    }
    else
    {
        printf("You lost, word to find was : %s\n", pchar_toFind);
    }
    free(pchar_toFindCpy);
}

int tryLetter(char* pchar_toFind, char* pchar_toFindCpy, int int_toFindLen)
{
    int int_res = 0; // boolean : 0 if letter not find, 1 else
    printf("Input the letter you want : ");
    char char_letter = inputLetter(); // letter to try
    if (char_letter >= 97 && char_letter <= 122)
    {
        // upper letter if tiny
        char_letter = toupper(char_letter);
    }
    for (int i = 0; i < int_toFindLen; i++)
    {
        // letter is in the word to find
        if (char_letter == pchar_toFind[i])
        {
            pchar_toFindCpy[i] = char_letter;
            int_res = 1;
        }
    }
    return (int_res);
}

void saveScore(char* pchar_word, int remainingTry)
{
    int int_lastScore; // 0 if no score affected to the name, 1 else
    char* pchar_name; // name of player
    printf("Print your name for the scoreboard : ");
    
    pchar_name = inputString();
    int_lastScore = isOnFile(pchar_name); // FIND IF THERE IS A SCORE AT THIS NAME : not find return -1, find return score
    if (int_lastScore != -1 && int_lastScore < remainingTry)
    {
        // delete last score
        deleteScore(pchar_name);
        // write new score
        writeScore(pchar_name, pchar_word, remainingTry);
    }
    else
    {
        //write score
        writeScore(pchar_name, pchar_word, remainingTry);
    }
    free(pchar_name);
}

int isOnFile(char* pchar_name)
{
    int int_res; // boolean : -1 if name is not on file, lastScore else
    int int_continue = 1;
    size_t sizet_memoryInFileLineSize;
    ssize_t ssizet_inFileLineSize; // length of line in file
    char* pchar_tmp = NULL; // temporary variable use with strtok
    char* pchar_line = NULL; // line from file_score
    char* pchar_inFileName = NULL; // name frome file_score
    FILE* file_score; // file where you can find all scores
    // lire le fichier et le creer si il n'existe pas
    if ((file_score = fopen("src/res/score.txt","a+")) == NULL)
    {
        // error file doesn't load correct
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    ssizet_inFileLineSize = getline(&pchar_line, &sizet_memoryInFileLineSize, file_score);
    while (ssizet_inFileLineSize != -1 && int_continue)
    {
        // get all names (1st part of the line ; ex line : "name wordToFind remainingTry")
        pchar_inFileName = strtok(pchar_line, " ");
        if (strcmp(pchar_inFileName, pchar_name) == 0)
        {
            int_continue = 0;
        }
        pchar_tmp = strtok(NULL, " ");
        pchar_tmp = strtok(NULL, " ");
        int_res = atoi(pchar_tmp);
        ssizet_inFileLineSize = getline(&pchar_line, &sizet_memoryInFileLineSize, file_score);
    }
    if (int_continue)
    {
        int_res = -1;
    }
    fclose(file_score);
    return (int_res);
}

void deleteScore(char* pchar_name)
{
    size_t sizet_memoryInFileLineSize; // memory of file
    ssize_t ssizet_inFileLineSize; // length of line in file
    char* pchar_line; // line from file_score
    char* pchar_inFileName = NULL; // name frome file_score
    FILE* file_score; // file where you can find all scores
    FILE* file_tmp; // file temporary to delete one line

    if ((file_score = fopen("src/res/score.txt","r+")) == NULL)
    {
        // error file doesn't load correct
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    if ((file_tmp = fopen("bin/tmp.txt","w+")) == NULL)
    {
        // error file doesn't load correct
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    ssizet_inFileLineSize = getline(&pchar_line, &sizet_memoryInFileLineSize, file_score);
    while (ssizet_inFileLineSize != -1)
    {
        // get all names (1st part of the line ; ex line : "name wordToFind remainingTry")
        pchar_inFileName = strtok(pchar_line, " ");
        if (strcmp(pchar_inFileName, pchar_name) != 0)
        {
            fprintf(file_tmp, "%s %s\n",pchar_inFileName, pchar_line);
        }
        ssizet_inFileLineSize = getline(&pchar_line, &sizet_memoryInFileLineSize, file_score);
    }
    fclose(file_score);
    fclose(file_tmp);
    if ((file_score = fopen("src/res/score.txt","w+")) == NULL)
    {
        // error file doesn't load correct
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    if ((file_tmp = fopen("bin/tmp.txt","r+")) == NULL)
    {
        // error file doesn't load correct
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    ssizet_inFileLineSize = getline(&pchar_line, &sizet_memoryInFileLineSize, file_tmp);
    while (ssizet_inFileLineSize != -1)
    {
        fprintf(file_score, "%s\n", pchar_line);
        ssizet_inFileLineSize = getline(&pchar_line, &sizet_memoryInFileLineSize, file_tmp);
    }
    fclose(file_score);
    fclose(file_tmp);
}

void writeScore(char* pchar_name, char* pchar_word, int remainingTry)
{
    FILE* file_score;
    if ((file_score = fopen("src/res/score.txt", "a+")) == NULL)
    {
        // error file doesn't load correct
        exit(ERROR_MESSAGE("ERROR : File not opened correctly"));
    }
    if (fgetc(file_score) != EOF)
    {
        fprintf(file_score, "\n");
    }
    fprintf(file_score,"%s %s %d", pchar_name, pchar_word, remainingTry);
    fclose(file_score);
}
