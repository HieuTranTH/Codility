

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

