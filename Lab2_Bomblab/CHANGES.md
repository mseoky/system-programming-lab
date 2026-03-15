# Lab 2 Changes

This directory has been reorganized around the original bomb target and the final solved inputs.

## Submission Type

Reverse-engineering lab centered on binary analysis rather than source modification.

## What Is Preserved

- `challenge/`: extracted original bomb files
- `solution/phase_solutions.txt`: final phase answers
- `docs/assignment.pdf`: archived assignment/writeup PDF
- `docs/secret_phase_tree.jpg`: analysis image for the secret phase

## What Was Removed

- the original tar archive after extraction
- the `.docx` report-style submission copy

## Main Deliverables

- `solution/phase_solutions.txt`
- `docs/secret_phase_tree.jpg`

## Key Files To Review

- `solution/phase_solutions.txt`
  The final defusing inputs for the visible and secret phases.
- `challenge/bomb`
  The target binary that drove the reverse-engineering work.
- `challenge/bomb.c`
  Useful reference context bundled with this bomb instance.
- `docs/secret_phase_tree.jpg`
  A compact artifact showing secret-phase structural analysis.
- `challenge/README`
  Identifies the specific bomb instance.

## Why It Matters

This lab demonstrates debugger-driven reverse engineering, control-flow reconstruction, and binary-level reasoning rather than code implementation.
