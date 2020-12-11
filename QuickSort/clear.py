import os
i = 0
while True:
    s = "input" + str(i) + ".txt"
    s1 = "output" + str(i) + ".txt"
    if os.path.exists(s):
        os.remove(s)
        os.remove(s1)
        i += 1
    else:
        break

