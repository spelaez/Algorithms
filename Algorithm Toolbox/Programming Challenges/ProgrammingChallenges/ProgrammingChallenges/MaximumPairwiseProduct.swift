//
//  MaximumPairwiseProduct.swift
//  ProgrammingChallenges
//
//  Created by Santiago Pelaez Rua on 1/08/20.
//  Copyright © 2020 Santiago Pelaez Rua. All rights reserved.
//

import Foundation

class MaximumPairwiseProduct: CLIExecutable {
    static func execute() {
//        print("Enter quantity of numbers")
//        let n = Int(readLine()!)!
//        let numbers = readLine()!.split(separator: " ").map { Double($0) ?? 0 }
//
//        print(MaximumPairwiseProduct(n: n, numbers: numbers))
//        print(MaximumPairwiseProductFast(n: n, numbers: numbers))
        stressTest()
    }
    
    static func MaximumPairwiseProduct(n: Int, numbers: [Double]) -> Double {
        var result = 0.0
        for first in 0..<numbers.count {
            for second in (first + 1)..<numbers.count {
                result = max(numbers[first] * numbers[second], result)
            }
        }
        
        return result
    }
    
    static func MaximumPairwiseProductFast(n: Int, numbers: [Double]) -> Double {
        var first = 0.0
        var maxI = 0
        var second = 0.0
        
        for i in 0..<numbers.count {
            if first < numbers[i] {
                first = numbers[i]
                maxI = i
            }
        }
        
        for j in 0..<numbers.count {
            if j != maxI && second < numbers[j] {
                second = numbers[j]
            }
        }
        
        
        return first * second
    }
    
    static func stressTest() {
        while true {
            let n = Int.random(in: 2...11)
            print(n)
            
            var numbers = [Double]()
            for _ in 0..<n {
                numbers.append(Double(Int.random(in: 0...100000)))
            }
            
            print(numbers)
            
            let res1 = MaximumPairwiseProduct(n: n, numbers: numbers)
            let res2 = MaximumPairwiseProductFast(n: n, numbers: numbers)
            
            if res1 != res2 {
                print("Wrong answer: \(res1) \(res2)\n")
                break
            } else {
                print("OK\n")
            }
        }
    }
}
