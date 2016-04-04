#include "db.h"

using std::endl;

vector<utente*>* DB::db = new vector<utente*>;

// ##### add_user #####
bool DB::esiste_utente(username* usn) {
    for (vector<utente*>::const_iterator it=db->begin(); it!=db->end(); ++it) {
        if ( *((*it)->get_username())==*usn) return true;
    }
    return false;
}

void DB::add_user(utente* ut) {
    if (!esiste_utente(ut->get_username())) {
        db->push_back(ut);
        DB::save();
    }
}

// ##### rem_user #####
void DB::rem_user(const username & un){
    vector<utente*>::iterator it =db->begin();
    for(;it!=db->end() && un!=*((*it)->get_username());++it){}
        if (it!=db->end()){
            delete (*it);
            db->erase(it);
            it =db->begin();    //scorro un'altra volta il db per eliminare l'utente dalle reti
            for(;it!=db->end();++it) {
                (*it)->get_rete()->rem_contatto(un);
            }
            DB::save();
        }
}

void DB::rem_user(utente* usr) {
    vector<utente*>::iterator it =db->begin();
    for(;it!=db->end() && *(usr->get_username())!=*((*it)->get_username());it++){}
        if (it!=db->end()){
            delete (*it);
            db->erase(it);
            it =db->begin();    //scorro un'altra volta il db per eliminare l'utente dalle reti
            for(;it!=db->end();++it) {
                (*it)->get_rete()->rem_contatto(usr->get_username()->get_login());
            }
            DB::save();
        }
}


// ##### save #####
void DB::save() {
    ofstream OUT("DataBase_utenti");
    if (OUT) {
        OUT<<db->size()<<endl;
        for (vector<utente*>::const_iterator it=db->begin(); it!=db->end(); ++it) {
            OUT<<*it<<endl;
        }
        OUT.close();
    }
}

vector<utente*>* DB::get_db() {return db;}



//####################################LOADING###########################################//
string DB::seek(ifstream& ifs, string tag) {
    string close_tag=tag.substr(0,1)+"/"+tag.substr(1,tag.length()-1);     //tag di chiusura
    string temp1="", temp2="";
    while (temp2!=tag) ifs>>temp2;          //scorro fino al tag di apertura
    ifs>>temp2;
    while (temp2!=close_tag) {                    //finché non trovo il tag di chiusura
        temp1+=temp2+" ";                         //se è formata da più parole le concateno
        ifs>>temp2;
    }
    temp1=temp1.substr(0,temp1.length()-1);     //cancello l'ultimo spazio
    return temp1;
}



void DB::load() {
    ifstream IN("DataBase_utenti");
    if (IN) {
        int num_utenti;
        IN>>num_utenti;

        string temp="";
        int d,m,y;

        for (int i=0; i<num_utenti; ++i) {                   //per ogni utente presente nel db
            info* inf=new info();
            rete* ret=new rete();

            while (temp!="<utente>") IN>>temp;        //cerco l'inizio dell'utente

            //USERNAME
            temp=seek(IN,"<usr>");
            username* use=new username(temp);
            //PROFILO
            temp=seek(IN,"<nom>");
            inf->set_nome(temp);

            temp=seek(IN,"<cogn>");
            inf->set_cognome(temp);

            temp=seek(IN,"<sex>");
            if (temp=="0") inf->set_sesso(false);
            if (temp=="1") inf->set_sesso(true);

            temp=seek(IN,"<ema>");
            inf->set_email(temp);

            while (temp!="<ddn>") IN>>temp;
            IN>>d;
            IN>>m;
            IN>>y;
            inf->set_data_di_nascita(d,m,y);

            temp=seek(IN,"<lin>");
            inf->set_lingue(temp);

            temp=seek(IN,"<expro>");
            inf->set_exp_professionali(temp);

            temp=seek(IN,"<comlav>");
            inf->set_comp_lavorative(temp);

            //RETE
            list<username> lu;
            while (temp!="<net>") IN>>temp;
            IN>>temp;
            while (temp!="</net>") {
                username usn(temp);
                lu.push_back(usn);
                IN>>temp;
            }
            ret=new rete(lu);           //uso il costruttore di copia ridefinito

            //CREAZIONE UTENTE
            utente* punt;           //puntatore a generico utente
            while (temp!="[basic]" && temp!="[business]" && temp!="[executive]") IN>>temp;
            if (temp=="[basic]")
                punt=new utente_basic(use,inf,ret);
            else if (temp=="[business]")
                punt=new utente_business(use,inf,ret);
            else if (temp=="[executive]")
                punt=new utente_executive(use,inf,ret);


            db->push_back(punt);
        }

        IN.close();
    }
}




//####################################FIND###########################################//
utente* DB::find(const username& us){
    std::vector<utente*>::const_iterator it=db->begin();
    bool trovato=false;
    while(!trovato && it != db->end()){
        if(us==*((*it)->get_username())){
            trovato=true;
            return *it;
        }
        else it++;
    }
    return 0;
}

list<utente*>* DB::find_nome(const QString & str){
    std::vector<utente*>::const_iterator it=db->begin();
    list<utente*>* l=new list<utente*>;
    while(it != db->end()){
        if(str==(*it)->get_info()->get_nome()) l->push_back(*it);
        ++it;
    }
    return l;
}

list<utente*>* DB::find_cognome(const QString & str){
    std::vector<utente*>::const_iterator it=db->begin();
    list<utente*>* l=new list<utente*>;
    while(it != db->end()){
        if(str==(*it)->get_info()->get_cognome()) l->push_back(*it);
        ++it;
    }
    return l;
}


vector<utente*>* DB::find_rete(rete* network) {
    list<username>::const_iterator it=network->get_rete()->begin();
    std::vector<utente*>* vec=new std::vector<utente*>;
    for (;it!=network->get_rete()->end();++it) {
        vec->push_back(DB::find(*it));
    }
    return vec;
}



//####################################AGGIUNGI FROM FORM###########################################//

utente* DB::candidato(string usname,
                     string nome,
                     string cognome,
                     int d,int m,int y,
                     string mail,
                     bool sex,
                     string lingue,
                     string exppro,
                     string comlav)
{
    string temp;
    temp=usname;                                                         //username
    if (temp.find(' ')!=temp.npos) throw string("invalid_usn");
    username* usn=new username(temp);
    if (DB::find(*usn)) {
        delete usn;
        throw string("existing_usn");
    }

    // ###INFO###
    info* profilo=new info;

    temp=nome;                                                           //nome
    if (temp=="") throw string("missing");
    profilo->set_nome(temp);

    temp=cognome;                                                        //cognome
    if (temp=="") throw string("missing");
    profilo->set_cognome(temp);

    if(sex) profilo->set_sesso(1);                                       //sesso
    else profilo->set_sesso(0);

    if (d<1 || d>31 || m<1 || m>12 || y<1900 || y>2015)                  //data
        throw string("invalid_date");
    profilo->set_data_di_nascita(d,m,y);

    temp=mail;                                                           //mail
    if (temp=="") throw string("missing");
    profilo->set_email(temp);

    profilo->set_lingue(lingue);
    profilo->set_exp_professionali(exppro);
    profilo->set_comp_lavorative(comlav);

    // ###TIPO###
    rete* ret=new rete;
    utente* punt=new utente_basic(usn,profilo,ret);
    return punt;
}
