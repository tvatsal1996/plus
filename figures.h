#ifndef _FIGURE_H_INCLUDED_
#define _FIGURE_H_INCLUDED_

typedef string figuretype;
typedef string figurecolor;

class figure {
    private :
    figuretype type;
    figurecolor color;
    public :
    void assignType(figuretype figtype) {
        type = figtype;
    }
    void assignColor(figurecolor figcolor) {
        color = figcolor;
    }
    figuretype getType() {
        return type;
    }
    figurecolor getColor() {
        return color;
    }
};

#endif