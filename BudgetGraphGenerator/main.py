# Import libraries
import numpy as np
import matplotlib.pyplot as plt

labels = ["Food", "Rent", "Car Payment", "Vaccation Savings"]
data = [200, 1500, 1500, 300]

plt.pie(data, labels = labels)
plt.show()