
#include "Game.cpp"

int main()
{
    int maxNumber = 400;
    Game game(maxNumber);
    while(true) {
    game.play();
    };
    return 0;
}
// arvaus peli looppaa loputtomasti samalla maxNumerolla
