//
//  main.cpp
//  ClosestPoints
//
//  Created by Santiago Pelaez Rua on 31/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

int compareX(const void* a, const void* b) {
    pair<float, float> *p1 = (pair<float, float> *)a, *p2 = (pair<float, float> *)b;
    return (p1->first - p2->first);
}

int compareY(const void* a, const void* b) {
    pair<float, float> *p1 = (pair<float, float> *)a, *p2 = (pair<float, float> *)b;
    return (p1->second - p2->second);
}

float distance(pair<float, float> p1, pair<float, float> p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

float closestNaive(pair<float, float> p[], int n) {
    float minDist = numeric_limits<float>::max();
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            float dist = distance(p[i], p[j]);
            minDist = min(minDist, dist);
        }
    }
    
    return minDist;
}

float stripClosest(pair<float, float> strip[], int size, float d) {
    float min = d; //initialize the minimum distance as d
    
    qsort(strip, size, sizeof(pair<float, float>), compareY);
    
    //Pick all points one by one and try the next points till the difference between y coordinates is smaller that d.
    //This is a proven fact that this loop runs at most 6 times
    for(int i = 0; i < size; i++) {
        for(int j = i+1; j < size && (strip[j].second - strip[i].second) < min; j++) {
            if (distance(strip[i], strip[j]) < min) {
                min = distance(strip[i], strip[j]);
            }
        }
    }
    
    return min;
}

float minimumDistance(pair<float, float> p[], int n) {
    //if there are 2 points, return their distance
    if (n <= 3) {
        return closestNaive(p, n);
    }
    
    //find the middle point
    int mid = n/2;
    pair<float, float> midPoint = p[mid];
    
    //Consider the vertical line passing through the middle point calculate the smallest distance dl on the left
    //of the middle point and dr on right side
    float dl = minimumDistance(p, mid);
    float dr = minimumDistance(p + mid, n - mid);
    
    //find the smaller of two differences
    float d = min(dl, dr);
    
    //build an array strip that contains points close (closer than d)
    //to the line passing through the middle point
    pair<float, float> strip[n];
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(abs(p[i].first - midPoint.first) < d) {
            strip[j] = p[i];
            j++;
        }
    }
    
    //find the closest points in strip. return the minimum of d and closest distance is strip[]
    return min(d, stripClosest(strip, j, d));
}

float closestPoints(pair<float, float> points[], int n) {
    //Order points by X
    qsort(points, n, sizeof(pair<float, float>), compareX);
    
    return minimumDistance(points, n);
}

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    
    pair<float, float> points[n];
    
    for(int i = 0; i < n; i++) {
        float x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }
    
    cout.precision(10);
    cout << closestPoints(points, n) << endl;
    return 0;
}
