#include "EditUserDialogController.h"
#include <QDebug>

EditUserDialogController::EditUserDialogController(User* original, User* edited): originalUser(original), editedUser(edited), fileManager(){}

bool EditUserDialogController::isRowEdited(){
    return originalUser->compare(editedUser);
}

void EditUserDialogController::setEdited(User* newRow){
    this->editedUser = newRow;
}

User* EditUserDialogController::getEdited(){
    return this->editedUser;
}

void EditUserDialogController::updateUser(){
    this->fileManager.updateUser(editedUser);
}

int EditUserDialogController::getNextUserId(){
    return fileManager.getNextUserId();
}

void EditUserDialogController::addNewUser(){
    fileManager.addUser(editedUser);
}
