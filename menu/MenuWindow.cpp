#include "MenuWindow.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "MenuController.h"

MenuWindow::MenuWindow(Menu* menu, QWidget *parent)
    : QMainWindow(parent), menuListView(new MenuListView(this)) {
    setWindowTitle(tr("Menu Management"));

    // Create a menu bar and add items
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = menuBar->addMenu(tr("&File"));
    QAction *exitAction = fileMenu->addAction(tr("E&xit"));
    connect(exitAction, &QAction::triggered, this, &MenuWindow::close);

    // Create a central widget
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Assume MenuListView has a method to accept Menu*
    menuListView->setMenu(menu);

    // Add the MenuListView to the layout
    layout->addWidget(menuListView);

    // Set the layout to the central widget and set it to be the central widget of the main window
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    // Set the menu bar
    setMenuBar(menuBar);

    MenuListView view;
    MenuController controller;

    controller.setMenuModel(menu);
    controller.setView(menuListView);
    controller.loadMenuItemsFromFile("/home/aditya-kulkarni/Projects/SJSU/CMPE202/restaurant-billing-system/db/menuitems.csv");
}