#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include <iostream>
#include "pankkitili.h"

class luottoTili : public pankkiTili
{
public:
    luottoTili();
    luottoTili(std::string, double);
    bool deposit(double);
    bool withdraw(double);
private:
    double luottoRaja = 0;
};

#endif // LUOTTOTILI_H
