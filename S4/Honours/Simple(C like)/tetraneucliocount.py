def tetra_nucleotide_count(dna):
    if len(dna) < 4:
        print("Error: DNA sequence must be at least 4 nucleotides long.")
        return

    tetra_freq = {} 

    for i in range(len(dna) - 3):
        tetra = dna[i:i+4]
        if tetra in tetra_freq:
            tetra_freq[tetra] += 1
        else:
            tetra_freq[tetra] = 1

    for k in tetra_freq:
        print(k, ":", tetra_freq[k])

dna = input()
tetra_nucleotide_count(dna)

