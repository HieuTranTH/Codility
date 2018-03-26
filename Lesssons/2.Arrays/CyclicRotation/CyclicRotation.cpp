// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() == 0) return A;

    K = K % A.size();
    if (K == 0) return A;
    
    vector<int> B;
    B.resize(A.size());
    
    for (int i = 0; i < A.size(); i++){
        B[(i+K) % A.size()] = A[i];
    }
    
    return B;
}