#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int comparadorDeNumeros(void *a, void *b)
{
        if ((int) a < (int) b)
        return -1;
    else if ((int) a > (int) b)
        return 1;
    else
        return 0;
}

void merge(void *arreglo[], int min, int half, int max, int (*comp)(void *, void *))
{
    int i, j, k;
    int x = half - min + 1;
    int y = max - half;

    void *leftSubarray[x];
    void *rigthSubarray[y];

    for (i = 0; i < x; i++)
        leftSubarray[i] = arreglo[min + i];
    for (j = 0; j < y; j++)
        rigthSubarray[j] = arreglo[half + 1 + j];

    i = 0;
    j = 0;
    k = min;
    while (i < x && j < y)
    {
        if ((*comp)(leftSubarray[i], rigthSubarray[j]) < 0)
        {
            arreglo[k] = leftSubarray[i];
            i++;
        }
        else
        {
            arreglo[k] = rigthSubarray[j];
            j++;
        }
        k++;
    }

    while (i < x)
    {
        arreglo[k] = leftSubarray[i];
        i++;
        k++;
    }

    while (j < y)
    {
        arreglo[k] = rigthSubarray[j];
        j++;
        k++;
    }
}

void mergeSort(void *arreglo[], int min, int max, int (*comp)(void *, void *))
{
    if (min < max)
    {

        int half = min + (max - min) / 2;

        mergeSort(arreglo, min, half, comp);
        mergeSort(arreglo, half + 1, max, comp);

        merge(arreglo, min, half, max, comp);
    }
}

int main()
{

    //CON STRINGS
    void *arreglo[] = {"z", "x", "e", "d", "c", "a"};
    int n1 = sizeof(arreglo) / sizeof(arreglo[0]);
    mergeSort(arreglo, 0, n1 - 1, strcmp);

    int i = n1;
    for (i = 0; i < n1; i++)
        printf("%s", arreglo[i]);
    printf("\n");

    //CON ENTEROS

    void *arregloNum[] = {5, 4, 3, 2, 1};
    int n2 = sizeof(arregloNum) / sizeof(arregloNum[0]);
    mergeSort(arregloNum, 0, n2 - 1, comparadorDeNumeros);

    int j = n2;
    for (j = 0; j < n2; j++)
        printf("%d", arregloNum[j]);
    printf("\n");

    return 0;
}