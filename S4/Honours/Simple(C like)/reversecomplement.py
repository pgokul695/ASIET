def reverse_complement(dna):
    rev_comp = ""

    for i in range(len(dna) - 1, -1, -1): //to itreate in reverse
        if dna[i] == 'A':
            rev_comp += 'T'
        elif dna[i] == 'T':
            rev_comp += 'A'
        elif dna[i] == 'C':
            rev_comp += 'G'
        elif dna[i] == 'G':
            rev_comp += 'C'

    print(rev_comp)

dna = input("Enter the DNA string")
reverse_complement(dna)

