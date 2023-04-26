#include "stdafx.h"
#include "employgui.h"
#include "addemployee.h"
#include "addsale.h"

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
    if (dialog.exec()) {
        QString name = dialog.nameEdit->text();

        if (!name.isEmpty()) {
            QListWidgetItem* item = new QListWidgetItem(name, ui.employeeList);
            ui.employeeList->setCurrentItem(item);
        }
    }
}

void employgui::on_employeeList_currentItemChanged()
{
    QListWidgetItem* curItem = ui.employeeList->currentItem();

    if (curItem) {
        ui.nameLabel->setText(curItem->text());

        auto text = ui.saleLabel;
        if (text) {
            ui.saleLabel->setText(curItem->data(Qt::UserRole + 1).toString());
        }
    }
    else {
        ui.nameLabel->clear();
        ui.saleLabel->clear();
    } 
}

void employgui::on_removeEmployeeButton_clicked()
{
    QListWidgetItem* curItem = ui.employeeList->currentItem();
    if (curItem) {
        int row = ui.employeeList->row(curItem);
        ui.employeeList->takeItem(row);
        delete curItem;

        if (ui.employeeList->count() > 0)
            ui.employeeList->setCurrentRow(0);
        else
            on_employeeList_currentItemChanged();
    }
}

void employgui::on_addSaleButton_clicked()
{
    QListWidgetItem* curItem = ui.employeeList->currentItem();
    if (curItem == NULL)
        return;

    addsale dialog(this);
    if (dialog.exec()) {
        QString sale = ui.saleLabel->text() 
                       + dialog.saleEdit->text() + " ";

        curItem->setData(Qt::UserRole + 1, sale);

        if (!sale.isEmpty()) {
            ui.saleLabel->setText(sale);
        }
    }
}