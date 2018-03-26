/*
Even sums is a game for two players. Players are given a sequence of N positive integers and take turns alternately. In each turn, a player chooses a non-empty slice (a subsequence of consecutive elements) such that the sum of values in this slice is even, then removes the slice and concatenates the remaining parts of the sequence. The first player who is unable to make a legal move loses the game.

You play this game against your opponent and you want to know if you can win, assuming both you and your opponent play optimally. You move first.

Write a function:

    string solution(vector<int> &A);

that, given an array A consisting of N integers, returns a string of format "X,Y" where X and Y are, respectively, the first and last positions (inclusive) of the slice that you should remove on your first move in order to win, assuming you have a winning strategy. If there is more than one such winning slice, the function should return the one with the smallest value of X. If there is more than one slice with the smallest value of X, the function should return the shortest. If you do not have a winning strategy, the function should return "NO SOLUTION".

For example, given the following array:
  A[0] = 4
  A[1] = 5
  A[2] = 3
  A[3] = 7
  A[4] = 2

the function should return "1,2". After removing a slice from positions 1 to 2 (with an even sum of 5 + 3 = 8), the remaining array is [4, 7, 2]. Then the opponent will be able to remove the first element (of even sum 4) or the last element (of even sum 2). Afterwards you can make a move that leaves the array containing just [7], so your opponent will not have a legal move and will lose. One of possible games is shown on the following picture:

Note that removing slice "2,3" (with an even sum of 3 + 7 = 10) is also a winning move, but slice "1,2" has a smaller value of X.

For the following array:
  A[0] = 2
  A[1] = 5
  A[2] = 4

the function should return "NO SOLUTION", since there is no strategy that guarantees you a win.

Assume that:

        N is an integer within the range [1..100,000];
        each element of array A is an integer within the range [1..1,000,000,000].

Complexity:

        expected worst-case time complexity is O(N);
        expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
*/


// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

string solution(vector<int> &A) {
    // write your code in C++11 (g++ 4.8.2)
    
        int sum = 0;
    int x,y;
    string result;
    int first, afterFirst, beforeLast, last;
    
    //Calculate the sum of array A if it is even or odd.
    for (int i = 0; i < A.size(); i++){
        sum = sum + A[i];
    }
    
    //If the total sum is even then return the whole array.
    if ((sum % 2) == 0){
        x = 0;
        y = A.size() - 1;
    }
    //If the total sum is not even then...
    else{
        //Look for the first and last odd integers in the array.
        for (int i = 0; i < A.size(); i++){
            if ((A[i] % 2) != 0){
                first = i;
                break;
            }
        }
        for (int i = A.size() - 1; i >= 0; i--){
            if ((A[i] % 2) != 0){
                last = i;
                break;
            }
        }
    
        //If the array has only 1 odd integer:
        if (first == last){
            //Check if the odd integer is in the middle of the array.
            if (first == A.size() - (first + 1)){
                return "NO SOLUTION";
            }
            //Check if the odd integer is in the 1st half of the array.
            else if (first < A.size() - (first + 1)){
                x = first + 1;
                y = A.size() - first - 1;
            }
            //Check if the odd integer is in the 2nd half of the array.
            else {
                x = 0;
                y = first - (A.size() - (first + 1)) - 1;
            }
        }
        //If the array has more than 1 odd integer:
        else{
            //Find the 2nd first odd integer
            for (int i = first + 1; i < A.size(); i++){
                if ((A[i] % 2) != 0){
                    afterFirst = i;
                    break;
                }
            }
            //Find the 2nd last odd integer
            for (int i = last - 1; i >= 0; i--){
                if ((A[i] % 2) != 0){
                    beforeLast = i;
                    break;
                }
            }
            
            //If the number of even integers before the first odd integer is equal or more than the number of even integers after the last odd integer:
            if (first >= A.size() - (last + 1)){
                //If the number of integers between the last 2 odd integers is equal or more than the number of integers after the last odd integer:
                if ((last - beforeLast - 1) >= (A.size() - (last + 1))){
                    x = 0;
                    y = last - (A.size() - (last + 1)) - 1;
                }
                //If the number of integers between the last 2 odd integer is less than the number of integers after the last odd integer:
                else {
                    x = A.size() - (last + 1) - (last - beforeLast - 1);
                    y = beforeLast;
                }
            }
            //If the number of even integers before the first odd integer is less than the number of even integers after the last odd integer:
            if (first < A.size() - (last + 1)){
                //If the number of integers between the last 2 odd integers is equal or more than the number of integers after the last odd integer:
                if ((last - beforeLast - 1) >= (A.size() - (last + 1))){
                    x = 0;
                    y = last - (A.size() - (last + 1)) - 1;
                }
                //If the number of integers between the last 2 odd integers is less than the number of integers after the last odd integer:
                else {
                    //If the total number of integers between the last 2 odd integers and before the first odd integer is equal or more than the number of integers after the last odd integer:
                    if ((last - beforeLast - 1) + first >= (A.size() - (last + 1))){
                        x = A.size() - (last + 1) - (last - beforeLast - 1);
                        y = beforeLast;
                    }
                    //If the total number of integers between the last 2 odd integers and before the first odd integer is less than the number of integers after the last odd integer:
                    else {
                        x = first + 1;
                        y = A.size() - first - 1;
                    }
                }
            }
        }
    }
    
    result = to_string(x) + "," + to_string(y);
    return result;

}

