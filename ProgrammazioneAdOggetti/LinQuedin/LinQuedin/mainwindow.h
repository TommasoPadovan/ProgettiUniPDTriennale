#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include "win_registration.h"
#include "win_admin.h"
#include "win_user.h"

#include "win_view.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    QLineEdit* UsernameLogin;
    QLabel* NoUtente;
public:
    //explicit MainWindow(QWidget *parent = 0);
    MainWindow();
    ~MainWindow();

public slots:
    void goto_registration();
    void goto_user();
    void goto_admin();
};

#endif // MAINWINDOW_H
