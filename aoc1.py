import sys
from string import digits


def compute(line: str) -> int:
    v = [c for c in line if c in digits]
    return int(v[0]) * 10 + int(v[-1])


if __name__ == "__main__":
    with open(("input.txt")) as f:
        result = sum(compute(line) for line in f)
    print(f"{result=}")
    sys.exit(0)
