#include "UndoRemove.h"

UndoRemove::UndoRemove(Norven_Tower tower, Repository & repo) : deletedTower{ tower }, repository{repo}
{
}

void UndoRemove::executeUndo()
{
	this->repository.addTower(deletedTower);
}

UndoRemove::~UndoRemove()
{
}
