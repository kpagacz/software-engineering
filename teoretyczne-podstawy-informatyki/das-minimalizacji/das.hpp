// USAGE
// Compile entry.cpp and das.cpp. Run in terminal.
// Interaction example:
//
// $ ./entry.exe
// Input number of nodes: 5
// Starting node number: 0     
// Input node numbers of ending nodes (-1 ends input): 0 1 3 4 -1
// Input pairs of values coresponding to outputs of the nodes.
// 1 3 1 2 2 2 1 4 1 3
// YOUR DAS
// Starting node number: 0
// Ending nodes numbers: 0 1 3 4
// Delta function:
//         Node no      Node name              a              b
//               0            {0}              1              3
//               1            {1}              1              2
//               2            {2}              2              2
//               3            {3}              1              4
//               4            {4}              1              3
// MINIMIZED DAS
// Starting node number: 0
// Ending nodes numbers: 0 1
// Delta function:
//         Node no      Node name              a              b
//               0        {0 3 4}              1              0
//               1            {1}              1              2
//               2            {2}              2              2

#include <set>
#include <vector>
#include <string>

class DAS {
    private:
        int nodes_number = 0;
        int starting_node;
        std::set<int> ending_nodes;
        std::vector<int> delta_matrix;
        int symbols_number = 2;
        std::vector<std::set<int>> node_names;

    public:
        DAS() = default;
        DAS(int nodes_number, int starting_node,
         std::set<int> ending_nodes, std::vector<int> delta_matrix,
         std::vector<std::set<int>> _node_names);
        ~DAS() = default;

        // input, outputs
        bool inputDAS();
        
        void print() const;
        void outputNode(const int&) const;
        std::string outputNodeName(const int&, const int&) const;

        // setters getters
        int size() const;
        void setSize(const int& size);

        void setStartingNode(const int& node_number);
        int getStartingNode() const;

        void setEndingNodes();
        void setEndingNodes(std::set<int> ending_nodes);
        std::set<int> getEndingNodes() const;

        void setFunctionMatrix();
        void setFunctionMatrix(std::vector<int> delta_matrix);
        std::vector<int> getFunctionMatrix() const;

        void setNodeNames(std::vector<std::set<int>> _node_names);

        // validation
        bool validateDAS();

        // minimization
        DAS minimizeDAS() const;
        void DFS(std::set<int>& node_name, const int& current_node, bool* visited_array, const std::vector<bool>& equivalence_matrix) const;
        std::vector<bool> buildEquivalenceMatrix() const;
        std::vector<std::set<int>> buildNewNodeNames(const std::vector<bool>& _equivalence_matrix) const;
        int findStartingNode(const int& old_starting_node, const std::vector<std::set<int>>& new_node_names) const;
        std::set<int> findEndingNodes(const std::set<int>& old_ending_nodes, const std::vector<std::set<int>>& new_node_names) const;
        std::vector<int> buildNewDeltaFunction(const std::vector<std::set<int>>& new_node_names, const std::vector<int>& old_delta_function) const;
};