using System;
using System.Threading;

namespace BitonicSort
{
    /// <summary>
    /// Multi threaded sorter.
    /// </summary>
    public class MultiThreadedSorter : BitonicSorter
    {
        int minimumLength = 1;

        /// <summary>
        /// Sorts the specified array.
        /// </summary>
        /// <returns>The sort.</returns>
        /// <param name="array">Array.</param>
        public override void Sort(ref int[] array)
        {
            InputData = array;

            minimumLength = InputData.Length / Environment.ProcessorCount;

            BitonicSort(new BitonicParameters(0, InputData.Length, ASCENDING));
        }

        void BitonicSort(object asyncState)
        {
            BitonicParameters parameters = (BitonicParameters)asyncState;

            if (parameters.Length <= 1)
            {
                return;
            }

            if (parameters.Length > minimumLength)
            {
                int median = parameters.Length / 2;

                Thread left = new Thread(BitonicSort);
                Thread right = new Thread(BitonicSort);

                left.Start(new BitonicParameters(parameters.Index, median, ASCENDING));
                right.Start(new BitonicParameters(parameters.Index + median, median, DESCENDING));

                left.Join();
                right.Join();
            }
            else
            {
                int median = parameters.Length / 2;

                if (median > 1)
                {
                    BitonicSort(new BitonicParameters(parameters.Index, median, ASCENDING));
                    BitonicSort(new BitonicParameters(parameters.Index, median, ASCENDING));
                }
            }

            BitonicMerge(new BitonicParameters(parameters.Index, parameters.Length, parameters.Direction));
        }

        void BitonicMerge(object AsyncState)
        {
            BitonicParameters parameters = (BitonicParameters)AsyncState;

            if (parameters.Length <= 1)
            {
                return;
            }

            if (parameters.Length > minimumLength)
            {
                int median = parameters.Length / 2;

                for (int i = parameters.Index; i < (parameters.Index + median); i++)
                {
                    Compare(i, (i + median), parameters.Direction);
                }

                Thread left = new Thread(BitonicMerge);
                Thread right = new Thread(BitonicMerge);

                left.Start(new BitonicParameters(parameters.Index, median, parameters.Direction));
                right.Start(new BitonicParameters(parameters.Index + median, median, parameters.Direction));

                left.Join();
                right.Join();
            }
            else
            {
                int median = parameters.Length / 2;

                for (int i = parameters.Index; i < (parameters.Index + median); i++)
                {
                    Compare(i, (i + median), parameters.Direction);
                }

                if (median > 1)
                {
                    BitonicMerge(new BitonicParameters(parameters.Index, median, parameters.Direction));
                    BitonicMerge(new BitonicParameters(parameters.Index + median, median, parameters.Direction));
                }
            }
        }
    }
}
