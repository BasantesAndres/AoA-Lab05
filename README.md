<div align="center">

# Analysis of Algorithms — Lab 05
### Insertion Sort, Binary Search, Interpolation Search, and Paper Summary

<p>
  <img src="https://img.shields.io/badge/Language-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B" alt="C++ badge" />
  <img src="https://img.shields.io/badge/Course-Analysis%20of%20Algorithms-6f42c1?style=for-the-badge" alt="Course badge" />
  <img src="https://img.shields.io/badge/University-Yachay%20Tech-0a7ea4?style=for-the-badge" alt="University badge" />
  <img src="https://img.shields.io/badge/Status-Completed-success?style=for-the-badge" alt="Status badge" />
</p>

</div>

---

## Overview

This repository contains the solution for **Lab 05** of **Analysis of Algorithms**. The lab includes three main tasks:

1. **Insertion Sort with alphabetic characters**
2. **Performance comparison between Binary Search and Interpolation Search** using **10,000,000 random numbers**
3. **A one-page summary** of the paper *Topological Sorting of Large Networks* by Arthur B. Kahn

In addition to the source code, the repository includes execution screenshots and the final PDF report.

---

## Repository Structure

```bash
Lab05/
├── AoALab05.pdf
├── Screen1 Task1.JPG
├── Screen2 Task2.JPG
├── task1.exe
├── task2.exe
├── task2_search_compare.cpp
└── src/
    ├── task1_insertion_chars.cpp
    └── task2_search_compare.cpp
```

> Note: The main source files are inside the `src/` folder.

---

## Implemented Tasks

### Task 1 — Insertion Sort with Characters

This program generates a random array of uppercase alphabetic characters and sorts it using **Insertion Sort**.

**Key idea:** no structural change is needed to adapt the algorithm from integers to characters, because `char` values can be compared directly in C++.

**Source file:** `src/task1_insertion_chars.cpp`

---

### Task 2 — Binary Search vs Interpolation Search

This program:

- generates **10,000,000 random integers**,
- sorts the array,
- selects a key guaranteed to exist,
- searches for it using:
  - **Binary Search**
  - **Interpolation Search**
- measures the execution time of both algorithms.

**Source file:** `src/task2_search_compare.cpp`

---

### Task 3 — Paper Summary

The repository also includes the final report in PDF format, with the requested summary of the article:

> *Kahn, Arthur B. (1962), "Topological Sorting of Large Networks"*

**Report file:** `AoALab05.pdf`

---

## Quick Start

### Compile Task 1

```bash
g++ -O2 -std=c++17 src/task1_insertion_chars.cpp -o task1
```

### Run Task 1

```bash
./task1
```

### Compile Task 2

```bash
g++ -O2 -std=c++17 src/task2_search_compare.cpp -o task2
```

### Run Task 2

```bash
./task2
```

---

## Windows (MinGW)

### Compile

```bash
g++ -O2 -std=c++17 src/task1_insertion_chars.cpp -o task1.exe
g++ -O2 -std=c++17 src/task2_search_compare.cpp -o task2.exe
```

### Run

```bash
task1.exe
task2.exe
```

---

## Example Outputs

<details>
<summary><strong>Task 1 — Insertion Sort Output</strong></summary>
<br>

```text
Enter the size of the character array: 20

Original array:
Q A M Z B K T H C P D X L N F J R E W G

Sorted array:
A B C D E F G H J K L M N P Q R T W X Z
```

</details>

<details>
<summary><strong>Task 2 — Search Comparison Output</strong></summary>
<br>

```text
Generating 10000000 random numbers...
Sorting the array...
Key to search: 523891274

===== RESULTS =====
Generation time: 430 ms
Sorting time: 980 ms

Binary Search:
  Position found: 5123487
  Time: 3 microseconds

Interpolation Search:
  Position found: 5123487
  Time: 1 microseconds
```

</details>

---

## Screenshots

### Task 1

![Task 1 Screenshot](./Screen1%20Task1.JPG)

### Task 2

![Task 2 Screenshot](./Screen2%20Task2.JPG)

---

## Algorithms Used

| Task | Algorithm | Purpose |
|------|-----------|---------|
| 1 | Insertion Sort | Sort a random array of alphabetic characters |
| 2 | Binary Search | Search a key in a sorted array |
| 2 | Interpolation Search | Estimate the likely position of a key in a sorted array |

---

## Notes

- The search algorithms require a **sorted array**, so sorting is performed before the searches.
- For Task 1, uppercase letters were used to keep the ordering simple and consistent.
- Execution times may vary depending on the computer and compiler optimizations.

---

## Author

**Andres Basantes**  
Analysis of Algorithms  
Professor: **Israel Pineda**  
Yachay Tech University

---

