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
};

vector<Move> getGames(Board* board, Field field, figuretype type, figurecolor color){
    figurecolor gameColor = other(color);
    vector<Move> movesList;
    switch (type)
    {
        case 'r' :
            vector <pair<int, int> > incrList = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1)};
            for (int i = 0; i<incrList.size(); i++){
                int col_inc = incrList[i].first, row_inc = incrList[i].second; 
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                while(board->find(temp) == board->end() && temp.isValidField()){
                    movesList.push_back(Move(field, temp, false));
                    temp.row = temp.row + row_inc;
                    temp.col = temp.col + col_inc;
                }
                if (board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)) {
                    movesList.push_back(Move(field, temp, true));
                }
            }
            break;
        case 'b' :
            vector <pair<int, int> > incrList = {make_pair(1,1), make_pair(-1,-1), make_pair(1,-1), make_pair(-1, 1)};
            for (int i = 0; i<incrList.size(); i++){
                int col_inc = incrList[i].first, row_inc = incrList[i].second; 
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                while(board->find(temp) == board->end() && temp.isValidField()){
                    movesList.push_back(Move(field, temp, false));
                    temp.row = temp.row + row_inc;
                    temp.col = temp.col + col_inc;
                }
                if (board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)) {
                    movesList.push_back(Move(field, temp, true));
                }
            }
            break;
        case 'q' :
            vector <pair<int, int> > incrList = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1), make_pair(1,1), make_pair(-1,-1), make_pair(1,-1), make_pair(-1, 1)};
            for (int i = 0; i<incrList.size(); i++){
                int col_inc = incrList[i].first, row_inc = incrList[i].second; 
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                while(board->find(temp) == board->end() && temp.isValidField()){
                    movesList.push_back(Move(field, temp, false));
                    temp.row = temp.row + row_inc;
                    temp.col = temp.col + col_inc;
                }
                if (board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)) {
                    movesList.push_back(Move(field, temp, true));
                }
            }
            break;
        case 'k' :
            vector <pair<int, int> > incrList = {make_pair(1,0), make_pair(-1,0), make_pair(0,1), make_pair(0,-1), make_pair(1,1), make_pair(-1,-1), make_pair(1,-1), make_pair(-1, 1)};
            for (int i = 0; i<incrList.size(); i++) {
                int col_inc = incrList[i].first, row_inc = incrList[i].second;
                Field temp = Field(field.col + col_inc, field.row + row_inc);
                if (board->find(temp) == board->end()){
                    movesList.push_back(Move(field, temp));
                } else if (board->find(temp) != board->end() && board->find(temp)->second.getColor() == other(color)){
                    movesList.push_back(Move(field, temp, true));
                } else{
                }
            }
            break;
        case 'p' :
            if(color == 'w'){
            } else{
            } 
            break;
        default :
            break;
    }
}

vector<Game*> nextGames(Game *game){
    vector<Game*> nextgames;
    vector<Move> nextmoves;
    Board* board = game->getBoard();
    figurecolor color = game->getColor();
    gamestatus status = game->getStatus();
    for (auto it = board->begin(); it != board->end(); it++){
        if(it->second.getColor() == color){
            figuretype type = it->second.getType();
            Field field = it->first;
            // nextgames.insert(nextgames.end(), tempgames.begin(), tempgames.end());
        }
    }
    return nextgames;
}

#endif