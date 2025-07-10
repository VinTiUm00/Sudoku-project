#include "MatrixFunctions.hpp"

void Transposition (std::vector<std::vector<short int>> & mesh_main, short int size){
    for (short int i = 0; i < size * size - 1; i++){
        for (short int j = i + 1; j < size * size; j++){
            std::swap(mesh_main[i][j], mesh_main[j][i]);
        }
    }
}

void Swap_columns_small (std::vector<std::vector<short int>> & mesh_main, short int size, short int small_column_1, short int small_column_2){
    std::swap(mesh_main[small_column_1], mesh_main[small_column_2]);
}

void Swap_columns_big (std::vector<std::vector<short int>> & mesh_main, short int size, short int big_column_1, short int big_column_2){
    for (short int i = 0; i < size; i++){
        std::swap(mesh_main[big_column_1 * size + i], mesh_main[big_column_2 * size + i]);
    }
}

void Swap_lines_small (std::vector<std::vector<short int>> & mesh_main, short int size, short int small_line_1, short int small_line_2){
    for (short int i = 0; i < size * size; i++){
        std::swap(mesh_main[i][small_line_1], mesh_main[i][small_line_2]);
    }
}

void Swap_lines_big (std::vector<std::vector<short int>> & mesh_main, short int size, short int big_line_1, short int big_line_2){
    for (short int i = 0; i < size; i++){
        for (short int j = 0; j < size * size; j++){
            std::swap(mesh_main[j][big_line_1 * size + i], mesh_main[j][big_line_2 * size + i]);
        }
    }
}
