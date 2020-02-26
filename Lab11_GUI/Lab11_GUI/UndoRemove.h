#pragma once
#include "UndoAction.h"
class UndoRemove :
	public UndoAction
{
private:
	Norven_Tower deletedTower;
	Repository& repository;
public:
	UndoRemove(Norven_Tower tower, Repository& repo);

	void executeUndo() override;

	~UndoRemove();
};

