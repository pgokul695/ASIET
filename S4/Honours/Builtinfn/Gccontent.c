def calculate_gc_content(dna_sequence):
    dna_sequence = dna_sequence.upper()  # Convert to uppercase to handle mixed case sequences
    g_count = dna_sequence.count('G')
    c_count = dna_sequence.count('C')
    gc_count = g_count + c_count
    gc_content = (gc_count / len(dna_sequence)) * 100 if dna_sequence else 0
    return gc_content

# Example usage:
dna_seq = "AGCTATAGCGCTAGCTAGGCT"
gc_percentage = calculate_gc_content(dna_seq)
print(f"GC Content: {gc_percentage:.2f}%")


