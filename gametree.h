#ifndef _GAMETREE_H_INCLUDED_
#define _GAMETREE_H_INCLUDED_

#include <vector>
#include "game.h"

class Tree {
    public :
    Game root;
    vector<Tree*> children;
    Tree() {}
};

Tree* makeTree(Game game, int depth){
    Tree* gametree = new Tree;
    gametree->root = game;  
    vector<Game> nextgames = game.nextGames();
    if (nextgames.size() == 0){
        gametree->children = {NULL};
        return gametree;
    }
    if (depth == 0){
        gametree->children = {NULL};
        return NULL;
    }
    vector<Tree*> childvect;
    for (int i = 0; i<nextgames.size(); i++){
        childvect.push_back(makeTree(nextgames[i], depth-1));
    }
    gametree->children =  childvect;
    return gametree; 
}

#endif