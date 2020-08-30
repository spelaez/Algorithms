//
//  main.cpp
//  Inversions
//
//  Created by Santiago Pelaez Rua on 30/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using std::vector;
using std::tuple;
using std::make_tuple;
using std::get;

tuple<int, vector<int>> merge(vector<int> &a, vector<int> &b) {
    vector<int> c(a.size() + b.size());
    int i = 0;
    
    for (int k = 0; k < c.size(); k++) {
        if (a.empty()) {
            c[k] = b[0];
            b.erase(b.begin());
        } else if (b.empty()) {
            c[k] = a[0];
            a.erase(a.begin());
        } else if (a[0] <= b[0]) {
            c[k] = a[0];
            a.erase(a.begin());
        } else {
            i += (int)a.size();
            c[k] = b[0];
            b.erase(b.begin());
        }
    }
    
    return make_tuple(i, c);
}

tuple<int, vector<int>> numberOfInversions(vector<int> &a, int l, int r) {
    if (l == r) {
        vector<int> b(a.begin() + l, a.begin() + r + 1);
        return make_tuple(0, b);
    }
    
    int middle = l + (r-l)/2;

    tuple<int, vector<int>> b = numberOfInversions(a, l, middle);
    tuple<int, vector<int>> c = numberOfInversions(a, middle + 1, r);

    tuple<int, vector<int>> merged = merge(get<1>(b), get<1>(c));

    return make_tuple(get<0>(b) + get<0>(c) + get<0>(merged), get<1>(merged));
}


int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    tuple<int ,vector<int>> ap = numberOfInversions(a, 0, n - 1);
    
    std::cout << get<0>(ap) << std::endl;
    return 0;
}
