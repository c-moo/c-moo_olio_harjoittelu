#include "luottotili.h"
#include "pankkitili.h"
#include <iostream>

luottoTili::luottoTili(std::string name,double lendAmount) {
    luottoRaja = lendAmount;
    std::cout << "Credit account for " << name << " has been made, with " << lendAmount << " lend amount" << std::endl;
}

bool luottoTili::deposit(double value) {
    std::cout <<"Credit account deposit: ";
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

bool luottoTili::withdraw(double value) {
    std::cout <<"Credit account withdrawal: ";
    if (value > 0) {
        if ((saldo - value) < -luottoRaja) {
            std::cout << "Transaction went over loan amount" << std::endl;
            return false;
        }
        saldo -= value;
        std::cout << "Withdrew " << value << " Euros from the account" << std::endl;
        return true;
    }
    else {
        std::cout << "Withdrawal failed, enter a number above 0" << std::endl;
        return false;
    }
}
