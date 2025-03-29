def fibonacci(n):
    if n <= 0:
        print("Invalid input")
        return

    a = 0
    b = 1

    for i in range(n):
        print(a, end=" ")
        temp = a + b
        a = b
        b = temp

n = int(input())
fibonacci(n)

