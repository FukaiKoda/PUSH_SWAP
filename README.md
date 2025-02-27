# push\_swap - Stack Sorting Algorithm

## 📌 Overview

push\_swap is an optimized sorting algorithm that sorts a stack of integers using the fewest possible operations. It provides a set of predefined stack operations (`pa`, `pb`, `sa`, `sb`, `ra`, `rb`, etc.) to achieve an efficient sorting sequence.

Additionally, the project includes a **checker** (bonus part) that verifies if a given sequence of operations successfully sorts the stack. The program ensures robust input validation, handles an unlimited number of arguments, and avoids memory leaks.

## 📂 Features

### 📝 Sorting Mechanism

- Implements an optimized sorting algorithm with minimal operations.
- Uses a combination of stack operations to efficiently reorder elements.
- Handles small and large stacks with different sorting strategies (e.g., brute force for small stacks, advanced algorithms for larger ones).

### ✅ Bonus - Checker

- The checker verifies whether the sequence of operations correctly sorts the stack.
- It reads the output from `push_swap` and determines if the final stack is sorted.

### 🔍 Input Handling

- Accepts numbers passed as separate arguments or within quoted strings:
  ```sh
  ./push_swap 5 2 1 -4 9
  ./push_swap "5 2 1    " "-1    +65"
  ```
- Splits and processes arguments correctly, ignoring extra spaces.
- Validates inputs and rejects:
  - Non-numeric values.
  - Duplicates.
  - Overflows and invalid signs.
  - Empty inputs or excessive whitespace.
- No memory leaks; every allocation is managed properly.

## 🚀 Usage

To compile the program:

```sh
make
```

Run `push_swap` with a set of numbers:

```sh
./push_swap 5 3 1 2 4
```

Use the checker to validate sorting:

```sh
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

## 🎯 Key Takeaways

- Developed an efficient sorting approach using stack-based operations.
- Implemented a robust input parser to handle complex argument structures.
- Ensured memory safety and leak-free execution.
- Created a reliable checker to validate sorting correctness.

## 📜 License

This project is open-source and available under the MIT License.

