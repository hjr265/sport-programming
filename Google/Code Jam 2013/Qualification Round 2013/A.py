T = int(input())

for no in range(T):
  G = []
  for i in range(4):
    G.append(list(input()))
  input()

  r = ''

  # find T
  Tc = None
  for i in range(4):
    for j in range(4):
      if G[i][j] == 'T':
        Tc = (i, j)

  # change T to X
  if Tc:
    G[Tc[0]][Tc[1]] = 'X'

  # has X won?
  for i in range(4):
    if G[i][0] == G[i][1] == G[i][2] == G[i][3] == 'X' or G[0][i] == G[1][i] == G[2][i] == G[3][i] == 'X':
      r = 'X won'
      break
  if G[0][0] == G[1][1] == G[2][2] == G[3][3] == 'X' or G[0][3] == G[1][2] == G[2][1] == G[3][0] == 'X':
    r = 'X won'

  # change T to O
  if Tc:
    G[Tc[0]][Tc[1]] = 'O'

  # has O won?
  for i in range(4):
    if G[i][0] == G[i][1] == G[i][2] == G[i][3] == 'O' or G[0][i] == G[1][i] == G[2][i] == G[3][i] == 'O':
      r = 'O won'
      break
  if G[0][0] == G[1][1] == G[2][2] == G[3][3] == 'O' or G[0][3] == G[1][2] == G[2][1] == G[3][0] == 'O':
    r = 'O won'

  if r == '':
    # no one won

    # count empty cells
    e = 0
    for i in range(4):
      for j in range(4):
        if G[i][j] == '.':
          e += 1

    if e == 0:
      # no empty cells: draw
      r = 'Draw'
    else:
      # empty cells, no one won: game has to ended
      r = 'Game has not completed'

  print('Case #%d: %s' % (no + 1, r))

