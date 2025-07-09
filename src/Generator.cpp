#include "../header/Generator.hpp"
#include <iostream>

std::vector<std::vector<Cell>> & Generate (short int mesh_size) {
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

    return mesh;
}