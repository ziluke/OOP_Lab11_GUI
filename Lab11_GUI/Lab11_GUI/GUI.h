#pragma once
#include <qwidget.h>
#include "Controler.h"
#include "myListTableModel.h"
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <qtableview.h>

class GUI : public QWidget
{
	Q_OBJECT

private:
	Controler& controler; 
	QLineEdit* locationEdit, *sizeEdit, *quantityEdit, *auraEdit, *visionEdit, *fileLocationEdit, *mylistLocationEdit, *currentTowerEdit;
	QPushButton* addButton, *removeButton, *updateButton, *modeButton, *nextButton, *saveButton, *mylistButton, *listButton, *undoButton, *redoButton;
	QListWidget *listWidget, *mylistWidget, *listUserWidget;
	QTableView* mylistView;
	myListTableModel* myListModel;
	int nextIndex;
	std::vector<Norven_Tower> mylist;

public:
	GUI(Controler& controler, QWidget *parent = 0);
	~GUI();

private:
	void initiate();
	void connectSignalsToSlots();
	void addButtonClicked();
	void removeButtonClicked();
	void updateButtonClicked();
	void modeButtonClicked();
	void nextButtonClicked();
	void saveButtonClicked();
	void mylistButtonClicked();
	void listButtonClicked();
	void undoButtonClicked();
	void redoButtonClicked();
	void setFileLocation();
	void setMylistLocation();
	void populate();

signals:
	void modeSignal();
	void addSignal();
	void removeSignal();
	void updateSignal();

public slots:
	void modeHandler();
	void updateListWidget();
	void undoSlot();
	void redoSlot();
};

