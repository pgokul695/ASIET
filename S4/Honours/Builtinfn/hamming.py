def hamming_distance(seq1, seq2):
    # Ensure sequences are of equal length
    if len(seq1) != len(seq2):
        raise ValueError("Sequences must be of equal length")
    # Calculate Hamming distance
    distance = sum(1 for a, b in zip(seq1, seq2) if a != b)
    return distance

def percentage_similarity(seq1, seq2):
    distance = hamming_distance(seq1, seq2)
    similarity = (1 - distance / len(seq1)) * 100
    return similarity

# Example sequences
seq1 = "AAACCCGGGTTT"
seq2 = "AACCCGGGTTTA"

# Calculate similarity
similarity = percentage_similarity(seq1, seq2)
print(f"Percentage Similarity: {similarity:.2f}%")
