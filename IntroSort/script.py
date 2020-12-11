from random import randint
from subprocess import run, PIPE
import matplotlib.pyplot as plt
times = dict()
print("Enter a number of arrays you want to sort:", end=" ")
n = int(input())
for i in range(n):
    f = open("command.txt", "w")
    f.write("input" + str(i) + ".txt output" + str(i) + ".txt")
    f.close()
    f = open("input" + str(i) + ".txt", "w")
    f.write(str(i * 100) + "\n")
    for j in range(i * 100):
        f.write(str(randint(-1000000, 1000000)) + " ")
    f.close()
    r = run(["ShellSort.exe"], stdout=PIPE)
    f = open("output" + str(i) + ".txt", "r")
    times[i * 1000] = float(f.readline()[:-1])
    f.close()
plt.plot(times.keys(), times.values())
plt.show()
