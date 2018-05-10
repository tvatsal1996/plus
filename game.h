#ifndef _GAME_H_INCLUDED_
#define _GAME_H_INCLUDED_

#include <iostream>
#include <iterator>
#include <vector>
using namespace std;
#include "field.h"
#include "figure.h"
#include "move.h"
#include "board.h"

typedef string gamestatus;

class Game {
    private :
        Board* board;
        Move lastmove;
        figurecolor color;
        gamestatus status;
    public :
        Board* getBoard() {
            return board;
        }
        Move getLastMove() {
            return lastmove;
        }
        figurecolor getColor() {
            return color;
        }
        gamestatus getStatus() {
            return status;
        }
        Game() {}
        Game(Board* gameboard, Move gameLastMove, figurecolor gameColor, gamestatus gameStatus){
            board = gameboard;
            lastmove = gameLastMove;
            color = gameColor;
            status = gameStatus;
        }
        int rank() {
            int colorRank = 0, otherColorRank = 0;
            for(auto it = board->begin(); it != board->end(); it++){
                if (it->second.getColor() == color){
                    colorRank += it->second.rank();
                    colorRank += fieldRank(it->first);
                } else {
                    otherColorRank += it->second.rank();
                    otherColorRank += fieldRank(it->first);
                }
            }
            return colorRank - otherColorRank;
        }
        Game updateGame(Move move){
            Game newgame;
            Board newBoard = *board;
            updateBoard(&newBoard, move);
            figurecolor newcolor = other(color);
            gamestatus newstatus = status;
            return Game(&newBoard, move, newcolor, newstatus);
        }
        vector<Game*> nextGames();
};

vector<Move> getGames(Board* board, Field field, figuretype type, figurecolor color){
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

vector<Game*> Game::nextGames(){
    vector<Game*> nextgames;
    vector<Move> nextmoves;
    for (auto it = board->begin(); it != board->end(); it++){
        if(it->second.getColor() == color){
            figuretype type = it->second.getType();
            Field field = it->first;
            Game updatedgame;
            nextmoves = getGames(board, field, type, color);
            for (int i = 0; i<nextmoves.size(); i++){
                updatedgame = this->updateGame(nextmoves[i]);
                nextgames.push_back(&updatedgame);
            }
        }
    }
    return nextgames;
}

#endif