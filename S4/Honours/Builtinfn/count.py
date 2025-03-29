def count_nucleotides(dna_sequence):
    # Initialize a dictionary to store counts
    counts = {'A': 0, 'T': 0, 'C': 0, 'G': 0}
    
    # Iterate over the sequence and update counts
    for nucleotide in dna_sequence:
        if nucleotide in counts:
            counts[nucleotide] += 1
    
    return counts


dna_sequence = "ATCGATCGA"
result = count_nucleotides(dna_sequence)
print(result)
