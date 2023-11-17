//
// Created by 24195 on 2023/10/27.
//
#include "func.h"

class DualHeap{
private:
    priority_queue<int>small;
    priority_queue<int, vector<int>, greater<int>> large;
    unordered_map<int, int> delayed;

    int k;
    int smallSize, largeSize;

public:
    DualHeap(int _k):k(_k), smallSize(0), largeSize(0){}

private:
    template<class T>
    void prune(T &heap){
        while (!heap.empty()){
            int num = heap.top();
            if (delayed.count(num) > 0){
                --delayed[num];
                if (!delayed[num]){
                    delayed.erase(num);
                }
                heap.pop();
            }
            else{
                break;
            }
        }
    }

    void makeBalance(){
        if (smallSize > largeSize + 1){
            large.push(small.top());
            small.pop();
            smallSize--;
            largeSize++;
            prune(small);
        }
        else if (largeSize > smallSize){
            small.push(large.top());
            large.pop();
            smallSize++;
            largeSize--;
            prune(large);
        }

    }

public:
    void insert(int num){
        if (small.empty() or num <= small.top()){
            small.push(num);
            smallSize++;
            makeBalance();
        }
        else{
            large.push(num);
            largeSize++;
            makeBalance();
        }
    }

    void erase(int num){
        ++delayed[num];
        if (num <= small.top()){
            --smallSize;
            if (num == small.top()){
                prune(small);
            }
        }
        else{
            --largeSize;
            if (num == large.top()){
                prune(large);
            }
        }

        makeBalance();
    }

    double getMedian(){
        if (k % 2 == 1){
            return small.top();
        }
        else{
            return (double(small.top()) + large.top()) / 2;
        }
    }

};


int main(){
    cout << "hello world. " << endl;
    test_dynamic();

}

