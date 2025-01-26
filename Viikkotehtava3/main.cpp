
#include "chef.h"
#include "italianchef.h"
using namespace std;

int main()
{
    Chef chef1("Tony");
    chef1.makeSalad(11);
    chef1.makeSoup(9);

    ItalianChef chef2("Antonio");
    chef2.askSecret("pizza", 15, 15);
    return 0;
}
