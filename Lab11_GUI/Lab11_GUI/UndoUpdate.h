#pragma once
#include "UndoAction.h"
class UndoUpdate :
	public UndoAction
{
private:
	Norven_Tower updatedTower;
	Repository& repository;
public:
	UndoUpdate(Norven_Tower tower, Repository& repo);

	void executeUndo() override;

	~UndoUpdate();
};

