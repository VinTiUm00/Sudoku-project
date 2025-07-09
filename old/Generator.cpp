#include "../header/Generator.hpp"
#include <ctime>
#include <cstdlib>

std::vector<std::vector<Cell>> & Generate (short int mesh_size) {
    std::srand(std::time(NULL));
    std::vector<std::vector<Cell>> mesh;
    short int cur_id, max_id = mesh_size * mesh_size - 1;

    // Make empty mesh
    for (int x = 0; x < mesh_size * mesh_size; x++){
        mesh.push_back({});
        for (int y = 0; y < mesh_size * mesh_size; y++){
            mesh[x].push_back(Cell());
        }
    }

    // First
    std::vector<short int> data;
    for (int i = 0; i < mesh_size * mesh_size; i++){
        data.push_back(i+1);
    }

    for (int x = 0; x < mesh_size; x++){
        for (int y = 0; y < mesh_size; y++){
            cur_id = std::rand()%(max_id + 1);
            mesh[x][y].set_v(data[cur_id]);
            
            if (max_id != cur_id){
                std::swap(data[max_id], data[cur_id]);
            }
            max_id--;
        }
    }

    // Make preset
    std::vector<std::vector<short int>> hor_rand;
    std::vector<std::vector<short int>> ver_rand;

    data = {};
    for (int i = 1; i < mesh_size; i++){
        data.push_back(i);
    }

    for (int i = 0; i < mesh_size; i++){
        hor_rand.push_back({});
        ver_rand.push_back({});
    }

    for (int y = 0; y < mesh_size; y++){
        max_id = mesh_size - 2;
        for (int x = 0; x < mesh_size; x++){
            if (x){
                cur_id = std::rand()%(max_id + 1);
                hor_rand[x].push_back(data[cur_id]);

                if (max_id != cur_id){
                    std::swap(data[max_id], data[cur_id]);
                }
                max_id--;
            }
            else {
                hor_rand[x].push_back(0);
            }
        }
    }

    for (int x = 0; x < mesh_size; x++){
        max_id = mesh_size - 2;
        for (int y = 0; y < mesh_size; y++){
            if (y){
                cur_id = std::rand()%(max_id + 1);
                ver_rand[x].push_back(data[cur_id]);

                if (max_id != cur_id){
                    std::swap(data[max_id], data[cur_id]);
                }
                max_id--;
            }
            else {
                ver_rand[x].push_back(0);
            }
        }
    }

    // Others
    for (int y_big = 0; y_big < mesh_size; y_big++){
        for (int x_big = 0; x_big < mesh_size; x_big++){
            if (!(x_big or y_big)){
                break;
            }

            // Get data

            
            // Fill
            short int max_id_y = mesh_size - 1;
            for (int y_small = 0; y_small < mesh_size; y_small++){
                std::vector<short int> data_hor;
                for (int i = 0; i < mesh_size; i++){
                    data_hor.push_back(mesh[x_big * mesh_size + i][y_big * mesh_size + (y_small + hor_rand[x_big][y_big]) % mesh_size].get_v());
                }

                short int max_id_x = mesh_size - 1;
                for (int x_small = 0; x_small < mesh_size; x_small++){
                    std::vector<short int> data_ver;
                    for (int i = 0; i < mesh_size; i++){
                        data_ver.push_back(mesh[x_big * mesh_size + (x_small + ver_rand[x_big][y_big]) % mesh_size][y_big * mesh_size + i].get_v());
                    }

                    short int cur_id_x = std::rand()%(max_id_x + 1);
                    mesh[x_big * mesh_size + x_small][y_big * mesh_size + y_small].set_v(data_hor[cur_id_x]);

                    if (max_id_x != cur_id_x){
                        std::swap(data_hor[max_id_x], data_hor[cur_id_x]);
                    }
                    max_id_x--;
                }
            }
        }
    }

    return mesh;
}