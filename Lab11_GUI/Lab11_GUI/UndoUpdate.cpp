#include "UndoUpdate.h"



UndoUpdate::UndoUpdate(Norven_Tower tower, Repository & repo) : updatedTower{ tower }, repository{repo}
{
}

void UndoUpdate::executeUndo()
{
	this->repository.updateTower(this->updatedTower);
}

UndoUpdate::~UndoUpdate()
{
}
