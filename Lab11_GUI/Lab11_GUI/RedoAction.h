#pragma once
#include "Norven_Tower.h"
#include "Repository.h"

class RedoAction
{
public:
	RedoAction();
	virtual void executeRedo() = 0;
	virtual ~RedoAction();
};

