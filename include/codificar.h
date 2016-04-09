/**
  * @file codificar.h
  * @brief Fichero cabecera para la codificacion de mensajes en imágenes
  *
  * Permite ocultar y revelar mensajes en fotografías
  */

#ifndef _CODIFICAR_H_
#define _CODIFICAR_H_

/**
  * @brief Ocultar Mensaje
  *
  *
  * @see ocultar.cpp
  */
  bool OcultarMensaje(unsigned char buffer[], char msg[], int numPixels);

/**
  * @brief Leer Mensaje
  *
  *
  *
  * @see revelar.cpp
  */
  bool LeerMensaje(unsigned char buffer[], char msg[], int numPixels);

#endif

/* Fin Fichero: codificar.h */

