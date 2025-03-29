def calculate_gc_content(dna):
    gc_count = 0
    length = 0

    for nucleotide in dna:
        if nucleotide == 'G' or nucleotide == 'C':
            gc_count += 1
        length += 1

    if length == 0:
        return 0

    return (gc_count / length) * 100

n = int(input("Enter the number of strings"))  

max_gc_content = 0
max_gc_sequence = ""

for i in range(n):
    dna_sequence = input("Enter DNA sequence")  
    gc_content = calculate_gc_content(dna_sequence)
    
    if gc_content > max_gc_content:
        max_gc_content = gc_content
        max_gc_sequence = dna_sequence

print("DNA sequence with the highest GC content:", max_gc_sequence)
print("GC Content:", max_gc_content, "%")

