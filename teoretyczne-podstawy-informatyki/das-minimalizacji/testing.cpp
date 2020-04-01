#include <iostream>
#include <set>

#include "das.hpp"

int main() {
    // hand input
    // bool validated = mini_das.inputDAS();

    // automatic input
    int node_number = 5;
    int starting_node = 0;
    std::set<int> ending_nodes {0, 1, 3, 4};
    std::vector<int> _delta_matrix(10);
    _delta_matrix[0] = 1;
    _delta_matrix[1] = 3;
    _delta_matrix[2] = 1;
    _delta_matrix[3] = 2;
    _delta_matrix[4] = 2;
    _delta_matrix[5] = 2;
    _delta_matrix[6] = 1;
    _delta_matrix[7] = 4;
    _delta_matrix[8] = 1;
    _delta_matrix[9] = 3;


    std::set<int> e = {0}; 
    std::set<int> f = {1}; 
    std::set<int> g = {2};
    std::set<int> h = {3};
    std::set<int> i = {4};

    std::vector<std::set<int>> _node_names {e, f, g, h, i};

    DAS das(node_number, starting_node, ending_nodes, _delta_matrix, _node_names);
    das.print();

    // minimization
    DAS min_das = das.minimizeDAS();

    min_das.print();


    
}