//
//  main.cpp
//  FractionalKnapsack
//
//  Created by Santiago Pelaez Rua on 17/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;
using std::sort;
using std::min;

struct loot {
    int value;
    int weigth;
    
    double getRatio() {
        return ((double) value / weigth);
    }
};

bool compare(loot lhs, loot rhs) {
    double ratio1 = lhs.getRatio();
    double ratio2 = rhs.getRatio();
    
    return ratio1 > ratio2;
}

double fractional_knapsack(int weight, vector<loot> l) {
    double value = 0.0;
    
    sort(l.begin(), l.end(), compare);
    
    for (int i = 0; i < l.size(); i++) {
        if (weight == 0) {
            return value;
        }
        
        int a = min(l[i].weigth, weight);
        value += ((double)a*l[i].getRatio());
        weight -= a;
    }
    
    return value;
}

int main(int argc, const char * argv[]) {
    int n, weight;
    
    std::cin >> n >> weight;
    vector<loot> l(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> l[i].value >> l[i].weigth;
    }
    
    std::cout.precision(10);
    std::cout << fractional_knapsack(weight, l) << std::endl;
    return 0;
}
