#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DIM 30
/*--------------------------------------------------------------------------------------------------*/
typedef struct {
    char nombreYapellido[DIM];
    int edad;
}stPersona;

typedef struct {
    stPersona informacionPersona;
    struct stNodo *ptrSiguiente;
    struct stNodo *ptrAnterior;
}stNodo;

typedef struct {
    int numero;
    struct stNodoInt *ptrSiguiente;
    struct stNodoInt *ptrAnterior;
}stNodoInt;

/*PROTOTIPADO---------------------------------------------------------------------------------------*/
stNodo *inicLista();
stNodo *crearNodo(stPersona unaPersona);
stNodo *buscarUltimoNodo(stNodo *ptrLista);
void mostrarListaRecursiva(stNodo *ptrLista);
void mostrarListaRecursivaInvertida(stNodo *ptrLista);

stNodo *agregarAlPrincipioDesdeArchivo(stNodo *ptrLista, char rutaArchivoPersonas[]);
stNodo *agregarNodoAlPrincipio(stNodo *ptrLista, stNodo *nuevoNodo);
stNodo *agregarAlFinalDesdeArchivo(stNodo *ptrLista, char rutaArchivoPersonas[]);
stNodo *agregarNodoAlFinal(stNodo *ptrLista, stNodo *nuevoNodo);
stNodo *agregarEnOrdenDesdeArchivo(stNodo *ptrLista, char rutaArchivoPersonas[]);
stNodo *agregarNodoEnOrden(stNodo *ptrLista, stNodo *nuevoNodo);

stNodo *eliminarNodoAlPrincipio(stNodo *ptrLista);
stNodo *eliminarNodoAlFinal(stNodo *ptrLista);
stNodo *eliminarNodoPorValor(stNodo *ptrLista, char nombre[]);
void borrarListaRecursiva(stNodo **ptrLista);

void mostrarArchivo(char nombreArchivo[]);
void mostrarPersona(stPersona unaPersona);

stNodoInt *cargarListaInt(stNodoInt *listaInt);
stNodoInt *crearNodoInt(int numero);
void mostrarListaIntRecursiva(stNodoInt *ptrLista);
stNodoInt *inicListaInt();
stNodoInt *agregarNodoIntAlFinal(stNodoInt *ptrLista, stNodoInt *nuevoNodo);
int calcularSiLaListaDobleEsCapicuaConRecursion(stNodoInt *listaInt, stNodoInt *ultimoNodo);
stNodoInt*buscarUltimoNodoInt(stNodoInt *ptrLista);

int contabilizarRegistrosLista(stNodo *ptrLista);
stNodo *eliminarNodoDelMedio(stNodo *ptrLista, int cantidadNodos);
/*--------------------------------------------------------------------------------------------------*/
int main() {
    srand(time(NULL));
    char nombreArchivoPersonas[] = {"archivoPersonas.bin"};
    stNodo *ptrLista = inicLista();
    stNodo *ptrLista2 = inicLista();

    ///DEBUG, MOSTRAR ARCHIVO
    printf("Mostrando Archivo de Personas \n\n");
    mostrarArchivo(nombreArchivoPersonas);

    ///FUNCIONES PARA AGREGAR NODOS DESDE ARCHIVO

//    ptrLista = agregarAlPrincipioDesdeArchivo(ptrLista, nombreArchivoPersonas);
//    printf("Mostrando Lista agregando al principio \n\n");
//    mostrarListaRecursiva(ptrLista);

//    ptrLista2 = agregarAlFinalDesdeArchivo(ptrLista2, nombreArchivoPersonas);
//    printf("Mostrando Lista2 agregando al final \n\n");
//    mostrarListaRecursiva(ptrLista2);

//    ptrLista = agregarEnOrdenDesdeArchivo(ptrLista, nombreArchivoPersonas);
//    printf("Mostrando Lista agregando en orden \n\n");
//    mostrarListaRecursiva(ptrLista);

    ///FUNCIONES DE ELIMINAR NODOS
//    ptrLista = eliminarNodoAlPrincipio(ptrLista);
//    printf("Mostrando Lista despues de haber eliminado el primer Nodo \n\n");
//    mostrarListaRecursiva(ptrLista);

//    ptrLista = eliminarNodoAlFinal(ptrLista);
//    printf("Mostrando Lista despues de haber eliminado el ultimo Nodo \n\n");
//    mostrarListaRecursiva(ptrLista);

//    char nombre[] = {"Paola Colino"};
//    ptrLista = eliminarNodoPorValor(ptrLista, nombre );
//    printf("Mostrando Lista despues de haber eliminado el ultimo Nodo \n\n");
//    mostrarListaRecursiva(ptrLista);

    ///EJERCICIO -> DETERMINAR SI UNA LISTA ES CAPICUA CON RECURSIÓN

    stNodoInt *listaInt = inicListaInt();

    listaInt = cargarListaInt(listaInt);
    mostrarListaIntRecursiva(listaInt);
//
//    stNodoInt *ultimoNodo = buscarUltimoNodoInt(listaInt);
//
//    int resultado = calcularSiLaListaDobleEsCapicuaConRecursion(listaInt, ultimoNodo);

//    if(resultado == 1) printf("La lista doblemente enlazada es capicua \n\n");
//    else printf("La lista doblemente enlazada No capicua \n\n");

    ///EJERCICIO -> ELIMINAR EL NODO QUE SE ENCUENTRA EN EL MEDIO

//    ptrLista = eliminarNodoAlFinal(ptrLista);
//
//    int cantidadNodos = contabilizarRegistrosLista(ptrLista);
//    printf("La cantidad de Nodos que tiene la Lista son %i \n\n", cantidadNodos);
//
//    ptrLista = eliminarNodoDelMedio(ptrLista, cantidadNodos);
//    mostrarListaRecursiva(ptrLista);

}
/*FUNCIONES-----------------------------------------------------------------------------------------*/
stNodo *inicLista() {
    return NULL;
}

stNodoInt *inicListaInt() {
    return NULL;
}

stNodo *crearNodo(stPersona unaPersona) {

    stNodo *nuevoNodo = (stNodo*) malloc(sizeof(stNodo));

    nuevoNodo->informacionPersona = unaPersona;
    nuevoNodo->ptrAnterior = NULL;
    nuevoNodo->ptrSiguiente = NULL;

    return nuevoNodo;
}

stNodoInt *crearNodoInt(int numero) {

    stNodoInt *nuevoNodo = (stNodoInt*) malloc(sizeof(stNodoInt));

    nuevoNodo->numero = numero;
    nuevoNodo->ptrAnterior = NULL;
    nuevoNodo->ptrSiguiente = NULL;

    return nuevoNodo;
}

stNodoInt *cargarListaInt(stNodoInt *listaInt) {

    for(int i = 0; i < 5; i++) listaInt = agregarNodoIntAlFinal(listaInt, crearNodoInt(rand()% 5 + 1));

    return listaInt;
}

stNodo *agregarAlPrincipioDesdeArchivo(stNodo *ptrLista, char rutaArchivoPersonas[]) {

    stPersona unaPersona;
    FILE *ptrArchivoPersonas = fopen(rutaArchivoPersonas, "rb");

    if(ptrArchivoPersonas == NULL) {
        printf("Error al abrir el archivo \n");
        return ptrLista;

    }else{
            while(!feof(ptrArchivoPersonas)) {
                fread(&unaPersona, sizeof(stPersona), 1, ptrArchivoPersonas);

                if(!feof(ptrArchivoPersonas)) ptrLista = agregarNodoAlPrincipio(ptrLista, crearNodo(unaPersona));
            }
    fclose(ptrArchivoPersonas);
    }
    return ptrLista;
}

stNodo *agregarNodoAlPrincipio(stNodo *ptrLista, stNodo *nuevoNodo) {

    if(ptrLista == NULL) ptrLista = nuevoNodo;

    else {
        nuevoNodo->ptrSiguiente = ptrLista;
        ptrLista->ptrAnterior = nuevoNodo;
        ptrLista = nuevoNodo;
    }
    return ptrLista;
}

stNodo *agregarAlFinalDesdeArchivo(stNodo *ptrLista, char rutaArchivoPersonas[]) {

    stPersona unaPersona;
    FILE *ptrArchivoPersonas = fopen(rutaArchivoPersonas, "rb");

    if(ptrArchivoPersonas == NULL) {
        printf("Error al abrir el archivo \n");
        return ptrLista;

    }else{
            while(!feof(ptrArchivoPersonas)) {
                fread(&unaPersona, sizeof(stPersona), 1, ptrArchivoPersonas);

                if(!feof(ptrArchivoPersonas)) ptrLista = agregarNodoAlFinal(ptrLista, crearNodo(unaPersona));
            }
    fclose(ptrArchivoPersonas);
    }
    return ptrLista;
}

stNodo *agregarNodoAlFinal(stNodo *ptrLista, stNodo *nuevoNodo) {

    if(ptrLista == NULL) ptrLista = nuevoNodo;

    else {
        stNodo *auxLista = ptrLista;

        while(auxLista->ptrSiguiente != NULL) auxLista = auxLista->ptrSiguiente;

        auxLista->ptrSiguiente = nuevoNodo;
        nuevoNodo->ptrAnterior = auxLista;
    }
    return ptrLista;
}

stNodoInt *agregarNodoIntAlFinal(stNodoInt *ptrLista, stNodoInt *nuevoNodo) {

    if(ptrLista == NULL) ptrLista = nuevoNodo;

    else {
        stNodoInt *auxLista = ptrLista;

        while(auxLista->ptrSiguiente != NULL) auxLista = auxLista->ptrSiguiente;

        auxLista->ptrSiguiente = nuevoNodo;
        nuevoNodo->ptrAnterior = auxLista;
    }
    return ptrLista;
}

stNodo *agregarEnOrdenDesdeArchivo(stNodo *ptrLista, char rutaArchivoPersonas[]) {

    stPersona unaPersona;
    FILE *ptrArchivoPersonas = fopen(rutaArchivoPersonas, "rb");

    if(ptrArchivoPersonas == NULL) {
        printf("Error al abrir el archivo \n");
        return ptrLista;

    }else{
            while(!feof(ptrArchivoPersonas)) {
                fread(&unaPersona, sizeof(stPersona), 1, ptrArchivoPersonas);

                if(!feof(ptrArchivoPersonas)) ptrLista = agregarNodoEnOrden(ptrLista, crearNodo(unaPersona));
            }
    fclose(ptrArchivoPersonas);
    }
    return ptrLista;
}

stNodo *agregarNodoEnOrden(stNodo *ptrLista, stNodo *nuevoNodo) {

    if(ptrLista == NULL) ptrLista = nuevoNodo;

    else {
        if(nuevoNodo->informacionPersona.edad < ptrLista->informacionPersona.edad) {

            ptrLista = agregarNodoAlPrincipio(ptrLista, nuevoNodo);
            return ptrLista;
        }else {

            stNodo *auxAnterior = ptrLista;
            stNodo *auxSeguidor = ptrLista->ptrSiguiente;

            while((auxSeguidor != NULL) && (nuevoNodo->informacionPersona.edad > auxSeguidor->informacionPersona.edad)) {
                auxAnterior = auxSeguidor;
                auxSeguidor = auxSeguidor->ptrSiguiente;
            }
            auxAnterior->ptrSiguiente = nuevoNodo;
            nuevoNodo->ptrAnterior = auxAnterior;
            nuevoNodo->ptrSiguiente = auxSeguidor;

            if(auxSeguidor != NULL)auxSeguidor->ptrAnterior = nuevoNodo;
        }
    }
    return ptrLista;
}

stNodo *eliminarNodoAlPrincipio(stNodo *ptrLista) {

    if(ptrLista != NULL) {
        stNodo *auxLista = ptrLista;
        ptrLista = ptrLista->ptrSiguiente;
        ptrLista->ptrAnterior = NULL;
        free(auxLista);
        auxLista = NULL;
    }
    return ptrLista;
}

stNodo *eliminarNodoAlFinal(stNodo *ptrLista) {

    if(ptrLista->ptrSiguiente == NULL) ptrLista = NULL;

    else {
        stNodo *ptrAnterior = ptrLista;
        stNodo *ptrSeguidor = ptrLista->ptrSiguiente;

        while(ptrSeguidor->ptrSiguiente != NULL) {
            ptrAnterior = ptrSeguidor;
            ptrSeguidor = ptrSeguidor->ptrSiguiente;
        }
        ptrAnterior->ptrSiguiente = NULL;
        ptrSeguidor->ptrAnterior = NULL;

        free(ptrSeguidor);
        ptrSeguidor = NULL;
    }
    return ptrLista;
}

stNodo *eliminarNodoPorValor(stNodo *ptrLista, char nombre[]) {

    if(ptrLista != NULL) {

        if(strcmp(ptrLista->informacionPersona.nombreYapellido, nombre) == 0) ptrLista = eliminarNodoAlPrincipio(ptrLista);

        else {
            stNodo *ptrAnterior = ptrLista;
            stNodo *ptrSeguidor = ptrLista->ptrSiguiente;

            while((ptrSeguidor != NULL) && (strcmp(ptrSeguidor->informacionPersona.nombreYapellido, nombre) != 0)) {

                ptrAnterior = ptrSeguidor;
                ptrSeguidor = ptrSeguidor->ptrSiguiente;
            }

            if(ptrSeguidor != NULL && (strcmp(ptrSeguidor->informacionPersona.nombreYapellido, nombre) == 0) ) {

                ptrAnterior->ptrSiguiente = ptrSeguidor->ptrSiguiente;
                ptrSeguidor->ptrAnterior = ptrAnterior;
                free(ptrSeguidor);
                ptrSeguidor = NULL;
            }else {
                printf("\nNo se encontraron coincidencias para eliminar ese dato \n\n");
            }
        }
    }
    return ptrLista;
}

stNodo *buscarUltimoNodo(stNodo *ptrLista) { //No me interesa si la lista es NULL. Solo verifico si es distinta de NULL

    stNodo *auxLista = ptrLista;

    if(ptrLista == NULL) return ptrLista;

    else while(auxLista->ptrSiguiente != NULL) auxLista = auxLista->ptrSiguiente;

    return auxLista;
}

void mostrarListaRecursiva(stNodo *ptrLista) {

    if(ptrLista != NULL) {

        printf("Nombre y Apellido --> %s \n", ptrLista->informacionPersona.nombreYapellido);
        printf("Edad --> %i \n\n", ptrLista->informacionPersona.edad);

        mostrarListaRecursiva(ptrLista->ptrSiguiente);
    }
}

void mostrarListaRecursivaInvertida(stNodo *ptrLista) {

    if(ptrLista != NULL) {

        mostrarListaRecursiva(ptrLista->ptrSiguiente);

        printf("Nombre y Apellido --> %s \n", ptrLista->informacionPersona.nombreYapellido);
        printf("Edad --> %i \n\n", ptrLista->informacionPersona.edad);
    }
}

void mostrarListaIntRecursiva(stNodoInt *ptrLista) {

    if(ptrLista != NULL) {

        printf("Numero --> %i \n\n", ptrLista->numero);
        printf("Anterior --> %p \n\n", ptrLista->ptrAnterior);
        printf("Siguiente --> %p \n\n", ptrLista->ptrSiguiente);

        mostrarListaIntRecursiva(ptrLista->ptrSiguiente);
    }
}

void borrarListaRecursiva(stNodo **ptrLista) {

    if(*ptrLista == NULL) printf("Mostrando Lista en Null -> %p", *ptrLista);

    else borrarListaRecursiva(&(*ptrLista)->ptrSiguiente);

    free(*ptrLista);
    *ptrLista = NULL;
}

void mostrarPersona(stPersona unaPersona) {

    printf("Nombre y Apellido --> |%s| \n", unaPersona.nombreYapellido);
    printf("Edad --> |%i| \n\n", unaPersona.edad);
}

void mostrarArchivo(char nombreArchivo[]) {

    FILE *ptrArchivoPersonas = fopen(nombreArchivo, "rb");
    stPersona unaPersona;

    if(ptrArchivoPersonas == NULL) printf("Error al abrir el archivo \n");

    else{
        while(!feof(ptrArchivoPersonas)) {
            fread(&unaPersona, sizeof(stPersona), 1, ptrArchivoPersonas);

            if(!feof(ptrArchivoPersonas)) mostrarPersona(unaPersona);
            }
        fclose(ptrArchivoPersonas);
        }
}

stNodoInt*buscarUltimoNodoInt(stNodoInt *ptrLista) { //No me interesa si la lista es NULL. Solo verifico si es distinta de NULL

    stNodo *auxLista = ptrLista;

    if(ptrLista == NULL) return ptrLista;

    else while(auxLista->ptrSiguiente != NULL) auxLista = auxLista->ptrSiguiente;

    return auxLista;
}

int calcularSiLaListaDobleEsCapicuaConRecursion(stNodoInt *listaInt, stNodoInt *ultimoNodo) {


    if(listaInt == NULL || ultimoNodo == NULL) return 1;

    if(listaInt->numero != ultimoNodo->numero)  return 0;

    calcularSiLaListaDobleEsCapicuaConRecursion(listaInt->ptrSiguiente, ultimoNodo->ptrAnterior);
}

int contabilizarRegistrosLista(stNodo *ptrLista) {

    int contadorRegistros = 0;

    if(ptrLista != NULL) {

        stNodo *auxLista = ptrLista;

        while(auxLista != NULL) {
            contadorRegistros++;
            auxLista = auxLista->ptrSiguiente;
        }
    }
    return contadorRegistros;
}

stNodo *eliminarNodoDelMedio(stNodo *ptrLista, int cantidadNodos) {

    if(cantidadNodos % 2 == 0 || cantidadNodos % 2 == 1 ) {

        stNodo *auxListaA;
        stNodo *auxListaS = ptrLista;
        int lugarDePosicion = ((cantidadNodos / 2) + 1);

        for(int i = 1; i < lugarDePosicion; i++) {
            auxListaA = auxListaS;
            auxListaS= auxListaS->ptrSiguiente;
        }
        auxListaA->ptrSiguiente = auxListaS->ptrSiguiente;
        auxListaS->ptrAnterior = auxListaA;
        free(auxListaS);
        auxListaS = NULL;
    }
    return ptrLista;
}






