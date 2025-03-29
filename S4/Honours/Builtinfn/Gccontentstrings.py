
def calculate_gc_content(dna_sequence):
    # Convert the sequence to uppercase to handle mixed case sequences
    dna_sequence = dna_sequence.upper()
    # Count the occurrences of 'G' and 'C'
    g_count = dna_sequence.count('G')
    c_count = dna_sequence.count('C')
    # Calculate GC content as a percentage
    gc_content = (g_count + c_count) / len(dna_sequence) * 100 if dna_sequence else 0
    return gc_content

# List of DNA sequences
dna_sequences = [
    "AGCTATAGCGCTAGCTAGGCT",
    "CGATCGATCGATCGATCGATCG",
    "TTAGGCTAGCTAGCTAGGCTA",
    "GCTAGCTAGCTAGCTAGCTA",
    "ATCGATCGATCGATCGATCGA"
]

# Initialize variables to track the sequence with the highest GC content
max_gc_content = 0
max_gc_sequence = ""

# Iterate over each DNA sequence
for seq in dna_sequences:
    gc_content = calculate_gc_content(seq)
    print(f"GC Content of '{seq}': {gc_content:.2f}%")
    if gc_content > max_gc_content:
        max_gc_content = gc_content
        max_gc_sequence = seq

print(f"\nDNA sequence with the highest GC content: '{max_gc_sequence}' with {max_gc_content:.2f}% GC content")
