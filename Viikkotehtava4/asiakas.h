#ifndef ASIAKAS_H
#define ASIAKAS_H
#include <iostream>

#include "pankkitili.h"
#include "luottotili.h"

class asiakas {
public:
    asiakas(std::string, double);
    std::string getNimi();
    void showSaldo();
    bool talletus(double);
    bool nosto(double);
    bool luotonMaksu(double);
    bool luotonNosto(double);
    bool tiliSiirto(double, asiakas &);
private:
    pankkiTili kayttotili;
    luottoTili luottotili;
    std::string name;
};

#endif // ASIAKAS_H
