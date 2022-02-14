#!python3

import os

if __name__ == "__main__":
    outputs = list(map(
        lambda f: (open(f, "r"), f),
        filter(
            lambda f: f.startswith("output_"),
            os.listdir('.')
        )
    ))

    inpt = open("input.csv", "r")

    for i, expr in enumerate(inpt):
        target, t_name = None, None
        for output, name in outputs:
            val = output.readline()
            if target is None:
                target, t_name = val, name
            elif val != target:
                print("=" * 20)
                print(f"Mismatch on line: {i}")
                print(f"Expr: {expr}")
                print(f"{target} {t_name}")
                print(f"{val} {name}")
