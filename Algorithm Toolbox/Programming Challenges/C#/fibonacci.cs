using System;
namespace Fibonacci {
    public class Program {

        static void Main(string [] args) {
            var input = Console.ReadLine();
            var n = int.Parse(input);

            Console.Write(fibonacci(n));
        }

        static int fibonacci(int n) {
            if (n <= 1) {
                return n;
            }

            int[] numbers = new int[n + 1];
            numbers[0] = 0;
            numbers[1] = 1;

            for (int i = 2; i <= n; ++i) {
                numbers[i] = numbers[i - 1] + numbers[i - 2];
            }

            return numbers[n];
        }
    }
}
