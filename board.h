#ifndef _BOARD_H_INCLUDED_
#define _BOARD_H_INCLUDED_

#include "figure.h"
#include "move.h"
#include <map>

typedef map<string, Figure> Board;

Board chessBoard = {
    {"a1", Figure('r', 'w')},
    {"b1", Figure('n', 'w')},
    {"c1", Figure('b', 'w')},
    {"e1", Figure('k', 'w')},
    {"f1", Figure('b', 'w')},
    {"d1", Figure('q', 'w')},
    {"g1", Figure('n', 'w')},
    {"h1", Figure('r', 'w')},    
    {"a2", Figure('p', 'w')},
    {"b2", Figure('p', 'w')},
    {"c2", Figure('p', 'w')},
    {"d2", Figure('p', 'w')},
    {"e2", Figure('p', 'w')},
    {"f2", Figure('p', 'w')},
    {"h2", Figure('p', 'w')},
    {"g2", Figure('p', 'w')},
    {"a8", Figure('r', 'b')},
    {"b8", Figure('n', 'b')},
    {"c8", Figure('b', 'b')},   
    {"d8", Figure('q', 'b')},
    {"e8", Figure('k', 'b')},
    {"f8", Figure('b', 'b')},
    {"g8", Figure('n', 'b')},
    {"h8", Figure('r', 'b')},    
    {"a7", Figure('p', 'b')},
    {"b7", Figure('p', 'b')},
    {"c7", Figure('p', 'b')},
    {"d7", Figure('p', 'b')},
    {"e7", Figure('p', 'b')},
    {"f7", Figure('p', 'b')},
    {"g7", Figure('p', 'b')},
    {"h7", Figure('p', 'b')},
};

void updateBoard(Board* board, Move move) {
    try{
        if (board->find(move.from) == board->end()) {
            throw 1;
        } else if (board->find(move.to) != board->end() && board->find(move.to)->second.getColor() == board->find(move.from)->second.getColor()) {
            throw 2;
        } else {
            auto it = board->find(move.from);
            board->erase(board->find(move.to));
            board->insert(pair <string, Figure> (move.to, it->second));
            board->erase(it);
        }
    }
    catch (int i) {
        switch (i) {
            case 1 :
                cout << "Source field " << move.from << " is empty\n";
                exit (EXIT_FAILURE);
            case 2 :
                cout << "Destination field " << move.to << " has same color as source field " << move.from << endl;
        }
    }
    return;
}

#endif