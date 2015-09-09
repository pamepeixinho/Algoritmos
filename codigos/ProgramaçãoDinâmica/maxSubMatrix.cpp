Encontra o valor da soma da submatriz que a maximize.

int kadane(int* arr, int* start, int* finish, int n) {
    int sum = 0, maxSum = INT_MIN, i;
 
    *finish = -1;
 
    int local_start = 0;
 
    for (i = 0; i < n; ++i) {
        sum += arr[i];
        if (sum < 0) {
            sum = 0;
            local_start = i+1;
        }
        else if (sum > maxSum) {
            maxSum = sum;
            *start = local_start;
            *finish = i;
        }
    }
 
    if (*finish != -1)
        return maxSum;
 
    maxSum = arr[0];
    *start = *finish = 0;
 
    for (i = 1; i < n; i++) {
        if (arr[i] > maxSum) {
            maxSum = arr[i];
            *start = *finish = i;
        }
    }
    return maxSum;
}

//O(n^3)
void findMaxSum(int M[][COL]) {
    int maxSum = INT_MIN, finalLeft, finalRight, finalTop, finalBottom;
 
    int left, right, i;
    int temp[ROW], sum, start, finish;
 
    // Set the left column
    for (left = 0; left < COL; ++left) {
        memset(temp, 0, sizeof(temp));
 
        // Set the right column for the left column set by outer loop
        for (right = left; right < COL; ++right) {
            // Calculate sum between current left and right for every row 'i'
            for (i = 0; i < ROW; ++i)
                temp[i] += M[i][right];
 
            // Find the maximum sum subarray in temp[]. The kadane() function
            // also sets values of start and finish.  So 'sum' is sum of
            // rectangle between (start, left) and (finish, right) which is the
            //  maximum sum with boundary columns strictly as left and right.
            sum = kadane(temp, &start, &finish, ROW);
 
            // Compare sum with maximum sum so far. If sum is more, then update
            // maxSum and other output values
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }
    }
 
    // Print final values
    printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
    printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
    printf("Max sum is: %d\n", maxSum);
}
