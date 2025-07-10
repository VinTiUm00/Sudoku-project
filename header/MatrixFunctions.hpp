#ifndef MATRIXFUNCTIONS_HPP
#define MATRIXFUNCTIONS_HPP

#include <vector>

void Transposition (std::vector<std::vector<short int>> &mash, short int size);
void Swap_columns_small (std::vector<std::vector<short int>> &mash, short int size, short int value1, short int value2);
void Swap_columns_big (std::vector<std::vector<short int>> &mash, short int size, short int value1, short int value2);
void Swap_lines_small (std::vector<std::vector<short int>> &mash, short int size, short int value1, short int value2);
void Swap_lines_big (std::vector<std::vector<short int>> &mash, short int size, short int value1, short int value2);

#endif
