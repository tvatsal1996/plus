#include <iostream>

using namespace std;
#include "figure.h"
#include "field.h"
#include "board.h"
#include "move.h"

int main() {
    string str;
    Move move;
    while(1) {
        cout << "Enter source field : ";
        cin >> str;
        move.from = Field(str);
        cout << "Enter destination field : ";
        cin >> str;
        move.to = Field(str);
        updateBoard(&chessBoard, move);
        showBoard(&chessBoard);
    }
    // showBoard(&chessBoard);
    return 0;
}