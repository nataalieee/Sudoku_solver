# Sudoku Solver

A fast and efficient C++20 Sudoku solver that uses recursive backtracking to solve standard 9x9 Sudoku puzzles read from an input file.

---

## 📋 Features

- **Backtracking Algorithm**: Solves any valid 9x9 Sudoku puzzle systematically using recursive depth-first backtracking.
- **Batch Processing**: Automatically loads and solves multiple Sudoku puzzles in sequence from a single file (`sudoku.txt`).
- **Pretty-Printed Grid**: Visualizes initial and solved boards in the terminal with 3x3 block delimiters (`|` and `---`).
- **Real-Time Constraint Validation**: Dynamically verifies row, column, and 3x3 box rules before placing candidate numbers.
- **Error Handling**: Detects missing or incomplete input files and reports when a puzzle has no valid solution.

---

## 🧩 How It Works

The solver implements a classical **recursive backtracking** search:

1. **Find Empty Cell**: Scans the board from top-left to bottom-right to find the first empty cell (`0`). If all cells are filled, the puzzle is solved.
2. **Candidate Testing (`isValid`)**: For candidates $1$ through $9$, the algorithm verifies:
   - **Row Rule**: The number does not already appear in the current row.
   - **Column Rule**: The number does not already appear in the current column.
   - **3x3 Subgrid Rule**: The number does not already appear within the 3x3 subgrid.
3. **Recursion & Backtracking**:
   - If candidate $d$ is valid, it is placed at `board[row][col]`.
   - Recursively calls `solve()` for subsequent cells.
   - If the branch does not lead to a valid full solution, it resets the cell to `0` (*backtracks*) and tries the next candidate.
   - Returns `false` if no candidate from $1$ to $9$ leads to a solution.

---

## 📁 Project Structure

```text
Sudoku_solver/
├── CMakeLists.txt              # CMake build configuration (C++20)
├── main.cpp                    # Solver source code (logic, I/O, display)
├── sudoku.txt                  # Input puzzle dataset (root directory)
├── cmake-build-debug/
│   └── sudoku.txt              # Input file for CLion's default run configuration
└── README.md                   # Project documentation
```

---

## 📄 Input File Format (`sudoku.txt`)

The program expects an input file named `sudoku.txt` in the current working directory:

1. **Header**: An integer $N$ denoting the number of Sudoku puzzles to solve.
2. **Puzzles**: Exactly $N$ boards of $9 \times 9$ integers separated by spaces or newlines:
   - Numbers `1` to `9`: Pre-filled clue cells.
   - Number `0`: Empty cells to be solved.

### Example `sudoku.txt`:

```text
2
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9

0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0
```

---

## ⚙️ Requirements

- **C++ Compiler**: GCC (10+), Clang (10+), or MSVC supporting **C++20**.
- **Build System**: [CMake](https://cmake.org/) (3.20+) or direct compiler invocation via `g++` / `clang++`.
- **IDE** *(Optional)*: JetBrains CLion, VS Code, etc.

---

## 🚀 Building and Running

### Option 1: JetBrains CLion (Recommended)

1. Open this directory in CLion.
2. CLion will automatically configure the CMake project.
3. Click the green **Run** button (`Shift + F10`) to build and execute `Sudoku_Solver`.

> **Note**: `sudoku.txt` is provided in both the project root and `cmake-build-debug/` so CLion finds the file regardless of working directory settings.

---

### Option 2: Command Line with CMake

```bash
# 1. Generate build files (adjust version in CMakeLists.txt if your system cmake is < 4.1)
cmake -B build -S .

# 2. Compile the executable
cmake --build build

# 3. Ensure sudoku.txt is available in the run directory
cp sudoku.txt build/

# 4. Run the solver
cd build
./Sudoku_Solver
```

---

### Option 3: Direct Compilation with `g++`

You can also compile and run directly without CMake:

```bash
# Compile
g++ -std=c++20 -O2 main.cpp -o Sudoku_Solver

# Run (reads sudoku.txt from the current directory)
./Sudoku_Solver
```

---

## 🖥️ Example Output

```text
--- Sudoku #1 ---
Tabla initiala:
5 3 0 | 0 7 0 | 0 0 0 
6 0 0 | 1 9 5 | 0 0 0 
0 9 8 | 0 0 0 | 0 6 0 
---------------------
8 0 0 | 0 6 0 | 0 0 3 
4 0 0 | 8 0 3 | 0 0 1 
7 0 0 | 0 2 0 | 0 0 6 
---------------------
0 6 0 | 0 0 0 | 2 8 0 
0 0 0 | 4 1 9 | 0 0 5 
0 0 0 | 0 8 0 | 0 7 9 

Solutie:
5 3 4 | 6 7 8 | 9 1 2 
6 7 2 | 1 9 5 | 3 4 8 
1 9 8 | 3 4 2 | 5 6 7 
---------------------
8 5 9 | 7 6 1 | 4 2 3 
4 2 6 | 8 5 3 | 7 9 1 
7 1 3 | 9 2 4 | 8 5 6 
---------------------
9 6 1 | 5 3 7 | 2 8 4 
2 8 7 | 4 1 9 | 6 3 5 
3 4 5 | 2 8 6 | 1 7 9 

--- Sudoku #2 ---
Tabla initiala:
0 0 0 | 2 6 0 | 7 0 1 
6 8 0 | 0 7 0 | 0 9 0 
1 9 0 | 0 0 4 | 5 0 0 
---------------------
8 2 0 | 1 0 0 | 0 4 0 
0 0 4 | 6 0 2 | 9 0 0 
0 5 0 | 0 0 3 | 0 2 8 
---------------------
0 0 9 | 3 0 0 | 0 7 4 
0 4 0 | 0 5 0 | 0 3 6 
7 0 3 | 0 1 8 | 0 0 0 

Solutie:
4 3 5 | 2 6 9 | 7 8 1 
6 8 2 | 5 7 1 | 4 9 3 
1 9 7 | 8 3 4 | 5 6 2 
---------------------
8 2 6 | 1 9 5 | 3 4 7 
3 7 4 | 6 8 2 | 9 1 5 
9 5 1 | 7 4 3 | 6 2 8 
---------------------
5 1 9 | 3 2 6 | 8 7 4 
2 4 8 | 9 5 7 | 1 3 6 
7 6 3 | 4 1 8 | 2 5 9 
```

