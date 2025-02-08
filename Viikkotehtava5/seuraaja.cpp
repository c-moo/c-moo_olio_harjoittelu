#include "seuraaja.h"

Seuraaja::Seuraaja(std::string n) {
    nimi = n;
    std::cout << "Luodaan seuraaja " << nimi << std::endl;
}

void Seuraaja::paivitys(std::string viesti) {
    std::cout << nimi << " sai viestin " << viesti << std::endl;
}

std::string Seuraaja::getNimi() {
    return nimi;
}
