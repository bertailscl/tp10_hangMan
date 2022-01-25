/*!
* \file main.c
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 05/01/2022
* \brief Main file for tp7
*/

/*! Importation of librairies and headers*/
#include "utils.h"
#include "hangMan.h"

/*!
* \fn int main(int argc, char** argv)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \brief Main function of the program
* \date 05/01/2022
* \param argc number of arguments given as inputs
* \param argv value of arguments given as inputs
* \return 0 if all went good
*/
int main(int argc, char** argv)
{
    srand(time(NULL));
    if (argc > 1)
    {
        char* pchar_word = randomWord(argv[1]);
        playHangMan(pchar_word);
        free(pchar_word);
    }
    else
    {
        exit(ERROR_MESSAGE("Missing arguments : file path"));
    }
    return (EXIT_SUCCESS);
}