#part 2

import re

f = open("2024/D3/input.txt", "r")
input = f.read()

res = 0

enabled = True
for instr in re.findall("don't\(\)|do\(\)|mul\(\d+,\d+\)", input):
    if instr == "don't()":
        enabled = False
    elif instr == "do()":
        enabled = True
    elif enabled:
        n1, n2 = instr[4:len(instr) - 1].split(",")

        res += int(n1) * int(n2)
print(res)

exit()
#part 1
import re

f = open("2024/D3/input.txt", "r")
input = f.read()

matchs = re.findall('mul\([0-9]{1,3},[0-9]{1,3}\)', input)

res = 0
for match in matchs:
    a,b = match[4:-1].split(',')
    res += int(a) * int(b)
print(res)