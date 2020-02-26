#include "UndoAdd.h"

UndoAdd::UndoAdd(Norven_Tower tower, Repository & repo) :UndoAction{}, addedTower{ tower }, repository{repo}
{
}

void UndoAdd::executeUndo()
{
	this->repository.removeTower(this->addedTower.getLocation());
}

UndoAdd::~UndoAdd()
{
}
