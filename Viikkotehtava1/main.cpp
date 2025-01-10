#include <iostream>
#include <cstdlib>
#include <ctime> // time

#define DEBUG true // kertoo numeron alussa, jos on DEBUG = true

using namespace std;

int game(int maxnum);

int main()
{
    int maxnum;
    cout << "Anna maksimi numero, jota arvotaan" << endl;
    while(!(cin >> maxnum) or (maxnum < 2) or (maxnum > 32766)) {

            cout << "Anna numero 2 - 32766 väliltä" << endl; // 32767 on ehkä maksimi, jota rand() functio voi tuottaa. En ole kuitenkaan varma
            cin.clear();
            cin.ignore(10000, '\n');
    }
    int guesses = game(maxnum);
    cout << "Arvausten määrä on " << guesses << endl;
}

int game(int maxnum) {
    srand(time(0)); // ctime ottaa ajan time(0) functiolla, joka tuottaa random numeron
    int randomNumber = 1 + (rand() % (maxnum));
    int guesses = 0;

    #if DEBUG
        cout << "Random numero on " << randomNumber << endl;
    #endif

    while(true)  {
        int guess = -1;
        cout << "Arvaa 1-" << maxnum <<" väliltä numero." << endl;

        while(!(cin >> guess) or (guess < 1) or (guess > maxnum)) {

            cout << "Anna sopiva numero, " << guess << " ei ole sopiva numero" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        if (guess < randomNumber) {
            cout << endl << "Luku on suurempi kuin " << guess << endl;
        }

        else if (guess > randomNumber) {
            cout << endl << "Luku on pienempi kuin " << guess << endl;
        }

        else {
            cout << endl << guess << " On oikein!" << endl;
            guesses += 1;
            break;
        }
        guesses += 1;
        cout << endl;
    }
    return guesses;
}
