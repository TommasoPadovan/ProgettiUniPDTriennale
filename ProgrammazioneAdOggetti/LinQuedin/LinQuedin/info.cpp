#include "info.h"

using std::endl;

info::data::data(int day, int mounth, int year) : d(day), m(mounth), y(year) {}

info::info() : nome("nome"), cognome("cognome"), sesso(0), email("email") {}
info::~info() {}

QString info::get_nome() const {return QString::fromStdString(nome);}
QString info::get_cognome() const {return QString::fromStdString(cognome);}
bool info::get_sesso() const {return sesso;}
QString info::get_email() const {return QString::fromStdString(email);}
info::data info::get_data_di_nascita() const {return data_di_nascita;}
QString info::get_lingue() const {return QString::fromStdString(lingue);}
QString info::get_exp_professionali() const {return QString::fromStdString(exp_professionali);}
QString info::get_comp_lavorative() const {return QString::fromStdString(comp_lavorative);}

void info::set_nome(const string& n) {nome=n;}
void info::set_cognome(const string& c) {cognome=c;}
void info::set_sesso (bool s) {sesso=s;}
void info::set_email(const string& e) {email=e;}
void info::set_data_di_nascita (int d,int m,int y) {data_di_nascita=data(d,m,y);}
void info::set_lingue(const string& l) {lingue=l;}
void info::set_exp_professionali(const string& ep) {exp_professionali=ep;}
void info::set_comp_lavorative(const string& cl) {comp_lavorative=cl;}

//#################FRIENDS#################//
ofstream& operator<< (ofstream& ofs, const info& i) {
    ofs<<"<nom> ";
    ofs<<i.nome<<" ";
    ofs<<"</nom> ";

    ofs<<"<cogn> ";
    ofs<<i.cognome<<" ";
    ofs<<"</cogn> ";

    ofs<<"<sex> ";
    ofs<<i.sesso<<" ";
    ofs<<"</sex> ";

    ofs<<"<ema> ";
    ofs<<i.email<<" ";
    ofs<<"</ema>"<<endl;

    ofs<<"<ddn> ";
    ofs<<i.data_di_nascita.d<<" "<<i.data_di_nascita.m<<" "<<i.data_di_nascita.y<<" ";
    ofs<<"</ddn> ";

    ofs<<"<lin> ";
    ofs<<i.lingue<<" ";
    ofs<<"</lin> ";

    ofs<<"<expro> ";
    ofs<<i.exp_professionali<<" ";
    ofs<<"</expro> ";

    ofs<<"<comlav> ";
    ofs<<i.comp_lavorative<<" ";
    ofs<<"</comlav> ";
    return ofs;
}
