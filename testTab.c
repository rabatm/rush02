#include <stdio.h>
#include <stdlib.h>
 
int         main(void)
{
    int     **tab;
    int     i;
    int     k;
    int     ligne = 4;
    int     colonne = 2;
 
    tab = (int**)malloc(4 * sizeof(int*)); ///allocation des lignes
    for (i = 0; i < 4; i++)
    {
        tab[i] = (int*)malloc(2 * sizeof(int)); ///allocation des colonnes
    }
    return (0);
}
