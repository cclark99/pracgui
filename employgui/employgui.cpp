#include "stdafx.h"
#include "employgui.h"
#include "addemployee.h"

employgui::employgui(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
}

employgui::~employgui()
{}

void employgui::on_addEmployeeButton_clicked()
{
    addEmployee dialog(this);
    dialog.exec();
}
