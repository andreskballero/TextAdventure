//-----------------------------------------------------------------------------
//
// $Id:$
//
// Copyright (C) 2017 by Andr�s K.
//
// DESCRIPCI�N:
// Clase que representa el gestor de eventos que desencadenan acciones
//    
//-----------------------------------------------------------------------------

#ifndef EVENTS_H
#define EVENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "descriptions.h"
#include "activeObject.h"

typedef struct
{
	char *name;
	char *notice;
} playerObject;

typedef struct {
	char *objectA;
	char *objectB;
	char *notice;

	activeObject *result; // nombre del objeto resultante de la combinaci�n de los anteriores
	// si tengo ambos, a�ado uno nuevo y estos los elimino del inventario
} objectCombined;

typedef struct {
	char *objectA;
	char *objectN;
	char *place;
	char *notice;
} placeReaction;

class events
{
private:
	playerObject			*playerEvents[MAX_PLAYER_EVENTS]; // guardo el nombre de los objetos que puede usar el player

	objectCombined			*craftedEvents[MAX_CRAFTED_OBJECTS]; // guardo el nombre de parejas de objetos combinables + su resultado

	placeReaction			*reactionEvents[MAX_REACTIONS]; // total reactions on the map

	void initEvents(void);
public:
	events();
	~events();

	char* getNotice(char *target);
	objectCombined* getObjectResult(char *element, char *element2);
	placeReaction* getReactionResult(char *element, char *element2);


	bool checkPlayerUsage(char *objectUsed);
};

#endif

//-----------------------------------------------------------------------------
//
// $Log:$
//
//-----------------------------------------------------------------------------