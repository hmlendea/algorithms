namespace BitonicSort
{
    public class SingleThreadedBitonicSorter : BitonicSorter
    {
        public override void Sort(ref int[] array)
        {
            InputData = array;
            BitonicSort(0, InputData.Length, ASCENDING);
        }

        void BitonicSort(int index, int length, bool direction)
        {
            if (length <= 1)
            {
                return;
            }

            int median = length / 2;

            if (median > 1)
            {
                BitonicSort(index, median, ASCENDING);
                BitonicSort(index + median, median, DESCENDING);
            }

            BitonicMerge(index, length, direction);
        }

        void BitonicMerge(int index, int length, bool direction)
        {
            if (length <= 1)
            {
                return;
            }

            int median = length / 2;

            for (int i = index; i < (index + median); i++)
            {
                Compare(i, (i + median), direction);
            }

            if (median > 1)
            {
                BitonicMerge(index, median, direction);
                BitonicMerge((index + median), median, direction);
            }
        }

    }
}
