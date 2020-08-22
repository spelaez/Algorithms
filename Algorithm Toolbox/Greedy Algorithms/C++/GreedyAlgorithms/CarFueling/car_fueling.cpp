//
//  main.cpp
//  CarFueling
//
//  Created by Santiago Pelaez Rua on 19/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <algorithm>

int car_fueling(int d, int m, int n, int stops[]) {
    int currentStop = 0;
    int refills = 0;
    
    while (currentStop < n) {
        int lastStop = currentStop;
        
        while (currentStop < n && stops[currentStop + 1] - stops[lastStop] <= m) {
            currentStop += 1;
        }
        
        if (currentStop == lastStop) {
            return -1;
        }
        
        if (currentStop == n - 1) {
            return refills;
        }
        
        if (currentStop < n) {
            refills += 1;
        }
    }
    
    return refills;
}

int main(int argc, const char * argv[]) {
    int d, m, n;
    std::cin >> d;
    std::cin >> m;
    std::cin >> n;
    
    n += 2;
    
    int stops[n];
    
    stops[0] = 0;
    stops[n - 1] = d;
    for (int i = 1; i < n - 1; i++) {
        std::cin >> stops[i];
    }
        
    std::cout << car_fueling(d, m, n, stops) << std::endl;
    return 0;
}
