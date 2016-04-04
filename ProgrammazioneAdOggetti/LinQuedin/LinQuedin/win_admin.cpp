#include "win_admin.h"


QGroupBox* win_admin::typeGroup() {
    QGroupBox *groupBox = new QGroupBox();
    rbuttonBasic=new QRadioButton("Basic");
    rbuttonBusiness=new QRadioButton("Business");
    rbuttonExecutive=new QRadioButton("Executive");
    rbuttonBasic->setChecked(true);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(rbuttonBasic);
    vbox->addWidget(rbuttonBusiness);
    vbox->addWidget(rbuttonExecutive);
    groupBox->setLayout(vbox);
    return groupBox;
}
QGroupBox* win_admin::typeGroup2() {
    QGroupBox *groupBox = new QGroupBox();
    rbuttonBasic2=new QRadioButton("Basic");
    rbuttonBusiness2=new QRadioButton("Business");
    rbuttonExecutive2=new QRadioButton("Executive");
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(rbuttonBasic2);
    vbox->addWidget(rbuttonBusiness2);
    vbox->addWidget(rbuttonExecutive2);
    groupBox->setLayout(vbox);
    return groupBox;
}


win_admin::win_admin() {
    setWindowTitle("LinQedIn - Admin");
    QVBoxLayout* mainVlay=new QVBoxLayout;
    QHBoxLayout* mainHlay=new QHBoxLayout;

    // ########## PARTE1 ########## INSERIMENTO UTENTE ##########
    QVBoxLayout* vlay1=new QVBoxLayout;
    QFormLayout* flay1=new QFormLayout;

    QLabel* title1=new QLabel("INSERIMENTO UTENTE");
    vlay1->addWidget(title1);
    vlay1->addSpacing(10);
    vlay1->addLayout(flay1);

    //form
    linea_inserimento1=new QLineEdit();                                 // dichiarazione textarea
    linea_inserimento2=new QLineEdit();
    linea_inserimento3=new QLineEdit();
    linea_inserimento4=new QLineEdit();
    inv_usn=new QLabel("##L'username non puo' contenere spazi##");      inv_usn->setVisible(false);     //errori
    exs_usn=new QLabel("##L'username e' gia' in uso##");                exs_usn->setVisible(false);
    missing=new QLabel("##Campi obbligatori mancanti##");               missing->setVisible(false);
    flay1->addRow(exs_usn);                                          // disegno form
    flay1->addRow(inv_usn);
    flay1->addRow(missing);
    flay1->addRow("Username: ",linea_inserimento1);
    flay1->addRow("Nome: ",linea_inserimento2);
    flay1->addRow("Cognome: ",linea_inserimento3);
    flay1->addRow("Mail: ",linea_inserimento4);
    flay1->addRow("Tipo utenza: ",typeGroup());


    //bottone aggiungi
    QPushButton* aggiungi=new QPushButton("Aggiungi");
    connect (aggiungi, SIGNAL(clicked()), this, SLOT(add()));
    vlay1->addSpacing(20);
    vlay1->addWidget(aggiungi);


    vlay1->setAlignment(Qt::AlignTop);
    mainHlay->addLayout(vlay1);
    mainHlay->addSpacing(20);


    // ########## PARTE2 ########## TUTTI GLI UTENTI ##########
    //lista di tutti gli utenti
    vector<utente*>* v=DB::get_db();
    vector<utente*>::iterator it=v->begin();
    all_users=new QListWidget;
    for (;it!=v->end();++it) {
        all_users->addItem(QString::fromStdString((*it)->get_username()->get_login()));
    }
    QVBoxLayout* vlay2=new QVBoxLayout;
    QLabel* title2=new QLabel("TUTTI GLI UTENTI");
    vlay2->addWidget(title2);
    vlay2->addSpacing(20);
    vlay2->addWidget(all_users);

    //AZIONI
    //vedi selezionato sia con tasto che doppioclick
    QPushButton* visualizza=new QPushButton("Visualizza Selezionato");
    connect (visualizza, SIGNAL(clicked()), this, SLOT(show_from_allusers()));
    connect (all_users, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(show_from_allusers()));
    vlay2->addWidget(visualizza);

    //elimina selezionato
    QPushButton* cancella=new QPushButton("Cancella Selezionato");
    connect (cancella, SIGNAL(clicked()), this, SLOT(del_from_allusers()));
    vlay2->addWidget(cancella);

    //cambia tipologia
    QPushButton* cambia_tipologia=new QPushButton("Cambia\nTipologia\nSelezionato");
    connect (cambia_tipologia, SIGNAL(clicked()), this, SLOT(ch_from_allusers()));
    connect (all_users, SIGNAL(itemSelectionChanged()), this, SLOT(modify_type_allusers()));
    QHBoxLayout* hlay2=new QHBoxLayout;
    hlay2->addWidget(typeGroup2());
    hlay2->addWidget(cambia_tipologia);
    vlay2->addLayout(hlay2);

    vlay2->setAlignment(Qt::AlignTop);
    mainHlay->addLayout(vlay2);
    mainHlay->addSpacing(20);


    // ########## PARTE3 ########## RICERCA UTENTI ##########
    QVBoxLayout* vlay3=new QVBoxLayout;
    QLabel* title3=new QLabel("RICERCA UTENTI");
    QGridLayout* glay3=new QGridLayout;

    linea_ricerca1=new QLineEdit;
    QPushButton* cerca_username=new QPushButton("per Username");
    connect (cerca_username, SIGNAL(clicked()), this, SLOT(find_username()));
    linea_ricerca2=new QLineEdit;
    QPushButton* cerca_nome=new QPushButton("per Nome");
    connect (cerca_nome, SIGNAL(clicked()), this, SLOT(find_name()));
    linea_ricerca3=new QLineEdit;
    QPushButton* cerca_cognome=new QPushButton("per Cognome");
    connect (cerca_cognome, SIGNAL(clicked()), this, SLOT(find_surname()));

    found_users=new QListWidget;
    connect (all_users, SIGNAL(itemSelectionChanged()), found_users, SLOT(clearSelection()));
    connect (found_users, SIGNAL(itemSelectionChanged()), this, SLOT(send_to_main_list()));
    connect (found_users, SIGNAL(itemDoubleClicked(QListWidgetItem*)), all_users, SIGNAL(itemDoubleClicked(QListWidgetItem*)));

    not_found=new QLabel("Nessun Utente Trovato"); not_found->setVisible(false);


    vlay3->addWidget(title3);
    vlay3->addSpacing(20);
    vlay3->addLayout(glay3);
    glay3->addWidget(linea_ricerca1,0,0);
    glay3->addWidget(cerca_username,0,1);
    glay3->addWidget(linea_ricerca2,1,0);
    glay3->addWidget(cerca_nome,1,1);
    glay3->addWidget(linea_ricerca3,2,0);
    glay3->addWidget(cerca_cognome,2,1);
    vlay3->addSpacing(20);
    vlay3->addWidget(not_found);
    vlay3->addWidget(found_users);

    vlay3->setAlignment(Qt::AlignTop);
    mainHlay->addLayout(vlay3);





    //fine finestra
    QPushButton* Exit=new QPushButton("Chiudi");
    connect (Exit, SIGNAL(clicked()), this, SLOT(close_win()));

    mainVlay->addLayout(mainHlay);
    mainVlay->addSpacing(20);
    mainVlay->addWidget(Exit);

    setLayout(mainVlay);
}

win_admin::~win_admin() {}





// #####################SLOT#####################
void win_admin::close_win() {delete this;}


// #PARTE1#
void win_admin::add() {
    inv_usn->setVisible(false);
    exs_usn->setVisible(false);
    missing->setVisible(false);
    try {
        utente* toinsert=DB::candidato((linea_inserimento1->displayText()).toStdString(),
                                      (linea_inserimento2->displayText()).toStdString(),
                                      (linea_inserimento3->displayText()).toStdString(),
                                      1,1,1900,
                                      (linea_inserimento4->displayText()).toStdString());
        utente* punt;
        if (rbuttonBasic->isChecked()) punt=new utente_basic(toinsert);
        else if (rbuttonBusiness->isChecked()) punt=new utente_business(toinsert);
        else if (rbuttonExecutive->isChecked()) punt=new utente_executive(toinsert);
        DB::add_user(punt);
        DB::save();
        all_users->addItem(QString::fromStdString(punt->get_username()->get_login()));      //lo aggiungo graficamente
    }
    catch (string err) {
        if (err=="invalid_usn") inv_usn->setVisible(true);
        else if (err=="existing_usn") exs_usn->setVisible(true);
        else if (err=="missing") missing->setVisible(true);
    }

}

// #PARTE2#
utente* win_admin::get_selected_user(QListWidget* qlw) const {
    vector<utente*>* v=DB::get_db();
    utente* aux=(*v)[qlw->currentRow()];
    return aux;
}

void win_admin::show_from_allusers() {
    if (all_users->selectedItems().count()>0) {
        win_view* ww=new win_view(get_selected_user(all_users));
        ww->show();
    }
}


void win_admin::del_from_allusers() {
    if (all_users->selectedItems().count()>0) {
        DB::rem_user(get_selected_user(all_users));
        all_users->takeItem(all_users->currentRow());   //lo cancello anche graficamente
    }
}


void win_admin::ch_from_allusers() {
    if (all_users->selectedItems().count()>0) {
        utente* olduser=get_selected_user(all_users);
        utente* newuser;
        if (rbuttonBasic2->isChecked()) newuser=new utente_basic(olduser);
        else if (rbuttonBusiness2->isChecked()) newuser=new utente_business(olduser);
        else if (rbuttonExecutive2->isChecked()) newuser=new utente_executive(olduser);
        DB::rem_user(olduser);
        DB::add_user(newuser);
        all_users->takeItem(all_users->currentRow());                                          //lo cancello graficamente
        all_users->addItem(QString::fromStdString(newuser->get_username()->get_login()));      //lo aggiungo graficamente
    }
}


void win_admin::modify_type_allusers() {
    utente* s=get_selected_user(all_users);
    rbuttonBasic2->setChecked(false);
    rbuttonBusiness2->setChecked(false);
    rbuttonExecutive2->setChecked(false);
    if (dynamic_cast<utente_executive*>(s)) rbuttonExecutive2->setChecked(true);
    else if (dynamic_cast<utente_business*>(s)) rbuttonBusiness2->setChecked(true);
    else if (dynamic_cast<utente_basic*>(s)) rbuttonBasic2->setChecked(true);

}


// #PARTE3#
void win_admin::find_username() {
    not_found->setVisible(false);
    string strusn=(linea_ricerca1->displayText()).toStdString();
    username usn=username(strusn);
    utente* ut=DB::find(usn);
    while(found_users->count()>0) found_users->takeItem(0);     //svuoto la lista
    if (ut) found_users->addItem(QString::fromStdString(ut->get_username()->get_login()));
    else not_found->setVisible(true);
}

void win_admin::find_name() {
    not_found->setVisible(false);
    QString Qnome=linea_ricerca2->displayText();
    list<utente*>* lu=DB::find_nome(Qnome);

    while(found_users->count()>0) found_users->takeItem(0);     //svuoto la lista
    list<utente*>::const_iterator it=lu->begin();
    if (lu->begin()!=lu->end())
        for (;it!=lu->end();++it)
            found_users->addItem(QString::fromStdString((*it)->get_username()->get_login()));
    else
        not_found->setVisible(true);
}

void win_admin::find_surname() {
    not_found->setVisible(false);
    QString Qcognome=linea_ricerca3->displayText();
    list<utente*>* lu=DB::find_cognome(Qcognome);

    while(found_users->count()>0) found_users->takeItem(0);     //svuoto la lista
    list<utente*>::const_iterator it=lu->begin();
    if (lu->begin()!=lu->end())
        for (;it!=lu->end();++it)
            found_users->addItem(QString::fromStdString((*it)->get_username()->get_login()));
    else
        not_found->setVisible(true);
}

void win_admin::send_to_main_list() {
    QString usn=found_users->currentItem()->text();
    int i=0;
    while (i<all_users->count() && all_users->item(i)->text()!=usn) {
        ++i;
    }
    if (i<all_users->count()) all_users->setCurrentRow(i);
}










