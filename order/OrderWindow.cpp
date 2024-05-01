#include "OrderWindow.h"
#include <QVBoxLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>

OrderWindow::OrderWindow(Order *order, QWidget *parent)
    : QMainWindow(parent), orderListView(new OrderListView(this))
{
    setWindowTitle(tr("Order Management"));

    // Menu bar setup
    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenu = menuBar->addMenu(tr("&File"));
    QAction *exitAction = fileMenu->addAction(tr("E&xit"));
    connect(exitAction, &QAction::triggered, this, &OrderWindow::close);

    // Central widget setup
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    orderListView->setOrder(order);
    layout->addWidget(orderListView);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    setMenuBar(menuBar);
}
