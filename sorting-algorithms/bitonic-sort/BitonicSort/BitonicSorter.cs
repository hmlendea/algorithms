namespace BitonicSort
{
    /// <summary>
    /// Bitonic sorter.
    /// </summary>
    public class BitonicSorter
    {
        protected int[] InputData { get; set; }

        protected const bool ASCENDING = true;
        protected const bool DESCENDING = false;

        /// <summary>
        /// Sort the specified array.
        /// </summary>
        /// <returns>The sort.</returns>
        /// <param name="array">Array.</param>
        public virtual void Sort(ref int[] array)
        {
        }

        /// <summary>
        /// Compare the specified source, destination and direction.
        /// </summary>
        /// <param name="source">Source.</param>
        /// <param name="destination">Destination.</param>
        /// <param name="direction">Direction.</param>
        protected void Compare(int source, int destination, bool direction)
        {
            if (direction != (InputData[source] > InputData[destination]))
            {
                return;
            }

            Swap(source, destination);
        }

        /// <summary>
        /// Swaps the elements on the specified indexes.
        /// </summary>
        /// <param name="index1">First index.</param>
        /// <param name="index2">Second index.</param>
        protected void Swap(int index1, int index2)
        {
            int temp = InputData[index1];

            InputData[index1] = InputData[index2];
            InputData[index2] = temp;
        }
    }
}
