#!/usr/bin/python3
import random
import string
n = 4     # num of strings
m = 2      # len of string
k = 2       # inserts k times as often as queries

print(n)
st = set()
# Q query
# I insert
query = ['Q'] + ['I'] * k
for i in range(n):
    op = query[random.randint(0, len(query)-1)]
    if (op == 'I'):
        s = ''.join(random.choices(string.ascii_uppercase, k=m))
        st.add(s)       
        print(op, s)
    elif (op == 'Q'):
        t = random.randint(0, 1)
        if (t == 0 and len(st) > 0):
            print(op, random.choice(tuple(st)))
        elif (t == 1):
            print(op, ''.join(random.choices(string.ascii_uppercase, k=m)))
