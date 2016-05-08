#include <iostream>
#include <vector>

using namespace std;

/*
 * 346. Moving Average from Data Stream
 *
 * Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
 */

class MovingAverage {
public:
    /** Initialize your data structure here. */
    vector<int> dataStream;
    int windowSize;
    MovingAverage(int size) {
        windowSize = size;
    }

    double next(int val) {
        dataStream.push_back(val);
        if (windowSize <= 0) {
            return 0.0;
        }
        int total = dataStream.size();
        int actualWindow = total >= windowSize ? windowSize : total;
        int sum = 0;
        for (int i = total-actualWindow +1; i <= total; i++){
            sum += dataStream[i];
        }
        return double(sum)/(double)actualWindow;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
