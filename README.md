# Linked List LIFO

A simple singly linked list implementation in C++ that supports stack-like (LIFO) operations via a command-line interface.

## Tech Stack

| Tool | Version |
|------|---------|
| Language | C++ (C++11 or later) |
| Build system | Visual Studio / MSBuild (`.sln` / `.vcxproj`) |
| Standard library | `<iostream>` |

## Architecture

The project consists of a single translation unit (`Linked list LIFO.cpp`) built around a self-referential `struct`:

```
list (struct)
 ├── key  (int)   – value stored in the node
 └── next (list*) – pointer to the next node
```

A sentinel **head** node is stack-allocated in `main()` and never stores a real value (`key = 0`, `next = nullptr`). All real elements are heap-allocated and appended after the head, making the *tail* act as the top of the LIFO stack.

### Functions

| Function | Description |
|----------|-------------|
| `Init(head)` | Initialises the sentinel head node |
| `InsertEl(i, l)` | Appends a new node with value `i` at the **end** of the list |
| `DeleteEl(l)` | Removes the **last** node and prints its key (LIFO pop) |
| `DeleteList(l)` | Removes the last node without printing (used during cleanup) |
| `GetEl(i, l)` | Returns the key of the node at zero-based index `i` |

## How to Use

### Build (Visual Studio)

1. Open `Linked list LIFO.sln` in Visual Studio.
2. Select **Debug** or **Release** configuration.
3. Press **Ctrl+Shift+B** (Build Solution).

### Build (command line with MSVC)

```bat
cl /EHsc /std:c++14 "Linked list LIFO.cpp" /Fe:lifo.exe
```

### Run

```
lifo.exe
```

The program reads commands from **stdin** until `q` is entered.

### Commands

| Command | Syntax | Description |
|---------|--------|-------------|
| Insert | `i <key>` | Appends an element with the given integer key to the end of the list |
| Delete | `d` | Removes the last element and prints its key |
| Get | `g <index>` | Prints the key of the element at the given zero-based index |
| Quit | `q` | Frees all allocated memory and exits |

### Example

**Input**
```
i 5
i 1
i 2
i 3
i 4
d
g 3
g 0
q
```

**Output**
```
4
3
5
```

**Explanation:**
- After inserting 5, 1, 2, 3, 4 the list is: `5 → 1 → 2 → 3 → 4`
- `d` removes `4` (last element) and prints it → list becomes `5 → 1 → 2 → 3`
- `g 3` fetches index 3 → value `3`
- `g 0` fetches index 0 → value `5`
