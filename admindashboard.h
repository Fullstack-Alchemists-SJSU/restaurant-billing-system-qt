#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QMainWindow>

namespace Ui {
class AdminDashboard;
}

class AdminDashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminDashboard(QWidget *parent = nullptr);
    ~AdminDashboard();
signals:
    void backNavigationRequested();

private slots:
    void on_buttonLogout_clicked();

private:
    Ui::AdminDashboard *ui;
};

#endif // ADMINDASHBOARD_H
