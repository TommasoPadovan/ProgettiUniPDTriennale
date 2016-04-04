#ifndef WIN_USER_H
#define WIN_USER_H

#include <vector>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QRadioButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include "utente.h"
#include "db.h"
#include "win_view.h"

class win_user : public QWidget {
    Q_OBJECT
private:
    utente* client;

    QLineEdit
        * linea1,
        * linea2,
        * linea3_1,* linea3_2,* linea3_3,
        * linea4,
        * linea5,
        * linea6,
        * linea7;
    QRadioButton* rbuttonM,* rbuttonF;
    QGroupBox* sexGroup();

    QListWidget* contatti;

    QLineEdit
        * ricerca1,
        * ricerca2,
        * ricerca3;
    QListWidget* found_users;


    QLabel* missing, * inv_dte;
    QLabel* not_found;
    QLabel* duplicato;



    utente* get_selected_user(QListWidget*) const;

public:
    win_user(utente*);
    ~win_user();
public slots:
    void close_win();
    void change_profile();
    void rem_contatto();
    void view_friend();
    void find_username();
    void find_name();
    void find_surname();
    void add_contatto();
    void view_foreign();
};

#endif // WIN_USER_H
