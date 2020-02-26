#pragma once
#include "Norven_Tower.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Exception.h"
#include "Repository.h"

void testEncyclopedia();

class Encyclopedia: public Repository
{
private:
	std::vector<Norven_Tower> towers;
	int capacity;
public:
	Encyclopedia(int capacity = 150)
	{
		this->capacity = capacity;
		this->towers.reserve(this->capacity);
	}

	bool addTower(Norven_Tower newTower) override
	{
		/*if (this->size >= this->capacity)
		{
			this->capacity *= 2;
			std::vector<T> newArrayOfTowers.reserve(this->capacity);
			for (int i = 0; i < this->size; i++)
			{
				newArrayOfTowers[i] = this->towers[i];
			}
			this->towers = newArrayOfTowers;
		}*/
		this->towers.reserve(this->capacity);

		/*for (int i = 0; i < this->size; i++)
		{
			if (this->towers[i].getLocation() == newTower.getLocation())
			{
				return false;
			}
		}*/

		if (std::any_of(this->towers.begin(), this->towers.end(), [newTower](Norven_Tower tower) {return(tower.getLocation() == newTower.getLocation()); }) == true)
			throw Exception("A tower already exists at location " + newTower.getLocation() + "!\n");

		this->towers.push_back(newTower);
		return true;
	}

	bool removeTower(std::string & location) override
	{
		/*for (int i = 0; i < this->size; i++)
		{
			if (this->towers[i].getLocation() == location)
			{
				int j = i;
				while (j < this->size - 1)
				{
					this->towers[j] = this->towers[j + 1];
					j++;
				}
				this->size--;
				this->towers.erase(this->towers[i]);
				return true;
			}
		}*/
		auto removeIterator = std::find_if(this->towers.begin(), this->towers.end(), [location](Norven_Tower tower) { return (tower.getLocation() == location); });

		if (removeIterator != this->towers.end())
		{
			this->towers.erase(removeIterator);
			return true;
		}
		throw Exception("Tower does not exist at location " + location + "!\n");
	}

	bool updateTower(Norven_Tower newTower) override
	{
		/*for (int i = 0; i < this->size; i++)
		{
			if (this->towers[i].getLocation() == location)
			{
				this->towers[i].setSize(newSize);
				this->towers[i].setQuantityOfParts(newQuantitiOfParts);
				this->towers[i].setAuraLevel(newAuraLevel);
				this->towers[i].setVision(newVision);
				return true;
			}
		}*/
		auto updateIterator = std::find_if(this->towers.begin(), this->towers.end(), [newTower](Norven_Tower tower) { return ( tower.getLocation() == newTower.getLocation() ); });

		if (updateIterator != this->towers.end())
		{
			this->towers.erase(updateIterator);
			this->towers.push_back(newTower);
			return true;
		}
		throw Exception("Tower does not exist!\n");
	}

	std::vector<Norven_Tower> getAllTowers() const override
	{
		return this->towers;
	}

	int getSize() const override { return this->towers.size(); }

	void setPath(std::string path) override { return ; }

	~Encyclopedia()
	{
	}
};

