import sys

def is_sorted(sequence):
    return all(sequence[i] <= sequence[i + 1] for i in range(len(sequence) - 1))

def extract_last_numbers_line(lines):
    # Try to find the last line with only numbers
    for line in reversed(lines):
        if all(part.strip().isdigit() for part in line.strip().split()):
            return list(map(int, line.strip().split()))
    return []

def main():
    # Read input from a file if provided, else from stdin
    if len(sys.argv) > 1:
        with open(sys.argv[1], "r") as f:
            lines = f.readlines()
    else:
        lines = sys.stdin.readlines()

    nums = extract_last_numbers_line(lines)

    if not nums:
        print("❌ No valid number line found in output.")
        sys.exit(1)

    if is_sorted(nums):
        print("✅ Output is sorted correctly.")
        sys.exit(0)
    else:
        print("❌ Output is NOT sorted.")
        sys.exit(1)

if __name__ == "__main__":
    main()
