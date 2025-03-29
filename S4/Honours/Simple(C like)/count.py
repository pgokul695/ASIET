def count_nucleotides(dna):
    count_A = 0
    count_T = 0
    count_C = 0
    count_G = 0

    for nucleotide in dna:
        if nucleotide == 'A':
            count_A += 1
        elif nucleotide == 'T':
            count_T += 1
        elif nucleotide == 'C':
            count_C += 1
        elif nucleotide == 'G':
            count_G += 1

    print("A:", count_A)
    print("T:", count_T)
    print("C:", count_C)
    print("G:", count_G)

dna = input("Enter the DNA STRING");
count_nucleotides(dna)

