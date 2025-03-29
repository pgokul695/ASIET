def hamming_distance(seq1, seq2):
    if len(seq1) != len(seq2):
        print("Error: Sequences must be of equal length")
        return -1  

    distance = 0
    for i in range(len(seq1)):
        if seq1[i] != seq2[i]:
            distance += 1

    return distance

def percentage_similarity(seq1, seq2):
    distance = hamming_distance(seq1, seq2)
    if distance == -1:
        return  

    similarity = (1 - distance / len(seq1)) * 100
    print("Percentage Similarity:", similarity, "%")

seq1 = input("ENTER THE FIRST STRING:")
seq2 = input("ENTER THE SECOND STRING:")

percentage_similarity(seq1, seq2)

