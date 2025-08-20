list1 = ["apple","banana","cherry","mango","guava","cherry"]
print(list1[0:2])
print(list1[2:])
print(list1[-1])
print(list1[-3:-1])
print(list1[0:5:2])
print(list1[-1:-2])
print(list1[-1:-2:-1])

list2 = ["apple","banana","cherry","mango","orange"]
print(list2+["tomato",50])
print(list2*3)
print(list2)
x = list1.index("cherry")
print(x)
list1.pop()
print(list1)

A = [
    [1,4,5,12],
    [-5,8,9,0],
    [-6,7,11,19]
]

print(A[0][-1])

thisdict = {
    "brand":"Ford",
    "model":"Mustang",
    "year":1964
}
print(thisdict.items())
print(thisdict.keys())
print(thisdict.values())

for x,y in thisdict.items():
    print(x,y)