#!/bin/python3
# https://www.hackerrank.com/challenges/migratory-birds/problem
import math
import os
import random
import re
import sys

# Complete the migratoryBirds function below.
def migratoryBirds(arr):
    count_dict = {}
    for bird in arr:
        if count_dict.get(bird):
            count_dict[bird] = count_dict[bird] + 1
        else:
            count_dict[bird] = 1
    max_count = max(count_dict.values())
    list_values = [key for key, val in count_dict.items() if val == max_count]
    list_values.sort()
    return list_values[0]
