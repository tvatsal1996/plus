#include <iostream>
using namespace std;
#include "figures.h"

int main() {
    figure fig1;
    fig1.assignType("Knight");
    fig1.assignColor("White");
    cout << fig1.getType() << endl;
    return 0;
}