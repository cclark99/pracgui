#pragma once

#include <QtWidgets/QWidget>
#include "ui_employgui.h"

class employgui : public QWidget
{
    Q_OBJECT

public:
    employgui(QWidget *parent = nullptr);
    ~employgui();

private:
    Ui::employguiClass ui;

private slots:
    void on_addEmployeeButton_clicked();
};
