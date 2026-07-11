# 🧠 Prolog — Logic Programming Starter Kit

> A beginner-friendly collection of Prolog programs, concepts, and practice problems to make learning logic programming easier.

---

## 📚 What's Inside

| Category | What You'll Learn |
|---|---|
| **Facts & Syntax** | How Prolog represents knowledge |
| **Rules & Queries** | Deriving new information from facts |
| **Recursion** | Factorial, Fibonacci, GCD |
| **List Operations** | Pattern matching, traversal |
| **Family Trees** | Classic logic relationships |
| **Graph Search** | Depth-first search (DFS) |

---

## 🗂️ Repository Structure

```
prolog/
│── LICENSE
│── README.md
│── dfs.pl          ← Depth-First Search
│── even-odd.pl     ← Even/Odd number check
│── fact.pl         ← Factorial
│── fibo.pl         ← Fibonacci sequence
│── gcd.pl          ← Greatest Common Divisor
│── grandparent.pl  ← Grandparent relationship
│── max.pl          ← Maximum of two numbers
│── parent.pl       ← Parent relationship
└── sibling.pl      ← Sibling relationship
```

---

## 🛠️ Requirements

Install **SWI-Prolog** to run these programs:

- 🌐 Official Website: [SWI-Prolog](https://www.swi-prolog.org)
- Available for Windows, macOS, and Linux
- Free and open-source

---

## ▶️ How to Run

### Step 1 — Download the Repository

- Click the **Code** button on GitHub → **Download ZIP**
- Extract the ZIP to a folder on your system

### Step 2 — Open SWI-Prolog

Launch the SWI-Prolog application after installing it.

### Step 3 — Load a File

```prolog
?- consult('path/to/filename.pl').
```

**Example (Windows):**
```prolog
?- consult('C:/Users/YourName/Documents/prolog/fact.pl').
```

**Shorthand syntax:**
```prolog
?- ['C:/Users/YourName/Documents/prolog/fact.pl'].
```

### Step 4 — Run a Query

```prolog
?- fact(5, X).
```

Expected output:
```
X = 120.
```

---

## 🔍 Quick Examples

### Factorial (`fact.pl`)
```prolog
?- fact(0, X).   % X = 1
?- fact(5, X).   % X = 120
```

### Fibonacci (`fibo.pl`)
```prolog
?- fibo(7, X).   % X = 13
```

### GCD (`gcd.pl`)
```prolog
?- gcd(12, 8, X).  % X = 4
```

### Even or Odd (`even-odd.pl`)
```prolog
?- even(4).   % true
?- odd(7).    % true
```

### Parent / Grandparent
```prolog
?- parent(tom, bob).      % Is tom bob's parent?
?- grandparent(tom, ann). % Is tom ann's grandparent?
```

### Siblings
```prolog
?- sibling(bob, liz).   % Are bob and liz siblings?
```

### DFS (`dfs.pl`)
```prolog
?- dfs(start, goal, Path).  % Find a path using depth-first search
```

---

## 💡 Prolog Tips for Beginners

- **Facts** end with a period: `parent(tom, bob).`
- **Rules** use `:-` (means "if"): `grandparent(X, Z) :- parent(X, Y), parent(Y, Z).`
- **Queries** start with `?-` in the REPL
- Use `;` after a result to find more solutions
- Use `trace.` to debug step-by-step
- Use `halt.` to exit SWI-Prolog

---

## 🤝 Contributions

Feel free to use the code, improve it, or add new examples.

---

## ⭐ Support

If this repository helps you during labs or revision, consider giving it a star on GitHub. Every ⭐ helps others discover it too!
