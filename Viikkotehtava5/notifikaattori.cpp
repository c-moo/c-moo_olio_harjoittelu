#include "notifikaattori.h"
#include "Seuraaja.h"

Notifikaattori::Notifikaattori() {
}

void Notifikaattori::lisaa(Seuraaja *uusiSeuraaja) {

    uusiSeuraaja->next = seuraajat;
    seuraajat = uusiSeuraaja;
    std::cout << "Notifikaattori lisaa seuraajan " << seuraajat->getNimi() << std::endl;
 }

void Notifikaattori::poista(Seuraaja *poistettavaSeuraaja) {
    std::cout << "Notifikaattori poistaa seuraajan " << poistettavaSeuraaja->getNimi() << std::endl;
    Seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        if(alku->next == poistettavaSeuraaja) {
            alku->next = poistettavaSeuraaja->next;
            return;
        }
        alku = alku->next;
    }
}

void Notifikaattori::postita(std::string viesti) {
    std::cout << "Notifikaattori postaa viestin " << viesti << std::endl;
    Seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        alku->paivitys(viesti);
        alku = alku->next;
    }
}

void Notifikaattori::tulosta() {
    Seuraaja *alku = seuraajat;
    while (alku != nullptr) {
        std::cout << "Seuraaja " << alku->getNimi() << std::endl;
        alku = alku->next;
    }
}
