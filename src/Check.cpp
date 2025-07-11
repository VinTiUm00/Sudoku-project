#include "Check.hpp"

bool isCellAccord2Rules (std::vector<std::vector<short int>> &mesh, short int size, short int x, short int y){
    // Check line
    for (short int j = 0; j < size * size; j++){
        if (y != j and mesh[x][y] == mesh[x][j]){
            return false;
        }
    }

    // Check column
    for (short int i = 0; i < size * size; i++){
        if (x != i and mesh[x][y] == mesh[i][y]){
            return false;
        }
    }

    // Check big cell
    for (short int i = x / size * size; i < (x / size + 1) * size; i++){
        for (short int j = y / size * size; j < (y / size + 1) * size; j++){
            if ((x != i or y != j) and mesh[x][y] == mesh[i][j]){
                return false;
            }
        }
    }

    return true;
}