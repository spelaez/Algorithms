//
//  APlusB.swift
//  ProgrammingChallenges
//
//  Created by Santiago Pelaez Rua on 1/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

import Foundation

class APlusB {
    init() {
        print("Enter 2 numbers to add")
        let input = readLine()!
        let numbers = input.split(separator: " ").map{ Int($0) ?? 0 }
        
        print(aPlusB(a: numbers[0], b: numbers[1]))
    }
    
    func aPlusB(a: Int, b: Int) -> Int {
        return a + b
    }
    
}
