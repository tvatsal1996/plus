#ifndef _FIELD_H_INCLUDED_
#define _FIELD_H_INCLUDED_

#include <string>

int cantorPairing (int x, int y) {
    int temp = (x+y)*(x+y+1);
    temp = temp/2;
    temp = temp + y;
    return temp;
}

class Field {
    public :
    int col;
    int row;
    bool operator <(const Field& rhs) const
    {
        return cantorPairing(col, row) < cantorPairing(rhs.col, rhs.row);
    }
    bool operator ==(const Field& rhs) const
    {
        return col == rhs.col && row == rhs.row;
    }
    bool operator !=(const Field& rhs) const
    {
        return col != rhs.col || row != rhs.row;
    }
    Field () {}
    Field(string info) {
        try
        {
            if(info.length() != 2 && info.length() != 0) {
                throw 3;
            } else {
                if (info.length() == 2){
                    row = info[1]-'0';
                    col = info[0]-'a'+1;
                    if (row < 1 || row > 8 || col < 1 || col > 8) {
                        throw 4;
                    }
                } else {
                    row = 0;
                    col = 0;
                }
            }
        }
        catch(int i) {
            switch (i) {
                case 3 : 
                    cout << "Invalid argument\n";
                    exit (EXIT_FAILURE);
                    break;
                case 4 :
                    cout << "Invalid Field\n";
                    exit (EXIT_FAILURE);
                    break;
                default :
                    cout << "Unknown error\n";
                    exit (EXIT_FAILURE);
                    break;
            }
        }
    }
    Field(int colx, int rowx) {
        col = colx;
        row = rowx;
        try {
            if (row < 1 || row > 8 || col < 1 || col > 8) {
                throw 5;
            }
        }
        catch (int i) {
            switch(i) {
                case 5 :
                    cout << "Invalid Field\n";
                    exit (EXIT_FAILURE);
            }
        }
    }
    string position() {
        char column = 'a'+col-1;
        char rowno = '0'+row;
        string str;
        str = str + column + rowno;
        return str;
    }
    int rank() {
        return 2 * min(col, 9-col)  * min(row, 9-row);
    }
    bool isValidField() {
        return 1 <= row && row <= 8 && 1 <= col && col <= 8;
    }
};

int fieldRank(const Field field){
    return 2 * min(field.col, 9-field.col) * min(field.row, 9-field.row);
}

#endif