import numpy as np

v1=[1,-2]
v2=[2,3]
v3=[1,-1]

c=1

ipt = [v1,v2,v3]

print("Default weight vector:") w1=[1,-1]
print(w1) w2=[1,-1]


def sgn(x):
    if x>=0:
        return 1 
    else:
        return -1

def sgm(x):
    return (2/ (1+ np.exp(-x*c))-1)
    

for i in range(3): 
    input = ipt[i]
    x = sum(input[j]*w1[j] for j in range(2))
    disc=sgn(x)
    cont=sgm(x)

for j in range(2):
    w1[j] = w1[j] + c*input[j]*disc 
    w2[j] = w2[j] + c*input[j]*cont
print("Trained vector for Discrete Bipolar activation func is:") 
print(w1)
print("Trained vector for continour Bipolar activation func is:") 
print(w2)