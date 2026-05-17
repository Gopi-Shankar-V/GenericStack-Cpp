# 📚 GenericStack-Cpp

A **menu-driven C++ console application** that implements a fully generic **Stack data structure** using **Class Templates** — supporting 5 different data types from a single reusable class, with a rich **ANSI color-coded terminal UI**.

> One Stack class. Five data types. Zero code duplication.

---

## 📁 Repository Structure

```
GenericStack-Cpp/
│
├── main.cpp        # Complete working application — all stack logic + menu UI
├── header.h        # Shared ANSI color macros + push() template + extern declarations
├── opt1.cpp        # Early modular attempt — sub-menu handler (work in progress)
├── push.cpp        # Standalone push function experiment
├── makefile        # Build automation
└── exe             # Compiled executable (Linux)
```

> **Note:** `main.cpp` is the **primary, fully working file** — it is self-contained with all stack operations, menu logic, and ANSI UI. `opt1.cpp` and `push.cpp` are early experiments in splitting the project into modules (pop, peek, display are still commented out in opt1.cpp).

---

## ✨ Features

- 🧩 **Generic Stack via C++ Class Templates** — one class handles all data types, zero duplication
- 🔢 **Supports 5 data types** — `int`, `char`, `float`, `double`, `string`
- 📦 **Full Stack Operations** — Push, Pop, Peek, Display
- 🛡️ **Overflow & Underflow Detection** — with descriptive error messages
- 🔁 **Session Memory** — detects existing stack data, asks to continue or reset
- 🎨 **24+ ANSI Color Macros** — bold, bright, and blinking terminal UI
- ⚠️ **3-Strike Input Validation** — 3 consecutive invalid inputs → graceful exit
- 🔤 **Static `TOP` pointer** — shared across template class instances

---

## 🛠️ Tech Stack

| Component | Details |
|---|---|
| **Language** | C++ (C++11 or later) |
| **Key Concept** | Class Templates, Static Members, OOP |
| **UI** | ANSI Escape Codes (24+ color macros) |
| **Compiler** | g++ (GCC) |
| **Build** | GNU Make |
| **Platform** | Linux / macOS (ANSI color support required) |

---

## 🧱 Core — Template Stack Class

A single generic class handles **all 5 data types** — no code duplication:

```cpp
template <class Type>
class stack {
public:
    Type stk[max];          // Fixed-size array storage (max = 5)
    static int TOP, count;  // Shared TOP pointer across all instances
    stack() { TOP = -1; }   // Initialize empty stack
};
```

Each data type gets its own independent stack instance in `main()`:

```cpp
stack<int>    intobj;
stack<char>   charobj;
stack<float>  floatobj;
stack<double> doubleobj;
stack<string> strobj;
```

---

## 📄 File Descriptions

### `main.cpp` — Complete Application
The fully working, self-contained file. Contains:

| Component | Description |
|---|---|
| `stack<Type>` class | Generic template class with `stk[]`, `TOP`, `count` |
| `push(obj)` | Checks overflow → reads input → stores at `stk[++TOP]` |
| `pop(obj)` | Checks underflow → displays deleted element → decrements `TOP` |
| `peek(obj)` | Checks underflow → displays `stk[TOP]` without removing |
| `display(obj)` | Iterates from `TOP` to `0` → prints all elements |
| `opt(obj)` | Sub-menu handler — routes to push/pop/peek/display |
| `main()` | Main menu with 5 type selections + session-aware stack management |

### `header.h` — Shared Header (used by opt1.cpp)
Contains:
- `#ifndef HEADER_H` include guard
- `#include <iostream>`, `#include <fstream>`, `using namespace std`
- `#define pf cout`, `#define sf cin`, `#define max 5`
- **24+ ANSI escape code macros** (dark + bright variants for all 8 terminal colors)
- `push()` template function definition
- `extern void opt1(Topt &)` forward declaration

> ⚠️ `main.cpp` does **not** include `header.h` — it is self-contained. `header.h` is used only by `opt1.cpp`.

### `opt1.cpp` — Modular Sub-menu (Work in Progress)
An early attempt at splitting the operations into separate files. Currently:
- `push()` is functional ✅
- `pop()`, `peek()`, `display()` are **commented out** ⚠️
- Includes `header.h` for shared macros

### `push.cpp` — Standalone Push Experiment
A standalone module experiment for the push operation.

---

## 🎨 ANSI Color System

The project defines **24+ color macros** in two variants — dark and bright:

```cpp
// Dark variants
#define GREEN_B   "\033[32;1m"    // Bold Green   → menus
#define RED_BB    "\033[31;1;5m"  // Bold Blinking Red → errors
#define YELLOW_B  "\033[33;1m"    // Bold Yellow  → warnings
#define BLUE_B    "\033[34;1m"    // Bold Blue    → prompts
#define WHITE_BB  "\033[37;1;5m"  // Bold Blinking White → input highlight

// Bright variants
#define green_b   "\033[92;1m"    // Bright Bold Green
#define red_bb    "\033[91;1;5m"  // Bright Bold Blinking Red
#define blue_b    "\033[94;1m"    // Bright Bold Blue

#define RESET     "\033[0m"       // Reset all formatting
```

---

## 🔄 Program Flow

```
[Main Menu] — Select data type
       │
       ├──▶ (1) Integer Stack
       ├──▶ (2) Character Stack
       ├──▶ (3) Float Stack
       ├──▶ (4) Double Stack
       └──▶ (5) String Stack
                    │
                    ├── Existing data? ──▶ (1) Continue  (2) Reset  (3) Back
                    │
                    └──▶ Sub-menu
                              ├──▶ (1) PUSH
                              ├──▶ (2) POP
                              ├──▶ (3) PEEK
                              ├──▶ (4) DISPLAY
                              └──▶ (5) MAIN MENU
```

---

## 🚀 Getting Started

### Prerequisites

```bash
sudo apt install g++ make      # Debian / Ubuntu
sudo dnf install gcc-c++ make  # Fedora / RHEL
```

### Compile & Run

```bash
# Clone the repository
git clone https://github.com/Gopi-Shankar-V/GenericStack-Cpp.git
cd GenericStack-Cpp

# Using Makefile
make

# Run
./exe
```

**Manual compilation:**
```bash
g++ main.cpp -o exe
./exe
```

---

## 💻 Usage Example

```
+++++++++++++++++++++++++++++++++
+   <<< STACK APPLICATION >>>  +
+++++++++++++++++++++++++++++++++
+       (1) INTEGER            +
+       (2) CHARACTER          +
+       (3) FLOAT              +
+       (4) DOUBLE             +
+       (5) STRING             +
+       (0) EXIT               +
+++++++++++++++++++++++++++++++++
Enter Your Choice$ 1

    Integer Stack Application Ready To Use!

    (1) PUSH  (2) POP  (3) Peek  (4) DISPLAY  (5) MAIN MENU

Enter Your Choice$ 1
    Enter the data$ 42

Enter Your Choice$ 1
    Enter the data$ 99

Enter Your Choice$ 4
     $99
     $42

Enter Your Choice$ 2
     $99 Is Deleted!

Enter Your Choice$ 3
     $42          ← Peek (not removed)
```

---

## 🧠 Key Concepts Demonstrated

| Concept | How It's Used |
|---|---|
| **C++ Class Templates** | `template <class Type> class stack` — single class for all types |
| **Static Class Members** | `static int TOP` — shared stack pointer across type instantiations |
| **Template Functions** | `push<T>`, `pop<T>`, `peek<T>`, `display<T>`, `opt<T>` |
| **Object-Oriented Design** | Encapsulated stack class with clean public interface |
| **ANSI Escape Sequences** | `\033[` codes for terminal color, bold, and blink effects |
| **Macro Definitions** | `pf`/`sf` aliases + 24+ color constants for readable code |
| **Input Validation** | 3-strike progressive warning system with graceful exit |
| **Session State** | Detects existing `TOP > -1`, prompts continue or reset |

---

## ⚠️ Known Limitations

- Stack capacity is fixed at `max = 5` (defined via `#define max 5`)
- No dynamic resizing — overflow is detected and reported
- `opt1.cpp` is incomplete — pop, peek, display are commented out (work in progress)
- ANSI colors require a terminal with escape code support (not visible in Windows CMD)

---

## 📌 .gitignore (Recommended)

```gitignore
# Compiled output
*.o
exe

# IDE files
.vscode/
*.code-workspace
.idea/
```

---

## 👤 Author

**Gopi Shankar V**
GitHub: [@Gopi-Shankar-V](https://github.com/Gopi-Shankar-V)

---

## 📄 License

This project is open source and available for educational and reference purposes.
