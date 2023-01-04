import sys
import math

inp = int(input())


def stirFact(n):
    if n == 1:
        return 1
    e = 2.71
    pi = 3.14

    z = (math.sqrt(2 * pi * n) * math.pow((n / e), n))
    return math.floor(z)

curr = 0
form = 1
formCheck = 0
for x in range(inp):
    curr = x
    currCheck = stirFact(x)
    
    if abs(inp - currCheck) > abs(inp - formCheck):
        break
    form = x
    formCheck = currCheck
print(form)
