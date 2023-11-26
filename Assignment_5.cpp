#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find longest common substring
string longestSubstring(string str1, string str2) {
    int l1 = str1.size();
    int l2 = str2.size();
    vector<vector<int>> table(l1+1, vector<int>(l2+1, 0)); //
    int max_len = 0;
    int ep = 0;

    // build dp table 
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (str1[i-1] == str2[j-1]) {
                table[i][j] = table[i-1][j-1] + 1;
                if (table[i][j] > max_len) {
                    max_len = table[i][j];
                    ep = i - 1;
                }
            }
        }
    }

    //print table
    cout << "------------Lookup Table:--------------- " << endl;
    cout << "    ";
    for (int j = 0; j < l2; j++) {
        cout << str2[j] << " ";
    }
    cout << endl;
    for (int i = 0; i <= l1; i++) {
        if (i <= 0) {
               cout << "  ";    
        } else {

            cout << str1[i-1] << " ";
        }
        for (int j = 0; j <= l2; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }


    cout << "The Length of the largest common substring: " << max_len << endl;

    return str1.substr(ep - max_len + 1, max_len); // return the longest common substring
}

// Defining the main function
int main() {
    string str1, str2;
    cout << "Please Enter first string: ";
    
    std::getline(std::cin, str1);
    cout << "Please Enter second string: ";
    std::getline(std::cin, str2);
    string lcs = longestSubstring(str1, str2); // find lcs
    cout << "The Longest Common Substring: " << lcs << endl;
    return 0;
}
