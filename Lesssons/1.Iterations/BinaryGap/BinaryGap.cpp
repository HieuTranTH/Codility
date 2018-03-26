

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int i = 0, result = 0;
    
    while ((N & 1) != 1){
        N = N >> 1;
    }
    
    while (N > 0){
        while ((N & 1) == 0){
            i++;
            N = N >> 1;
        }
        if (i > result){
            result = i;
        }
        i = 0;
        N = N >> 1;
    }
    return result;
}

