#include "Generator.hpp"

#include <cstdlib>
#include <ctime>

void Format (std::vector<std::vector<short int>> &mesh, short int size, short int chance){
    std::srand(time(NULL));

    for (short int x = 0; x < size * size; x++){
        for (short int y = 0; y < size * size; y++){
            if (rand() % 100 < chance){
                mesh[x][y]=0;
            }
        }
    }
}
