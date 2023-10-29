#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> findSum(vector<int>& nums, int target) {
    unordered_map<int, int> dict;
    for (int i = 0; i < nums.size(); i++) {
        
        if (dict.count(target - nums[i])) {
            return {dict[target - nums[i]], i};
        }
        dict[nums[i]] = i;
    }
    return {};
}

int main() {
    int arraySize=0;
    int targetSum=0;
    cout << "Enter the size of array: " << endl;
    cin >> arraySize;
    std::vector<int> input_array(arraySize);
    cout << "Enter array elements:" <<endl;
    for(int i=0;i<arraySize;i++){
        cin >> input_array[i];
    }
    cout <<"Enter the target sum to find: "<<endl;
    cin >> targetSum;
    vector<int> result = findSum(input_array, targetSum);
    if(result.size()>0){
          cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    else{
        cout<<"No pair of elements found"<<endl;
    }
  
    return 0;
}
