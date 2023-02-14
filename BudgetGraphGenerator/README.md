# Microservice Communication Contract
This microservice is for the generation of pie plots based on the labels and values passed into the program. The way this is achieved is through OS system calls and the writing of files

## Requesting Information
The program expects the information needed to generate the pie chart to be passed in as arguments when the program is called. The format for these arguments is described below
`PyChartGenerator.py <label_1>,<value_1> <label_2>,<value_2> ... <label_n>,<value_n>`

An example of how you would request this information in python is detailed below
```python
import os

response_path = os.popen("python3 PieChartGenerator.py budget,300 budget2,400 budget3,500").read()
```

## Receiving Information
The client is expected to receive information in two ways
1. When the command is run through OS system calls it will print an absolute filepath to the generated pie plot image into the standard pipe
2. The generated pie plot will be saved to the filesystem with a path of `./BudgetPieChart_output.png` the absolute filepath of this is what is returned in the standard output

## Additional Information
Should the user desire to change the text color they can change `PieChartGenerator.py: 9` to a standard color, rgb value, or hex code. Additionally, should the user wish to add a background to the pie chart they can remove `Transparent=True` from `PieChartGenerator.py: 31`. Finally, if it is important that the program is an exe instead of a python script there is a tool called `pyinstaller` that can be installed through `pip` and used to generate an exe. I could not do this ahead of time as I use a linux development environments and exe's depend on the final operating sytems being used 