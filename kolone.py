import sys

# Read in all the inputs
n = sys.stdin.readline().strip()
lineOne = sys.stdin.readline().strip()
lineTwo = sys.stdin.readline().strip()
timeT = sys.stdin.readline().strip()

# Turn into usable forms.
# n into the two ints we need to read the lines as characters
# (Technically unneeded in python but I switch between this
# and other languages so I want to keep up the practice)
# timeT into a single int

n1 = int(n[0])
n2 = int(n[2])
timeT = int(timeT[0])
# lineMain exists to merge the two given lines
lineMain = []

# Do it seperately to use n1 and n2, they might be different
# Append each value to the lineMain
for x in reversed(range(n1)):
    lineMain.append(lineOne[x])
for x in range(n2):
    lineMain.append(lineTwo[x])

# Main work loop. timeT seconds of work
for t in range(1, timeT+1):
    mark = 0
    for c in range(len(lineMain)):
        if (lineMain[c] in lineOne) and mark < t:
            if lineMain[c+1] not in lineOne:
                hold = lineMain[c+1]
                lineMain[c+1] = lineMain[c]
                lineMain[c] = hold
                mark += 1
# And, print.
for x in lineMain:
    print(x, end="")
