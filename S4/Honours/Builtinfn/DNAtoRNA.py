# Function to convert DNA sequence to RNA sequence
def dna_to_rna(dna_sequence):
    # Replace all occurrences of T with U
    rna_sequence = dna_sequence.replace('T', 'U')
    return rna_sequence

# Example DNA sequence
dna_sequence = "ATCGTAGC"

# Convert DNA to RNA
rna_sequence = dna_to_rna(dna_sequence)

# Print results
print("DNA Sequence: ", dna_sequence)
print("RNA Sequence: ", rna_sequence)
