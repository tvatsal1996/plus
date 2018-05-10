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
    int rank(){
        switch (type)
        {
            case 'q' :
                return 900;
                break;
            case 'r' :
                return 450;
                break;
            case 'b' :
                return 300;
                break;
            case 'n' :
                return 300;
                break;
            case 'p' :
                return 50;
                break;
            default :
                return 0;
                break;
            
        }
    } 
};

#endif