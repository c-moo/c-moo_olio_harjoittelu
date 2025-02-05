#include "asiakas.h"
#include <iostream>

asiakas::asiakas(std::string na, double credit):kayttotili(na),
    luottotili(na,credit){
    name = na;
}

std::string asiakas::getNimi() {
    return name;
}

void asiakas::showSaldo() {
    std::cout << name << " Debit account balance: " << kayttotili.getBalance() << std::endl;
    std::cout << name << " Credit account balance: " << luottotili.getBalance() << std::endl;
}

bool asiakas::talletus(double value) {
    if (value > 0) {
        std::cout << "Account " << name << " deposits " << value << std::endl;
        if (kayttotili.deposit(value)) {
            return true;
        }
        else {
            std::cout << "Transfer failed" << std::endl;
            return false;
        }
    }
    else {
        std::cout << "Please enter a value above 0" << std::endl;
        return false;
    }
}

bool asiakas::nosto(double value) {
    std::cout << "Account " << name << " withdraws " << value << std::endl;
    if (kayttotili.withdraw(value)) {
        return true;
    }
    else {
        std::cout << "Transfer failed" << std::endl;
        return false;
    }
}

bool asiakas::luotonMaksu(double value) {
    std::cout << name << " pays " << value << " off their credit" << std::endl;
    if(luottotili.deposit(value)) {
        if (luottotili.getBalance() > 0) {
            std::cout << "Credit account went over 0 putting rest into Debit accout" << std::endl;
            kayttotili.deposit(luottotili.getBalance());
        }
        return true;
    }
    else {
        std::cout << "Transfer failed" << std::endl;
        return false;
    }
}

bool asiakas::luotonNosto(double value) {
    std::cout << name << " withdraws " << value << " off their credit" << std::endl;
    if(luottotili.withdraw(value)) {
        return true;
    }
    else {
        std::cout << "Transfer failed" << std::endl;
        return false;
    }
}

bool asiakas::tiliSiirto(double value, asiakas &x) {
    std::cout << name << " tranfers " << value << " to " << x.getNimi() << std::endl;
    if(nosto(value)) {
        x.talletus(value);
        return true;
    }
    else {
        std::cout << "Transfer failed" << std::endl;
        return false;
    }
}
