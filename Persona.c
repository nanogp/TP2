#include <stdio.h>
#include <string.h>
#include "Persona.h"
#include "General.h"

void ePersona_init(ePersona lista[])
{
    int i;

    for(i=0 ; i<CANT_MAX_PERSONAS ; i++)
    {
        lista[i].dni = 0;
        lista[i].edad = 0;
        lista[i].estado = LIBRE;
        strcpy(lista[i].nombre,"");
    }
};

void ePersona_mostrarUno(const ePersona persona)
{
    printf("\n%-20s | edad: %d | dni: %d", persona.nombre, persona.edad, persona.dni);

}

void ePersona_mostrarLista(const ePersona lista[])
{
    int i;

    for(i=0 ; i< CANT_MAX_PERSONAS ; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            ePersona_mostrarUno(lista[i]);
        }
    }

    if(i == 0)
    {
        imprimirEnPantalla("\nNada para mostrar! \n\nLa lista esta vacia o todos los registros se dieron de baja.");
    }
}

void ePersona_ordenar(ePersona lista[], const char orden[])
{
	int i;
	int j;
	ePersona aux;

	if(strcmp(orden, "nombreAsc") == 0)
	{
		for(i=0 ; i<CANT_MAX_PERSONAS-1 ; i++)
		{
			for(j=i+1 ; j<CANT_MAX_PERSONAS ; j++)
			{
				if(strcmp(lista[i].nombre, lista[j].nombre) > 0)
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
		for(i=0 ; i<CANT_MAX_PERSONAS-1 ; i++)
		{
			for(j=i+1 ; j<CANT_MAX_PERSONAS ; j++)
			{
				if(strcmp(lista[i].nombre, lista[j].nombre) < 0)
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

int ePersona_buscarLugarLibre(ePersona lista[])
{
    int retorno = -1;
    int i;

    for(i=0 ; i<CANT_MAX_PERSONAS ; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

int ePersona_buscarPorDni(ePersona lista[], const int dni)
{
    int retorno = -1;
    int i;

    for(i=0 ; i<CANT_MAX_PERSONAS ; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].dni == dni)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

void ePersona_alta(ePersona lista[], ePersona registro, const int posicion)
{
    lista[posicion] = registro;
    ePersona_ordenar(lista, "nombreAsc");
}

void ePersona_baja(ePersona lista[], const int posicion)
{
    lista[posicion].estado = LIBRE;
}

void ePersona_procesarAlta(ePersona lista[])
{
    char confimacion;
    int posicion;
    ePersona registroAlta;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("DANDO DE ALTA UNA PERSONA");

    posicion = ePersona_buscarLugarLibre(lista);

    if(posicion == -1)
    {
        imprimirEnPantalla("\nNo queda mas espacio para altas");
    }
    else
    {
        registroAlta = ePersona_pedirPersona();
        ePersona_mostrarUno(registroAlta);
        confimacion = pedirConfirmacion("\nConfirma que desea dar de alta la persona?");

        if(confimacion == 'S')
        {
            ePersona_alta(lista, registroAlta, posicion);
            imprimirEnPantalla("\nSe dio de alta la persona ingresada");
        }
        else
        {
            imprimirEnPantalla("\nSe cancelo la operatoria. No se hicieron cambios");
        }
    }

    ejecutarEnConsola(HACER_PAUSA);
}

void ePersona_procesarBaja(ePersona lista[])
{
    char confimacion;
    int dni;
    int posicion;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("DANDO DE BAJA UNA PERSONA");

    ePersona_mostrarLista(lista);

    dni = ePersona_pedirDni();

    posicion = ePersona_buscarPorDni(lista, dni);

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
    ejecutarEnConsola(HACER_PAUSA);
}

void ePersona_procesarMostrarLista(const ePersona lista[])
{
    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("LISTADO DE PERSONAS ORDENADAS POR NOMBRE");

    ePersona_mostrarLista(lista);

    ejecutarEnConsola(HACER_PAUSA);
}


//void ePersona_procesarMostrarGrafico(const ePersona lista[])
