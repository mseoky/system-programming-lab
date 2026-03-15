# System Programming Lab

This repository archives my Spring 2024 System Programming coursework at Pusan National University (PNU).

The labs are based on the CS:APP-style systems programming track and cover bit-level integer manipulation, reverse engineering, binary exploitation, and cache-aware programming.

This is coursework rather than production systems software, but it still demonstrates practical low-level skills:

- reading and modifying C code under tight constraints
- understanding compiled binaries and assembly behavior
- using debugger-driven reverse engineering workflows
- reasoning about calling conventions, stack layout, and exploit payloads
- implementing a cache simulator and cache-conscious matrix transpose

## Overview

| Lab | Topic | Main Artifact Type |
| --- | --- | --- |
| 1 | Data Lab | constrained C implementation |
| 2 | Bomb Lab | reverse engineering notes and phase solutions |
| 3 | Attack Lab | exploit payloads and attack notes |
| 4 | Cache Lab | systems C source code |

## Why This Repository Exists

I am keeping this repository as an archive of low-level programming coursework that is still relevant to systems, platform, security, and performance-oriented roles.

- Data Lab shows bit-level reasoning in C.
- Bomb Lab shows assembly reading and debugger-based analysis.
- Attack Lab shows stack-based exploitation and ROP-oriented reasoning.
- Cache Lab shows memory hierarchy awareness and performance-focused C implementation.

## Repository Structure

Each lab is organized around the most useful final review artifacts rather than raw submission bundles.

### `Lab1_Datalab`

- `src/`: extracted handout with my final `bits.c`
- `docs/`: assignment/writeup PDF
- `CHANGES.md`: summary of what was implemented

### `Lab2_Bomblab`

- `challenge/`: extracted original bomb files
- `solution/`: solved phase inputs
- `docs/`: assignment PDF and secret-phase analysis image
- `CHANGES.md`: summary of the solution artifacts

### `Lab3_Attacklab`

- `challenge/`: extracted target binaries and supporting files
- `solution/`: exploit payload files and analysis notes
- `docs/`: assignment PDF
- `CHANGES.md`: summary of the exploit workflow

### `Lab4_Cachelab`

- `src/`: extracted handout with my submitted `csim.c` and `trans.c`
- `docs/`: assignment PDF
- `CHANGES.md`: summary of the implementation

## Lab Summary

### Lab 1. Data Lab

Implemented the required integer/bit-manipulation functions in `bits.c` under operator and control-flow restrictions.

Core skills demonstrated:

- two's-complement reasoning
- bit masking and shifting
- constraint-driven C implementation

### Lab 2. Bomb Lab

Solved the bomb phases by reverse engineering the target binary and recording the required inputs.

Core skills demonstrated:

- disassembly reading
- control-flow analysis
- debugger-assisted problem solving
- binary logic reconstruction

### Lab 3. Attack Lab

Built phase-specific payloads for code-injection and return-oriented programming targets.

Core skills demonstrated:

- stack-frame analysis
- exploit string construction
- gadget chaining
- calling-convention reasoning

### Lab 4. Cache Lab

Implemented a cache simulator and a cache-optimized matrix transpose.

Core skills demonstrated:

- set-associative cache simulation
- LRU-style eviction logic
- memory access optimization
- performance-aware C programming

## Running the Archived Labs on Linux CLI

Some labs are source-based and can be rebuilt directly. Others are analysis/exploit labs centered on provided binaries.

### Data Lab

```bash
cd Lab1_Datalab/src
make
```

Typical handout tools include `btest` and `dlc`, depending on your environment and the original handout.

### Cache Lab

```bash
cd Lab4_Cachelab/src
make
```

This typically builds the cache simulator and the transpose test/driver programs from the handout.

### Bomb Lab

```bash
cd Lab2_Bomblab/challenge
./bomb
```

The solved inputs are archived in:

```bash
cat ../solution/phase_solutions.txt
```

### Attack Lab

The original targets and helper utility are archived in `Lab3_Attacklab/challenge`, and the saved payload files are in `Lab3_Attacklab/solution`.

Example inspection workflow:

```bash
cd Lab3_Attacklab/challenge
objdump -d ctarget | less
objdump -d rtarget | less
cat ../solution/solution_notes.txt
```

## Notes

- This repository is intended as an academic archive.
- It has been reorganized to keep the final review artifacts visible on GitHub instead of leaving everything inside tarballs.
- Some original screenshots and private report-style submission documents were intentionally omitted from the cleaned archive because they add less review value than the extracted source, challenge, and solution files.
