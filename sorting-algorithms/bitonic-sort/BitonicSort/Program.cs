using System;
using System.Diagnostics;

namespace BitonicSort
{
    /// <summary>
    /// Program entry class.
    /// </summary>
    class Program
    {
        static Random random;

        /// <summary>
        /// The entry point of the program, where the program control starts and ends.
        /// </summary>
        /// <param name="args">The command-line arguments.</param>
        static void Main(string[] args)
        {
            int arraySize = 524288;
            int iterations = 5;

            random = new Random();

            int[] originalData = new int[arraySize];

            for (int i = 0; i < originalData.Length; i++)
            {
                originalData[i] = random.Next();
            }

            TestSpeed("Single Threaded", new SingleThreadedBitonicSorter(), originalData, iterations);
            TestSpeed("Multi Threaded ", new MultiThreadedSorter(), originalData, iterations);

            Console.ReadLine();
        }

        /// <summary>
        /// Tests the speed.
        /// </summary>
        /// <param name="testName">Test name.</param>
        /// <param name="sorter">Sorter.</param>
        /// <param name="originalArray">Original array.</param>
        /// <param name="iterations">Iterations.</param>
        static void TestSpeed(string testName, BitonicSorter sorter, int[] originalArray, int iterations)
        {
            long totalTicks = 0;

            for (int i = 0; i < iterations; i++)
            {
                int[] data = (int[])originalArray.Clone();

                Stopwatch timer = Stopwatch.StartNew();
                sorter.Sort(ref data);
                timer.Stop();

                totalTicks += timer.ElapsedTicks;
            }

            TimeSpan span = new TimeSpan(totalTicks);
            Console.WriteLine("Result: {0} - {1:0.00} ms", testName, span.TotalMilliseconds / iterations);
        }
    }
}
