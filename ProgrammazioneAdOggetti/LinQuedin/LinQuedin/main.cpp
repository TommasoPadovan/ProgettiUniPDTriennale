#include <iostream>
#include <QApplication>

#include "username.h"
#include "info.h"
#include "rete.h"
#include "utente.h"
#include "db.h"
#include "mainwindow.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    info i;
    i.set_data_di_nascita(5,7,1993);
    cout<<"Data: "
        <<i.get_data_di_nascita().d<<"/"
        <<i.get_data_di_nascita().m<<"/"
        <<i.get_data_di_nascita().y<<endl;
    ofstream OUT;

    rete r;
    r.add_contatto(username("chiape"));
    r.add_contatto(username("ano"));
    r.add_contatto(username("tette"));
    r.add_contatto(username("chiape"));
    r.add_contatto(username("poppe"));
    r.add_contatto(username("culo"));

    r.rem_contatto(username("chiape"));
    cout<<"tette: "<<r.has_user(username("tette"))<<endl;
    cout<<"chiape: "<<r.has_user(username("chiape"))<<endl;
    cout<<"super cane magic: "<<r.has_user(username("super cane magic"))<<endl;


    username t=username("tua mamma");
    utente_executive tuamamma(&t,&i,&r);

    //DB::add_user(&tuamamma);

    OUT.open("output.txt");
    OUT<<&tuamamma;
    OUT.close();



    // ########################################################################################
    QApplication a(argc, argv);
    DB::load();
    /*win_view* ww=new win_view(&tuamamma);
    ww->show();*/
    MainWindow* mw=new MainWindow();
    mw->show();


    cout<<"tutto bene pado, tutto bene"<<endl;

    return a.exec();

}
