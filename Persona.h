#ifndef PERSONA_H_INCLUDE
#define PERSONA_H_INCLUDE
#define OCUPADO 1
#define LIBRE 0
#define LARGO_NOMBRE_PERSONA 100
#define CANT_MAX_PERSONAS 20
#define DNI_MAX 99999999
#define DNI_MIN 0
#define EDAD_MAX 200
#define EDAD_MIN 0
#define NUM_GRUPOS_ETARIOS 3
#define CONTADOR_MENORES_18 0
#define CONTADOR_18_A_35 1
#define CONTADOR_MAYORES_35 2

typedef struct
{
    char nombre[LARGO_NOMBRE_PERSONA];
    int edad;
    int dni;
    int estado;
} ePersona;


/** \brief inicializa la estructura persona
 *
 * \param ePersona[]: recibe lista de personas
 * \param limite const int: cantidad de elementos del array
 * \return void
 *
 */
void ePersona_init(ePersona[], const int limite);


/** \brief inicializa todos los elementos del array de personas con datos de prueba
 *
 * \param ePersona[]> la lista de personas
 * \return void
 *
 */
void ePersona_initHardcode(ePersona[]);


/** \brief muestra en pantalla un registro tipo persona
 *
 * \param ePersona const: registro de persona
 * \return void
 *
 */
void ePersona_mostrarUno(const ePersona);


/** \brief muestra en pantalla una lista de personas
 *
 * \param lista[] const ePersona: lista de personas
 * \param limite const int: cantidad de elementos del array
 * \return void
 *
 */
void ePersona_mostrarLista(const ePersona lista[], const int limite);


/** \brief ordena lista de personas segun criterio pasado por parametro
 *
 * \param lista[] ePersona: lista a ordenar
 * \param limite const int: cantidad de elementos del array
 * \param orden[] const char: nombreAsc o nombreDesc para ordenar por nombre en forma ascendente o descendente
 * \return void
 *
 */
void ePersona_ordenar(ePersona lista[], const int limite, const char orden[]);


/** \brief pide al usuario que ingrese un numero de dni valido y lo retorna
 *
 * \return int: dni valido
 *
 */
int ePersona_pedirDni();


/** \brief pide al usuario que ingrese una edad valida y la retorna
 *
 * \return int: edad valida
 *
 */
int ePersona_pedirEdad();


/** \brief pide al usuario que ingrese un nombre valido y lo retorna por parametro
 *
 * \param char[]: nombre valido
 * \return void
 *
 */
void ePersona_pedirNombre(char[]);


/** \brief pide al usuario que ingrese los datos de una persona, los valida y retorna un registro tipo persona
 *
 * \return ePersona: persona valida
 *
 */
ePersona ePersona_pedirPersona();


/** \brief busca en la lista de personas algun lugar libre y devuelve la posicion
 *
 * \param lista[] ePersona: lista de personas
 * \param limite const int: cantidad de elementos del array
 * \return int: la posicion libre en el array, -1 si no hay lugar
 *
 */
int ePersona_buscarLugarLibre(ePersona lista[], const int limite);


/** \brief busca si la esta vacia
 *
 * \param lista[] const ePersona: lista de personas
 * \param limite const int: cantidad de elementos del array
 * \return int: 1 si el array esta vacio, 0 si hay ocupados
 *
 */
int ePersona_estaVacia(const ePersona lista[], const int limite);


/** \brief busca en lista de personas el dni ingresado y devuelve la posicion
 *
 * \param lista[] ePersona: lista de personas
 * \param limite const int: cantidad de elementos del array
 * \param dni const int: numero de dni a buscar
 * \return int: la posicion del dni buscado, -1 si no se encuentra
 *
 */
int ePersona_buscarPorDni(ePersona lista[], const int limite, const int dni);


/** \brief agrega a la lista de personas el registro ingresado en la posicion indicada
 *
 * \param lista[] ePersona: lista de personas
 * \param registro ePersona: persona a dar de alta
 * \param posicion const int: posicion del array donde colocar el registro
 * \return void
 *
 */
void ePersona_alta(ePersona lista[], ePersona registro, const int posicion);


/** \brief marca como libre la posicion del array de personas recibida por parametro
 *
 * \param lista[] ePersona: lista de personas
 * \param posicion const int: posicion a dar de baja
 * \return void
 *
 */
void ePersona_baja(ePersona lista[], const int posicion);


/** \brief maneja todo el proceso de alta, incluido
 *
 * \param lista[] ePersona: lista de personas
 * \param limite const int: cantidad de elementos del array
 * \return void
 *
 */
void ePersona_procesarAlta(ePersona lista[], const int limite);


/** \brief
 *
 * \param lista[] ePersona: lista de personas
 * \param limite const int: cantidad de elementos del array
 * \return void
 *
 */
void ePersona_procesarBaja(ePersona lista[], const int limite);


/** \brief
 *
 * \param lista[] const ePersona: lista de personas
 * \param limite const int: cantidad de elementos del array
 * \return void
 *
 */
void ePersona_procesarMostrarLista(const ePersona lista[], const int limite);


/** \brief
 *
 * \param lista[] const ePersona: lista de personas
 * \param limite const int: cantidad de elementos del array
 * \return void
 *
 */
void ePersona_procesarMostrarGrafico(const ePersona lista[], const int limite);


#endif // PERSONA_H_INCLUDE
