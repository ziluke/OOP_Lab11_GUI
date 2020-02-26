#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Lab11_GUI.h"
#include "Controler.h"

class Lab11_GUI : public QMainWindow
{
	Q_OBJECT

private:
	Controler& controler;

public:
	Lab11_GUI(Controler& controler, QWidget *parent = Q_NULLPTR);

private slots:
	void addButtonClicked();
	void deleteButtonClicked();
	void updateButtonClicked();
	void modeButtonClicked();
	void chartButtonClicked();

private:
	Ui::Lab11_GUIClass ui;
};
