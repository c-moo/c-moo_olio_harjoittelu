#include "pankkitili.h"

pankkiTili::pankkiTili() {};
pankkiTili::pankkiTili(std::string name) {
    omistaja = name;
    std::cout << "Debit account for " << name << " has been made" << std::endl;
}

bool pankkiTili::deposit(double value) {
    std::cout <<"Debit deposit: ";
    if (value > 0) {
        saldo += value;
        std::cout << "Deposited " << value << " Euros to the account" << std::endl;
        return true;
    }
    else {
        std::cout << "Deposit failed, enter a number above 0" << std::endl;
        return false;
    }
}

bool pankkiTili::withdraw(double value) {
    std::cout <<"Debit withdrawal: ";
    if (value > 0) {
        if ((saldo - value) < 0) {
            std::cout << "You don't have enough money on your account" << std::endl;
            return false;
        }
        saldo -= value;
        std::cout << "Withrew " << value << " Euros from the account" << std::endl;
        return true;
    }
    else {
        std::cout << "Withdrawal failed, enter a number above 0" << std::endl;
        return false;
    }
}

double pankkiTili::getBalance() {
    return saldo;
}
