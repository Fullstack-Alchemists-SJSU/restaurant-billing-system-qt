#include "MenuWindow.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include "MenuController.h"

MenuWindow::MenuWindow(Menu* menu, QWidget *parent)
    : QMainWindow(parent), menuListView(new MenuListView(this)), menuController(new MenuController(this)) {
    setWindowTitle(tr("Menu Management"));

    menuController->setMenuModel(menu);
    menuController->setView(menuListView);
    menuController->loadMenuItemsFromFile("/Users/vijithagunta/Vijitha Masters Work/MSSE Sem2/cmpe202/restaurant-billing-system-qt/db/menuitems.csv");

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
}
