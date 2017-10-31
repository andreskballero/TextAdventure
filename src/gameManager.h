//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase principal del juego. 
// Realiza el procesado general de la acci�n del juego y representa un gestor
// para realizar las acciones que se escriban.
//    
//-----------------------------------------------------------------------------

#ifndef GESTACC_H
#define GESTACC_H

#include "descriptions.h"
#include "textParser.h"
#include "player.h"
#include "map.h"

// struct para chequear existencia; almacena
// si el input es correcto y la posici�n de la
// orden en el array de �rdenes
typedef struct {
	bool correct;
	int order;
	int element;
	int prepos;
	int element2;
} words;

class gameManager
{
private:
	// porque como m�ximo se cargar�n 100 objetos en el juego

	// hecho con array din�mico para poder eliminar con el delete los objetos
	// contenidos reservados de forma din�mica

	//objetoActivo*				colaObjetos[100]; 
	//activeObject*				objectStack = new activeObject[100]; // mejor global


	// parser propio para parsear el texto analizado
	textParser				parser;
	player					player;
	map						map;
	words					wordsExistant;

	char					inputText[MAX_INPUT_SIZE];

	void objectLoader(void);
	void placeLoader(void);
	void playerLoader(void);

public:
	gameManager();
	~gameManager();

	void gameLoad(void);
	void gameStart(void);

	void getInput(void);
	bool parsing(void);
	int checkExistance(void);
	void act(void);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------