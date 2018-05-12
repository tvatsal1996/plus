#include <iostream>
#include <vector>
using namespace std;

class Bus {
    private :
    int milage;
    int seats;
    string name;
    public :
    Bus() {}
    Bus(int milg, int noOfSeats, string busName) {
        milage = milg;
        seats = noOfSeats;
        name = busName;
    }
    int getMilage(){
        return milage;
    }
    int getSeats(){
        return seats;
    }
    string getName(){
        return name;
    }
    void assignMilage(int milg){
        milage = milg;
    }
    void assignSeats(int noOfSeats){
        seats = noOfSeats;
    }
    void assignName(string busName){
        name = busName;
    }
};

class Tree {
    public:
    vector<Bus*> buslist;
    int totalmilage;
    Tree() {}
    int getTotalMilage(){
        int total = 0;
        for (int i = 0; i<buslist.size(); i++) {
            // cout << buslist[i]->getMilage() << " ";
            total = total + buslist[i]->getMilage();
        }
        return total;
    }
    int getTotalSeats(){
        int total = 0;
        for (int i = 0; i<buslist.size(); i++){
            total = total + buslist[i]->getSeats();
        }
        return total;
    }
    string getBunchName() {
        return buslist[0]->getName();
    }
};

// void func(Tree* tree){
//     Bus* bus = tree->root;
//     bus->assignMilage(bus->getMilage()*2);
//     bus->assignSeats(bus->getSeats()*2);
//     return;
// }

int main() {
    Tree tree;
    vector<Bus*> buses;
    Bus* bus;
    for (int i = 1; i<=5; i++){
        // Bus bus = Bus(i*10, i*5, "spider");
        // buses.push_back(&bus);
        bus = new Bus;
        *bus = Bus(i*10, i*5, "spider");
        buses.push_back(bus);
        // delete bus;
    }
    delete bus;
    tree.buslist = buses;
    tree.totalmilage = 100;
    cout << "total milage of all the buses in the bunch = " << tree.getTotalMilage() << endl;
    cout << "total seats in all the buses of the bunch = " << tree.getTotalSeats() << endl;
    cout << "Name of the bunch of buses = " << tree.getBunchName() << endl;
    return 0;
}