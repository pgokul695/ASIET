from collections import Counter

def tetra_nucleotide_count(dna_sequence):
    # Ensure the DNA sequence is long enough to form 4-mers
    if len(dna_sequence) < 4:
        raise ValueError("DNA sequence must be at least 4 nucleotides long.")
    
    # Use a sliding window of size 4 to extract 4-mers
    tetra_freq = Counter(dna_sequence[i:i+4] for i in range(len(dna_sequence) - 3))
    
    return tetra_freq

# Example DNA sequence
dna_sequence = "ATCGATCGAGCT"

# Calculate tetra nucleotide frequencies
result = tetra_nucleotide_count(dna_sequence)

# Output the tetra nucleotide frequency count
print("Tetra Nucleotide Frequency Count:")
for k, v in result.items():
    print(f"{k}: {v}")


