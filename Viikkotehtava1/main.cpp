#include <iostream>
#include <cstdlib>
#include <ctime> // time library
#include <unistd.h> // sleep library

#define DEBUG false // kertoo numeron alussa, jos on DEBUG = true

using namespace std;

int main()
{
    srand(time(0)); // ctime ottaa ajan time(0) functiolla, joka tuottaa random numeron
    int randomNumber = rand() % 21;

    #if DEBUG
    cout << "Random numero on " << randomNumber << endl;
    #endif

    while(true)  {
        int guess = -1;

        cout << "Arvaa 1-20 väliltä numero." << endl;
        while(true) {
            cin >> guess;
            if (guess < 0) {    // estää negatiivisen numeron antamisen, mutta voit silti laittaa numeroita yli 20. En näe tarvetta laittaa korjausta siihen
                cout << "Anna positiivinen numero" << endl;
                guess = -1;
            }
            else {
                break;
            }
            sleep(1);
        } // ei jatka koodia ennen kuin saadaan numero käyttäjältä


        if (guess < randomNumber) {
            cout << "Luku on suurempi kuin " << guess << endl;
        }
        else if (guess > randomNumber) {
            cout << "Luku on pienempi kuin " << guess << endl;
        }
        else {
            cout << guess << " On oikein!" << endl;
            break;
        }
        cout << endl;
    }
    return 0;
}
