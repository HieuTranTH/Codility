/*


This is a demo task.

Write a function:

    int solution(vector<int> &A);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Assume that:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [−1,000,000..1,000,000].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

*/

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    std::sort(A.begin(), A.end());
    
    if (A[A.size() - 1] <= 0) return 1;
    
    else if (A[0] > 1) return 1;
    
    else {
        for (int i = 0; i < A.size() - 1; i++){
            if (A[i] <= 0) {
                if (A[i + 1] > 1) return 1;
                else continue;
            }
            
            else if ((A[i + 1] - A[i]) > 1) return A[i] + 1;
            
        }
    }
    
    return A[A.size() - 1] + 1;
}