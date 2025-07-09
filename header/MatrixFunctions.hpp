#ifndef MATRIXFUNCTIONS_HPP
#define MATRIXFUNCTIONS_HPP

#include <vector>
#include "Cell.hpp"

void Transposition (std::vector<std::vector<Cell>> &, short int);
void Swap_columns_small (std::vector<std::vector<Cell>> &, short int, short int, short int);
void Swap_columns_big (std::vector<std::vector<Cell>> &, short int, short int, short int);
void Swap_lines_small (std::vector<std::vector<Cell>> &, short int, short int, short int);
void Swap_lines_big (std::vector<std::vector<Cell>> &, short int, short int, short int);

#endif