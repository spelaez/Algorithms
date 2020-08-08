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
print("1: APlusB")
print("2: MaxPairwiseProduct")
print("3: Fibonacci")


let input = readLine()!

switch input {
case "1":
    APlusB.execute()
case "2":
    MaximumPairwiseProduct.execute()
case "3":
    Fibonacci.execute()
default:
    exit(0)
}
