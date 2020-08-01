//
//  main.swift
//  ProgrammingChallenges
//
//  Created by Santiago Pelaez Rua on 1/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

import Foundation

print("Choose which algorithm to run\n")
print("1: APlusB\n2: MaxPairwiseProduct")

let input = readLine()!

if input == "1" {
    APlusB.execute()
} else if input == "2" {
    
} else {
    exit(0)
}
