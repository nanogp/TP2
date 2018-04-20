#include "estructuras.h"

int buscarEnArrayInt(const int *buscar, const int *array, const int *cantElementos)
{
    int retorno = -1;
    int i;

    for(i=0 ; i< *cantElementos ; i++)
    {
        if(array[i] == *buscar)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int buscarEnPersonasDni(const int *buscar, const ePersona *array)
{
    int retorno = -1;
    int i;

    for(i=0 ; i< CANT_MAX_PERSONAS ; i++)
    {
        if((array+i)->dni == *buscar)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}
