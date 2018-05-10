#include <iostream>
using namespace std;
// #include <map>
#include "game.h"

int main() {
    Game game(&chessBoard, Move(Field("a2"), Field("a3"), false), 'w', "Just started");
    vector<Game*> validGames = game.nextGames();
    for(int i = 0; i<validGames.size(); i++){
        showBoard(validGames[i]->getBoard());
    }
    return 0;
}