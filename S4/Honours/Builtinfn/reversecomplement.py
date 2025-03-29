def reverse_complement(dna_sequence):
    # Create a dictionary for the complement of each nucleotide
    complement = {'A': 'T', 'T': 'A', 'C': 'G', 'G': 'C'}
    
    # Get the complement for each nucleotide and reverse the sequence
    reverse_complement_sequence = ''.join(complement[nucleotide] for nucleotide in dna_sequence)[::-1]
    
    return reverse_complement_sequence

# Example usage
dna_sequence = "ATCGTAGC"
result = reverse_complement(dna_sequence)
print("Reverse Complement:", result)

