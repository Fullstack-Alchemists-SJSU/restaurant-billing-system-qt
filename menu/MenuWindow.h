#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QMainWindow>
#include "MenuListView.h"
#include "Menu.h"

class MenuWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MenuWindow(Menu* menu, QWidget *parent = nullptr);
private:
    MenuListView* menuListView;
};

#endif // MENUWINDOW_H
