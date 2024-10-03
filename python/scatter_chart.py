import matplotlib.pyplot as plt
import sys

E_in = []
E_out = []
N = 2000
for i in range(N):
    tmp = input().strip().split()
    E_in.append(float(tmp[0]))
    E_out.append(float(tmp[1]))

plt.scatter(E_in, E_out, c = sys.argv[1])
plt.title("scatter chart of (E_in, E_out)")
# plt.show()
plt.savefig(sys.argv[2])

dif = []
for i in range(N):
    dif.append(E_out[i] - E_in[i])

dif.sort()
print(f"the median: {(dif[N // 2 - 1] + dif[N // 2]) / 2}")
