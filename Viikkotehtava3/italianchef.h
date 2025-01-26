#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "chef.h"

class ItalianChef : public Chef
{
public:
    ItalianChef();
    ItalianChef(string name);
    ~ItalianChef();
    bool askSecret(string pw, int f, int w);

private:
    int makePizza();
    int flour;
    int water;
    string password = "pizza";

};

#endif // ITALIANCHEF_H
