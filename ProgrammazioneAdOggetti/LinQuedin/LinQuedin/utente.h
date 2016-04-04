#ifndef UTENTE_H
#define UTENTE_H

#include "username.h"
#include "info.h"
#include "rete.h"


class utente {
private:
    username* nome_utente;
    info* profilo_utente;
    rete* rete_utente;
public:
    utente();
    utente(username*, info*, rete*);
    virtual ~utente();

    username* get_username() const;
    info* get_info() const;
    rete* get_rete() const;

    void aggiorna_profilo(
                        string,
                        string,
                        int, int, int,
                        bool,
                        string,
                        string,
                        string,
                        string);

    virtual void print(ofstream&) const;
};

ofstream& operator<< (ofstream&, utente*);

class utente_basic : public utente {
private:
public:
    utente_basic();
    utente_basic(username*, info*, rete*);
    utente_basic(utente*);
    void print(ofstream&) const;
};


class utente_business : public utente_basic {
private:
public:
    utente_business();
    utente_business(username*, info*, rete*);
    utente_business(utente*);
    void print(ofstream&) const;
};


class utente_executive : public utente_business {
private:
public:
    utente_executive();
    utente_executive(username*, info*, rete*);
    utente_executive(utente*);
    void print(ofstream&) const;
};


#endif // UTENTE_H
