#ifndef SEURAAJA_H
#define SEURAAJA_H

#include <iostream>
class Seuraaja
{
public:
    Seuraaja(std::string);
    std::string getNimi();
    void paivitys(std::string);
    Seuraaja *next  = nullptr;
private:
    std::string nimi;
};

#endif // SEURAAJA_H
