//////////////////////
//	Salvador Corts	//
//	Ruben Mógica	//
//	UGR				//
//					//
//	revelar.cpp		//
//////////////////////

/**
  * @file revelar.cpp
  * @brief Fichero con definiciones para revelar mensajes ocultos en imágenes
  *
  *	El programa para revelar un mensaje oculto deberá obtener el mensaje
  *	que previamente se haya ocultado con el programa ocultar
  *
  */

#include <iostream>
#include "imagenES.h"
#include "codificar.h"

using namespace std;
int main(){

	bool procesamientoCorrecto = true;
	const int MAXNOMBRE = 100;
	const int MAXBUFFER = 10000000;
	const int MAXMSG = MAXBUFFER / 8;
	TipoImagen tipo;
	int filas, column, totalPixels = 0;
	char nombre[MAXNOMBRE];
	static char msg[MAXMSG];
	static unsigned char buffer[MAXBUFFER];	// Vector donde almacenamos los datos de la imagen

	// ENTRADA DE DATOS
	cout << "\nIntroduzca la imagen de entrada: ";
	cin.getline(nombre, MAXNOMBRE);
	cout << "Revelando..." << endl;

	// Leemos el tipo de imagen que es
	tipo = LeerTipoImagen(nombre, filas, column);

	totalPixels = filas*column;

	if (tipo == IMG_PGM){

		if (LeerImagenPGM(nombre, filas, column, buffer)){

			if(!LeerMensaje(buffer, msg, totalPixels)){
				cout << "\nError procesando el archivo";
				procesamientoCorrecto = false;
			}
		}
	}
	else if (tipo == IMG_PPM){

		if (LeerImagenPPM(nombre, filas, column, buffer)){

			if(!LeerMensaje(buffer, msg, totalPixels)){
				cout << "\nError procesando el archivo";
				procesamientoCorrecto = false;
			}
		}
	}
	else{

		cout << "\n\nFormato de archivo no soportado.\n";
		procesamientoCorrecto = false;
	}

	// SALIDA DE DATOS
	if(procesamientoCorrecto){
		cout << endl << msg << endl;
	}
}

