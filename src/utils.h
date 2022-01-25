/*!
* \file utils.h
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 23/11/2021
* \brief File containing headers for utils.c functions
*/


#ifndef UTILS_H
#define UTILS_H
/*!
* \def ERROR_MESSAGE(message)
* Used on exit() to print a message.
*/
#define ERROR_MESSAGE(message) fprintf(stderr, "%s\n",message) // error

/*! Importation of librairies and headers*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include <string.h>

/*!
* \fn void helloWorld()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Print hello world
*/
void helloWorld();

/*!
* \fn void clearBuffer()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/11/2021
* \brief Clear buffer
*/
void clearBuffer();

/*!
* \fn int inputInteger()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/11/2021
* \brief Secure integer input
* \return Integer
*/
int inputInteger();

/*!
* \fn char inputLetter()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/01/2022
* \brief Secure letter input
* \remarks None
* \return Letter
*/
char inputLetter();

/*!
* \fn char* inputString()
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  17/01/2022
* \brief Secure string input
* \remarks None
* \return String
*/
char* inputString();

/*!
* \fn void invert1DIntArray(int* pint_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Invert 1D array
* \param pint_array Array to invert
* \param int_size Size of array
*/
void invert1DIntArray(int* pint_array, int int_size);

/*!
* \fn void insertionSortInt(int* pint_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Sort an 1D integer array with insertion methode
* \param pint_array Array to sort
* \param int_size Size of the array
*/
void insertionSortInt(int* pint_array, int int_size);

/*!
* \fn void minMaxArray(int* pint_array, int int_size, int* pint_min, int* pint_max)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  10/12/2021
* \brief Affect min of array to pint_min and max of the array to pint_max
* \param pint_array Array to sort
* \param int_size Size of the array
* \param pint_min Min of the array to sort
* \param pint_max Max of the array to sort
*/
void minMaxArray(int* pint_array, int int_size, int* pint_min, int* pint_max);

/*!
* \fn void histogram(int* pint_array, int int_size, int* pint_histo, int int_min)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  10/12/2021
* \brief Histogram for counting sort
* \param pint_array Array to sort
* \param int_size Size of the array
* \param pint_histo Histogram
* \param int_min Min of array
*/
void histogram(int* pint_array, int int_size, int* pint_histo, int int_min);

/*!
* \fn void countingSortInt(int* pint_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Sort an 1D integer array with counting sort methode
* \param pint_array Array to sort
* \param int_size Size of the array
*/
void countingSortInt(int* pint_array, int int_size);

/*!
* \fn int partition(int* pint_array, int int_min, int int_max)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  09/12/2021
* \brief Partition to realize quick sort
* \param pint_array Array
* \param int_min Min
* \param int_max Max
* \return Position of partition
*/
int partition(int* pint_array, int int_min, int int_max);

/*!
* \fn void quickSortInt(int* pint_array, int int_min, int int_max)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Sort an 1D integer array with quick sort methode
* \param pint_array Array to sort
* \param int_min Min of the array
* \param int_max Max of the array
*/
void quickSortInt(int* pint_array, int int_min, int int_max);

/*!
* \fn void bubbleSortInt(int* pint_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Sort an 1D integer array with bubble sort methode
* \param pint_array Array to sort
* \param int_size Size of the array
*/
void bubbleSortInt(int* pint_array, int int_size);

/*!
* \fn void selectionSortInt(int* pint_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Sort a 1D integer array with selection methode
* \param pint_array Array to sort
* \param int_size Size of array
*/
void selectionSortInt(int* pint_array, int int_size);

/*!
* \fn int* malloc1DIntArray(int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Allocate the necessary memory to a pointer
* \param int_size Size of allocation
* \return Array allocated
*/
int* malloc1DIntArray(int int_size);

/*!
* \fn char* malloc1DCharArray(int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  06/01/2022
* \brief Allocate the necessary memory to a pointer
* \remarks None
* \param int_size Size of allocation
* \return Array allocated
*/
char* malloc1DCharArray(int int_size);

/*!
* \fn int* calloc1DIntArray(int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  10/12/2021
* \brief 
* \remarks Allocate the necessary memory to a pointer and initialize all values to 0
* \param int_size Size of allocation
* \return Array allocated and initialize all values to 0
*/
int* calloc1DIntArray(int int_size);

/*!
* \fn int** malloc2DIntArray(int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Allocate the necessary memory to a pointer of pointer
* \param int_size Size of allocation
* \return Array allocated
*/
int** malloc2DIntArray(int int_size);

/*!
* \fn int** calloc2DIntArray(int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Allocate the necessary memory to a pointer of pointer and initialize all values to 0
* \param int_size Size of allocation
* \return Array allocated and initialize all values to '0'
*/
int** calloc2DIntArray(int int_size);

/*!
* \fn char** calloc2DCharArray(int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  18/12/2021
* \brief Allocate the necessary memory to a pointer of pointer and initialize all values to '0'
* \param int_size Size of allocation
* \return Array allocated and initialize all values to '0'
*/
char** calloc2DCharArray(int int_size);

/*!
* \fn void free2DIntArray(int** tp_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Free a 2D array
* \param tp_array Array to free
* \param int_size Size of array
*/
void free2DIntArray(int** tp_array, int int_size);

/*!
* \fn void free2DCharArray(char** tp_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  08/12/2021
* \brief Free a 2D array
* \param tp_array Array to free
* \param int_size Size of array
*/
void free2DCharArray(char** tp_array, int int_size);

/*!
* \fn void displayTab1DInt(int* pint_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  10/12/2021
* \brief Display a 1D integer array
* \param pint_array Array to display
* \param int_size Size of array
*/
void displayTab1DInt(int* pint_array, int int_size);

/*!
* \fn void displayTab2DInt(int** pint_array, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  10/12/2021
* \brief Display a 2D integer array
* \param pint_array Array to display
* \param int_size Size of array
*/
void displayTab2DInt(int** pint_array, int int_size);

/*!
* \fn int randomInt(int int_min, int int_max)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  10/12/2021
* \brief Generate a random number between int_min and int_max
* \param int_min Min
* \param int_max Max
* \return Random integer
*/
int randomInt(int int_min, int int_max);

/*!
* \fn void copy2DIntArray(int** tpint_toCopyArray, int** tpint_copyArray, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  23/12/2021
* \brief Copy toCopyArray to copyArray
* \param tpint_toCopyArray Array 2D to copy
* \param tpint_copyArray Copy of toCopyArray
* \param int_size Size of arrays
*/
void copy2DIntArray(int** tpint_toCopyArray, int** tpint_copyArray, int int_size);

/*!
* \fn void copy2DCharArray(char** tpchar_toCopyArray, char** tpchar_copyArray, int int_size)
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date  23/12/2021
* \brief opy toCopyArray to copyArray
* \param tpchar_toCopyArray Array 2D to copy
* \param tpchar_copyArray Copy of toCopyArray
* \param int_size Size of arrays
*/
void copy2DCharArray(char** tpchar_toCopyArray, char** tpchar_copyArray, int int_size);

#endif // !UTILS_H