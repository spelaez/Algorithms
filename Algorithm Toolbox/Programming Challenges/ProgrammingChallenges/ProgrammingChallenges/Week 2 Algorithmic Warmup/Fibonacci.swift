//
//  Fibonacci.swift
//  ProgrammingChallenges
//
//  Created by Santiago Pelaez Rua on 7/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

import Foundation

class Fibonacci: CLIExecutable {
    static func execute() {
        print("Enter what nth fibonacci number to calculate (0 <= n <= 45)")
        let n = Int(readLine()!)!
        assert(0 <= n && n <= 45, "n is out of the limits")
        print(fibonacci(n: n))
    }
    
    static func fibonacci(n: Int) -> Int {
        if n <= 1 {
            return n
        }
        
        var numbers = [0, 1]
        
        for i in 2...n {
            numbers.append(numbers[i-1] + numbers[i-2])
        }
        
        return numbers[n]
    }
}
