#include "chef.h"

#include <iostream>

using namespace std;

Chef::Chef() {
    cout << "Default constructor, no name" << endl;
}

Chef::Chef(string name) {
    chefName = name;
    cout << "Chefs constructor, chefs name is " << chefName << endl;
}

Chef::~Chef() {
    cout << "Chef destructor" << endl;
}

string Chef::getChefName() const {
    return chefName;
}
int Chef::makeSalad(int items) {
    cout << "Chef " << chefName << " with " << items << " items";
    int x = items/5;
    cout << " can make " << x << " portions of salad" << endl;
    return 0;
}

int Chef::makeSoup(int items) {
    cout << "Chef " << chefName << " with " << items << " items";
    int x = items/3;
    cout << " can make " << x << " portions of soup" << endl;
    return 0;
}


