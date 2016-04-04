#ifndef WIN_ADMIN_H
#define WIN_ADMIN_H

#include <typeinfo>
#include <QString>
#include <QWidget>
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QRadioButton>
#include <QGroupBox>
#include "win_view.h"
#include "db.h"
#include "utente.h"

class win_admin : public QWidget{
    Q_OBJECT
private:
    QListWidget* all_users;
    QListWidget* found_users;

    QLineEdit* linea_inserimento1,* linea_inserimento2,* linea_inserimento3,* linea_inserimento4;
    QLineEdit* linea_ricerca1,* linea_ricerca2,* linea_ricerca3;
    QRadioButton* rbuttonBasic,* rbuttonBusiness,* rbuttonExecutive;
    QRadioButton* rbuttonBasic2,* rbuttonBusiness2,* rbuttonExecutive2;

    QLabel* inv_usn;
    QLabel* exs_usn;
    QLabel* inv_dte;
    QLabel* missing;
    QLabel* not_found;

    QGroupBox* typeGroup();
    QGroupBox* typeGroup2();


    utente* get_selected_user(QListWidget*) const;

public:
    win_admin();
    ~win_admin();

public slots:
    void close_win();

    void add();

    void show_from_allusers();
    void del_from_allusers();
    void ch_from_allusers();
    void modify_type_allusers();

    void find_username();
    void find_name();
    void find_surname();
    void send_to_main_list();
};

#endif // WIN_ADMIN_H
