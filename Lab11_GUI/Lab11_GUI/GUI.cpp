#include "GUI.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <qmessagebox.h>
#include <qshortcut.h>

GUI::GUI(Controler & controler, QWidget * parent) : QWidget{ parent }, controler{ controler }
{
	this->initiate();
	QShortcut *undoS = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z), this, SLOT(undoSlot()));
	QShortcut *redoS = new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y), this, SLOT(redoSlot()));
	this->connectSignalsToSlots();
	this->populate();
	this->nextIndex = 0;
}


GUI::~GUI()
{
}

void GUI::initiate()
{
	QHBoxLayout* mainLayout = new QHBoxLayout{ this };

	this->listWidget = new QListWidget{};
	mainLayout->addWidget(this->listWidget);

	QVBoxLayout* rightLayout = new QVBoxLayout{};

	QFormLayout* dataLayout = new QFormLayout{};
	this->locationEdit = new QLineEdit{};
	this->sizeEdit = new QLineEdit{};
	this->quantityEdit = new QLineEdit{};
	this->auraEdit = new QLineEdit{};
	this->visionEdit = new QLineEdit{};
	dataLayout->addRow("Location", this->locationEdit);
	dataLayout->addRow("Size", this->sizeEdit);
	dataLayout->addRow("Quantity of Parts", this->quantityEdit);
	dataLayout->addRow("Aura Level", this->auraEdit);
	dataLayout->addRow("Vision", this->visionEdit);

	rightLayout->addLayout(dataLayout);
	mainLayout->addLayout(rightLayout);

	this->listUserWidget = new QListWidget{};

	rightLayout->addWidget(this->listUserWidget);

	QHBoxLayout* buttonsLayout = new QHBoxLayout{};
	this->addButton = new QPushButton{ "Add" };
	this->removeButton = new QPushButton{ "Remove" };
	this->updateButton = new QPushButton{ "Update" };
	this->modeButton = new QPushButton{ "Mode" };
	this->nextButton = new QPushButton{ "Next" };
	this->undoButton = new QPushButton{ "Undo" };
	this->redoButton = new QPushButton{ "Redo" };
	this->nextButton->setEnabled(false);
	this->saveButton = new QPushButton{ "Save" };
	this->saveButton->setEnabled(false);
	this->mylistButton = new QPushButton{ "mylist" };
	this->listButton = new QPushButton{ "List" };
	this->mylistButton->setEnabled(false);
	this->listButton->setEnabled(false);
	buttonsLayout->addWidget(this->addButton);
	buttonsLayout->addWidget(this->removeButton);
	buttonsLayout->addWidget(this->updateButton);
	buttonsLayout->addWidget(this->modeButton);
	buttonsLayout->addWidget(this->nextButton);
	buttonsLayout->addWidget(this->saveButton);
	buttonsLayout->addWidget(this->mylistButton);
	buttonsLayout->addWidget(this->listButton);
	buttonsLayout->addWidget(this->undoButton);
	buttonsLayout->addWidget(this->redoButton);

	rightLayout->addLayout(buttonsLayout);

	QFormLayout* locations = new QFormLayout{};
	this->fileLocationEdit = new QLineEdit{};
	this->mylistLocationEdit = new QLineEdit{};
	this->currentTowerEdit = new QLineEdit{};
	locations->addRow("file Location", this->fileLocationEdit);
	locations->addRow("mylist Location", this->mylistLocationEdit);
	locations->addRow("Current Tower", this->currentTowerEdit);
	mainLayout->addLayout(locations);
	this->mylistWidget = new QListWidget{};
	mainLayout->addWidget(this->mylistWidget);
}

void GUI::connectSignalsToSlots()
{
	QObject::connect(this->addButton, &QPushButton::clicked, this, &GUI::addButtonClicked);
	QObject::connect(this->removeButton, &QPushButton::clicked, this, &GUI::removeButtonClicked);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &GUI::updateButtonClicked);
	QObject::connect(this->modeButton, &QPushButton::clicked, this, &GUI::modeButtonClicked);
	QObject::connect(this->saveButton, &QPushButton::clicked, this, &GUI::saveButtonClicked);
	QObject::connect(this->mylistButton, &QPushButton::clicked, this, &GUI::mylistButtonClicked);
	QObject::connect(this->listButton, &QPushButton::clicked, this, &GUI::listButtonClicked);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &GUI::undoButtonClicked);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &GUI::redoButtonClicked);
	QObject::connect(this, SIGNAL(modeSignal()), this, SLOT(modeHandler()));
	QObject::connect(this, SIGNAL(addSignal()), this, SLOT(updateListWidget()));
	QObject::connect(this, SIGNAL(updateSignal()), this, SLOT(updateListWidget()));
	QObject::connect(this, SIGNAL(removeSignal()), this, SLOT(updateListWidget()));
	QObject::connect(this->nextButton, &QPushButton::clicked, this, &GUI::nextButtonClicked);
	QObject::connect(this->fileLocationEdit, &QLineEdit::returnPressed, this, &GUI::setFileLocation);
	QObject::connect(this->mylistLocationEdit, &QLineEdit::returnPressed, this, &GUI::setMylistLocation);
}

void GUI::modeHandler()
{
	if (this->nextButton->isEnabled())
	{
		this->nextButton->setEnabled(false);
		this->saveButton->setEnabled(false);
		this->mylistButton->setEnabled(false);
		this->listButton->setEnabled(false);
		this->addButton->setEnabled(true);
		this->updateButton->setEnabled(true);
		this->removeButton->setEnabled(true);
	}
	else
	{
		this->nextButton->setEnabled(true);
		this->saveButton->setEnabled(true);
		this->mylistButton->setEnabled(true);
		this->listButton->setEnabled(true);
		this->addButton->setEnabled(false);
		this->updateButton->setEnabled(false);
		this->removeButton->setEnabled(false);
	}
}

void GUI::addButtonClicked()
{
	QString location = this->locationEdit->text();
	QString size = this->sizeEdit->text();
	QString auraLevel = this->auraEdit->text();
	QString quantityOfParts = this->quantityEdit->text();
	QString vision = this->visionEdit->text();
	if (location.isEmpty() || size.isEmpty() || auraLevel.isEmpty() || quantityOfParts.isEmpty() || vision.isEmpty())
	{
		QMessageBox::critical(this, tr("Failure!"), tr("Not all the required fields have been occupied!"));
	}
	else
	{
		try {
			if (this->controler.add(location.toStdString(), size.toStdString(), auraLevel.toStdString(), quantityOfParts.toStdString(), vision.toStdString()))
			{
				QMessageBox::information(this, tr("Sucess!"), tr("The tower has been successfully added!"));
				emit addSignal();
			}
			else
				QMessageBox::critical(this, tr("Failure!"), tr("There has been a problem while adding! Please check the information!"));
		}
		catch (Exception exception)
		{
			QMessageBox::critical(this, tr("Failure!"), tr(exception.getMessage().c_str()));
		}
	}
}

void GUI::removeButtonClicked()
{
	QString location = this->locationEdit->text();
	QString size = this->sizeEdit->text();
	QString auraLevel = this->auraEdit->text();
	QString quantityOfParts = this->quantityEdit->text();
	QString vision = this->visionEdit->text();
	if (!size.isEmpty() || !auraLevel.isEmpty() || !quantityOfParts.isEmpty() || !vision.isEmpty())
	{
		QMessageBox::critical(this, tr("Failure!"), tr("Too many fields have been occupied! Please specify just the location!"));

	}
	else if (location.isEmpty())
	{
		QMessageBox::critical(this, tr("Failure!"), tr("Location not specified!"));
	}
	else
	{
		try {
			if (this->controler.remove(location.toStdString()))
			{
				QMessageBox::information(this, tr("Sucess!"), tr("The tower has been successfully removed!"));
				emit removeSignal();
			}
			else
				QMessageBox::critical(this, tr("Failure!"), tr("There has been a problem while deleting! Please check the information!"));
		}
		catch (Exception exception)
		{
			QMessageBox::critical(this, tr("Failure!"), tr(exception.getMessage().c_str()));
		}
	}
}

void GUI::updateButtonClicked()
{
	QString location = this->locationEdit->text();
	QString size = this->sizeEdit->text();
	QString auraLevel = this->auraEdit->text();
	QString quantityOfParts = this->quantityEdit->text();
	QString vision = this->visionEdit->text();
	if (location.isEmpty() || size.isEmpty() || auraLevel.isEmpty() || quantityOfParts.isEmpty() || vision.isEmpty())
	{
		QMessageBox::critical(this, tr("Failure!"), tr("Not all the required fields have been occupied!"));
	}
	else
	{
		try {
			if (this->controler.update(location.toStdString(), size.toStdString(), auraLevel.toStdString(), quantityOfParts.toStdString(), vision.toStdString()))
			{
				QMessageBox::information(this, tr("Sucess!"), tr("The tower has been successfully updated!"));
				emit updateSignal();
			}
			else
				QMessageBox::critical(this, tr("Failure!"), tr("There has been a problem while updating! Please check the information!"));
		}
		catch (Exception exception)
		{
			QMessageBox::critical(this, tr("Failure!"), tr(exception.getMessage().c_str()));
		}
	}
}

void GUI::modeButtonClicked()
{
	emit modeSignal();
}

void GUI::nextButtonClicked()
{
	QString size = this->sizeEdit->text();
	int  sizeOfTowers;
	std::vector<Norven_Tower> towers;
	this->controler.listGivenSize(size.toStdString(), sizeOfTowers, towers);
	if (this->nextIndex > sizeOfTowers)
	{
		nextIndex = sizeOfTowers-1;
	}
	else if (this->nextIndex == sizeOfTowers)
	{
		this->nextIndex = 0;
	}
	this->currentTowerEdit->setText(QString::fromStdString(towers.at(nextIndex).toString()));
	nextIndex++;
}

void GUI::saveButtonClicked()
{
	QString location = this->locationEdit->text();
	if (this->controler.checkTowerByLocation(location.toStdString()))
	{
		mylist.push_back(controler.getTowerByLocation(location.toStdString()));
		this->controler.writeMyList(mylist);
		this->mylistWidget->clear();
		for (auto& s : mylist)
		{
			this->mylistWidget->addItem(QString::fromStdString(
				s.getLocation() + " - " + s.getSize() + " - " + std::to_string(s.getQuantityOfParts()) + " - " + std::to_string(s.getAuraLevel()) + " - " + s.getVision()));
		}
	}

	//emit dataChanged(index, index);
}

void GUI::mylistButtonClicked()
{
	//this->controler.displayMyList();
	this->myListModel = new myListTableModel{this->controler};
	this->mylistView = new QTableView{};
	this->mylistView->setModel(this->myListModel);
	this->mylistView->resizeColumnToContents(0);
	this->mylistView->resizeColumnToContents(1);
	this->mylistView->resizeColumnToContents(2);
	this->mylistView->resizeColumnToContents(3);
	this->mylistView->resizeColumnToContents(4);
	this->mylistView->show();
}

void GUI::listButtonClicked()
{
	QString size = this->sizeEdit->text();
	QString quantotyOfParts = this->quantityEdit->text();
	int  sizeOfTowers;
	std::vector<Norven_Tower> towers;
	this->controler.listGivenSize(size.toStdString(), sizeOfTowers, towers, quantotyOfParts.toInt());
	this->listUserWidget->clear();
	for (auto& s : towers)
	{
		this->listUserWidget->addItem(QString::fromStdString(
			s.getLocation() + " - " + s.getSize() + " - " + std::to_string(s.getQuantityOfParts()) + " - " + std::to_string(s.getAuraLevel()) + " - " + s.getVision()));
	}
}

void GUI::undoButtonClicked()
{
	try {
		this->controler.undo();
		this->updateListWidget();
	}
	catch (std::exception exception)
	{
		QMessageBox::critical(this, tr("Failure!"), tr(exception.what()));
	}
}

void GUI::redoButtonClicked()
{
	try {
		this->controler.redo();
		this->updateListWidget();
	}
	catch (std::exception exception)
	{
		QMessageBox::critical(this, tr("Failure!"), tr(exception.what()));
	}
}

void GUI::setFileLocation()
{
	QString fileLocation = this->fileLocationEdit->text();
	this->controler.setPath(fileLocation.toStdString());
}

void GUI::setMylistLocation()
{
	QString fileLocation = this->mylistLocationEdit->text();
	this->controler.mylistLocation(fileLocation.toStdString());
}

void GUI::populate()
{
	/*std::string location = "location";
	std::string size = "size";
	std::string vision = "vision";
	for (int i = 1; i <= 10; i++)
	{
		this->controler.add(location+std::to_string(i), size+std::to_string(i), std::to_string(i*10),std::to_string(i*100),vision+std::to_string(i));
	}*/

	std::vector<Norven_Tower> towers = this->controler.getAllTowers();
	this->listWidget->clear();
	for (auto& s : towers)
	{
		this->listWidget->addItem(QString::fromStdString(
			s.getLocation() + " - " + s.getSize() + " - " + std::to_string(s.getQuantityOfParts()) + " - "+ std::to_string(s.getAuraLevel()) + " - " + s.getVision()));
	}
}

void GUI::updateListWidget()
{
	std::vector<Norven_Tower> towers = this->controler.getAllTowers();
	this->listWidget->clear();
	for (auto& s : towers)
	{
		this->listWidget->addItem(QString::fromStdString(
			s.getLocation() + " - " + s.getSize() + " - " + std::to_string(s.getQuantityOfParts()) + " - " + std::to_string(s.getAuraLevel()) + " - " + s.getVision()));
	}
}

void GUI::undoSlot()
{
	this->undoButtonClicked();
}

void GUI::redoSlot()
{
	this->redoButtonClicked();
}
