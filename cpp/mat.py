# import numpy as np
# import matplotlib.pyplot as plt


# x = np.linspace(0, 10, 100)


# def triangular(x, a, b, c):
#     return np.maximum(0, np.minimum((x - a) / (b - a), (c - x) / (c- b)))


# def trapezoidal(x, a, b, c, d):
#     return np.maximum(0, np.minimum(np.minimum((x - a) / (b - a),1), (d - x) / (d - c)))


# def gaussian(x, mean, sigma):
#     return np.exp(-((x - mean) ** 2) / (2 * sigma ** 2))


# def generalized_bell(x, a, b, c):
#     return 1 / (1 + np.abs((x - c) / a) ** (2 * b))


# def sigmoid(x, a, b):
#     return 1 / (1 + np.exp(-a * (x - b)))


# # Plot the membership functions
# plt.figure(figsize=(12, 8))


# #Triangular
# plt.subplot(231)
# plt.title('Triangular')
# plt.plot(x, triangular(x, 3, 5, 7)) 


# # Trapezoidal
# plt.subplot(232)
# plt.title('Trapezoidal')
# plt.plot(x, trapezoidal(x, 2, 4, 6, 8))


# # Gaussian
# plt.subplot(233)
# plt.title('Gaussian')
# plt.plot(x, gaussian(x, 5, 1))


# # Generalized Bell
# plt.subplot(234)
# plt.title('Generalized Bell')
# plt.plot(x, generalized_bell(x, 2, 1, 5))


# # Sigmoid
# plt.subplot(235)
# plt.title('Sigmoid')
# plt.plot(x, sigmoid(x, 1, 5))
# plt.tight_layout()
# plt.show()


# import numpy as np
# import matplotlib.pyplot as plt


# x = np.linspace(0, 10, 100)


# # Define three fuzzy sets A, B, and C
# A = np.minimum(1, np.maximum(0, (x - 3) / 2))
# B = np.minimum(1, np.maximum(0, (x - 6) / 2))
# C = np.exp(-((x - 5) ** 2) / 4)


# # Perform fuzzy operations: Union, Intersection, and Complement
# union_result = np.maximum(A, B)
# intersection_result = np.minimum(A, B)
# complement_A = 1 - A
# complement_B = 1 - B


# # Plot the fuzzy sets
# plt.figure(figsize=(12, 8))


# # Fuzzy Set A
# plt.subplot(231)
# plt.title('Fuzzy Set A')
# plt.plot(x, A)


# # Fuzzy Set B
# plt.subplot(232)
# plt.title('Fuzzy Set B')
# plt.plot(x, B)


# # Union of A and B
# plt.subplot(233)
# plt.title('Union (A ∪ B)')
# plt.plot(x, union_result)


# # Intersection of A and B
# plt.subplot(234)
# plt.title('Intersection (A ∩ B)')
# plt.plot(x, intersection_result)


# # Complement of A
# plt.subplot(235)
# plt.title('Complement of A (A\')')
# plt.plot(x, complement_A)


# # Complement of B
# plt.subplot(236)
# plt.title('Complement of B (B\')')
# plt.plot(x, complement_B)
# plt.tight_layout()
# plt.show()

import numpy as np
import matplotlib.pyplot as plt


marks = np.linspace(0, 100, 1000)


EX = np.where(marks >= 90, 1, 0)
A = np.maximum(0, np.minimum((marks - 80) / 10, (90 - marks) / 10))
B = np.maximum(0, np.minimum((marks - 70) / 10, (80 - marks) / 10))
C = np.maximum(0, np.minimum((marks - 60) / 10, (70 - marks) / 10))
D = np.maximum(0, np.minimum((marks - 50) / 10, (60 - marks) / 10))
P = np.maximum(0, np.minimum((marks - 35) / 15, (50 - marks) / 15))
F = np.where(marks < 35, 1, 0)


# Plot the membership functions for each grade
plt.figure(figsize=(10, 6))
plt.plot(marks, EX, label='Excellent')
plt.plot(marks, A, label='Good')
plt.plot(marks, B, label='Average')
plt.plot(marks, C, label='Satisfactory')
plt.plot(marks, D, label='Poor')
plt.plot(marks, P, label='Fail')
plt.plot(marks, F, label='Fail')
plt.xlabel('Marks')
plt.ylabel('Membership Degree')
plt.title('Fuzzy Course Evaluation')
plt.legend()
plt.grid(True)
plt.show()
