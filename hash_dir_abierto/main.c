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

# define tam 200

typedef struct _cabecera{
	//Hash tablaHash[tam];
	Nodo *nodo;
	int cantidadDatos,
	    cantidadNodos;
	char tipoTabla;	
}Cabecera;


//Cabecera *inicializar_cabecera();
//void imprimir_cabecera(Cabecera *cabecera);

Cabecera *inicializar_cabecera(){
	int i=0;
	Cabecera *cabecera=(Cabecera*)malloc(sizeof(Cabecera));
	cabecera->nodo=cargar_archivo(&i,cabecera->nodo);
	cabecera->cantidadDatos=6;
	cabecera->cantidadNodos=i;
	cabecera->tipoTabla='a';
	return cabecera;
}

void imprimir_cabecera(Cabecera *cabecera){
	printf ("Cantidad de datos:\t%i\n", (cabecera->cantidadDatos));
	printf ("Cantidad de Nodos:\t%i\n", (cabecera->cantidadNodos));
	printf ("Tipo de tabla:\t%c\n", (cabecera->tipoTabla));
}

int main() {
	Cabecera* cabecera=inicializar_cabecera();
	int m = (cabecera->cantidadNodos)%((cabecera->cantidadNodos)/70);
	Hash tablaHash[m];
	inicializar_tabla_hash((cabecera->nodo),m,tablaHash); 
	imprimir_cabecera(cabecera);
	imprimir_tabla_hash(m,tablaHash);

	return -1;
}
