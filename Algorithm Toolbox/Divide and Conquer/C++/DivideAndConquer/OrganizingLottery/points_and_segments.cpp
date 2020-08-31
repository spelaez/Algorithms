//
//  main.cpp
//  OrganizingLottery
//
//  Created by Santiago Pelaez Rua on 30/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

using std::tuple;
using std::make_tuple;

bool lessThan(pair<int, char> lhs, pair<int, char> rhs) {
    if (lhs.first == rhs.first) {
        return lhs.second < rhs.second;
    }
    
    return lhs.first < rhs.first;
}

bool equal(pair<int, char> lhs, pair<int, char> rhs) {
    return lhs.first == rhs.first && lhs.second == rhs.second;
}

tuple<int, int> partition3(vector<pair<int, char>> &a, int l, int r) {
    pair<int, char> x = a[l];
    int j = l;
    
    for (int i = l + 1; i <= r; i++) {
        if (lessThan(a[i], x)) {
            j++;
            swap(a[i], a[j]);
        }
    }
    
    swap(a[l], a[j]);

    int p = j;
    
    for (int i = p + 1; i <= r; i ++) {
        if (equal(a[i], x)) {
            p++;
            swap(a[i], a[p]);
        }
    }
    
    return make_tuple(j, p);
}

void randomized_quick_sort(vector<pair<int, char>> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    tuple<int, int> m = partition3(a, l, r);
    
    randomized_quick_sort(a, l, std::get<0>(m) - 1);
    randomized_quick_sort(a, std::get<1>(m) + 1, r);
}

vector<int> countSegments(vector<pair<int, char>> a, int p) {
    vector<int> count;
    int currentSegments = 0;
    for(int i = 0; i < a.size(); i++) {
        if (a[i].second == 'l') {
            currentSegments++;
        } else if (a[i].second == 'r') {
            currentSegments--;
        } else {
            count.push_back(currentSegments);
        }
    }
    
    return count;
}

int main() {
    int s, p;
    
    cin >> s >> p;
    vector<pair<int, char>> segments;
    
    int l, r;
    
    for(int i = 0; i < s; i++) {
        cin >> l >> r;
        segments.push_back(make_pair(l, 'l'));
        segments.push_back(make_pair(r, 'r'));
    }
    
    for(int i = 0; i < p; i++) {
        int point;
        cin >> point;
        segments.push_back(make_pair(point, 'p'));
    }
    
    randomized_quick_sort(segments, 0, segments.size() - 1);
    vector<int> count = countSegments(segments, p);
    
    for (int i = 0; i < count.size(); i++) {
        cout << count[i] << ' ';
    }
    cout << endl;
}
