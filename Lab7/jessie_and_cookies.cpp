#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */


int cookies(int k, vector<int> A) {
    // Variable definitions
    int counter = 0;
    
    // First build min-heap
    make_heap(A.begin(), A.end(), greater<int>());
    
    // Keep doing while array is not single and root is < k
    while (A.size() > 1 && A[0] < k){
           
        // Pop first element
        int first = A.front();
        pop_heap(A.begin(), A.end(), greater<int>());
        A.pop_back();
        
        // Then pop the 2nd element
        int second = A.front();
        pop_heap(A.begin(), A.end(), greater<int>());
        A.pop_back();
        
        // Mix
        int mixed = first + 2*second;
        
        // Put back into array
        A.push_back(mixed);
        push_heap(A.begin(), A.end(), greater<int>());

        // Increment counter
        counter++;
    }
    
    // If root is less than k, not possible
    if (A[0] < k){
        return -1;
    } else {
        // Otherwise return counter
        return counter;
    }  
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}
