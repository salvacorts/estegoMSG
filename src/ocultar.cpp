//////////////////////
//	Salvador Corts	//
//	Ruben Mógica	//
//	UGR				//
//					//
//	ocultar.cpp		//
//////////////////////

/**
  * @file ocultar.cpp
  * @brief Fichero con definiciones para la ocultacion de mensajes en imágenes
  *
  *	El programa de ocultación debe insertar un mensaje en una imagen. El programa pide en consola el nombre de la imagen
  *	de entrada, el nombre de la imagen de salida, y el mensaje a insertar
  * 
  */

#include <iostream>
#include "imagenES.h"
#include "codificar.h"

using namespace std;

int main(){
	int filas, column, totalPixels = 0;
	const char TERMINADOR = '#';
	const int MAXNOMBRE = 100;
	const int MAXBUFFER = 10000000;
	const int MAXMSG = MAXBUFFER / 8;
	char nombreEntrada[MAXNOMBRE];
	char nombreSalida[MAXNOMBRE];
	static char msg[MAXMSG];
	static unsigned char buffer[MAXBUFFER];
	TipoImagen tipo;
	bool procesamientoCorrecto = true;

	cout << "\nIntroduzca la imagen de entrada: ";
	cin.getline(nombreEntrada, MAXNOMBRE);
	cout << "\nIntroduzca el nombre de la imagen de salida: ";
	cin.getline(nombreSalida, MAXNOMBRE);
	cout << "\nIntroduzca el mensaje (# para terminar): ";
	cin.getline(msg, MAXMSG, TERMINADOR);

	tipo = LeerTipoImagen(nombreEntrada, filas, column);

	totalPixels = filas*column;

	if (tipo == IMG_PGM){

		if (LeerImagenPGM(nombreEntrada, filas, column, buffer)){

			if(!OcultarMensaje(buffer, msg, totalPixels)){
				cout << "\nError procesando el archivo";
				procesamientoCorrecto = false;
			}

			if(procesamientoCorrecto){
				if(!EscribirImagenPGM(nombreSalida, buffer, filas, column)){
					procesamientoCorrecto = false;
				}
			}
		}
	}
	else if (tipo == IMG_PPM){

		if (LeerImagenPPM(nombreEntrada, filas, column, buffer)){

			if(!OcultarMensaje(buffer, msg, totalPixels)){
				cout << "\nError procesando el archivo";
				procesamientoCorrecto = false;
			}

			if(procesamientoCorrecto){
				if(!EscribirImagenPPM(nombreSalida, buffer, filas, column)){
					procesamientoCorrecto = false;
				}
			}
		}
	}
	else{

		cout << "\n\nFormato de archivo no soportado.\n";
		procesamientoCorrecto = false;
	}

	if(procesamientoCorrecto){

		cout << "\nExito!!" << endl;
	}
}