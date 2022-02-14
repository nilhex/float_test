#!python3

import random

SIZE = 1000000

operators = [
    ("+",    2), 
    ("-",    2), 
    ("/",    2), 
    ("*",    2),
    ("sqrt", 1),
]

if __name__ == '__main__':
    with open("input.csv", "w") as file:
        for _ in range(SIZE):
            op, args = random.choice(operators)
            file.write(f"{op} {args} {' '.join(map(lambda _: str(random.random()), range(args)))}\n")
    file.close()
