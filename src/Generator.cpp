#include "../header/Generator.hpp"
#include "../header/MatrixFunctions.hpp"

#include <ctime>
#include <cstdlib>

std::vector<std::vector<Cell>> & Generate (short int mesh_size) {
    std::srand(std::time(NULL));
    std::vector<std::vector<Cell>> mesh;
    short int amount = mesh_size * mesh_size;

    // Create data with nums 1-amount
    std::vector<short int> data;
    for (short int i = 1; i <= amount; i++){
        data.push_back(i);
    }

    // Create pre-mesh
    int cust_id;
    for (short int x = 0; x < amount; x++){
        mesh.push_back({});
        cust_id = mesh_size * x + x / mesh_size;

        for (short int y = 0; y < amount; y++){
            mesh[x].push_back(Cell(data[cust_id % amount]));
            cust_id++;
        }
    }

    // Preparation for shufflig
    data = {};
    for (int i = 0; i < mesh_size; i++){
        data.push_back(i);
    }
    short int max_num, cur_id_1, cur_id_2, cell_id, cur_num;

    // Shuffling
    int iterations = 1000;
    for (int iter = 0; iter < iterations; iter++){
        max_num = mesh_size;
        short int rand_num = rand() % 5;
        if (rand_num == 0){
            Transposition(mesh, mesh_size);
        }
        else if (rand_num == 1){
            cell_id = rand() % mesh_size;
            cur_num = rand() % max_num;
            cur_id_1 = data[cur_num];
            max_num--;
            std::swap(data[cur_num], data[max_num]);
            cur_id_2 = data[rand() % max_num];

            Swap_columns_small(mesh, mesh_size, cell_id * mesh_size + cur_id_1, cell_id * mesh_size + cur_id_2);
        }
        else if (rand_num == 2){
            cur_num = rand() % max_num;
            cur_id_1 = data[cur_num];
            max_num--;
            std::swap(data[cur_num], data[max_num]);
            cur_id_2 = data[rand() % max_num];

            Swap_columns_big(mesh, mesh_size, cur_id_1, cur_id_2);
        }
        else if (rand_num == 3){
            cell_id = rand() % mesh_size;
            cur_num = rand() % max_num;
            cur_id_1 = data[cur_num];
            max_num--;
            std::swap(data[cur_num], data[max_num]);
            cur_id_2 = data[rand() % max_num];

            Swap_lines_small(mesh, mesh_size, cell_id * mesh_size + cur_id_1, cell_id * mesh_size + cur_id_2);
        }
        else {
            cur_num = rand() % max_num;
            cur_id_1 = data[cur_num];
            max_num--;
            std::swap(data[cur_num], data[max_num]);
            cur_id_2 = data[rand() % max_num];

            Swap_lines_big(mesh, mesh_size, cur_id_1, cur_id_2);
        }
    }

    return mesh;
}