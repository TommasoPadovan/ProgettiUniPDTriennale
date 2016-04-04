#ifndef USERNAME_H
#define USERNAME_H
#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::ofstream;

class username {
    friend ofstream& operator<< (ofstream& ofs, const username&);
private:
    string login;
public:
    username(const string& ="username");
    ~username();

    bool operator== (const username&) const;
    bool operator!= (const username&) const;

    string get_login() const;
    void set_login(const string&);
};

ofstream& operator<< (ofstream& ofs, const username&);

#endif // USERNAME_H
