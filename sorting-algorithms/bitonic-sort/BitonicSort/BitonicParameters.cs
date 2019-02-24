namespace BitonicSort
{
    /// <summary>
    /// Bitonic parameters.
    /// </summary>
    public class BitonicParameters
    {
        /// <summary>
        /// Gets or sets the index.
        /// </summary>
        /// <value>The index.</value>
        public int Index { get; set; }

        /// <summary>
        /// Gets or sets the length.
        /// </summary>
        /// <value>The length.</value>
        public int Length { get; set; }

        /// <summary>
        /// Gets or sets a bool value indicating the direction.
        /// </summary>
        /// <value><c>true</c> if direction is set; otherwise, <c>false</c>.</value>
        public bool Direction { get; set; }

        /// <summary>
        /// Initializes a new instance of the <see cref="BitonicParameters"/> class.
        /// </summary>
        /// <param name="index">Index.</param>
        /// <param name="length">Length.</param>
        /// <param name="direction">Direction.</param>
        public BitonicParameters(int index, int length, bool direction)
        {
            Index = index;
            Length = length;
            Direction = direction;
        }
    }
}
