#include <stdio.h>
#include <string.h>
#include "Persona.h"
#include "General.h"

void ePersona_init(ePersona lista[], const int limite)
{
    int i;

    for(i=0 ; i<limite ; i++)
    {
        lista[i].dni = 0;
        lista[i].edad = 0;
        lista[i].estado = LIBRE;
        strcpy(lista[i].nombre,"");
    }
};

void ePersona_initHardcode(ePersona lista[])
{
                            /*nombre               ,edad, dni*/
	lista[0] = (ePersona) {{"juan perez"}           ,21 ,10 ,OCUPADO};
	lista[1] = (ePersona) {{"perica sanchez"}       ,34 ,11 ,OCUPADO};
	lista[2] = (ePersona) {{"esteban quito"}        ,52 ,12 ,OCUPADO};
	lista[3] = (ePersona) {{"Rodrigo Serna"}        ,76 ,13 ,OCUPADO};
	lista[4] = (ePersona) {{"Lorena paola"}         ,18 ,14 ,OCUPADO};
	lista[5] = (ePersona) {{"Juan Alberto Mateico"} ,56 ,15 ,OCUPADO};
	lista[6] = (ePersona) {{"aquillego Bala"}       ,15 ,16 ,OCUPADO};
	lista[7] = (ePersona) {{"ascensooooor"}         ,14 ,17 ,OCUPADO};
	lista[8] = (ePersona) {{"enrico palazzo"}       ,27 ,18 ,OCUPADO};
	lista[9] = (ePersona) {{"mini me"}              ,57 ,19 ,OCUPADO};
	lista[10] = (ePersona) {{"Austin Powers"}       ,15 ,20 ,OCUPADO};
	lista[11] = (ePersona) {{"Austin sin power"}    ,75 ,21 ,OCUPADO};
	lista[12] = (ePersona) {{"Fulano"}              ,43 ,22 ,OCUPADO};
	lista[13] = (ePersona) {{"Mengano"}             ,56 ,23 ,OCUPADO};
	lista[14] = (ePersona) {{"Sultano"}             ,12 ,24 ,OCUPADO};
	lista[15] = (ePersona) {{"Butano"}              ,43 ,25 ,OCUPADO};
	lista[16] = (ePersona) {{"Un tano"}             ,2  ,26 ,OCUPADO};
	lista[17] = (ePersona) {{"No es sano"}          ,56 ,27 ,OCUPADO};
	lista[18] = (ePersona) {{"programar hasta"}     ,18 ,28 ,OCUPADO};
	lista[19] = (ePersona) {{"tan tarde"}           ,16 ,29 ,OCUPADO};
    //6 edad < 18
    //5 18 < edad < 35
    //9 edad > 35
    ePersona_ordenar(lista, CANT_MAX_PERSONAS, "nombreAsc");
}

void ePersona_mostrarUno(const ePersona persona)
{
    printf("\n%-20s | edad: %-2d | dni: %d", persona.nombre, persona.edad, persona.dni);

}

void ePersona_mostrarLista(const ePersona lista[], const int limite)
{
    int i;

    if(ePersona_estaVacia(lista, limite) == 0)
    {
        for(i=0 ; i< limite ; i++)
        {
            if(lista[i].estado == OCUPADO)
            {
                ePersona_mostrarUno(lista[i]);
            }
        }
    }
    else
    {
        imprimirEnPantalla("\nNada para mostrar! \n\nLa lista esta vacia o todos los registros se dieron de baja.");
    }
}

void ePersona_ordenar(ePersona lista[], const int limite, const char orden[])
{
	int i;
	int j;
	ePersona aux;

	if(strcmp(orden, "nombreAsc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(strcmpi(lista[i].nombre, lista[j].nombre) > 0)
				{
					aux = lista[i];
					lista[i] = lista[j];
					lista[j] = aux;
				}
			}
		}
	}
	else if(strcmp(orden, "nombreDesc") == 0)
	{
		for(i=0 ; i<limite-1 ; i++)
		{
			for(j=i+1 ; j<limite ; j++)
			{
				if(strcmpi(lista[i].nombre, lista[j].nombre) < 0)
				{
					aux = lista[i];
					lista[i] = lista[j];
					lista[j] = aux;
				}
			}
		}
	}
}

int ePersona_pedirDni()
{
    int retorno;

    retorno = pedirIntValido("\nIngrese el DNI de la persona: "
                            ,"\nEl DNI ingresado no es valido. Reingrese dicho numero: "
                            ,DNI_MIN
                            ,DNI_MAX);
    return retorno;
}

int ePersona_pedirEdad()
{
    int retorno;

    retorno = pedirIntValido("\nIngrese edad: "
                            ,"\nLa edad ingresada no es valida. Reingrese dicho numero: "
                            ,EDAD_MIN
                            ,EDAD_MAX);
    return retorno;
}

void ePersona_pedirNombre(char retorno[])
{
    pedirStringValido(retorno
                     ,"\nIngrese nombre: "
                     ,"\nEl nombre ingresado supera el tamaño maximo posible. Reingrese el nombre: "
                     ,LARGO_NOMBRE_PERSONA);
}

ePersona ePersona_pedirPersona()
{
    ePersona retorno;

    retorno.dni = ePersona_pedirDni();
    retorno.edad = ePersona_pedirEdad();
    ePersona_pedirNombre(retorno.nombre);
    retorno.estado = OCUPADO;

    return retorno;
}

int ePersona_buscarLugarLibre(ePersona lista[], const int limite)
{
    int retorno = -1;
    int i;

    if(ePersona_estaVacia(lista, limite) == 1)
    {
        retorno = 0; //devuelvo la primera posicion
    }
    else
    {
        for(i=0 ; i<limite ; i++)
        {
            if(lista[i].estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int ePersona_estaVacia(const ePersona lista[], const int limite)
{
    int retorno = 1;
    int i;

    for(i=0 ; i<limite ; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            retorno = 0;
            break;//con el primer ocupado ya se que no esta vacio
        }
    }

    return retorno;
}

int ePersona_buscarPorDni(ePersona lista[], const int limite, const int dni)
{
    int retorno = -1;
    int i;

    for(i=0 ; i<limite ; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].dni == dni)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int ePersona_buscarSiYaExiste(ePersona lista[], ePersona registro, const int limite)
{
    int retorno;

    retorno = ePersona_buscarPorDni(lista, limite, registro.dni);
    if(retorno != -1)
    {
        imprimirEnPantalla("El registro con ese DNI ya existe en la lista como:");
        ePersona_mostrarUno(lista[retorno]);
    }

    return retorno;
}

void ePersona_alta(ePersona lista[], ePersona registro, const int posicion)
{
    lista[posicion] = registro;
}

void ePersona_baja(ePersona lista[], const int posicion)
{
    lista[posicion].estado = LIBRE;
}

void ePersona_procesarAlta(ePersona lista[], const int limite)
{
    char confimacion;
    int posicion;
    int existePreviamente;
    ePersona registroAlta;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("DANDO DE ALTA UNA PERSONA");

    posicion = ePersona_buscarLugarLibre(lista, limite);

    if(posicion == -1)
    {
        imprimirEnPantalla("\nNo queda mas espacio para altas");
    }
    else
    {
        registroAlta = ePersona_pedirPersona();

        existePreviamente = ePersona_buscarSiYaExiste(lista, registroAlta, limite);

        if(existePreviamente == -1)
        {
            ePersona_mostrarUno(registroAlta);
            confimacion = pedirConfirmacion("\nConfirma que desea dar de alta la persona?");

            if(confimacion == 'S')
            {
                ePersona_alta(lista, registroAlta, posicion);
                ePersona_ordenar(lista, limite, "nombreAsc");
                imprimirEnPantalla("\nSe dio de alta la persona ingresada");
            }
            else
            {
                imprimirEnPantalla("\nSe cancelo la operatoria. No se hicieron cambios");
            }
        }
    }

    ejecutarEnConsola(HACER_PAUSA);
}

void ePersona_procesarBaja(ePersona lista[], const int limite)
{
    char confimacion;
    int dni;
    int posicion;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("DANDO DE BAJA UNA PERSONA");

    if(ePersona_estaVacia(lista, limite) == 1)
    {
        imprimirEnPantalla("\n\nLa lista esta vacia o todos los registros se dieron de baja.");
    }
    else
    {
        ePersona_mostrarLista(lista, limite);

        dni = ePersona_pedirDni();

        posicion = ePersona_buscarPorDni(lista, limite, dni);

        if(posicion == -1)
        {
            imprimirEnPantalla("\nEl dni ingresado no existe en la lista de personas");
        }
        else
        {
            ePersona_mostrarUno(lista[posicion]);

            confimacion = pedirConfirmacion("Esta seguro que desea dar de baja a la persona?");
            if(confimacion == 'S')
            {
                ePersona_baja(lista, posicion);
                imprimirEnPantalla("\nSe dio de baja la persona seleccionada");
            }
            else
            {
                imprimirEnPantalla("\nSe cancelo la gestion\n");
            }
        }
    }
    ejecutarEnConsola(HACER_PAUSA);
}

void ePersona_procesarMostrarLista(const ePersona lista[], const int limite)
{
    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("LISTADO DE PERSONAS ORDENADAS POR NOMBRE");

    ePersona_mostrarLista(lista, limite);

    ejecutarEnConsola(HACER_PAUSA);
}

void ePersona_recuentoEdadesPorRango(const ePersona lista[], const int limite, int contadores[])
{
    int i;

    for(i=0 ; i<limite ; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            if(lista[i].edad < 18)
            {
                contadores[0]++;
            }
            else
            {
                if(lista[i].edad > 35)
                {
                    contadores[2]++;
                }
                else
                {
                    //edad entre 18 y 35 años
                    contadores[1]++;
                }
            }
        }
    }
}

int ePersona_getMayorContador(const int contadores[])
{
    int retorno;
    int i;

    //busco valor mas grande de contador para dibujar luego
    for(i=0 ; i<CANT_GRUPOS_GRAFICO ; i++)
    {
        if(contadores[i] > retorno || i == 0)
        {
            retorno = contadores[i];
        }
    }

    return retorno;
}

void ePersona_dibujarGrafico(const int contadores[], const int limite)
{
    int i;

    //procedo a dibujar
    for(i=limite ; i>0 ; i--)
    {
        if(contadores[0] >= i)
        {
            if(contadores[1] >= i)
            {
                if(contadores[2] >= i)
                {
                    //dibuja los 3
                    printf("\n *    *    *");
                }
                else
                {
                    //dibuja los 2 primeros
                    printf("\n *    *");
                }
            }
            else
            {
                if(contadores[2] >= i)
                {
                    //dibuja el 1ero y el 3ro
                    printf("\n *         *");
                }
                else
                {
                    //dibuja solo el primero
                    printf("\n *");
                }
            }
        }
        else
        {
            if(contadores[1] >= i)
            {
                if(contadores[2] >= i)
                {
                    //dibuja los 2 ultimos
                    printf("\n      *    *");
                }
                else
                {
                    //dibuja solo el del medio
                    printf("\n      *");
                }
            }
            else
            {
                //dibuja solo el ultimo
                printf("\n           *");
            }
        }
    }

    //muestro el pie de grafico
    printf("\n<18 18-35 >35");
    printf("\nGrafico para una estad¡stica de %d personas con edad menor a 18,\n%d personas con edades entre 18 y 35, y %d personas con edades mayores a 35"
           ,contadores[0]
           ,contadores[1]
           ,contadores[2]);
}

void ePersona_procesarMostrarGrafico(const ePersona lista[], const int limite)
{
    int contadoresEdades[CANT_GRUPOS_GRAFICO] = {0,0,0};
    int mayorContador;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("GRAFICO DE BARRAS POR EDAD");

    if(ePersona_estaVacia(lista, limite))
    {
        imprimirEnPantalla("\nNada para mostrar! \n\nLa lista esta vacia o todos los registros se dieron de baja.");
    }
    else
    {

        ePersona_recuentoEdadesPorRango(lista, limite, contadoresEdades);

        mayorContador = ePersona_getMayorContador(contadoresEdades);

        ePersona_dibujarGrafico(contadoresEdades, mayorContador);

    }


    ejecutarEnConsola(HACER_PAUSA);
}
