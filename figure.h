#ifndef _FIGURE_H_INCLUDED_
#define _FIGURE_H_INCLUDED_

typedef char figuretype;
typedef char figurecolor;

class Figure {
    private :
    figuretype type;
    figurecolor color;
    public :
    Figure() {}
    Figure(figuretype figtype, figurecolor figcolor) {
        type = figtype;
        color = figcolor;
    }
    void assignType(figuretype figtype) {
        type = figtype;
        return;
    }
    void assignColor(figurecolor figcolor) {
        color = figcolor;
        return;
    }
    figuretype getType() {
        return type;
    }
    figurecolor getColor() {
        return color;
    }
    bool operator ==(const Figure &rhs) const
    {
        return type == rhs.type && color == rhs.color;
    }
};

#endif