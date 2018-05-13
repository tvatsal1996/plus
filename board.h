#ifndef _BOARD_H_INCLUDED_
#define _BOARD_H_INCLUDED_

#include <iostream>
using namespace std;
#include <vector>
#include "figure.h"
#include "move.h"
#include "field.h"
#include <map>

int signum(int x){
    if (x > 0) return 1;
    else if (x < 0) return -1;
    else return 0;
}

typedef map<Field, Figure> Board;

Board chessBoard = {
    {Field("a1"), Figure('r', 'w')},
    {Field("b1"), Figure('n', 'w')},
    {Field("c1"), Figure('b', 'w')},
    {Field("e1"), Figure('k', 'w')},
    {Field("f1"), Figure('b', 'w')},
    {Field("d1"), Figure('q', 'w')},
    {Field("g1"), Figure('n', 'w')},
    {Field("h1"), Figure('r', 'w')},    
    {Field("a2"), Figure('p', 'w')},
    {Field("b2"), Figure('p', 'w')},
    {Field("c2"), Figure('p', 'w')},
    {Field("d2"), Figure('p', 'w')},
    {Field("e2"), Figure('p', 'w')},
    {Field("f2"), Figure('p', 'w')},
    {Field("g2"), Figure('p', 'w')},
    {Field("h2"), Figure('p', 'w')},
    {Field("a8"), Figure('r', 'b')},
    {Field("b8"), Figure('n', 'b')},
    {Field("c8"), Figure('b', 'b')},   
    {Field("d8"), Figure('q', 'b')},
    {Field("e8"), Figure('k', 'b')},
    {Field("f8"), Figure('b', 'b')},
    {Field("g8"), Figure('n', 'b')},
    {Field("h8"), Figure('r', 'b')},    
    {Field("a7"), Figure('p', 'b')},
    {Field("b7"), Figure('p', 'b')},
    {Field("c7"), Figure('p', 'b')},
    {Field("d7"), Figure('p', 'b')},
    {Field("e7"), Figure('p', 'b')},
    {Field("f7"), Figure('p', 'b')},
    {Field("g7"), Figure('p', 'b')},
    {Field("h7"), Figure('p', 'b')},
};

bool isValidMove(Move move, Board* board) {
    if (board->find(move.from) == board->end()) {
        cout << "No figure present on the chess board at Field " << move.from.position() << endl;
        return false;
    } else if (!isValidFigureMove(board->find(move.from)->second, move)) {
        cout << "Sorry invalid figure move\n";
        return false;
    } else if (board->find(move.to) != board->end() && board->find(move.to)->second.getColor() == board->find(move.from)->second.getColor()) {
        cout << "Trying to capture your own color, sorry not allowed\n";
        return false;
    } else {
        figuretype figtype = board->find(move.from)->second.getType();
        figurecolor figcolor = board->find(move.from)->second.getColor();
        int row_it = signum(move.to.row-move.from.row), col_it = signum(move.to.col-move.from.col);
        Field temp = Field(move.from.col+col_it, move.from.row+row_it);
        bool check = true;
        switch (figtype)
        {
            case 'n' :
                break;
            default :
                while (temp != move.to) {
                    if (board->find(temp) != board->end()){
                        check = false;
                        break;
                    }
                    temp.col = temp.col + col_it;
                    temp.row = temp.row + row_it;
                }     
        }
        if (!check) cout << "Road blocked, can't make this move\n";
        return check;
    }
}

void showBoard(Board* board){
    cout << endl;
    cout << "\t\t";
    for (int i = 0; i < 8; i++){
        cout << (char)('a'+i) << "\t";
    }
    cout << endl << endl;
    for (int row = 8; row > 0; row--){
        cout << "\t" << row << "\t";
        for (int col = 1; col<9; col++){
            auto it = board->find(Field(col, row));
            if ( (it == board->end())){
                cout << "-" << "\t";
            } else {
                cout << (char)(it->second.getType() - (it->second.getColor() == 'b' ? 0 : 32)) << "\t";
            }
        }
        cout << row;
        cout << endl << endl;
    }
    cout << "\t\t";
    for (int i = 0; i < 8; i++){
        cout << (char)('a'+i) << "\t";
    }
    cout << endl << endl;
    return;
}

Board* updateBoard(Board* board, Move move) {
    Board* newboard = new Board;
    if (!isValidMove(move, board)){
        return board;
    } else {
        for(auto it = board->begin(); it != board->end(); it++){
            newboard->insert(pair <Field, Figure> (it->first, it->second));
        }
        auto it = newboard->find(move.from);
        if (newboard->find(move.to) != newboard->end()){
            newboard->erase(newboard->find(move.to));
        }
        newboard->insert(pair <Field, Figure> (move.to, it->second));
        newboard->erase(it);
    }
    return newboard;
}

vector<Move> getGames(Board* board, const Field field, figuretype type, figurecolor color){
    figurecolor gameColor = other(color);
    vector<Move> movesList;
    vector <pair<int, int> > incrList;
    switch (type)
    {
        case 'r' :{
            incrList = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};
            for (int i = 0; i<incrList.size(); i++){
                int col_inc = incrList[i].first, row_inc = incrList[i].second; 
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                while(temp.isValidField() && board->find(temp) == board->end()){
                    movesList.push_back(Move(field, temp, false));
                    temp.row = temp.row + row_inc;
                    temp.col = temp.col + col_inc;
                }
                if (temp.isValidField() && board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)) {
                    movesList.push_back(Move(field, temp, true));
                }
            }
            break;
        }
        case 'b' :{
            incrList = {make_pair(1,1), make_pair(-1,-1), make_pair(1,-1), make_pair(-1, 1)};
            for (int i = 0; i<incrList.size(); i++){
                int col_inc = incrList[i].first, row_inc = incrList[i].second; 
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                while(temp.isValidField() && board->find(temp) == board->end()){
                    movesList.push_back(Move(field, temp, false));
                    temp.row = temp.row + row_inc;
                    temp.col = temp.col + col_inc;
                }
                if (temp.isValidField() && board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)) {
                    movesList.push_back(Move(field, temp, true));
                }
            }
            break;
        }
        case 'q' :{
            incrList = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1), make_pair(1,1), make_pair(-1,-1), make_pair(1,-1), make_pair(-1, 1)};
            for (int i = 0; i<incrList.size(); i++){
                int col_inc = incrList[i].first, row_inc = incrList[i].second; 
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                while(temp.isValidField() && board->find(temp) == board->end()){
                    movesList.push_back(Move(field, temp, false));
                    temp.row = temp.row + row_inc;
                    temp.col = temp.col + col_inc;
                }
                if (temp.isValidField() && board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)) {
                    movesList.push_back(Move(field, temp, true));
                }
            }
            break;
        }
        case 'k' :{
            incrList = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1), make_pair(1,1), make_pair(-1,-1), make_pair(1,-1), make_pair(-1, 1)};
            for (int i = 0; i<incrList.size(); i++) {
                int col_inc = incrList[i].first, row_inc = incrList[i].second;
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                if (temp.isValidField() && board->find(temp) == board->end()){
                    movesList.push_back(Move(field, temp, false));
                } else if (temp.isValidField() && board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)){
                    movesList.push_back(Move(field, temp, true));
                } else{
                }
            }
            break;
        }
        case 'p' :{
            int dir = 1;
            if (color == 'b') dir = -1;
            Field temp = Field(field.col + 0, field.row + dir);
            if (temp.isValidField() && board->find(temp) == board->end()) movesList.push_back(Move(field, temp, false));
            incrList = {make_pair(1,dir), make_pair(-1,dir)};
            for (int i = 0; i<incrList.size(); i++){
                int col_inc = incrList[i].first, row_inc = incrList[i].second;
                temp = Field(field.col+col_inc, field.row+row_inc);
                if (temp.isValidField() && board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)){
                    movesList.push_back(Move(field, temp, true));
                }
            }
            break;
        }
        default :{
            incrList = {make_pair(2,1), make_pair(2,-1), make_pair(-2,1), make_pair(-2,-1), make_pair(1,2), make_pair(1,-2), make_pair(-1,2), make_pair(-1,-2)};
            for (int i = 0; i<incrList.size(); i++){
                int col_inc = incrList[i].first, row_inc = incrList[i].second;
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                if (temp.isValidField() && board->find(temp) == board->end()){
                    movesList.push_back(Move(field, temp, false));
                } else if (temp.isValidField() && board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)){
                    movesList.push_back(Move(field, temp, true));
                } else{
                }
            }
            break;
        }
    }
    return movesList;
}

#endif