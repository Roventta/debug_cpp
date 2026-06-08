#include <iostream>
#include <vector>
using namespace std;

int find_largest(vector<int> int_arr){
    int a_small_value = 0;
    //comparing the value with every element in the arr
    for(int i : int_arr){
        if(a_small_value < i){
            a_small_value = i;
        }
    }
    //the small value will slowly grow to the largest value in the function during comparisons. 
    return a_small_value;
}

int main(){
    // programs starts here
    vector<int> arr = {-2,-3,-4,-10,-9,-9,-1};
    printf("the largest number in the array is %i\n", find_largest(arr));
}
