#include "MenuController.h"
#include "MenuItemDialog.h"
#include <QDebug>
#include "../util/Constants.h"

MenuController::MenuController(QObject *parent) : QObject(parent), menuModel(nullptr), menuView(nullptr) {}

void MenuController::setMenuModel(Menu* menu) {
    menuModel = menu;
}

void MenuController::setView(MenuListView* view) {
    menuView = view;
    connect(menuView, &MenuListView::itemDeleted, this, &MenuController::handleItemDeletion);
    connect(menuView, &MenuListView::addItemRequested, this, &MenuController::addItem);
    connect(menuView, &MenuListView::editItemRequested, this, &MenuController::editItem);
}

void MenuController::loadMenuItemsFromFile(const QString& filename) {
    if (menuModel != nullptr) {
        auto items = adapter.loadMenuItemsFromCSV(filename.toStdString());
        for (auto& item : items) {
            menuModel->addItem(item);
        }
        if(menuView != nullptr){
            menuView->setMenu(menuModel);
        }
    }
}

void MenuController::saveMenuItemsToFile(const QString &filename) {
    if (menuModel != nullptr) {
        adapter.saveMenuItemsToCSV(menuModel->getMenuItems(), filename.toStdString());
    }
}

void MenuController::handleItemDeletion(const QString &itemName) {
    if (menuModel) {
        menuModel->removeItem(itemName.toStdString());
        saveMenuItemsToFile(Constants::MENU_FILE);
    }
}

void MenuController::addItem() {
    MenuItemDialog dialog(menuView);
    if (dialog.exec() == QDialog::Accepted) {
        MenuItem newItem = dialog.getItem();
        menuModel->addItem(newItem);
        saveMenuItemsToFile(Constants::MENU_FILE);
    }
}

void MenuController::editItem(const QString &itemName) {
    qDebug() << "Attempting to edit item:" << itemName;
    auto& items = menuModel->getMenuItems();
    auto itemIt = std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getName() == itemName.toStdString();
    });

    if (itemIt != items.end()) {
        MenuItemDialog dialog(menuView);
        dialog.setItem(*itemIt);
        if (dialog.exec() == QDialog::Accepted) {
            MenuItem newItem = dialog.getItem();
            menuModel->updateItem(newItem);
            saveMenuItemsToFile(Constants::MENU_FILE);
            qDebug() << "Item updated successfully. noww";
        }
    } else {
        qDebug() << "Item not found for editing:" << itemName;
    }
}

Menu* MenuController::getMenu(){
    return menuModel;
}

Menu* MenuController::getMenuItems(const QString &fileName){
    Menu* menu = new Menu();
    auto items = adapter.loadMenuItemsFromCSV(fileName.toStdString());
    for (auto& item : items) {
        menu->addItem(item);
    }
    return menu;
}
