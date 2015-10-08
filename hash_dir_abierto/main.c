# ifndef stdio_h
# include <stdio.h>
# define stdio_h
# endif

# ifndef stdlib_h
# include <stdlib.h>
# define stdlib_h
# endif

# ifndef hash_h
# include "hash.h"
# define hash_h
# endif

# ifndef nodo_h
# include "nodo.h"
# define nodo_h
# endif

# define tam 5

typedef struct _cabecera{
	Hash tablaHash[tam];
	int cantidadDatos,
	    cantidadNodos;
	char tipoTabla;	
}Cabecera;


Cabecera *inicializar_cabecera();
void imprimir_cabecera(Cabecera *cabecera);

Cabecera *inicializar_cabecera(){
	Cabecera *cabecera=(Cabecera*)malloc(sizeof(Cabecera));
	inicializar_tabla_hash(cabecera->tablaHash);
	cabecera->cantidadDatos=0;
	cabecera->cantidadNodos=0;
	cabecera->tipoTabla='a';
	return cabecera;
}

void imprimir_cabecera(Cabecera *cabecera){
	printf ("Cantidad de datos:\t%i\n", (cabecera->cantidadDatos));
	printf ("Cantidad de Nodos:\t%i\n", (cabecera->cantidadNodos));
	printf ("Tipo de tabla:\t%c\n", (cabecera->tipoTabla));
	imprimir_tabla_hash(cabecera->tablaHash);
}

int main (){
	Cabecera* cabecera=inicializar_cabecera();
	imprimir_cabecera(cabecera);
	return 0;
}
