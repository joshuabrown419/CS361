# Import libraries
import matplotlib.pyplot as plt
import sys
import os

# Change this variable to change the color of text
# Can be basic color name or hex string in form of #0f0f0f
# Can also be RGB values in form of (0.1, 0.2, 0.5)
TEXT_COLOR = 'white'

# Define array for labels
labels = []
# Define array for values
values = []
# Define array pieces will be split into
arg_pieces = []
# The first arg in the python argv array is the python script name
# so we loop through all args after the first
for arg_str in sys.argv[1:]:
    arg_pieces = arg_str.split(",")
    # Add label to array
    labels.append(arg_pieces[0])
    # Add value associated with label to values
    values.append(int(arg_pieces[1]))

# Set text color
plt.rcParams['text.color'] = TEXT_COLOR
# Generate pie chart
plt.pie(values, labels=labels)
# Save pie chart to file with transparent background
plt.savefig("BudgetPieChart_output.png", transparent=True)

print(os.path.abspath("./BudgetPieChart_output.png"), end="")
