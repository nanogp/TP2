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

void ePersona_initHardcode(ePersona lista[])
{
                            /*nombre               ,edad, dni*/
	lista[0] = (ePersona) {{"juan perez"}           ,21 ,10 ,OCUPADO};
	lista[1] = (ePersona) {{"perica sanchez"}       ,34 ,11 ,OCUPADO};
	lista[2] = (ePersona) {{"esteban quito"}        ,52 ,12 ,OCUPADO};
	lista[3] = (ePersona) {{"Rodrigo Serna"}        ,76 ,13 ,OCUPADO};
	lista[4] = (ePersona) {{"Lorena paola"}         ,18 ,14 ,OCUPADO};
	lista[5] = (ePersona) {{"Juan Alberto Mateico"} ,56 ,15 ,OCUPADO};
	lista[6] = (ePersona) {{"aquillego Bala"}       ,85 ,16 ,OCUPADO};
	lista[7] = (ePersona) {{"ascensooooor"}         ,34 ,17 ,OCUPADO};
	lista[8] = (ePersona) {{"enrico palazzo"}       ,27 ,18 ,OCUPADO};
	lista[9] = (ePersona) {{"mini me"}              ,57 ,19 ,OCUPADO};
	lista[10] = (ePersona) {{"Austin Powers"}       ,35 ,20 ,OCUPADO};
	lista[11] = (ePersona) {{"Austin sin power"}    ,75 ,21 ,OCUPADO};
	lista[12] = (ePersona) {{"Fulano"}              ,43 ,22 ,OCUPADO};
	lista[13] = (ePersona) {{"Mengano"}             ,56 ,23 ,OCUPADO};
	lista[14] = (ePersona) {{"Sultano"}             ,12 ,24 ,OCUPADO};
	lista[15] = (ePersona) {{"Butano"}              ,43 ,25 ,OCUPADO};
	lista[16] = (ePersona) {{"Un tano"}             ,2  ,26 ,OCUPADO};
	lista[17] = (ePersona) {{"No es sano"}          ,56 ,27 ,OCUPADO};
	lista[18] = (ePersona) {{"programar hasta"}     ,18 ,28 ,OCUPADO};
	lista[19] = (ePersona) {{"tan tarde"}           ,16 ,29 ,OCUPADO};
    //3 edad < 18
    //7 18 < edad < 35
    //10 edad > 35
}

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

int ePersona_buscarSiYaExiste(ePersona lista[], ePersona registro)
{
    int retorno;

    retorno = ePersona_buscarPorDni(lista, registro.dni);
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
    int existePreviamente;
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

        existePreviamente = ePersona_buscarSiYaExiste(lista, registroAlta);

        if(existePreviamente == -1)
        {
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

void ePersona_recuentoEdadesPorRango(const ePersona lista[], int contadores[])
{
    int i;

    for(i=0 ; i<CANT_MAX_PERSONAS ; i++)
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

void ePersona_procesarMostrarGrafico(const ePersona lista[])
{
    int contadoresEdades[] = {0,0,0};

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo("GRAFICO DE BARRAS POR EDAD");

    ePersona_recuentoEdadesPorRango(lista, contadoresEdades);
    printf("\ncontadoresEdades[0] = %d", contadoresEdades[0]);
    printf("\ncontadoresEdades[1] = %d", contadoresEdades[1]);
    printf("\ncontadoresEdades[2] = %d", contadoresEdades[2]);

    ejecutarEnConsola(HACER_PAUSA);
}
