using System;

namespace MaxPairwiseProduct {
    class Program {
        static void Main(string[] args) {
            var input = Console.ReadLine();
            var n = int.Parse(input);
            input = Console.ReadLine();
            var tokens = input.Split(' ');
            int[] numbers = Array.ConvertAll(tokens, int.Parse);

            Console.Write(maxPairwiseProduct(numbers));
        }

        static double maxPairwiseProduct(int[] numbers) {
            double first = 0;
            double second = 0;
            int maxI = -1;

            int n = numbers.Length;

            for (int i = 0; i < n; ++i) {
                if (numbers[i] > first) {
                    first = numbers[i];
                    maxI = i;
                }
            }

            for (int j = 0; j < n; ++j) {
                if (j != maxI && numbers[j] > second) {
                    second = numbers[j];
                }
            }


            return first * second;
        }
    }
}
