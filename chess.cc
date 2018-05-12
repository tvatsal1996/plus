#include <iostream>
using namespace std;
// #include <map>
#include "board.h"
#include "game.h"

int main() {
    Game game(&chessBoard, Move(Field("a2"), Field("a3"), false), 'w', "Just started");
    Game newgame = game.updateGame(Move(Field("a2"), Field("a3"), false));
    Board* board = newgame.getBoard();
    for (auto it = board->begin(); it != board->end(); it++){
        cout << "Field = (" << it->first.col << ", " << it->first.row << ") ";
        cout << "Figure = " << it->second.getType() << " " << it->second.getColor();
        cout << endl;
    }
    return 0;
}