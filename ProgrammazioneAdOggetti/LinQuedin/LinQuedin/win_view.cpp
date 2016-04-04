#include "win_view.h"

win_view::win_view(utente* ut, utente* ch) : usr(ut), chiamante(ch) {
    setWindowTitle(QString::fromStdString(usr->get_username()->get_login()));

    //scritte
    QLabel* riga1=new QLabel("Nome: ");
    QLabel* riga2=new QLabel("Cognome: ");
    QLabel* riga3=new QLabel("Sesso: ");
    QLabel* riga4=new QLabel("Data: ");
    QLabel* riga5=new QLabel("Email: ");
    QLabel* riga6=new QLabel("Lingue parlate: ");
    QLabel* riga7=new QLabel("Esperienze Professionali: ");
    QLabel* riga8=new QLabel("Competente Lavorative: ");


    //cose pescate
    QLabel* header=new QLabel(QString::fromStdString("Profilo di: "+usr->get_username()->get_login()));
    QLabel* nome=new QLabel(usr->get_info()->get_nome());
    QLabel* cognome=new QLabel(usr->get_info()->get_cognome());
    bool s=usr->get_info()->get_sesso();
        QLabel* sex;
        if (s) sex=new QLabel("Maschile");
        else sex=new QLabel("Femminile");

    int d=usr->get_info()->get_data_di_nascita().d;
    int m=usr->get_info()->get_data_di_nascita().m;
    int y=usr->get_info()->get_data_di_nascita().y;
    string temp;
    std::ostringstream convert;
    convert<<d;
    temp=convert.str();
    convert.str("");
    convert.clear();
    convert<<m;
    temp+="/"+convert.str();
    convert.str("");
    convert.clear();
    convert<<y;
    temp+="/"+convert.str();
    QLabel* date=new QLabel(QString::fromStdString(temp));

    QLabel* mail=new QLabel(usr->get_info()->get_email());
    QLabel* lingue=new QLabel(usr->get_info()->get_lingue());
    QLabel* exppro=new QLabel(usr->get_info()->get_exp_professionali());
    QLabel* comlav=new QLabel(usr->get_info()->get_comp_lavorative());

    //layout
    QGridLayout* glay=new QGridLayout;
    glay->addWidget(riga1,1,0);                   glay->addWidget(nome,1,1);
    glay->addWidget(riga2,2,0);                   glay->addWidget(cognome,2,1);
    glay->addWidget(riga3,3,0);                   glay->addWidget(sex,3,1);
    glay->addWidget(riga4,4,0);                   glay->addWidget(date,4,1);
    glay->addWidget(riga5,5,0);                   glay->addWidget(mail,5,1);
    glay->addWidget(riga6,6,0);                   glay->addWidget(lingue,6,1);
    glay->addWidget(riga7,7,0);                   glay->addWidget(exppro,7,1);
    glay->addWidget(riga8,8,0);                   glay->addWidget(comlav,8,1);

    QVBoxLayout* vlay=new QVBoxLayout;
    vlay->addWidget(header);
    vlay->addSpacing(20);
    vlay->addLayout(glay);

    //per gli executive
    if (dynamic_cast<utente_executive*>(chiamante)) {           //questa parte è dedicata a chi ha privilegi uguali (o eventualmente
        QLabel* labelrete = new QLabel("Rete dei contatti:");   // superiori) ad "executive", quindi sono costretto ad utilizzare
        QListWidget* listarete = new QListWidget();             // un cast dinamico per verificare che l'utente in questione sia
                                                                // o meno executive
        list<username>::const_iterator it=usr->get_rete()->get_rete()->begin();
        for (;it!=usr->get_rete()->get_rete()->end();++it) {
            listarete->addItem(QString::fromStdString(it->get_login()));
        }

        vlay->addSpacing(20);
        vlay->addWidget(labelrete);
        vlay->addWidget(listarete);

    }


    QPushButton* Exit=new QPushButton("Chiudi");
    connect (Exit, SIGNAL(clicked()), this, SLOT(close_win()));
    vlay->addSpacing(20);
    vlay->addWidget(Exit);

    setLayout(vlay);
}




win_view::~win_view() {}

void win_view::close_win() {delete this;}
