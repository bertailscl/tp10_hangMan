/*!
* \file utils.c
* \author Clément Bertails <clement.bertails@cy-tech.fr>
* \version 0.1
* \date 23/11/2021
* \brief File containing utilitaries functions
*/

/*! Importation of librairies and headers*/
#include "utils.h"

void helloWorld(){printf("Hello World !\n");}

void clearBuffer()
{
    int int_c; // select first caractere on buffer
    // clear buffer
    do
    {
        int_c = getchar();
    } while (int_c != EOF && int_c != '\n');
}

int inputInteger()
{
    int int_res; // input integer
    // ask again if entered is not an integer or float
    while (!scanf("%d", &int_res))
    {
        // clear the buffer if entered is not an integer or float
        clearBuffer();
        printf("Input error : input is not an integer.\nPlease retry : ");
    }
    // clear buffer if entered is a float
    clearBuffer();
    return (int_res);
}

char inputLetter()
{
    char char_res; // input letter
    // ask again if entered is not a letter
    while (!scanf("%c", &char_res) || !((char_res >= 65 && char_res <= 90) || (char_res >= 97 && char_res <= 122)))
    {
        // clear the buffer if entered is not an integer or float
        clearBuffer();
        printf("Input error : input is not a letter.\nPlease retry : ");
    }
    // clear the buffer to avoid not good next input
    clearBuffer();
    return (char_res);
}

char* inputString()
{
    char* pchar_res = NULL;
    size_t buffer;
    fflush(stdout);
    if (getline(&pchar_res, &buffer , stdin) == -1) {
        exit(ERROR_MESSAGE("Error, getline"));
    }

    if (strlen(pchar_res) < 2) {
        free(pchar_res);
        printf("Not valid, retry : ");
        return inputString();
    }
    pchar_res = realloc(pchar_res, sizeof(pchar_res) - sizeof(char));
    pchar_res[strlen(pchar_res) - 1] = '\0';
    return (pchar_res);
}

void invert1DIntArray(int* pint_array, int int_size)
{
    int int_tmp; // temprary var for exchange
    for (int i = 0; i < (int) int_size / 2; i++)
    {
        // exchange variables
        int_tmp = pint_array[i];
        pint_array[i] = pint_array[int_size - 1 - i];
        pint_array[int_size - 1 - i] = int_tmp;
    }
}

void insertionSortInt(int* pint_array, int int_size)
{
    int tmp; // temporary var for exchange
    int j; // loop iteration
    for (int i = 0; i < int_size; i++)
    {
        j = i;
        // where to insert
        while (pint_array[j] < pint_array[j - 1] && j > 0)
        {
            // exchange
            tmp = pint_array[j - 1];
            pint_array[j - 1] = pint_array[j];
            pint_array[j] = tmp;
            j--;
        }
    }
}

void minMaxArray(int* pint_array, int int_size, int* pint_min, int* pint_max)
{
    for (int i = 0; i < int_size; i++)
    {
        // select min
        if (pint_array[i] < *pint_min)
        {
            *pint_min = pint_array[i];
        }
        // select max
        if (pint_array[i] > *pint_max)
        {
            *pint_max = pint_array[i];
        }
    }
}

void histogram(int* pint_array, int int_size, int* pint_histo, int int_min)
{
    for (int i = 1; i < int_size; i++)
    {
        // counting
        pint_histo[pint_array[i] - int_min]++;
    }
}

void countingSortInt(int* pint_array, int int_size)
{
    int x = 0; // loop var
    int int_min = pint_array[0]; // min of array
    int int_max = pint_array[0]; // max of array
    int int_sizeHisto; // size of histogram
    int* pint_histo; // histogram

    // find min and max
    minMaxArray(pint_array, int_size, &int_min, &int_max);
    // size of histogram
    int_sizeHisto = int_max - int_min + 1;
    // histogram init to 0
    pint_histo = calloc1DIntArray(int_sizeHisto);
    // modify values on histogram
    histogram(pint_array, int_size, pint_histo, int_min);
    // reorganize array
    for (int i = 0; i < int_sizeHisto; i++)
    {
        while (pint_histo[i] >= 1)
        {
            pint_array[x] = i + int_min;
            pint_histo[i]--;
            x++;
        }
    }   
}

int partition(int* pint_array, int int_min, int int_max)
{
    int pivot = pint_array[int_max]; // pivot
    int tmp; // temporary var for exchange
    int i = int_min -1; // position of partition

    for (int j = int_min; j < int_max; j++)
    {
        if (pint_array[j] <= pivot)
        {
            i++;
            // exchange
            tmp = pint_array[i];
            pint_array[i] = pint_array[j];
            pint_array[j] = tmp;
        }
    }
    tmp = pint_array[i + 1];
    pint_array[i + 1] = pint_array[int_max];
    pint_array[int_max] = tmp;
    return (i+1);
}

void quickSortInt(int* pint_array, int int_min, int int_max) // 1er appel : quicksort(array, 0, size -1)
{
    int pivot;

    if (int_min < int_max)
    {
        pivot = partition(pint_array, int_min, int_max);
        quickSortInt(pint_array, int_min, pivot - 1);
        quickSortInt(pint_array, pivot + 1, int_max);
    }
}

void bubbleSortInt(int* pint_array, int int_size)
{
    int tmp;
    for (int i = 0; i < int_size; i++)
    {
        for (int j = 0; j < int_size; j++)
        {
            if (pint_array[j] > pint_array[j+1])
            {
                // exchange
                tmp = pint_array[j];
                pint_array[j+1] = pint_array[j];
                pint_array[j] = tmp;
            }
        }
    }
}

void selectionSortInt(int* pint_array, int int_size)
{
    int tmp; // temporary var for exchange
    int indiceMin; // indice of minimum value in array
    
    for (int i = 0; i < int_size; i++)
    {
        indiceMin = i; // new min
        for (int j = i+1; j < int_size; j++)
        {
            if (pint_array[j] < pint_array[indiceMin])
            {
                indiceMin = j; // new min
            }
            
        }
        if (pint_array[indiceMin] != pint_array[i])
        {
            // exchange
            tmp = pint_array[i];
            pint_array[i] = pint_array[indiceMin];
            pint_array[indiceMin] = tmp;
        }
    }
}

int* malloc1DIntArray(int int_size)
{
    int* pint_array = malloc(sizeof(int) * int_size);
    if (pint_array == NULL)
    {
        exit(ERROR_MESSAGE("Error allocation\n"));
    }
    return (pint_array);
}

char* malloc1DCharArray(int int_size)
{
    char* pint_array = malloc(sizeof(char) * int_size);
    if (pint_array == NULL)
    {
        exit(ERROR_MESSAGE("Error allocation\n"));
    }
    return (pint_array);
}

int* calloc1DIntArray(int int_size)
{
    int* pint_array = calloc(int_size, sizeof(int));
    if (pint_array == NULL)
    {
        exit(ERROR_MESSAGE("Error allocation\n"));
    }
    return (pint_array);
}

int** malloc2DIntArray(int int_size)
{
    int** tpint_array = malloc(sizeof(int*) * int_size);
    if (tpint_array == NULL)
    {
        exit(ERROR_MESSAGE("Error allocation\n"));
    }
    for (int i = 0; i < int_size; i++)
    {
        tpint_array[i] = malloc(sizeof(int) * int_size);
        if (tpint_array[i] == NULL)
        {
            exit(ERROR_MESSAGE("Error allocation\n"));
        }
    }
    return (tpint_array);
}

int** calloc2DIntArray(int int_size)
{
    int** tpint_array = malloc(sizeof(int*) * int_size);
    if (tpint_array == NULL)
    {
        exit(ERROR_MESSAGE("Error allocation\n"));
    }
    for (int i = 0; i < int_size; i++)
    {
        tpint_array[i] = calloc(int_size, sizeof(int));
        if (tpint_array[i] == NULL)
        {
            exit(ERROR_MESSAGE("Error allocation\n"));
        }
    }
    return (tpint_array);
}

char** calloc2DCharArray(int int_size)
{
    char** tpchar_array = malloc(sizeof(char*) * int_size);
    if (tpchar_array == NULL)
    {
        exit(ERROR_MESSAGE("Error allocation\n"));
    }
    for (int i = 0; i < int_size; i++)
    {
        tpchar_array[i] = calloc(int_size, sizeof(char));
        if (tpchar_array[i] == NULL)
        {
            exit(ERROR_MESSAGE("Error allocation\n"));
        }
    }
    return (tpchar_array);
}

void free2DIntArray(int** tp_array, int int_size)
{
    for (int i = 0; i < int_size; i++)
    {
        free(tp_array[i]);
    }
    free(tp_array);
}

void free2DCharArray(char** tp_array, int int_size)
{
    for (int i = 0; i < int_size; i++)
    {
        free(tp_array[i]);
    }
    free(tp_array);
}
void displayTab1DInt(int* pint_array, int int_size)
{
    for (int i = 0; i < int_size; i++)
    {
        printf(" %d ", pint_array[i]);
    }
    printf("\n");
}

void displayTab2DInt(int** pint_array, int int_size)
{
    for (int i = 0; i < int_size; i++)
    {
        for (int j = 0; j < int_size; j++)
        {
            printf(" %d ", pint_array[i][j]);
        }
        printf("\n");
    }
}

int randomInt(int int_min, int int_max) 
{
   return (int_min + rand() % (int_max - int_min));
}

void copy2DIntArray(int** tpint_toCopyArray, int** tpint_copyArray, int int_size)
{
    for (int i = 0; i < int_size; i++) // lines
    {
        for (int j = 0; j < int_size; j++) // columns
        {
            // copy case
            tpint_copyArray[i][j] = tpint_toCopyArray[i][j];
        }
    }
}

void copy2DCharArray(char** tpchar_toCopyArray, char** tpchar_copyArray, int int_size)
{
    for (int i = 0; i < int_size; i++) // lines
    {
        for (int j = 0; j < int_size; j++) // columns
        {
            // copy case
            tpchar_copyArray[i][j] = tpchar_toCopyArray[i][j];
        }
    }
}