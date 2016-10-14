import bisect
import math

P = []
Q = []

x = '1'
P.append(int(x))

for i in range(10 ** 5):
  xx = str(int(x) ** 2)
  if xx == xx[::-1]:
    Q.append(int(xx))

  xa = int(x[:math.ceil(len(x) / 2)])
  xa += 1
  if len(x) % 2 == 1:
    y = str(xa) + str(xa)[::-1][1:]
  else:
    y = str(xa) + str(xa)[::-1]
  if len(y) > len(x):
    if len(x) % 2 == 1:
      y = str(xa)[:-1] + str(xa)[::-1][1:]
    else:
      y = str(xa) + str(xa)[::-1][1:]

  P.append(int(y))
  x = y

print(len(Q))

T = int(input())

for no in range(T):
  A, B = map(int, input().split())
  print('Case #%d: %d' % (no + 1, bisect.bisect_right(Q, B) - bisect.bisect_left(Q, A)))