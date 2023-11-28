""" import random
from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from tkinter import *
import tkinter as tk
import csv
import random
import time
from threading import *

class egram():

    def window(self):
        graph_window = Tk()
        graph_window.title("Egram Data")
        graph_window.geometry("400x400")

        plt.style.use('fivethirtyeight')

        x_vals = []
        y_vals = []

        def graph():
            def animate(i):
                data = pd.read_csv('data.csv')
                x = data['x_value']
                y1 = data['total_1']
                y2 = data['total_2']

                plt.cla()

                plt.plot(x, y1, label='Channel 1')
                plt.plot(x, y2, label='Channel 2')

                plt.legend(loc='upper left')
                plt.tight_layout()

            ani = FuncAnimation(plt.gcf(), animate, interval=1000)

            plt.tight_layout()
            plt.show()

        graph_frame = tk.Frame(graph_window, bg='#4863A0')

        button = Button(graph_frame, text="Graph It!", command=graph)
        button.pack(graph_frame)
        graph_window.mainloop()

    def data_gen(self):
        x_value = 0
        total_1 = 1000
        total_2 = 1000

        fieldnames = ["x_value", "total_1", "total_2"]


        with open('data.csv', 'w') as csv_file:
            csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
            csv_writer.writeheader()

        while True:

            with open('data.csv', 'a') as csv_file:
                csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)

                info = {
                    "x_value": x_value,
                    "total_1": total_1,
                    "total_2": total_2
                }

                csv_writer.writerow(info)
                print(x_value, total_1, total_2)

                x_value += 1
                total_1 = total_1 + random.randint(-6, 8)
                total_2 = total_2 + random.randint(-5, 6)

            time.sleep(1)

    T = Thread(target = data_gen)
    #T.setDaemon(True)
    T.start()
    window()

 """

import random
from itertools import count
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from tkinter import *
import csv
import random
import time
from threading import *

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
    amplitude = 1000

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

            x_value += 1
            amplitude = amplitude + random.randint(-6, 8) #will come from serial communication

        time.sleep(1)

T = Thread(target = data_gen)
T.setDaemon(True)
T.start()
window()