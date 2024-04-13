#include "admindashboard.h"
#include "ui_admindashboard.h"
#include <QDebug>

AdminDashboard::AdminDashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::AdminDashboard)
{
    ui->setupUi(this);
    setupTable();
}

AdminDashboard::~AdminDashboard()
{
    delete ui;
}


void AdminDashboard::on_buttonLogout_clicked()
{
    emit backNavigationRequested();
}

void AdminDashboard::showUserDialog(int row){
    int columnCount = ui->tableView->model()->columnCount() - 1; // -1 for excluding the Actions column
    QStringList rowData;
    if(row != -1){
        for (int column = 0; column < columnCount; ++column) {
            QModelIndex index = ui->tableView->model()->index(row, column);
            QVariant data = ui->tableView->model()->data(index);
            rowData.append(data.toString());
        }
    }
    editUserDialog = new EditUserDialog(rowData, this);
    connect(editUserDialog, &EditUserDialog::operationFinished, this, &AdminDashboard::setupTable);
    editUserDialog->exec();
}

void AdminDashboard::editUserClicked(int row){
    showUserDialog(row);
}

void AdminDashboard::setupTable(){
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QStandardItemModel *model = controller.populateTable();
    ui->tableView->setModel(model);

    for(int lineIndex = 0; lineIndex < model->rowCount(); lineIndex++){
        QModelIndex index = model->index(lineIndex, Constants::ACTIONS_COLUMN_INDEX);
        ui->tableView->setIndexWidget(index, actionsColumnWidget(this, lineIndex));
    }

    ui->tableView->update();
}

void AdminDashboard::deleteUserClicked(int row){
    controller.deleteUser(row);
    setupTable();
}

void AdminDashboard::on_pushButton_clicked()
{
    showUserDialog(-1);
}

