//
//  main.swift
//  ProgrammingChallenges
//
//  Created by Santiago Pelaez Rua on 1/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

import Foundation

protocol CLIExecutable {
    static func execute()
}

print("Choose which algorithm to run\n")
print("1: APlusB\n2: MaxPairwiseProduct")

let input = readLine()!

if input == "1" {
    APlusB.execute()
} else if input == "2" {
    MaximumPairwiseProduct.execute()
} else {
    exit(0)
}
