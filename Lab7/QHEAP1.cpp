#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// Min-Heapify function
void min_heapify(vector<int> &arr, int N, int i){
    // Initiate largest as root and define children
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    // If left child is smaller than root
    if (l < N && arr[l] < arr[smallest])
        smallest = l;
    // If right child is smaller than largest
    if (r < N && arr[r] < arr[smallest])
        smallest = r;
    // Swap root with largest
    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        // Recursively heapify the subtrees
        min_heapify(arr, N, smallest);
    }
}

void build_min_heap(vector<int> &arr, int N){
    if (N == 1){
        return;
    }
    // Build heap using min-heapify
    for (int i = N / 2 - 1; i >= 0; i--){
        min_heapify(arr, N, i);
    }
}

int main() {  
    // Variable definitions
    int Q, func, op;
    
    // Create array
    vector<int> arr;
    int N = arr.size();
    
    // Get no. of queries
    cin >> Q;
    
    // Get query for N times
    for (int i = 0; i < Q; i++){
        cin >> func;

        if (func == 1){
            cin >> op;
            // Add op to vector
            arr.push_back(op);
            N++;
            
            if (N == 1){
                // Build min heap for the first time
                build_min_heap(arr, N);
            } else {
                // Simply maintain heap without rebuilding
                int i = N - 1;
                // If parent is larger than current node, swap
                while (i > 0 && arr[(i - 1) / 2] > arr[i]) {
                    swap(arr[i], arr[(i - 1) / 2]);
                    i = (i - 1) / 2;
                }
            }     
        } else if (func == 2){
            cin >> op;
            
            // Get index of op
            auto index = find(arr.begin(), arr.end(), op);
            
            // Erase op
            if (index != arr.end()) {
                arr.erase(index);
                N--;
            }
            x
            // Rebuild heap
            build_min_heap(arr, N);
        } 
        else {
            // Print root (minimum)
            cout << arr[0] << endl;
        }  
    }
    return 0;
}
