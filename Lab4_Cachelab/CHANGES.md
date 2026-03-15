# Lab 4 Changes

This directory has been reorganized around the final Cache Lab source submission.

## Submission Type

Source-based systems programming lab.

## What Is Preserved

- `src/`: the original handout tree restored from the handout archive
- `src/csim.c`: my submitted cache simulator
- `src/trans.c`: my submitted optimized transpose implementation
- `docs/assignment.pdf`: archived assignment PDF

## What Was Removed

- self-grade image
- the original handout and handin tar archives after extraction

## Main Deliverables

- `src/csim.c`
- `src/trans.c`

## Key Files To Review

- `src/csim.c`
  The cache simulator implementation, including cache state and replacement logic.
- `src/trans.c`
  The performance-focused matrix transpose solution.
- `src/cachelab.h`
  Reference interface used by the handout framework.
- `src/test-trans.c`
  Useful for understanding how transpose correctness/performance is checked.
- `src/README`
  Original handout context and expected workflow.

## Why It Matters

This lab is the strongest performance-oriented artifact in the repository and shows both correctness-focused simulation work and cache-aware optimization.
