#include "UserManager.h"

UserManager::UserManager(): FileManager(Constants::USER_FILE){

}

QList<User*> UserManager::getAllUsers(){
    QList<QStringList> rows = read(true);
    QList<User*> allUsers;
    for(QStringList row : rows){
        Role role = User::intToEnumValue(row.at(Constants::ROLE_COLUMN_INDEX).toInt());
        User* user = UserFactory::build(row.at(Constants::USER_ID_COLUMN_INDEX).toInt(), row.at(Constants::USERNAME_COLUMN_INDEX), row.at(Constants::PASSWORD_COLUMN_INDEX), role);
        allUsers.append(user);
    }
    return allUsers;
}

void UserManager::addUser(User* user){
    appendAtEnd(User::deserialize(user));
}

void UserManager::updateUser(User* user){
    update(user->getUserId(), User::deserialize(user));
}

void UserManager::deleteUser(User* user){
    QList<QStringList> rows = read(true);
    int rowIndexToDelete = -1;
    for(int i = 0; i < rows.size(); i++){
        if(rows.at(i).at(Constants::USER_ID_COLUMN_INDEX).toInt() == user->getUserId()){
            rowIndexToDelete = i;
            break;
        }
    }
    deleteRowAtIndex(rowIndexToDelete);
}

int UserManager::getNextUserId(){
    QList<QStringList> data = read();
    int maxId = 0;  // Start with a default max ID of 0
    bool ok;

    for (const QStringList& row : data) {
        if (!row.isEmpty()) {
            int currentId = row.first().toInt(&ok);
            if (ok && currentId > maxId) {
                maxId = currentId;
            }
        }
    }

    return maxId + 1; // + 1 for the next ID to assign to the new user
}
