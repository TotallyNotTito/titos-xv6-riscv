import sys
count = 0;
total = 0
data = sys.stdin.read().splitlines()
for i in range(len(data)) :
  val = int(data[i],16)
  if (val >= 555555 and val <= 777777) :
    total += 1
  count += 1
print(float(total/count))

  #print(val)
#print(type(val))
#print(count)
#print(total)
#print(val)
#print(data[0])










"""
import sys
import numpy as np

data = np.fromfile(f, dtype=np.uint32)
ext = ('.bin')
file_num = 0

for i in range(len(data)) :
  loc = ('/u/tkral/532/unsorted/' + 'unsorted_' + str(file_num) + ext)
  fromfile = open(loc)
  print(data[i])
  file_num += 1
"""






"""
import sys

def value(data) :
  print(data)

data = sys.stdin.read()
array = []
"""
"""
count = 0 
hit = 0
file_num = 0

path_of_directory = '/u/tkral/532/unsorted/'
ext = ('.bin')

#print(loc)
for files in os.listdir(path_of_directory) : 
  loc = (path_of_directory + "unsorted_" + str(file_num) + ext);
  if files.endswith(ext) :
    fd = open(loc)
    print(fd)
    file_num += 1
"""










"""
for files in os.listdir(path_of_directory) :	
  if files.endswith(ext) :
    i = 0
    fd = open(path_of_directory + 'unsorted_' + str(file_num) + ext, 'rb') 
    with open(path_of_directory + 'unsorted_' + str(file_num) + ext, 'rb') as file :
      value = fd.readline()
      #print("line is: ",value[i])
      print(bin(value[i]))
      if (value[i] >= 555555 and value[i] <= 777777) :
        count += 1
      total += 1
      i += 1
    fd.close()      
  file_num += 1

print(float(count/total))
"""

"""
for files in os.listdir(path_of_directory) : 
  loc = (path_of_directory + "unsorted_" + str(file_num) + ext)
  if files.endswith(ext) :
    fd = open(loc, 'rb')
    with open(loc) as file :
      value = fd.readline()    
      print(int.from_bytes(value,"little",signed=False),"\n")
      if (int.from_bytes(value,"big",signed=False) >= 555555 and int.from_bytes(value,"big",signed=False) <= 777777) :
        hit += 1
      count += 1
    file_num += 1

print(count)
print(hit)
"""

