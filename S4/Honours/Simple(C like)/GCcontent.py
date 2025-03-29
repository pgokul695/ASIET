def calculate_gc_content(dna):
    gc_count = 0
    length = 0

    for nucleotide in dna:
        if nucleotide == 'G' or nucleotide == 'C':
            gc_count += 1
        length += 1

    if length == 0:
        print("GC Content: 0.00%")
        return

    gc_content = (gc_count / length) * 100
    print("GC Content:", gc_content, "%")

dna_seq = input()
calculate_gc_content(dna_seq)

