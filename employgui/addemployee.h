#pragma once

#include <QDialog>
#include "ui_addemployee.h"

class addEmployee : public QDialog, public Ui::addEmployeeClass
{
	Q_OBJECT

public:
	addEmployee(QWidget *parent = nullptr);
	~addEmployee();

private:
	 
};
