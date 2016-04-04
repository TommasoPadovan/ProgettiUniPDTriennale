#include "win_user.h"

QGroupBox* win_user::sexGroup() {
    QGroupBox *groupBox = new QGroupBox();
    rbuttonM=new QRadioButton("M");
    rbuttonF=new QRadioButton("F");
    QVBoxLayout *vbox = new QVBoxLayout;
    if (client->get_info()->get_sesso()) rbuttonM->setChecked(true);
    else rbuttonF->setChecked(true);
    vbox->addWidget(rbuttonM);
    vbox->addWidget(rbuttonF);
    groupBox->setLayout(vbox);
    return groupBox;
}

win_user::win_user(utente* ut) : client(ut) {
    string nickname=ut->get_username()->get_login();
    setWindowTitle(QString::fromStdString("LinQedIn - "+nickname));
    QVBoxLayout* mainVlay=new QVBoxLayout;
    QHBoxLayout* mainHlay=new QHBoxLayout;
    mainVlay->addLayout(mainHlay);

    // ########## PARTE1 ########## AGGIORNAMENTO PROFILO ##########
    QLabel* title1=new QLabel("AGGIORNAMENTO PROFILO");
    linea1=new QLineEdit(client->get_info()->get_nome());
    linea2=new QLineEdit(client->get_info()->get_cognome());
    linea3_1=new QLineEdit(QString::number(client->get_info()->get_data_di_nascita().d));
    linea3_2=new QLineEdit(QString::number(client->get_info()->get_data_di_nascita().m));
    linea3_3=new QLineEdit(QString::number(client->get_info()->get_data_di_nascita().y));
    linea4=new QLineEdit(client->get_info()->get_email());
    linea5=new QLineEdit(client->get_info()->get_lingue());
    linea6=new QLineEdit(client->get_info()->get_exp_professionali());
    linea7=new QLineEdit(client->get_info()->get_comp_lavorative());
    missing=new QLabel("##Campi obbligatori mancanti##");   missing->setVisible(false);
    inv_dte=new QLabel("##La data non e' valida##");        inv_dte->setVisible(false);

    QPushButton* modifica=new QPushButton("Modifica Profilo");
    connect (modifica, SIGNAL(clicked()), this, SLOT(change_profile()));


    QLabel* dateSeparator=new QLabel("/");
    QHBoxLayout* datelay1=new QHBoxLayout;
    datelay1->addWidget(linea3_1);
    datelay1->addWidget(dateSeparator);
    datelay1->addWidget(linea3_2);
    datelay1->addWidget(dateSeparator);
    datelay1->addWidget(linea3_3);

    QFormLayout* flay1=new QFormLayout;
    flay1->addRow("Nome: ",linea1);
    flay1->addRow("Cognome: ",linea2);
    flay1->addRow("Sesso: ",sexGroup());
    flay1->addRow("",inv_dte);
    flay1->addRow("Data di Nascita: ",datelay1);
    flay1->addRow("E-Mail: ",linea4);
    flay1->addRow("Lingue Parlate",linea5);
    flay1->addRow("Esperienze Professionali",linea6);
    flay1->addRow("Competenze Lavorative",linea7);

    QVBoxLayout* vlay1=new QVBoxLayout;
    vlay1->addWidget(title1);
    vlay1->addSpacing(20);
    vlay1->addWidget(missing);
    vlay1->addLayout(flay1);
    vlay1->addSpacing(20);
    vlay1->addWidget(modifica);



    // ########## PARTE2 ########## LISTA AMICI ##########
    QLabel* title2=new QLabel("LISTA AMICI");
    rete* network=client->get_rete();
    std::vector<utente*>* vec=DB::find_rete(network);
    contatti=new QListWidget;
    std::vector<utente*>::const_iterator it=vec->begin();
    for (;it!=vec->end();++it) {
        contatti->addItem(QString::fromStdString( (*it)->get_username()->get_login() ));
    }

    QPushButton* rimuovi=new QPushButton("Rimuovi Contatto");
    connect (rimuovi, SIGNAL(clicked()), this, SLOT(rem_contatto()));
    QPushButton* vedi_contatto=new QPushButton("Visualizza Contatto");
    connect (vedi_contatto, SIGNAL(clicked()), this, SLOT(view_friend()));
    connect (contatti, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(view_friend()));



    QVBoxLayout* vlay2=new QVBoxLayout;
    vlay2->addWidget(title2);
    vlay2->addSpacing(20);
    vlay2->addWidget(contatti);
    vlay2->addSpacing(20);
    vlay2->addWidget(rimuovi);
    vlay2->addWidget(vedi_contatto);




    // ########## PARTE3 ########## RICERCA ##########
    QVBoxLayout* vlay3=new QVBoxLayout;
    //questo controllo è necessario in quanto in un futuro si potrebbe espandere la gerarchia con un atro ramo
    //non derivato da utente_basic, ad esempio "utente a privilegi ridotti" che potrebbe non essere ablitato a
    //nessun tipo di ricerca
    utente* punt=dynamic_cast<utente_basic*>(client);
    if (punt) {
        QLabel* title3=new QLabel("RICERCA UTENTI");
        ricerca1=new QLineEdit;
        ricerca2=new QLineEdit;
        ricerca3=new QLineEdit;
        not_found=new QLabel("Nessun Utente Trovato"); not_found->setVisible(false);
        duplicato=new QLabel("Siete gia' contatti"); duplicato->setVisible(false);

        found_users=new QListWidget;
        QPushButton* cerca_username =new QPushButton("per Username");
        connect (cerca_username, SIGNAL(clicked()), this, SLOT(find_username()));
        QPushButton* cerca_nome =new QPushButton("per Nome");
        connect (cerca_nome, SIGNAL(clicked()), this, SLOT(find_name()));
        QPushButton* cerca_cognome =new QPushButton("per Cognome");
        connect (cerca_cognome, SIGNAL(clicked()), this, SLOT(find_surname()));

        QGridLayout* glay3=new QGridLayout;
        glay3->addWidget(ricerca1,0,0);          glay3->addWidget(cerca_username,0,1);
        glay3->addWidget(ricerca2,1,0);          glay3->addWidget(cerca_nome,1,1);
        glay3->addWidget(ricerca3,2,0);          glay3->addWidget(cerca_cognome,2,1);

        QPushButton* add=new QPushButton("Aggiungi Contatto");
        connect (add, SIGNAL(clicked()), this, SLOT(add_contatto()));

        vlay3->addWidget(title3);
        vlay3->addSpacing(20);
        vlay3->addLayout(glay3);
        vlay3->addSpacing(20);
        vlay3->addWidget(not_found);
        vlay3->addWidget(duplicato);
        vlay3->addWidget(found_users);
        vlay3->addSpacing(20);
        vlay3->addWidget(add);

        punt=dynamic_cast<utente_business*>(punt);
        //se l'utente chiamante ha privilegi sufficienti aggiungo il bottone per visualizzare gli utenti dal db
        //non è necessario dynamiccastare anche ad executive perché l'unica differenza sta nella visualizzazione
        //del profilo, e quindi questo contrllo è delegato alla finestra di visualizzazione
        if (punt) {
            QPushButton* vedi_non_contatto=new QPushButton("Visualizza Contatto");
            connect (vedi_non_contatto, SIGNAL(clicked()), this, SLOT(view_foreign()));
            connect (found_users, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(view_foreign()));
            vlay3->addWidget(vedi_non_contatto);
        }
    }





    //fine finestra
    vlay1->setAlignment(Qt::AlignTop);
    vlay2->setAlignment(Qt::AlignTop);
    vlay3->setAlignment(Qt::AlignTop);
    mainHlay->addLayout(vlay1);
    mainHlay->addSpacing(20);
    mainHlay->addLayout(vlay2);
    mainHlay->addSpacing(20);
    mainHlay->addLayout(vlay3);
    mainVlay->addSpacing(20);
    QPushButton* exit=new QPushButton("Chiudi");
    connect (exit, SIGNAL(clicked()), this, SLOT(close_win()));
    mainVlay->addWidget(exit);
    setLayout(mainVlay);


}

win_user::~win_user() {}







// ################################# SLOT #################################
void win_user::close_win() {delete this; }

// ### PARTE1 ###
utente* win_user::get_selected_user(QListWidget* qlw) const {
    vector<utente*>* v=DB::find_rete(client->get_rete());
    return (*v)[qlw->currentRow()];

}

void win_user::change_profile() {
    missing->setVisible(false);
    inv_dte->setVisible(false);
    bool s;
    if (rbuttonM->isChecked()) s=true;
    else if (rbuttonF->isChecked()) s=false;
    try {
        client->aggiorna_profilo(
                (linea1->displayText()).toStdString(),
                (linea2->displayText()).toStdString(),
                (linea3_1->displayText()).toInt(),
                (linea3_2->displayText()).toInt(),
                (linea3_3->displayText()).toInt(),
                s,
                (linea4->displayText()).toStdString(),
                (linea5->displayText()).toStdString(),
                (linea6->displayText()).toStdString(),
                (linea7->displayText()).toStdString());
        DB::save();
    }
    catch (string err) {
        if (err=="missing") missing->setVisible(true);
        else if (err=="invalid_date") inv_dte->setVisible(true);
    }
}

// ### PARTE2 ###
void win_user::rem_contatto() {
    if (contatti->selectedItems().count()>0) {
        utente* markfordeath=get_selected_user(contatti);
        client->get_rete()->rem_contatto(markfordeath->get_username()->get_login());
        contatti->takeItem(contatti->currentRow());     //cancello graficamente
        DB::save();
    }
}

void win_user::view_friend() {
    if (contatti->selectedItems().count()>0) {
        win_view* wv=new win_view(get_selected_user(contatti),client);
        wv->show();
    }
}


// ### PARTE3 ###
void win_user::find_username() {
    not_found->setVisible(false);
    string strusn=(ricerca1->displayText()).toStdString();
    username usn=username(strusn);
    utente* ut=DB::find(usn);
    while(found_users->count()>0) found_users->takeItem(0);     //svuoto la lista
    if (ut) found_users->addItem(QString::fromStdString(ut->get_username()->get_login()));
    else not_found->setVisible(true);
}

void win_user::find_name() {
    not_found->setVisible(false);
    QString Qnome=ricerca2->displayText();
    list<utente*>* lu=DB::find_nome(Qnome);

    while(found_users->count()>0) found_users->takeItem(0);     //svuoto la lista
    list<utente*>::const_iterator it=lu->begin();
    if (lu->begin()!=lu->end())
        for (;it!=lu->end();++it)
            found_users->addItem(QString::fromStdString((*it)->get_username()->get_login()));
    else
        not_found->setVisible(true);
}

void win_user::find_surname() {
    not_found->setVisible(false);
    QString Qcognome=ricerca3->displayText();
    list<utente*>* lu=DB::find_cognome(Qcognome);

    while(found_users->count()>0) found_users->takeItem(0);     //svuoto la lista
    list<utente*>::const_iterator it=lu->begin();
    if (lu->begin()!=lu->end())
        for (;it!=lu->end();++it)
            found_users->addItem(QString::fromStdString((*it)->get_username()->get_login()));
    else
        not_found->setVisible(true);
}

void win_user::add_contatto() {
    if (found_users->selectedItems().count()>0) {
        duplicato->setVisible(false);
        string usnlogin=(found_users->currentItem()->text()).toStdString();
        if (client->get_rete()->add_contatto(username(usnlogin))) {
            contatti->addItem(QString::fromStdString(usnlogin));
            DB::save();
        }
        else duplicato->setVisible(true);
    }

}

void win_user::view_foreign() {
    if (found_users->selectedItems().count()>0) {
        win_view* wv=new win_view(get_selected_user(found_users),client);
        wv->show();
    }
}

