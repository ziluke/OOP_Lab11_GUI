#include "RedoUpdate.h"


void RedoUpdate::executeRedo()
{
	this->repository.updateTower(updatedTower);
}

RedoUpdate::~RedoUpdate()
{
}
