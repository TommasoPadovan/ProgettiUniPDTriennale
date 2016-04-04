#include "username.h"

username::username(const string& str) : login(str) {}
username::~username(){}

bool username::operator== (const username& usr) const {
    return (login==usr.login);
}
bool username::operator!= (const username& usr) const {
    return !(login==usr.login);
}

string username::get_login() const {
    return login;
}
void username::set_login(const string& str) {
    login=str;
}

ofstream& operator<< (ofstream& ofs, const username& usr){
    ofs<<usr.login<<" ";
    return ofs;
}
