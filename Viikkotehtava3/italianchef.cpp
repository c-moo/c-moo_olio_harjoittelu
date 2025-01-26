#include "italianchef.h"

ItalianChef::ItalianChef() {
    cout <<"Italian Chef default constructor, no name" << endl;
}

ItalianChef::ItalianChef(string name) {
    chefName = name;
    cout << "Italian chefs constructor, Italian chefs name is " << chefName << endl;
}

ItalianChef::~ItalianChef() {
    cout <<"Italian Chef deconstructor" << endl;
}

bool ItalianChef::askSecret(string pw, int f,int w) {
    if(pw == password) {
        cout << "password is correct" << endl;
        flour = f;
        water = w;
        cout << "Italian Chef " << chefName << " with " << f << " flour and " << w << " can make " << makePizza() << "pizzas" << endl;
        return 0;
    }
    else {
        cout << "password WRONG" << endl;
        return 1;
    }
}


int ItalianChef::makePizza() {
    int x = flour / 5; // will only give full numbers rounded down because of the in parameter
    int y = water / 5;
    return min(x,y);
}
