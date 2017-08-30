#!/bin/bash
for f in *.in; do
  echo "${f}"
  ./a.out < "${f}"
  echo "========================================"
done
