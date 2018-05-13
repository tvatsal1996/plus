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
        Game* updateGame(Move move);
        vector<Game*> nextGames();
        Game* bestGame();
};

Board* Game::getBoard() {
    // showBoard(board);
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
    int finalRank = colorRank - otherColorRank;
    
    return finalRank;
}

Game* Game::updateGame(Move move){
    Game* newgame = new Game;
    *newgame = Game(updateBoard(board, move), move, other(color), status);
    return newgame;
}

vector<Game*> Game::nextGames(){
    vector<Game*> nextgames;
    vector<Move> nextmoves;
    for (auto it = board->begin(); it != board->end(); it++){
        if(it->second.getColor() == color){
            figuretype type = it->second.getType();
            Field field = it->first;
            Game* updatedgame;
            nextmoves = getMoves(board, field, type, color);
            for (int i = 0; i<nextmoves.size(); i++){
                updatedgame = this->updateGame(nextmoves[i]);
                nextgames.push_back(updatedgame);
            }
        }
    }
    return nextgames;
}

Game* Game::bestGame(){
    vector<Game*> validGames = this->nextGames();
    Game* bestgame;
    try{
        if (validGames.size()==0){
            throw 1;
        }
        int rank = validGames[0]->rank();
        int temp = rank;
        bestgame = validGames[0];
        for (int i = 1; i<validGames.size(); i++){
            temp = validGames[i]->rank();
            if (temp > rank){
                rank = temp;
                bestgame = validGames[i];
            }
        }  
    }
    catch(int i) {
        if (i==1){
            cout << "No moves possible\n";
            exit (EXIT_FAILURE);
        }
    }
    return bestgame;
}

#endif