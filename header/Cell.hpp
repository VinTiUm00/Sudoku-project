#ifndef CELL_HPP
#define CELL_HPP

class Cell {
public:
    Cell();
    Cell(short int);

    void set_v (short int);
    short int get_v ();
    void set_gen (bool);
    bool get_gen ();
private:
    short int val = 0;
    bool generated = true;
};

#endif
