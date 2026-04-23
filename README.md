# Design-Patterns-in-Modern-Cpp
A structured collection of Design Patterns implemented in Modern C++, showcasing practical examples, explanations, and best practices. This repository serves as a learning resource and reference guide for mastering design patterns, with clean, minimal code samples and step-by-step documentation.

## Reference Index

### 1. Single Responsibility Principle (SRP)

- File: `01_Single_Responsibility_Principle_SRP.cpp`
- Topic: Keep business logic and persistence logic in separate classes

What this code shows:

- `Journal` stores the journal title and entries.
- `Journal::add_entry()` adds numbered entries to the journal.
- `PersistenceManager` saves journal data into a file.
- This separation follows the Single Responsibility Principle.

Why `PersistenceManager` is better than saving inside `Journal`:

- `Journal` should focus on journal data and journal behavior only.
- Saving to a file is a separate responsibility called persistence.
- If file format, location, or storage type changes, only the persistence code should change.
- This reduces coupling and makes the code easier to maintain, test, and extend.

About `ofstream ofs`:

- `ofstream` means output file stream.
- `ofstream ofs(filename);` creates a file-writing object named `ofs`.
- It opens the file given by `filename`.
- `ofs << e << endl;` writes each journal entry into the file.
- This is used for file persistence, meaning saving program data outside the program.

About `to_string` in this example:

- `to_string(count)` converts the integer counter into text.
- It is used to build numbered entries such as `1: I ate a bug`.
- This version does not require Boost.

Design pattern / principle takeaway:

- Bad approach: `Journal` stores entries and also knows how to save itself.
- Better approach: `Journal` stores data, and `PersistenceManager` handles saving.
- This is a clean example of SRP and is a good revision reference.

## Common C++ Headers Used

- `#include <vector>`
  Used for `std::vector`, a dynamic array container. It stores elements in contiguous memory and can grow or shrink at runtime.

- `#include <cstdio>`
  Used for C-style input/output functions such as `printf`, `scanf`, and file APIs like `fopen`.

- `#include <fstream>`
  Used for file streams such as `std::ofstream`, which writes data to files.

- `#include <string>`
  Used for `std::string` and utility functions such as `std::to_string`.
