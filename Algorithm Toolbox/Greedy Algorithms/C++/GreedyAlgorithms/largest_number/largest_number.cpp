//
//  main.cpp
//  largest_number
//
//  Created by Santiago Pelaez Rua on 22/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::sort;

bool isGreaterOrEqual(string a, string b) {
    string option1 = a+b;
    string option2 = b+a;

    int option1n = stoi(option1);
    int option2n = stoi(option2);

    return option1n > option2n;
}

string largest_number(vector<string> a) {
    string result = "";
    
    sort(a.begin(), a.end(), isGreaterOrEqual);
    
    while (!a.empty()) {
        result = result + a[0];
        a.erase(a.begin());
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;
    vector<string> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        std::cin >> a[i];
    }
    std::cout << largest_number(a) << std::endl;
}
