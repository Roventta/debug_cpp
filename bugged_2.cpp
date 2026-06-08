#include <iostream>
#include <vector>
using namespace std;

int find_largest(vector<int> int_arr){
    int a_small_value = 0;
    for(int i : int_arr){
        if(a_small_value < int_arr[i]){
            a_small_value = int_arr[i];
        }
    }
}

int main(){
    // programs starts here
    vector<int> arr = {-2,-3,-4,-10,-9,-9,-1};
    printf("the largest number in the array is %i\n", find_largest(arr));
}