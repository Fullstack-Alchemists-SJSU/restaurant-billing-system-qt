#include "EditUserDialogController.h"
#include "Constants.h"
#include <QDebug>

EditUserDialogController::EditUserDialogController(QStringList original, QStringList edited): originalRow(original), editedRow(edited), fileManager(Constants::USER_FILE){}

bool EditUserDialogController::isRowEdited(){
    if(originalRow.size() != editedRow.size()){
        throw std::runtime_error("Incompatible data");
    }else{
        for(int i = 0; i < originalRow.size(); i++){
            if(originalRow.at(i) != editedRow.at(i)){
                return true;
            }
        }
        return false;
    }
}

void EditUserDialogController::setEdited(int columnIndex, QString newValue){
    if(!this->editedRow.isEmpty()){
        QStringList temp(this->editedRow);
        temp.replace(columnIndex, newValue);
        this->editedRow = temp;
    }
}

void EditUserDialogController::setEdited(QStringList newRow){
    this->editedRow = newRow;
}

QStringList EditUserDialogController::getEdited(){
    return this->editedRow;
}

void EditUserDialogController::updateUser(){
    this->fileManager.update(this->editedRow.at(static_cast<int>(Constants::USER_ID_COLUMN_INDEX)).toInt(), this->editedRow);
}

int EditUserDialogController::getNextUserId(){
    return fileManager.getNextUserId();
}

void EditUserDialogController::addNewUser(QStringList newUser){
    fileManager.appendAtEnd(newUser);
}
