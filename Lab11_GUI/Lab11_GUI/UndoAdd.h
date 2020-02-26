#pragma once
#include "UndoAction.h"
class UndoAdd :
	public UndoAction
{
private:
	Norven_Tower addedTower;
	Repository& repository;
public:
	UndoAdd(Norven_Tower tower, Repository& repo);

	void executeUndo() override;

	~UndoAdd();
};

