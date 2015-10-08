# ifndef stdio_h
# include <stdio.h>
# define stdio_h
# endif

# ifndef stdlib_h
# include <stdlib.h>
# define stdlib_h
# endif

/*
typedef int Rut;
typedef char Nombre;
*/

typedef struct _datos{
	int rut;
	char nombre;
}Datos;

Datos *inicializar_datos(int i){
	Datos *datos=(Datos*)malloc(sizeof(Datos));
	datos->rut=i;
	datos->nombre='a'+i;
	return datos;
}

void imprimir_datos(Datos *datos){
	printf("%i\t%c\n", (datos->rut), (datos->nombre));
}
