#ifndef DB_H
#define DB_H
#include <vector>
#include <fstream>
#include "rete.h"
#include "utente.h"
#include "rete.h"

using std::vector;
using std::ifstream;

class DB {
private:
    static vector<utente*>* db;
    static string seek(ifstream&,string);
public:
    static void save();
    static void load();
    static vector<utente*>* get_db();

    static bool esiste_utente(username*);
    static void add_user(utente*);
    static void rem_user(const username&);
    static void rem_user(utente*);
    static utente* candidato(string,
                            string,
                            string,
                            int,int,int,
                            string,
                            bool=1,
                            string ="",
                            string ="",
                            string ="");

    static utente* find(const username&);
    static list<utente*>* find_nome(const QString&);
    static list<utente*>* find_cognome(const QString&);
    static vector<utente*>* find_rete(rete*);
};

#endif // DB_H
