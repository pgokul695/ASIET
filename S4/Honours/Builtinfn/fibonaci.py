def fibonacci_sequence(n):
    sequence = []
    a, b = 0, 1
    for _ in range(n):
        sequence.append(a)
        a, b = b, a + b
    return sequence

# Example usage:
n_terms = 10  # Generate the first 10 Fibonacci numbers
fib_sequence = fibonacci_sequence(n_terms)
print(fib_sequence)

