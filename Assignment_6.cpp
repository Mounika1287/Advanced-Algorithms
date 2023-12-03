#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Definition for a binary tree node.
struct Node {
    char input_string;
    unsigned repeat_frequency;
    Node *left_node, *right_node;

    // Constructor
    Node(char input_data, unsigned repeatition, Node* lft_n = NULL, Node* rht_n = NULL)
        : input_string(input_data), repeat_frequency(repeatition), left_node(lft_n), right_node(rht_n) {}
};

struct compare {
    bool operator()(Node* lft_n, Node* rht_n) {
        return (lft_n->repeat_frequency > rht_n->repeat_frequency);
    }
};

// Function to print the Huffman code for each character.
void print_output_codes(Node* root_node, string str_value) {
    if (!root_node)
        return;

    if (root_node->input_string != '$' && root_node->input_string != '\0') // if the node is a leaf node
        cout << root_node->input_string << ": " << str_value << "\n";

    // traverse the left subtree
    print_output_codes(root_node->left_node, str_value + "0");
    // traverse the right subtree
    print_output_codes(root_node->right_node, str_value + "1");
}

// Function to perform Huffman Coding
void Huffman_Coding(const string& input_str, const vector<unsigned>& repeat_freq) {
    priority_queue<Node*, vector<Node*>, compare> min_Heap;

    // Create nodes for each character and push them to the min heap
    for (int i = 0; i < input_str.length(); ++i)
        min_Heap.push(new Node(input_str[i], repeat_freq[i]));

    while (min_Heap.size() != 1) {
        Node* left_side = min_Heap.top();
        min_Heap.pop();

        Node* right_side = min_Heap.top();
        min_Heap.pop();

        Node* top_value = new Node('$', left_side->repeat_frequency + right_side->repeat_frequency, left_side, right_side);
        min_Heap.push(top_value);
    }

    print_output_codes(min_Heap.top(), ""); // print the Huffman tree
}

int main() {
    string input_str;
    int no_of_characters;

    // Prompting the user to enter the input string
    cout << "Enter the input string: ";
    cin >> input_str;

    // Prompting the user to enter the number of characters
    no_of_characters = input_str.length();

    // Allocating memory for the arrays
    vector<unsigned> repeat_freq(no_of_characters);

    // Prompting the user to enter the frequencies of the characters
    cout << "Enter the repeat frequencies: ";
    for (int i = 0; i < no_of_characters; ++i)
        cin >> repeat_freq[i];

    // Calling the Huffman Coding function
    Huffman_Coding(input_str, repeat_freq);

    return 0;
}
