#ifndef _GAME_H_INCLUDED_
#define _GAME_H_INCLUDED_

#include <iostream>
#include <iterator>
using namespace std;
#include "field.h"
#include "figure.h"
#include "move.h"
#include "board.h"

typedef string gamestatus;

// class GameStart {
//     private :
//         Board* board;
//         figurecolor color;
//         gamestatus status;
//     public :
//         Board* getBoard() {
//             return board;
//         }
//         figurecolor getColor() {
//             return color;
//         }
//         gamestatus getStatus() {
//             return status;
//         }
//         GameStart() {}
//         GameStart(Board* gameboard, figurecolor gameColor, gamestatus gameStatus) {
//             board = gameboard;
//             color = gameColor;
//             status = gameStatus;
//         }
// };

class OngoingGame {
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
        OngoingGame() {}
        OngoingGame(Board* gameboard, Move gameLastMove, figurecolor gameColor, gamestatus gameStatus){
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
            cout << "Gamecolor rank = " << colorRank << " and other color rank = " << otherColorRank << endl;
            return colorRank - otherColorRank;
        }
};

// class Game : public GameStart {
//     using GameStart::GameStart;
//     private:
//         Move lastmove;
//     public :
//         Game() {}
//         Game(Board* gameboard, Move gameLastMove, figurecolor gameColor, gamestatus gameStatus) {
//             board = gameboard;
//             lastmove = gameLastMove;
//             color = gameColor;
//             status = gameStatus;
//         } 
//         int rank() {
//             int colorRank = 0, otherColorRank = 0;
//             for(auto it = board->begin(); it != board->end(); it++){
//                 if (it->second.getColor() == color){
//                     colorRank += it->second.rank();
//                     colorRank += it->first.rank();
//                 } else {
//                     otherColorRank += it->second.rank();
//                     otherColorRank += it->first.rank();
//                 }
//             }
//             cout << "Gamecolor rank = " << colorRank << " and other color rank = " << otherColorRank << endl;
//             return colorRank - otherColorRank;
//         }
// };

#endif