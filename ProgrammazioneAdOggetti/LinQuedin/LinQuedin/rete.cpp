#include "rete.h"

rete::rete() {}
rete::rete(const list<username>& l) : net(l) {}
rete::~rete() {}



const list<username>* rete::get_rete() const {return &net;}

bool rete::has_user(const username& usn) const {
    list<username>::const_iterator it=net.begin();
    for (; it!=net.end(); ++it) {
        if (usn==*it) return true;
    }
    return false;
}



bool rete::add_contatto(const username& usn) {
    if (!has_user(usn)) {
        net.push_back(usn);
        return true;
    }
    else return false;
}

void rete::rem_contatto(const username& usn) {
    if (has_user(usn)) net.remove(usn);
}


ofstream& operator<<(ofstream& ofs, const rete& r) {
    ofs<<"<net> ";
    const list<username>* L=r.get_rete();
    list<username>::const_iterator it=L->begin();
    for (; it!=L->end(); ++it) {
        ofs<<*it<<" ";
    }
    ofs<<"</net> ";
    return ofs;
}
