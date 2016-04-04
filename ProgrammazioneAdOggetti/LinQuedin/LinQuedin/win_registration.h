#ifndef WIN_REGISTRATION_H
#define WIN_REGISTRATION_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QPushButton>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QGroupBox>
#include "utente.h"
#include "username.h"
#include "db.h"

class win_registration : public QWidget {
    Q_OBJECT
private:
    QLineEdit* Linea_inserimento1,* Linea_inserimento2,* Linea_inserimento3;
    QLineEdit* Linea_inserimento5_1,* Linea_inserimento5_2,* Linea_inserimento5_3;
    QLineEdit* Linea_inserimento6,* Linea_inserimento7,* Linea_inserimento8,* Linea_inserimento9;

    QRadioButton* rbuttonBasic,* rbuttonBusiness,* rbuttonExecutive;
    QGroupBox* typeGroup();

    QRadioButton* rbuttonM;
    QRadioButton* rbuttonF;
    QGroupBox* sexGroup();

    void aggiungi();

    QLabel* inv_usn;
    QLabel* exs_usn;
    QLabel* inv_dte;
    QLabel* missing;

public:
    win_registration();
    ~win_registration();

public slots:
    void add_user();
    void close_win();
};

#endif // WIN_REGISTRATION_H
