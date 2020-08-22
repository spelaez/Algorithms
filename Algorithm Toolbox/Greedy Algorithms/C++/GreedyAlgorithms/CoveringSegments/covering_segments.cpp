//
//  main.cpp
//  CoveringSegments
//
//  Created by Santiago Pelaez Rua on 22/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <algorithm>

using std::sort;
using std::max;
using std::min;

struct point {
    int a, b;
};

bool pointsInteract(point lhs, point rhs) {
    return (lhs.b >= rhs.a);
}

point intersection(point lhs, point rhs) {
    point intersect;
    
    intersect.a = max(lhs.a, rhs.a);
    intersect.b = min(lhs.b, rhs.b);
    
    return intersect;
}

bool compare(point lhs, point rhs) {
    return lhs.a <= rhs.a;
}

void covering_segments(int n, point points[]) {
    sort(points, points+n, compare);
    
    int m = 0;
    int result[n];
    
    point currentPoint = points[0];
    
    for (int i = 0; i < n; i++) {
        if (pointsInteract(currentPoint, points[i])) {
            currentPoint = intersection(currentPoint, points[i]);
        } else {
            result[m] = currentPoint.a;
            m += 1;
            currentPoint = points[i];
        }
    }
    
    result[m] = currentPoint.a;
    m += 1;
    
    std::cout << m << std::endl;
    for (int i = 0; i < m; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, const char * argv[]) {
    int n;
    std::cin >> n;
    
    point points[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> points[i].a >> points[i].b;
    }
    
    covering_segments(n, points);
    return 0;
}
