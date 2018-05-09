#ifndef _MOVE_H_INCLUDED_
#define _MOVE_H_INCLUDED_

#include "field.h"
#include "figure.h"

class Move {
    public :
    Field from;
    Field to;
    bool capture;
    Move () {}
    Move (Field fromField, Field toField, bool captureMove) : from(fromField), to(toField), capture(captureMove) {}
};

bool isValidFigureMove(Figure figure, Move move) {
    switch (figure.getType()) {
        case 'r' :
            if (move.from.col == move.to.col || move.from.row == move.to.row)
                return true;
            else
                return false;
            break;
        case 'n' :
            if ((abs(move.from.col - move.to.col)==2 && abs(move.from.row - move.to.row)==1)
               || (abs(move.from.col - move.to.col)==1 && abs(move.from.row - move.to.row)==2))
                return true;
            else 
                return false;
            break;
        case 'b' :
            if (abs(move.from.col - move.to.col) == abs(move.from.row - move.to.row))
                return true;
            else
                return false;
            break;
        case 'q' :
            if ((move.from.col == move.to.col || move.from.row == move.to.row) || (abs(move.from.col - move.to.col) == abs(move.from.row - move.to.row))) 
                return true;
            else 
                return false;
            break;
        case 'k' :
            if ((abs(move.from.col - move.to.col) == 1 && move.from.row == move.to.row) || (abs(move.from.row - move.to.row) == 1 && move.from.col == move.to.col) || (abs(move.from.col - move.to.col) == 1 && abs(move.from.row - move.to.row) == 1))
                return true;
            else
                return false;
            break;
        case 'p' :
            if (figure.getColor() == 'w'){
                if (move.capture) {
                    if (abs(move.from.col - move.to.col) == 1 && move.to.row - move.from.row == 1) return true;
                    else return false;
                } else {
                    if (move.from.col == move.to.col && move.to.row - move.from.row == 1) return true;
                    else return false;
                }
            } else {
                if (move.capture) {
                    if (abs(move.from.col - move.to.col) == 1 && move.to.row - move.from.row == -1) return true;
                    else return false;
                } else {
                    if (move.from.col == move.to.col && move.to.row - move.from.row == -1) return true;
                    else return false;
                }
            }
        default :
            return false;
            break;
    }
}

#endif