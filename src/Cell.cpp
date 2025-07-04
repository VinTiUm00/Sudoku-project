#include "../header/Cell.hpp"

Cell::Cell (short int val){
    set_v(val);
}

void Cell::set_v (short int new_val){
    this->val = new_val;
}

short int Cell::get_v () {
    return this->val;
}

void Cell::set_gen (bool new_gen) {
    this->generated = new_gen;
}

bool Cell::get_gen () {
    return this->generated;
}