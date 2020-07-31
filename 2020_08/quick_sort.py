# 퀵 정렬의 평균 시간복잡도는 O(N * log N)
#  그러나 최악의 시간복잡도는 O(N^2)

# 최악의 시간복잡도는 애초에 정렬되어 있는 상태일수록
# 즉, 오름차순 또는 내림차순 일수록 O(N^2)에 가까워진다.
# 이를 개선하기 위해서는 여러가지 방법이 있는데
# 그 중 가장 간단한 것은 피봇을 중앙으로 지정하는 것이다.

# 기존에는 피봇을 맨 앞이나 맨 뒤로 잡았는데 
# 이렇게 하게 되면 1부터 100만까지 정렬된 상태일 경우 1또는 100만이 피봇으로 지정이 돼서
# 시간 복잡도가 최악이 될 수 밖에 없다.

# 그런데 피봇을 중앙으로 지정하게 되면
# 어느정도 정렬된 상태일 경우에도 50만 언저리에서 잡히게 되니
# 최악의 시간복잡도를 피할 수 있을 뿐더러 개선된 퀵 정렬을 볼 수 있다.

import csv
import random
import time

MILLION = 1000000

#일반적인 퀵정렬
def quick_sort(q_sort):
  if len(q_sort) < 2:
    return q_sort
    
  pivot = q_sort[0]
  left = list()
  right = list()
    
  for i in range( 1, len(q_sort) ):
    if pivot > q_sort[i]:
      left.append(  q_sort[i] )
    else:
      right.append( q_sort[i] )
  return quick_sort(left)+[pivot]+quick_sort(right)

#개선된 퀵정렬
def my_quick_sort(my_q_sort):
  if len(my_q_sort) < 2:
    return my_q_sort
    
  pivot = my_q_sort[len(my_q_sort) // 2]              # 바뀐 건 여기 하나
  left = list()
  right = list()
    
  for i in range( 1, len(my_q_sort) ):
    if pivot > my_q_sort[i]:
      left.append(  my_q_sort[i] )
    else:
      right.append( my_q_sort[i] )
  return my_quick_sort(left) + [pivot] + my_quick_sort(right)

#file write
f = open('write.csv','w', newline='')
wr = csv.writer(f)
#randnum = random.sample(range(1, MILLION+1), MILLION)   #랜덤 정렬
randnum = range(1, MILLION+1)                            #오름차순 정렬(최악의 경우)
for i in randnum:
  wr.writerow([i])
f.close()

#file read
f = open('write.csv','r')
rdr = csv.reader(f)
rdrlist = []
for line in rdr:
  rdrlist.append(line)
f.close()

#일반적인 퀵정렬 출력
q_sort = rdrlist
start = time.time()
quick_sort(q_sort)
print("quick sort time : ", time.time()-start)           

#개선된 퀵정렬 출력
my_q_sort = rdrlist
start = time.time()
my_quick_sort(my_q_sort)
print("my quick sort time : ", time.time()-start)
