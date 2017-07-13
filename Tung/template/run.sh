#!/bin/bash
for f in *; do
  ./a.out < "${f}"
  echo "===="
done
