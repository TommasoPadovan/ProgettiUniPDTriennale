#include "win_registration.h"

//gruppo con le checkbox per il sesso
QGroupBox* win_registration::sexGroup() {
    QGroupBox *groupBox = new QGroupBox();
    rbuttonM=new QRadioButton("M");
    rbuttonF=new QRadioButton("F");
    rbuttonM->setChecked(true);
    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(rbuttonM);
    vbox->addWidget(rbuttonF);
    groupBox->setLayout(vbox);
    return groupBox;
}

//gruppo con le checkbox per la tipologia di utente
QGroupBox* win_registration::typeGroup() {
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

win_registration::win_registration() {
    //scritte
    QLabel* istruzioni  =new QLabel("Crea il tuo profilo. I campi contrassegnati con * sono obbligatori.");
    QLabel* linea_testo1=new QLabel("Scegli il tuo username *");;
    QLabel* linea_testo2=new QLabel("Inserisci il tuo nome *");
    QLabel* linea_testo3=new QLabel("Inserisci il tuo cognome *");
    QLabel* linea_testo4=new QLabel("\nSelezionare il proprio sesso *");
    QLabel* linea_testo5=new QLabel("Inserisci la tua data di nascita *");
        QLabel* linea_testo5_1=new QLabel("/");
        QLabel* linea_testo5_2=new QLabel("/");
    QLabel* linea_testo6=new QLabel("Inserisci un indirizzo e-mail*");
    QLabel* linea_testo7=new QLabel("Inserisci le lingue parlate");
    QLabel* linea_testo8=new QLabel("Inserisci le esperienze professionali");
    QLabel* linea_testo9=new QLabel("Inserisci le competenze lavorative");

    //textarea
    Linea_inserimento1=new QLineEdit();
    Linea_inserimento2=new QLineEdit();
    Linea_inserimento3=new QLineEdit();
        Linea_inserimento5_1=new QLineEdit("dd");
        Linea_inserimento5_2=new QLineEdit("mm");
        Linea_inserimento5_3=new QLineEdit("yyyy");
    Linea_inserimento6=new QLineEdit();
    Linea_inserimento7=new QLineEdit();
    Linea_inserimento8=new QLineEdit();
    Linea_inserimento9=new QLineEdit();

    //buttons
    QPushButton* Avvia=new QPushButton("Avanti");
    QPushButton* Exit=new QPushButton("Esci");

    //exceptions
    inv_usn=new QLabel("##L'username non puo' contenere spazi##");      inv_usn->setVisible(false);
    exs_usn=new QLabel("##L'username e' gia' in uso##");                exs_usn->setVisible(false);
    inv_dte=new QLabel("##La data non e' valida##");                    inv_dte->setVisible(false);
    missing=new QLabel("##Campi obbligatori mancanti##");               missing->setVisible(false);



    //layouts
    QVBoxLayout* vlay=new QVBoxLayout;
    QFormLayout* flay=new QFormLayout;
    QHBoxLayout* data=new QHBoxLayout;

    data->addWidget(Linea_inserimento5_1);                           //data
    data->addWidget(linea_testo5_1);
    data->addWidget(Linea_inserimento5_2);
    data->addWidget(linea_testo5_2);
    data->addWidget(Linea_inserimento5_3);

    flay->addRow("",inv_usn);//errmsg                                //form
    flay->addRow("",exs_usn);//errmsg
    flay->addRow(linea_testo1, Linea_inserimento1);
    flay->addRow(linea_testo2, Linea_inserimento2);
    flay->addRow(linea_testo3, Linea_inserimento3);
    flay->addRow(linea_testo4,sexGroup());
    flay->addRow("",inv_dte);//errmsg
    flay->addRow(linea_testo5, data);
    flay->addRow(linea_testo6, Linea_inserimento6);
    flay->addRow(linea_testo7, Linea_inserimento7);
    flay->addRow(linea_testo8, Linea_inserimento8);
    flay->addRow(linea_testo9, Linea_inserimento9);
    flay->addRow("\nScegli il tuo tipo di utente*", typeGroup());

    vlay->addWidget(istruzioni);                                     //layout verticale generale
    vlay->addSpacing(20);
    vlay->addWidget(missing);//errmsg
    vlay->addLayout(flay);
    vlay->addSpacing(40);
    vlay->addWidget(Avvia);
    vlay->addWidget(Exit);


    //gestione finestra
    setWindowTitle("LinQedIn - Register");
    setLayout(vlay);


    //connessioni
    connect (Avvia,SIGNAL(clicked()),this,SLOT(add_user()));
    connect (Exit,SIGNAL(clicked()),this,SLOT(close_win()));

}

win_registration::~win_registration() {}



// ######################################################################################################


void win_registration::aggiungi() {
    string temp;
    temp=(Linea_inserimento1->displayText()).toStdString();             //username
    if (temp.find(' ')!=temp.npos) throw string("invalid_usn");
    username* usn=new username(temp);
    if (DB::find(*usn)) {
        delete usn;
        throw string("existing_usn");
    }

    // ###INFO###
    info* profilo=new info;
    int d,m,y;

    temp=(Linea_inserimento2->displayText()).toStdString();             //nome
    if (temp=="") throw string("missing");
    profilo->set_nome(temp);

    temp=(Linea_inserimento3->displayText()).toStdString();             //cognome
    if (temp=="") throw string("missing");
    profilo->set_cognome(temp);

    if(rbuttonM->isChecked()) profilo->set_sesso(1);                    //sesso
    else{
        if (rbuttonF->isChecked()) profilo->set_sesso(0);
    }

    d=(Linea_inserimento5_1->displayText()).toInt();                    //data
    m=(Linea_inserimento5_2->displayText()).toInt();
    y=(Linea_inserimento5_3->displayText()).toInt();
    if (d<1 || d>31 || m<1 || m>12 || y<1900 || y>2015)
        throw string("invalid_date");
    profilo->set_data_di_nascita(d,m,y);

    temp=(Linea_inserimento6->displayText()).toStdString();             //mail
    if (temp=="") throw string("missing");
    profilo->set_email(temp);


    temp=((Linea_inserimento7->displayText()).toStdString());           //lingue
    profilo->set_lingue(temp);

    temp=((Linea_inserimento8->displayText()).toStdString());           //exp_pro
    profilo->set_exp_professionali(temp);

    temp=((Linea_inserimento9->displayText()).toStdString());           //comp_lav
    profilo->set_comp_lavorative(temp);

    // ###TIPO###                   //////DA REFFARE
    rete* ret=new rete;
    if (rbuttonBasic->isChecked()) {
        utente_basic* punt=new utente_basic(usn,profilo,ret);
        DB::add_user(punt);
        DB::save();
    }
    else if (rbuttonBusiness->isChecked()) {
        utente_business* punt=new utente_business(usn,profilo,ret);
        DB::add_user(punt);
        DB::save();
    }
    else if (rbuttonExecutive->isChecked()) {
        utente_executive* punt=new utente_executive(usn,profilo,ret);
        DB::add_user(punt);
        DB::save();
    }
}


void win_registration::add_user() {
    inv_usn->setVisible(false);
    exs_usn->setVisible(false);
    inv_dte->setVisible(false);
    missing->setVisible(false);
    try {
        bool s;
        if (rbuttonM->isChecked()) s=true;
        else if (rbuttonF->isChecked()) s=false;
        utente* toinsert=DB::candidato(
                    (Linea_inserimento1->displayText()).toStdString(),
                    (Linea_inserimento2->displayText()).toStdString(),
                    (Linea_inserimento3->displayText()).toStdString(),
                    (Linea_inserimento5_1->displayText()).toInt(),
                    (Linea_inserimento5_2->displayText()).toInt(),
                    (Linea_inserimento5_3->displayText()).toInt(),
                    (Linea_inserimento6->displayText()).toStdString(),
                    s,
                    (Linea_inserimento7->displayText()).toStdString(),
                    (Linea_inserimento8->displayText()).toStdString(),
                    (Linea_inserimento9->displayText()).toStdString());
        utente* punt;
        if (rbuttonBasic->isChecked()) punt=new utente_basic(toinsert);
        else if (rbuttonBusiness->isChecked()) punt=new utente_business(toinsert);
        else if (rbuttonExecutive->isChecked()) punt=new utente_executive(toinsert);
        DB::add_user(punt);
        DB::save();
        close_win();
    }
    catch (string err) {
        if (err=="invalid_usn") inv_usn->setVisible(true);
        else if (err=="existing_usn") exs_usn->setVisible(true);
        else if (err=="missing") missing->setVisible(true);
        else if (err=="invalid_date") inv_dte->setVisible(true);
    }
}

void win_registration::close_win() {delete this;}





















