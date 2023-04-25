#pragma once

#include <QDialog>
#include "ui_addsale.h"

class addsale : public QDialog, public Ui::addsaleClass
{
	Q_OBJECT

public:
	addsale(QWidget *parent = nullptr);
	~addsale();

private:
	 
};
