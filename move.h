#ifndef _MOVE_H_INCLUDED_
#define _MOVE_H_INCLUDED_

class Move {
    public :
    string from;
    string to;
    Move (string fieldfrom, string fieldto) {
        from = fieldfrom;
        to = fieldto;
        return;
    }
};

#endif