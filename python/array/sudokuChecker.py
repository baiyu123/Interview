def checkRows(board):
  for row in board:
    mySet = set()
    for elem in row:
      if elem in mySet:
        return False
      else:
        mySet.add(elem)
  return True

def checkColums(board):
  mySet = set()
  for i in xrange(len(board[0])):
    mySet.clear()
    for j in xrange(len(board)):
      if board[i][j] in mySet:
        return False
      mySet.add(board[i][j])
  return True

def checkSubset(board,x,y):
  mySet = set()
  for i in xrange(x,x+3,1):
    for j in xrange(y,y+3,1):
      if board[x][y] in mySet:
        return False
      mySet.add(board[x][y])
  return True

def checkSubsets(board):
  for startx in xrange(0,9,3):
    for starty in xrange(0,9,3):
      if not checkSubset(board, startx, starty):
        return False
  return True


board = [[0 for i in xrange(9)] for j in xrange(9)]
print checkRows(board)
print checkColums(board)
print checkSubsets(board)