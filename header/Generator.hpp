#ifndef GENERATOR_HPP
#define GENERATOR_HPP

#include <vector>

std::vector<std::vector<short int>> Generate (short int size, short int chance);
void Format (std::vector<std::vector<short int>> &mesh, short int size, short int chance);

#endif
