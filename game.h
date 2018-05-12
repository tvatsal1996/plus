#ifndef _GAME_H_INCLUDED_
#define _GAME_H_INCLUDED_

// #include <iostream>
using namespace std;
#include <iterator>
#include <vector>
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
        Board* getBoard();
        Move getLastMove();
        figurecolor getColor();
        gamestatus getStatus();
        Game();
        Game(Board* gameboard, Move gameLastMove, figurecolor gameColor, gamestatus gameStatus);
        int rank();
        Game updateGame(Move move);
        vector<Game> nextGames();
};

Board* Game::getBoard() {
    return board;
}

Move Game::getLastMove() {
    return lastmove;
}

figurecolor Game::getColor() {
    return color;
}

gamestatus Game::getStatus() {
    return status;
}

Game::Game() {}

Game::Game(Board* gameboard, Move gameLastMove, figurecolor gameColor, gamestatus gameStatus){
    board = gameboard;
    lastmove = gameLastMove;
    color = gameColor;
    status = gameStatus;
}

int Game::rank() {
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

Game Game::updateGame(Move move){
    Game newgame;
    Board newBoard = *board;
    updateBoard(&newBoard, move);
    // showBoard(&newBoard);
    return Game(&newBoard, move, other(color), status);
}

vector<Game> Game::nextGames(){
    vector<Game> nextgames;
    vector<Move> nextmoves;
    for (auto it = board->begin(); it != board->end(); it++){
        if(it->second.getColor() == color){
            figuretype type = it->second.getType();
            Field field = it->first;
            Game updatedgame;
            nextmoves = getGames(board, field, type, color);
            for (int i = 0; i<nextmoves.size(); i++){
                updatedgame = this->updateGame(nextmoves[i]);
                nextgames.push_back(updatedgame);
            }
        }
    }
    return nextgames;
}

#endif