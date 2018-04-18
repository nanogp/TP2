int buscarEnArrayInt(int *buscar, int *array, int *cantElementos)
{
    int retorno = -1;
    int i;

    for(i=0 ; i<cantElementos ; i++)
    {
        if(array[i] == buscar)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}
