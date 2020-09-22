//
//  main.cpp
//  MaxSlidingWindow
//
//  Created by Santiago Pelaez Rua on 20/09/20.
//
#include <iostream>
#include <deque>
#include <limits>

using namespace std;

void pushDroppingAllSmaller(deque<int> &q, int i, int a[]) {
    while(!q.empty() && a[i] >= a[q.back()]){
        q.pop_back();
    }
    
    q.push_back(i);
}

void popFromQueue(deque<int> &q, int w) {
    while(!q.empty() && q.front() <= w) {
        q.pop_front();
    }
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int w;
    cin >> w;
    
    deque<int> q;
    
    for(int i = 0; i < w; i++) {
        pushDroppingAllSmaller(q, i, a);
    }
    
    for(int i = w; i < n; i++) {
        cout << a[q.front()] << " ";
        popFromQueue(q, i - w);
        pushDroppingAllSmaller(q, i, a);
    }
    
    cout << a[q.front()];
    return 0;
}
