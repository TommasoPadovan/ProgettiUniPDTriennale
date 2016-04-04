#ifndef INFO_H
#define INFO_H
#include <string>
#include <iostream>
#include <fstream>
#include <QString>
#include <list>

using std::ofstream;
using std::string;

class info {
    friend ofstream& operator<< (ofstream&, const info&);
private:
    class data {            //nested class per la rappresentazione delle date
    public:
        int d;
        int m;
        int y;
        data(int=1, int=1, int=1900);
    };
    string nome;
    string cognome;
    bool sesso;
    string email;
    data data_di_nascita;
    string lingue;
    string exp_professionali;
    string comp_lavorative;

public:
    info();
    ~info();

    QString get_nome() const;
    QString get_cognome() const;
    bool get_sesso() const;
    QString get_email() const;
    data get_data_di_nascita() const;
    QString get_lingue() const;
    QString get_exp_professionali() const;
    QString get_comp_lavorative() const;

    void set_nome(const string&);
    void set_cognome(const string&);
    void set_sesso (bool);
    void set_email(const string&);
    void set_data_di_nascita (int,int,int);
    void set_lingue(const string&);
    void set_exp_professionali(const string&);
    void set_comp_lavorative(const string&);
};

ofstream& operator<< (ofstream&, const info&);

#endif // INFO_H
