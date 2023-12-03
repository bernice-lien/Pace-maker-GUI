from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from tkinter import *
import csv
import time
from threading import *
import serialcomms

def window():
    root = Tk()
    root.title("hello")
    root.geometry("400x200")

    plt.style.use('fivethirtyeight')

    x_vals = []
    y_vals = []

    index = count()

    def graph():

        def animate(i):
            data = pd.read_csv('data.csv')
            x = data['x_value']
            y = data['amplitude']

            plt.cla()
            plt.plot(x, y, label='Amplitude')
            plt.tight_layout()

        ani = FuncAnimation(plt.gcf(), animate, interval=100, cache_frame_data=False)

        plt.tight_layout()
        plt.show()

    button = Button(root, text="Graph It!", command=graph)
    button.pack()
    root.mainloop()

def data_gen():
    x_value = 0
    amplitude = 0
    pulse = 0

    fieldnames = ["x_value", "amplitude"]

    with open('data.csv', 'w') as csv_file:
        csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        csv_writer.writeheader()

    while True:
        with open('data.csv', 'a') as csv_file:
            csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)

            info = {
                "x_value": x_value,
                "amplitude": amplitude,
            }

            csv_writer.writerow(info)
            print(x_value, amplitude)

            x_value += 0.1
            val = serialcomms.egramreceive()
        
            amplitude = val[3]*3.3

            if (pulse == 10):
                pulse = 0
            else:
                pulse += 1


        time.sleep(0.1)

T = Thread(target = data_gen)
T.setDaemon(True)
T.start()
window()