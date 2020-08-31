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

bool lessThan(pair<int, pair<char, int>> lhs, pair<int, pair<char, int>> rhs) {
    if (lhs.first == rhs.first) {
        return lhs.second.first < rhs.second.first;
    }
    
    return lhs.first < rhs.first;
}

bool equal(pair<int, pair<char, int>> lhs, pair<int, pair<char, int>> rhs) {
    return lhs.first == rhs.first && lhs.second.first == rhs.second.first;
}

tuple<int, int> partition3(vector<pair<int, pair<char, int>>> &a, int l, int r) {
    pair<int, pair<char, int>> x = a[l];
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

void randomized_quick_sort(vector<pair<int, pair<char, int>>> &a, int l, int r) {
    if (l >= r) {
        return;
    }
    
    int k = l + rand() % (r - l + 1);
    swap(a[l], a[k]);
    tuple<int, int> m = partition3(a, l, r);
    
    randomized_quick_sort(a, l, std::get<0>(m) - 1);
    randomized_quick_sort(a, std::get<1>(m) + 1, r);
}

vector<int> countSegments(vector<pair<int, pair<char, int>>> a, int p) {
    vector<int> count(p);
    int currentSegments = 0;
    for(int i = 0; i < a.size(); i++) {
        if (a[i].second.first == 'l') {
            currentSegments++;
        } else if (a[i].second.first == 'r') {
            currentSegments--;
        } else {
            count[a[i].second.second] = currentSegments;
        }
    }
    
    return count;
}

int main() {
    int s, p;
    
    cin >> s >> p;
    vector<pair<int, pair<char, int>>> segments;
    
    int l, r;
    
    for(int i = 0; i < s; i++) {
        cin >> l >> r;
        segments.push_back(make_pair(l, make_pair('l', -1)));
        segments.push_back(make_pair(r, make_pair('r', -1)));
    }
    
    for(int i = 0; i < p; i++) {
        int point;
        cin >> point;
        segments.push_back(make_pair(point, make_pair('p', i)));
    }
    
    randomized_quick_sort(segments, 0, segments.size() - 1);
    vector<int> count = countSegments(segments, p);
    
    for (int i = 0; i < count.size(); i++) {
        cout << count[i] << ' ';
    }
    cout << endl;
}
