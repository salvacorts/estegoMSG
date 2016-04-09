//////////////////////
//	Salvador Corts	//
//	Ruben Mógica	//
//	UGR				//
//					//
//	codificar.cpp	//
//////////////////////

/**
  * @file ocultar.cpp
  * @brief Fichero con definiciones para la ocultacion de mensajes en imágenes
  *
  *	Codificar facilita el proceso de ocultacion y extraccion de mensajes en imágenes.
  * 
  */

#include <iostream>
#include "imagenES.h"
#include "codificar.h"
  
using namespace std;

bool OcultarMensaje(unsigned char buffer[], char msg[], int numPixels){	// Modificamos el buffer
	bool correcto = false;
	char letra;

	for(int i, inicio = 0; !correcto && i < (numPixels / 8); i++, inicio+=8){
		letra = msg[i];

		if(letra == '\0'){
			correcto = true;
		}

		for(int pixel = inicio; pixel < inicio + 8; pixel++){

			if((letra&128) != 0){	// Meter un 1 en el buffer 	   128 = 2^7 = bit mas significativo de un byte
				buffer[pixel] = buffer[pixel]|1;
			}
			else{	// Meter un 0 en el buffer
				buffer[pixel] = ~buffer[pixel];
				buffer[pixel] = buffer[pixel]|1;
				buffer[pixel] = ~buffer[pixel];
			}

			letra = letra<<1;
		}
	}

	return correcto;
}

bool LeerMensaje(unsigned char buffer[], char msg[], int numPixels){	// Modificamos msg
	bool correcto = false;
	char dato, letra;

	for (int i, t = 0; i+8 < numPixels && !correcto; i+=8, t++){
		for(int f=i; f < i+8; f++){
			dato = buffer[f];
			letra = letra<<1;

			if((dato&1) != 0){	// Hay un 1 en el primer bit del dato del buffer
				letra = letra|1;
			}
		
		}

		if(letra == '\0'){
			correcto = true;
		}

		msg[t] = letra;	// Mete la letra en el mensaje
	}

	return correcto;
}