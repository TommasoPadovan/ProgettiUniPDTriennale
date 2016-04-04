#include "mainwindow.h"


MainWindow::MainWindow() {
    setWindowTitle("LinQedIn");
    QPushButton* Login=new QPushButton("Login");
    UsernameLogin=new QLineEdit(" Username");
    QPushButton* Registration=new QPushButton("Register");
    QPushButton* AdminLogin=new QPushButton("Accedi come amministratore");
    QPushButton* Exit=new QPushButton("Chiudi");
    NoUtente=new QLabel("Username inesistente");
    NoUtente->setVisible(false);
    QLabel* label1 = new QLabel("Benvenuto in LinQedin!\nAccedi con il tuo account o registrati");

    QVBoxLayout* layout=new QVBoxLayout;
    layout->addWidget(label1);
    layout->addSpacing(20);
    layout->addWidget(NoUtente);
    layout->addWidget(UsernameLogin);//errmsg
    layout->addWidget(Login);
    layout->addWidget(Registration);
    layout->addSpacing(40);
    layout->addWidget(AdminLogin);
    layout->addWidget(Exit);

    QWidget* window = new QWidget;
    window->setLayout(layout);
    setCentralWidget(window);



    connect (Login, SIGNAL(clicked()), this, SLOT(goto_user()));
    connect (Registration, SIGNAL(clicked()), this, SLOT(goto_registration()));
    connect (AdminLogin, SIGNAL(clicked()), this, SLOT(goto_admin()));
    connect (Exit,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow() {}





void MainWindow::goto_registration() {
    win_registration* wr=new win_registration();
    connect(wr, SIGNAL(destroyed()), this, SLOT(show()));
    this->hide();
    wr->show();
}

void MainWindow::goto_user() {
    NoUtente->setVisible(false);
    username us((UsernameLogin->displayText()).toStdString());
    utente* punt(DB::find(us));
    if(punt){
        win_user* fu = new win_user(punt);
        connect(fu,SIGNAL(destroyed()),this,SLOT(show()));  //alla distruzione la finestra principale torna visibile
        this->hide();
        fu->show();}
    else NoUtente->setVisible(true);
}

void MainWindow::goto_admin() {
    win_admin* wa=new win_admin();
    connect(wa, SIGNAL(destroyed()), this, SLOT(show()));
    this->hide();
    wa->show();
}
