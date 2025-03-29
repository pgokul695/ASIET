def dna_to_rna(dna):
    rna = ""

    for i in dna:
        if i == 'T':
            rna += 'U'
        else:
            rna += i

    print("RNA:",rna)

dna = input("Enter THE DNA")
print("DNA:",dna)
dna_to_rna(dna)

