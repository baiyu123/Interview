from random import randint

def getRandomSubset(list,size):
  for i in xrange(0,size):
    index = randint(0,len(list)-1)
    list[i],list[index] = list[index],list[i]
  return list[:size]

testlist = [1,2,3,4,5,6,7]
print(getRandomSubset(testlist,5))
