#ifndef WIN_VIEW_H
#define WIN_VIEW_H

#include <sstream>
#include <QObject>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QGridLayout>
#include "db.h"
#include "utente.h"

class win_view : public QWidget {
    Q_OBJECT
private:
    utente* usr;
    utente* chiamante;
public:
    win_view(utente*,utente* =new utente_executive());
    ~win_view();

public slots:
    void close_win();
};

#endif // WIN_VIEW_H
