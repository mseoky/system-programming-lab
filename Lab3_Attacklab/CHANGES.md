# Lab 3 Changes

This directory has been reorganized around the original target binaries and the final exploit payloads.

## Submission Type

Binary exploitation lab centered on payload construction and attack notes.

## What Is Preserved

- `challenge/`: extracted original attacklab target files
- `solution/`: saved payload files for phases 1-5 and working notes
- `docs/assignment.pdf`: archived assignment/writeup PDF

## What Was Removed

- the original tar archives after extraction
- the `.docx` report-style submission copy

## Main Deliverables

- `solution/target132.p1`
- `solution/target132.p2`
- `solution/target132.p3`
- `solution/target132.p4`
- `solution/target132.p5`
- `solution/solution_notes.txt`

## Key Files To Review

- `solution/solution_notes.txt`
  Notes on addresses, gadgets, cookie handling, and payload construction.
- `solution/target132.p4`
  Representative saved payload for the ROP stage.
- `solution/target132.p5`
  Representative saved payload for the final target stage.
- `challenge/ctarget`
  Code-injection target used in the earlier phases.
- `challenge/rtarget`
  ROP target used in the later phases.

## Why It Matters

This lab demonstrates stack analysis, payload construction, gadget chaining, and a working understanding of low-level calling conventions and binary behavior.
