#ifndef PERSONA_H_INCLUDE
#   define PERSONA_H_INCLUDE
#define OCUPADO 1
#define LIBRE 0
#define LARGO_NOMBRE_PERSONA 100
#define CANT_MAX_PERSONAS 20
#define DNI_MAX 99999999
#define DNI_MIN 0
#define EDAD_MAX 200
#define EDAD_MIN 0

typedef struct
{
    char nombre[LARGO_NOMBRE_PERSONA];
    int edad;
    int dni;
    int estado;
} ePersona;


void ePersona_init(ePersona[]);


void ePersona_initHardcode(ePersona[]);


void ePersona_mostrarUno(const ePersona);


void ePersona_mostrarLista(const ePersona lista[]);


void ePersona_ordenar(ePersona lista[], const char orden[]);


int ePersona_pedirDni();


int ePersona_pedirEdad();


void ePersona_pedirNombre(char[]);


ePersona ePersona_pedirPersona();


int ePersona_buscarLugarLibre(ePersona lista[]);


int ePersona_buscarPorDni(ePersona lista[], const int dni);


void ePersona_alta(ePersona lista[], ePersona registro, const int posicion);


void ePersona_baja(ePersona lista[], const int posicion);


void ePersona_procesarAlta(ePersona lista[]);


void ePersona_procesarBaja(ePersona lista[]);


void ePersona_procesarMostrarLista(const ePersona lista[]);


void ePersona_procesarMostrarGrafico(const ePersona lista[]);


#endif // PERSONA_H_INCLUDE
