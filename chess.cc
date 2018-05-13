#include <iostream>
using namespace std;
#include "game.h"

int main() {
    Game game(&chessBoard, Move(Field("a2"), Field("a3"), false), 'w', "Just started");
    // Game newgame = game.updateGame(Move(Field("a2"), Field("a3"), false));
    // showBoard(newgame.getBoard());
    // for (auto it = newgame.getBoard()->begin(); it != newgame.getBoard()->end(); it++){
    //     cout << "Field = (" << it->first.col << ", " << it->first.row << ") ";
    //     cout << "Figure = " << it->second.getType() << " " << it->second.getColor();
    //     cout << endl;
    // }
    vector<Game> nextgames = game.nextGames();
    for(int i = 0; i<nextgames.size(); i++){
        showBoard(nextgames[i].getBoard());
    }
    return 0;
}