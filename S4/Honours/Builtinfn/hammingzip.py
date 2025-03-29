
def hamming_distance(seq1, seq2):
    """
    Calculate the Hamming distance between two sequences of equal length.

    Parameters:
    seq1 (str): The first sequence.
    seq2 (str): The second sequence.

    Returns:
    int: The Hamming distance between seq1 and seq2.

    Raises:
    ValueError: If the sequences are of different lengths.
    """
    # Ensure the sequences are of equal length
    if len(seq1) != len(seq2):
        raise ValueError("Sequences must be of equal length.")

    # Use zip() to pair corresponding elements from both sequences
    # Compare each pair and count mismatches
    distance = sum(1 for a, b in zip(seq1, seq2) if a != b)

    return distance

# Example usage:
seq1 = "GATTACA"
seq2 = "GACTATA"
try:
    distance = hamming_distance(seq1, seq2)
    print(f"The Hamming distance between the sequences is: {distance}")
except ValueError as e:
    print(e)


