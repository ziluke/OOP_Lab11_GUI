#pragma once
#include "Norven_Tower.h"
#include "Repository.h"

class UndoAction
{
public:
	UndoAction();
	virtual void executeUndo() = 0;

	virtual ~UndoAction();
};

