from bokeh.plotting import figure, output_file, show
import numpy as np

output_file("line.html")

x = np.linspace(0, 4 * np.pi, 100)
y = np.sin(x)

p = figure(title="Sine Wave Example", x_axis_label='x', y_axis_label='sin(x)')
p.line(x, y, legend_label="sine", line_width=2)

show(p)



