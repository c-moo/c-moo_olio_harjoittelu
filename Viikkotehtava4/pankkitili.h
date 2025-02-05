#ifndef PANKKITILI_H
#define PANKKITILI_H

#include <iostream>
class pankkiTili
{
public:
    pankkiTili();
    pankkiTili(std::string);
    double getBalance();
    bool deposit(double);
    bool withdraw(double);
protected:
    std::string omistaja;
    double saldo = 0;
};

#endif // PANKKITILI_H
