#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Defining the structure for the node
struct Node {
    int vertex_node;
    int weight_length;

    bool operator>(const Node &another) const {
        return weight_length > another.weight_length;
    }
};


// dijkstra function
void dijkstra(const vector<vector<pair<int, int>>> &graph_ds, int start_point, int end_point) {
    int n = graph_ds.size();
    vector<int> weight_length(n, INT_MAX);
    vector<int> parent_node(n, -1);
    priority_queue<Node, vector<Node>, greater<Node>> priorque;


  // Initializing the weight_length and parent_node vectors
    weight_length[start_point] = 0;
    priorque.push({start_point, 0});


  // Looping through the priority queue
    while (!priorque.empty()) {
        Node present_node = priorque.top();
        priorque.pop();

        int n_present = present_node.vertex_node;
        int dist = present_node.weight_length;

      // Looping through the adjacent nodes of the current node
        auto neighbor_node = graph_ds[n_present].begin();
        while (neighbor_node != graph_ds[n_present].end()) {
            int v_first = neighbor_node->first;
            int weight_cost = neighbor_node->second;

          // Checking if the weight_length of the adjacent node is greater than the current weight_length
            if (dist + weight_cost < weight_length[v_first]) {
                weight_length[v_first] = dist + weight_cost;
                parent_node[v_first] = n_present;
                priorque.push({v_first, weight_length[v_first]});
            }

            ++neighbor_node;
        }
    }

  // Printing the path from start_point to end_point
    cout << "Shortest Path from " << start_point << " to " << end_point << ":\n";
    cout << "Cost: " << weight_length[end_point] << "\nPath: ";

    int i = end_point;
    vector<int> path_traversal;
    while (i != -1) {
        path_traversal.push_back(i);
        i = parent_node[i];
    }

    for (int j = path_traversal.size() - 1; j >= 0; --j) {
        cout << path_traversal[j];
        if (j != 0) cout << " -> ";
    }
}


// main function defination
int main() {
    int num_of_Nodes;

  // Prompting the user to maximum number of nodes
    cout << "Enter the number of nodes should be present in the graph: ";
    cin >> num_of_Nodes;

    if (num_of_Nodes <= 0) {
        cout << "Enter atleast one node.\n";
        return 1;
    }

    vector<vector<pair<int, int>>> graph_ds(num_of_Nodes);
  cout << "If there is no connection enter -ve number:\n ";
 
    // Letting the user to enter the weights between nodes
    for (int node1 = 0; node1 < num_of_Nodes; ++node1) {
        for (int node2 = node1 + 1; node2 < num_of_Nodes; ++node2) {
            int weight_in_between;

            cout << "Enter weight from node " << node1 << " to " << node2 << ": ";
            cin >> weight_in_between;

            if (weight_in_between < 0) {
                continue;
            }

            // Check if the same edge already exists with a different weight
            for (const auto &edge_path : graph_ds[node1]) {
                if (edge_path.first == node2 && edge_path.second != weight_in_between) {
                    cout << "Different weights found between same nodes.\n";
                    return 1;
                }
            }
            // Pushing the edge and weight to the graph
            graph_ds[node1].push_back({node2, weight_in_between});
            graph_ds[node2].push_back({node1, weight_in_between});
        }
    }

    int start, end;

    // Prompting the user to input the starting node and the ending node
    cout << "Enter the start node: ";
    cin >> start;

    cout << "Enter the end node: ";
    cin >> end;

    dijkstra(graph_ds, start, end); // Calling dijkstra's function

    return 0;
}
