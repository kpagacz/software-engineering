import matplotlib.pyplot as plt 
import random
from math import log2

counter = 0
def find_in_array(T, el):
    global counter
    for arr_id in range(len(T)):
        counter += 1
        if(T[arr_id] == el):
            return arr_id

    return -1



x = []
y = []
T = []
for _ in range(1, 1001):
    T.append(random.randint(0, 100000))
    counter = 0
    find_in_array(T, random.randint(0, 100000))
    x.append(len(T))
    y.append(counter)

plt.plot(x, y)
plt.show()

def find_min(T):
    global counter
    curr_min = 0
    for el_id in range(1, len(T)):
        counter += 1
        if T[el_id] < T[curr_min]:
            curr_min = el_id

    return curr_min


x = []
y = []
T = []
for _ in range(1, 1001):
    T.append(random.randint(0, 100000))
    counter = 0
    find_in_array(T, random.randint(0, 100000))
    x.append(len(T))
    y.append(counter)

plt.plot(x, y)
plt.show()

def find_min_begin(T, start):
    global counter
    curr_min = start
    for el_id in range(start + 1, len(T)):
        counter += 1
        if T[el_id] < T[curr_min]:
            curr_min = el_id

    return curr_min

def selection_sort(T):
    for id_ in range(len(T)):
        curr_min = find_min_begin(T, id_)
        T[id_], T[curr_min] = T[curr_min], T[id_]

    print(T)

x = []
y = []
T = []
for _ in range(1, 1001):
    T.append(random.randint(0, 100000))
    counter = 0
    selection_sort(T)
    x.append(len(T))
    y.append(counter)

plt.plot(x, y)
plt.show()


def power(a, b):
    global counter
    temp = 1
    while b > 0:
        temp *= a
        b -= 1
        counter += 1
    return temp

x = []
y = []
T = []
for b in range(1, 101):
    counter = 0
    power(2, b)
    x.append(len(T))
    y.append(counter)

plt.plot(x, y)
plt.show()


# a ^ 2k = (a^2)^k
# a ^ (2k + 1) = (a^2)^k * a
# a ^ 0 = 1
def fast_power(a, b):
    global counter
    counter += 1
    if b == 0:
        return 1
    
    if b % 2 == 0:
        return fast_power(a * a, b // 2)
    else:
        return fast_power(a, b - 1) * a


x = []
y = []
y_rek = []
y_log2 = []
y_2log2 = []
for b in range(1, 101):
    x.append(b)
    y_log2.append(log2(b))
    y_2log2.append(2 * log2(b))
    counter = 0
    power(2, b)
    y.append(counter)
    counter = 0
    fast_power(2, b)
    y_rek.append(counter)


plt.plot(x, y, y_rek, y_log2, y_2log2)
plt.show()

def power_it(a, b):
    global counter
    result = 1

    while b > 0:
        if b % 2 == 0:
            a *= a
            b = b / 2
        else:
            result *= a
            b = b - 1
    
    return temp

power_it(3, 4)


