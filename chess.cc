#include <iostream>

using namespace std;
#include "figure.h"
#include "field.h"
#include "board.h"
#include "move.h"

int main() {
    updateBoard (&chessBoard, Move(Field("a1"), Field("a9"), false));
    return 0;
}