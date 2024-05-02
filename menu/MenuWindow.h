#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "MenuController.h"
#include "MenuListView.h"
#include "Menu.h"

class MenuWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MenuWindow(Menu* menu, QWidget *parent = nullptr);
private:
    MenuListView* menuListView;
    MenuController* menuController;
};

#endif // MENUWINDOW_H
