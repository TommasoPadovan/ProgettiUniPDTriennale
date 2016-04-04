#include "utente.h"
#include <typeinfo>

using std::endl;

// UTENTE //
utente::utente() {rete_utente=new rete;}
utente::utente(username* u, info* i, rete* r) : nome_utente(u), profilo_utente(i), rete_utente(r) {}
utente::~utente() {
    delete nome_utente;
    delete profilo_utente;
    delete rete_utente;
}

username* utente::get_username() const {return nome_utente;}
info* utente::get_info() const {return profilo_utente;}
rete* utente::get_rete() const {return rete_utente;}

void utente::print(ofstream& ofs) const {
    ofs<<"<utente>"<<endl;
    ofs<<"<usr> ";
    ofs<<*(nome_utente);
    ofs<<"</usr>"<<endl;
    ofs<<*(profilo_utente)<<endl;
    ofs<<*(rete_utente)<<endl;
}

void utente::aggiorna_profilo(
                    string nome,
                    string cognome,
                    int d,int m,int y,
                    bool sex,
                    string mail,
                    string lingue,
                    string exp,
                    string comp)
{
    if (nome=="" || cognome=="", mail=="") throw string ("missing");
    if (d<1 || d>31 || m<1 || m>12 || y<1900 || y>2015) throw string("invalid_date");
    profilo_utente->set_nome(nome);
    profilo_utente->set_cognome(cognome);
    profilo_utente->set_data_di_nascita(d,m,y);
    profilo_utente->set_sesso(sex);
    profilo_utente->set_email(mail);
    profilo_utente->set_lingue(lingue);
    profilo_utente->set_exp_professionali(exp);
    profilo_utente->set_comp_lavorative(comp);
}



// BASIC //
utente_basic::utente_basic() {}
utente_basic::utente_basic(username* u, info* i, rete* r) : utente (u,i,r) {}
utente_basic::utente_basic(utente* ut) : utente(ut->get_username(),ut->get_info(),ut->get_rete()) {}
void utente_basic::print(ofstream& ofs) const {
    utente::print(ofs);
    ofs<<"[basic]";
}

// BUSINESS //
utente_business::utente_business() {}
utente_business::utente_business(username* u, info* i, rete* r) : utente_basic (u,i,r) {}
utente_business::utente_business(utente* ut) : utente_basic(ut->get_username(),ut->get_info(),ut->get_rete()) {}
void utente_business::print(ofstream& ofs) const {
    utente::print(ofs);
    ofs<<"[business]";
}

// EXECUTIVE //
utente_executive::utente_executive() {}
utente_executive::utente_executive(username* u, info* i, rete* r) : utente_business (u,i,r) {}
utente_executive::utente_executive(utente* ut) : utente_business(ut->get_username(),ut->get_info(),ut->get_rete()) {}
void utente_executive::print(ofstream& ofs) const {
    utente::print(ofs);
    ofs<<"[executive]";
}

// STAMPA //
ofstream& operator<< (ofstream& ofs, utente* ut) {
    // usando la funzione virtuale print si "rende virtuale" l'operator<< evitando inutili static_cast
    // ovviamente il termine è una inesattezza in quanto non essendo membro non può essere virutale
    // ma aggiungendo un layer di indirezione si fa in modo che assuma un "comportamento virtuale"
    ut->print(ofs);
    ofs<<endl<<"</utente>"<<endl;
    return ofs;
}



















