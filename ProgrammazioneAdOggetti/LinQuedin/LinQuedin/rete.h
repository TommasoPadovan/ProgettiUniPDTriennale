#ifndef RETE_H
#define RETE_H
#include <list>
#include "username.h"

using std::list;
using std::ofstream;

class rete {
private:
    list<username> net;
public:
    rete();
    rete (const list<username>&);
    ~rete();

    const list<username>* get_rete() const;
    bool has_user(const username&) const;

    bool add_contatto(const username&);
    void rem_contatto(const username&);
};


ofstream& operator<< (ofstream&, const rete&);

#endif // RETE_H
