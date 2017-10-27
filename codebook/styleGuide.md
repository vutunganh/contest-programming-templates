# Codebook Style Guide

This document (in-progress) contains style restrictions on the codebook structure 
and implementations. It should enforce to write the codebook the best way with
focus on its usage during both ACM-like contests (for rewriting code by hand)
and during online contest which allow to copy-paste code on the fly.

## The main goals

- fast black-box usage 
    - user can use it without understanding the algorithm at all
- reusability multiple times in same code 
    - although using global state is often recommended, consider case when i would
      like to use the code for two different purposes at the same time
- bendability
    - the code should be written with the aim of possible changes to the
      algorithm for specific tasks, so distinct stages of algorithms should be
      easily distinguishible

## Documentation

What should be on first few lines:

- Full name of algorithm
- What algorithm does
- Time (+space if needed) complexity
- Constraints of algorithm 
    - Input: directed graphs, negative evaluated edges, shelf-loops, ...
        - API: 1-index format (heap, Fenwick)

## General Code Style
- Use the single template across whole codebook
- Choose most bendable and readible implementation

### Graphs
### Structs
### Algorithms
