#!/bin/bash

for i in *.in; do
  echo "$i"
  ./a.out < "$i"
  echo "============================================================"
done

