#include <iostream> 
#include <vector>
using namespace std; 

#include "functions.hpp"
  
// Driver program to test above functions 
int main() 
{ 
    vector<vector<int>> points;
    points.push_back(vector<int>({3,12}));
    points.push_back(vector<int>({-2,5}));
    points.push_back(vector<int>({-4,1}));

    cout << minDistance(points) << endl; 

    return 0; 
} 