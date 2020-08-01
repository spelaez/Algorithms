import UIKit

let input = readLine()!
let numbers = input.split(separator: " ").map { Int($0) ?? 0 }

print(aPlusB(a: numbers[0], b: numbers[1]))
