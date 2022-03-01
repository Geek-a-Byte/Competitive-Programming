#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int id, key;

    Node(){
    }

    Node(int i, int k){
        id = i;
        key = k;
    }

    void print(){
        cout<<"Id: "<<id<<" || Key: "<<key<<endl;
    }
};

class PriorityQueueMin{
private:
    Node arr[1001];
    int SIZE;

public:
    PriorityQueueMin(){
        SIZE = 0;
    }

private:
    void topToBottomAdjust(int i){
        while(i!=1){
            if(arr[i].key < arr[i/2].key)   swap(arr[i], arr[i/2]);
            else    return;
            i = i/2;
        }
    }

    void heapify(int i){   ///bottomTop
        while(i<=SIZE/2){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;
            int minIndex = leftIndex;
            if(rightIndex <=SIZE && arr[rightIndex].key < arr[leftIndex].key)   minIndex = rightIndex;
            if(arr[minIndex].key < arr[i].key)  swap(arr[minIndex], arr[i]);
            else    return;
            i = minIndex;
        }
    }

public:
    bool push(Node n){
        if(SIZE==1000)   return false;
        SIZE++;
        arr[SIZE]=n;
        topToBottomAdjust(SIZE);
    }

    bool pop(){
        if(SIZE==0) return false;
        arr[1] = arr[SIZE];
        SIZE--;
        heapify(1);
    }

    Node top(){
        return arr[1];
    }

    bool isEmpty(){
        if(SIZE==0) return true;
        return false;
    }

    int size(){
        return SIZE;
    }
};
