#include "myListTableModel.h"
#include <QFont>
#include <QBrush>

myListTableModel::myListTableModel(Controler& controler, QObject* parent) : controler{ controler }, QAbstractTableModel{parent}
{
}

int myListTableModel::rowCount(const QModelIndex & parent) const
{
	std::vector<Norven_Tower> towers = controler.getMyList();
	int size = towers.size();
	return size;
}

int myListTableModel::columnCount(const QModelIndex & parent) const
{
	return 5;
}

QVariant myListTableModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int column = index.column();
	Norven_Tower tower = this->controler.getMyList()[row];

	if (role == Qt::DisplayRole || role == Qt::EditRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(tower.getLocation());
		case 1:
			return QString::fromStdString(tower.getSize());
		case 2:
			return QString::number(tower.getAuraLevel());
		case 3:
			return QString::number(tower.getQuantityOfParts());
		case 4:
			return QString::fromStdString(tower.getVision());		
		default:
			break;
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setItalic(false);
		return font;
	}
	if (role == Qt::BackgroundRole)
	{
		if (row % 2 == 1)
		{
			return QBrush{ QColor{ 0, 250, 154 } };
		}
	}

	return QVariant();
}

QVariant myListTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (orientation == Qt::Horizontal)
		{
			switch (section)
			{
			case 0:
				return QString{ "Location" };
			case 1:
				return QString{ "Size" };
			case 2:
				return QString{ "Aura Level" };
			case 3:
				return QString{ "Quantity of parts" };
			case 4:
				return QString{ "Vision" };
			default:
				break;
			}
		}
	}
	if (role == Qt::FontRole)
	{
		QFont font("Times", 15, 10, true);
		font.setBold(true);
		font.setItalic(false);
		return font;
	}
	return QVariant();
}

//bool myListTableModel::setData(const QModelIndex & index, const QVariant & value, int role)
//{
//	if (!index.isValid() || role != Qt::EditRole)
//		return false;
//
//	// set the new data to the gene
//	int row = index.row();
//	Norven_Tower currenttower = this->controler.getMyList()[row];
//	switch (index.column())
//	{
//	case 0:
//		this->controler.add(value.toString().toStdString(), "", "", "0", "");
//		break;
//	case 1:
//		this->controler.add("", value.toString().toStdString(), "", "0", "");
//		break;
//	case 2:
//		this->controler.add("", "", value.toString().toStdString(), "0", "");
//		break;
//	case 3:
//		this->controler.add("", "", value.toString().toStdString(), "0", "");
//		break;
//	default:
//		break;
//	}
//
//	// emit the dataChanged signal
//	emit dataChanged(index, index);
//
//	return true;
//}


Qt::ItemFlags myListTableModel::flags(const QModelIndex & index) const
{
	return Qt::ItemIsSelectable | Qt::ItemIsEnabled;
}

myListTableModel::~myListTableModel()
{
}
