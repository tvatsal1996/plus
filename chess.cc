#include <iostream>
using namespace std;
// #include <map>
#include "game.h"
#include "gametree.h"

int main() {
    Game* game = new Game; 
    *game = Game(&chessBoard, Move(Field("a2"), Field("a3"), false), 'w', "Just started");
    showBoard(game->getBoard());
    string str;
    while(1){
        cout << "Enter source field : ";
        cin >> str;
        Field fieldf = Field(str);
        cout << "Enter destination field : ";
        cin >> str;
        Field fieldt = Field(str);
        cout << "Is it a capture move : ";
        cin >> str;
        bool capture;
        if (str == "y") capture = true;
        else capture = false;
        Game* nextgame = game->updateGame(Move(fieldf, fieldt, capture));
        cout << nextgame->getColor() << endl;
        showBoard(nextgame->getBoard());
        game = nextgame->bestGame();
        showBoard(game->getBoard());
    }
    return 0;
}