#include <iostream>

#include "pankkitili.h"
#include "luottotili.h"
#include "asiakas.h"

int main()
{
    asiakas BA1("Marco", 2000);
    BA1.showSaldo();
    BA1.talletus(1750);
    BA1.talletus(-100);
    BA1.showSaldo();
    BA1.nosto(-200);
    BA1.nosto(1000);
    BA1.showSaldo();
    BA1.luotonNosto(2001);
    BA1.luotonNosto(2000);
    BA1.luotonMaksu(1000);
    BA1.showSaldo();
    BA1.luotonMaksu(1500);

    asiakas BA2("Lucas", 1000);
    BA1.tiliSiirto(700,BA2);
    BA1.showSaldo();
    BA2.showSaldo();
    return 0;
}
