#ifndef __DAS
#define __DAS

#include <iostream>
#include <set>
#include <stdexcept>
#include <iomanip>
#include <string>
#include <sstream>
#include "das.hpp"

// getters setters
int DAS::size() const {
    return nodes_number;
}

void DAS::setSize(const int& size) {
    nodes_number = size;
    delta_matrix.resize(nodes_number * symbols_number);
}

void DAS::setStartingNode(const int& _node_number) {
    starting_node = _node_number;
}

int DAS::getStartingNode() const {
    return starting_node;
}

void DAS::setEndingNodes() {
    std::set<int> new_ending_nodes;
    std::cout << "Input node numbers of ending nodes (-1 ends input): ";
    int node_no = 0;
    while(true) {
        std::cin >> node_no;
        if (node_no == -1) {
            break;
        }
        new_ending_nodes.insert(node_no);
    }

    ending_nodes = new_ending_nodes;
}

void DAS::setEndingNodes(std::set<int> _ending_nodes) {
    ending_nodes = _ending_nodes;
}

std::set<int> DAS::getEndingNodes() const {
    return ending_nodes;
}

void DAS::setFunctionMatrix() {
    std::cout << "Input pairs of values coresponding to outputs of the nodes." << std::endl;

    for (int i = 0; i < nodes_number; i++) {
        for (int j = 0; j < symbols_number; j++) {
            std::cin >> delta_matrix[i * symbols_number + j];
        }
    }
}

void DAS::setFunctionMatrix(std::vector<int> new_delta_matrix) {
    delta_matrix = new_delta_matrix;
}

std::vector<int> DAS::getFunctionMatrix() const {
    return delta_matrix;
}

void DAS::setNodeNames(std::vector<std::set<int>> new_node_names) {
    node_names = new_node_names;
}

// DAS validation
bool DAS::validateDAS() {
    if (starting_node >= nodes_number || starting_node < 0) {
        throw std::runtime_error("Starting node is not in range of nodes number.");
    }

    for (auto it = ending_nodes.begin(); it != ending_nodes.end(); it++) {
        if (*it >= nodes_number || *it < 0) {
            throw std::runtime_error("One of the ending nodes is out of range.");
        }
    }
    return true;
}

// constructors, destructor, assignment operators
DAS::DAS(int _nodes_number, int _starting_node,
         std::set<int> _ending_nodes, std::vector<int> _delta_matrix, std::vector<std::set<int>> _node_names) {
    nodes_number = _nodes_number;
    starting_node = _starting_node;
    ending_nodes = _ending_nodes;
    delta_matrix = _delta_matrix;
    node_names = _node_names;

    validateDAS();
}

// input output
bool DAS::inputDAS() {
    std::cout << "Input" << std::endl;
    
    // size
    std::cout << "Input number of nodes: ";
    int nodes;
    std::cin >> nodes;
    setSize(nodes);

    // node names setting
    std::vector<std::set<int>> new_node_names;
    for (int i = 0; i < nodes; i++) {
        std::set<int> init {i};
        new_node_names.push_back(init);
    }
    node_names = new_node_names;

    // starting node setting
    std::cout << "Starting node number: ";
    int starting_no;
    std::cin >> starting_no;
    setStartingNode(starting_no);

    // ending node setting
    setEndingNodes();

    // set function matrix
    setFunctionMatrix();

    bool validated = validateDAS();
    return validated;
}


void DAS::print() const {
    std::cout << "Starting node number: " <<  starting_node << std::endl;
    std::cout << "Ending nodes numbers: ";
    for (auto it = ending_nodes.begin(); it != ending_nodes.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "Delta function: " << std::endl;
    for (int i = 0; i < nodes_number; i++) {
        outputNode(i);
    }
}

void DAS::outputNode(const int& _node_number) const {
    const int print_width = 15;
    if (_node_number == 0) {
        std::cout 
        << std::setw(print_width) << "Node no" 
        << std::setw(print_width) << "Node name";
        for (int i = 0; i < symbols_number; i++) {
            std::cout << std::setw(print_width) << char('a' + i);
        }
        std::cout << std::endl;
    }

    std::cout 
    << std::setw(print_width) 
    << _node_number
    << std::setw(print_width) << outputNodeName(_node_number, print_width)
    << std::setw(print_width) << delta_matrix[symbols_number * _node_number]
    << std::setw(print_width) << delta_matrix[symbols_number * _node_number + 1];
    std::cout << std::endl;
}

std::string DAS::outputNodeName(const int& _node_number, const int& _print_width) const {
    std::ostringstream oss;
    oss << "" << "{";
    bool first = true;
    for (auto it = node_names[_node_number].begin(); 
            it != node_names[_node_number].end(); 
            it++) {
        if (first) {
            oss << *it;
            first = false;
        } else {
            oss << " " << *it; 
        }
    }
    oss << "}";
    return oss.str();
}

// MINIMIZATION
DAS DAS::minimizeDAS() const {
    
    std::vector<bool> equivalence_matrix = buildEquivalenceMatrix();

    // for (int i = 0; i < nodes_number; i++) {
    //     for (int j = 0; j < i; j++) {
    //         std::cout << equivalence_matrix[i * nodes_number + j] << " ";
    //     }
    //     std::cout << "s" << i << std::endl;
    // }

    std::vector<std::set<int>> new_node_names = buildNewNodeNames(equivalence_matrix); 
    
    // for(auto it = new_node_names.begin(); it != new_node_names.end(); it++) {
    //     for (auto set_it = it->begin(); set_it != it->end(); set_it++) {
    //         std::cout << *set_it << " ";
    //     }
    //     std::cout << std::endl;
    // }

    // minimized das size
    int minimized_nodes_number = new_node_names.size();
    // std::cout << "New size: " << minimized_nodes_number << std::endl;

    // minimized das starting node index
    int minimized_starting_node = findStartingNode(starting_node, new_node_names);
    // std::cout << "New starting node: " << minimized_starting_node << std::endl;

    // minimized das ending nodes
    std::set<int> new_ending_nodes = findEndingNodes(ending_nodes, new_node_names);
    // std::cout << "New ending nodes numbers: ";
    // for (auto it = new_ending_nodes.begin(); it != new_ending_nodes.end(); it++) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // minimized DAS delta function matrix
    std::vector<int> new_delta_function = buildNewDeltaFunction(new_node_names, delta_matrix);
    // std::cout << "New delta function: " << std::endl;
    // for (int i = 0; i < minimized_nodes_number; i++) {
    //     for (int j = 0; j < symbols_number; j++) {
    //         std::cout << new_delta_function[i * symbols_number + j] << " ";
    //     }
    //     std::cout << std::endl;
    // }

    
    DAS minimized_das(minimized_nodes_number, minimized_starting_node, 
        new_ending_nodes, new_delta_function, new_node_names);
    
    return minimized_das;
}

void DAS::DFS(std::set<int>& node_name, const int& current_node, bool* visited_array, const std::vector<bool>& equivalence_matrix) const {
    visited_array[current_node] = true;
    node_name.insert(current_node);
    // std::cout << current_node << " ";

    // covers these neighbours, eg:
    // for current_node = 2
    // s0
    // 0 s1 
    // 0 0 s2 <- this verse
    // 1 0 0 s3
    // 1 0 0 1 s4
    for (int i = 0; i < current_node; i++) {
        if (equivalence_matrix[current_node * nodes_number + i] == true && 
        visited_array[i] == false) {
            DFS(node_name, i, visited_array, equivalence_matrix);
        }
    }

    // covers these neighbours, eg:
    // for current_node = 2
    // s0
    // 0 s1 
    // 0 0 s2 
    // 1 0 0 s3
    // 1 0 0 1 s4
    //     ^
    //     | 
    //  this column
    for (int i = current_node + 1; i < nodes_number; i++) {
        if (equivalence_matrix[i * nodes_number + current_node] == true && 
            visited_array[i] == false) {
                DFS(node_name, i, visited_array, equivalence_matrix);
        }
    }

}

std::vector<bool> DAS::buildEquivalenceMatrix() const {
    std::vector<bool> equivalence_matrix (nodes_number * nodes_number, true);
        
        // mark pairs of ending-nonending nodes as nonequivalent
        for (int i = 0; i < nodes_number; i++) {
            for (int j = 0; j < i; j++) {
                if (ending_nodes.count(i) != ending_nodes.count(j)) {
                    equivalence_matrix[i * nodes_number + j] = false;
                }
            }
        }

        // if something was changed in the equivalence matrix, do not end
        // the algorithm, it needs to run another iteration 
        bool changed_matrix = false;

        // for (int i = 0; i < nodes_number; i++) {
        //     for (int j = 0; j < i; j++) {
        //         std::cout << equivalence_matrix[i * nodes_number + j] << " ";
        //     }
        //     std::cout << "s" << i << std::endl;
        // }

        do {
            changed_matrix = false;
            for (int i = 0; i < nodes_number; i++) {
                for (int j = 0; j < i; j++) {
                    bool equivalent = true;
                    if (equivalence_matrix[i * nodes_number + j] == false) {
                        continue;
                    }
                    for (int symbol = 0; symbol < symbols_number; symbol++) {
                        // std::cout << "Values from delta matrix: " ;
                        // std::cout << delta_matrix[i * symbols_number + symbol] << " " <<
                        //     delta_matrix[j * symbols_number + symbol];

                        equivalent =
                            equivalence_matrix[delta_matrix[i * symbols_number + symbol] * nodes_number +
                                delta_matrix[j * symbols_number + symbol]] &&
                            equivalence_matrix[delta_matrix[j * symbols_number + symbol] * nodes_number +
                                delta_matrix[i * symbols_number + symbol]];
                        
                        // std::cout << "Nodes: " << i << " " << j << " " << equivalent << std::endl;
                        if (!equivalent) {
                            equivalence_matrix[i * nodes_number + j] = false;
                            changed_matrix = true;
                            break;
                        }
                    }
                }
            }
        } while (changed_matrix);
    return equivalence_matrix;
}

std::vector<std::set<int>> DAS::buildNewNodeNames(const std::vector<bool>& equivalence_matrix) const {
    std::vector<std::set<int>> new_node_names;

    // uses DFS to find all connected subgraphs of the graph created
    // based on the connectivity map equivalence_matrix

    bool* visited_array = new bool[nodes_number] {false};

    for (int i = 0; i < nodes_number; i++) {
        std::set<int> new_node_name;
        if (visited_array[i] == false) {
            DFS(new_node_name, i, visited_array, equivalence_matrix);
            new_node_names.push_back(new_node_name);
        }
    }

    return new_node_names;
}

int DAS::findStartingNode(const int& old_starting_node, const std::vector<std::set<int>>& new_node_names) const {
    for(auto it = new_node_names.begin(); it != new_node_names.end(); it++) {
        for (auto set_it = it->begin(); set_it != it->end(); set_it++) {
            if (*set_it == old_starting_node) {
                return std::distance(new_node_names.begin(), it);
            }
        }
    }
    throw std::runtime_error("Starting node not found.");
}

std::set<int> DAS::findEndingNodes(const std::set<int>& old_ending_nodes, const std::vector<std::set<int>>& new_node_names) const {
    std::set<int> ending_nodes;
    for(auto it = new_node_names.begin(); it != new_node_names.end(); it++) {
        for (auto set_it = it->begin(); set_it != it->end(); set_it++) {
            if (old_ending_nodes.count(*set_it) == 1) {
                ending_nodes.insert(std::distance(new_node_names.begin(), it));
            }
        }
    }
    return ending_nodes;
}

std::vector<int> DAS::buildNewDeltaFunction(const std::vector<std::set<int>>& new_node_names, const std::vector<int>& old_delta_function) const {
    std::vector<int> new_delta_function(new_node_names.size() * symbols_number);
    auto new_node_names_it = new_node_names.begin();

    for (int i = 0; i < new_node_names.size(); i++) {
        int node_representative = *new_node_names_it[i].begin();
        for (int j = 0; j < symbols_number; j++) {
            int old_delta_matrix_next_node = old_delta_function[node_representative * symbols_number + j];
            new_delta_function[i * symbols_number + j] = 
                findStartingNode(old_delta_matrix_next_node, new_node_names);
        }
    }

    return new_delta_function;
}



#endif