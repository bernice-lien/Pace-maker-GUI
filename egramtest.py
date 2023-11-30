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
            data = pd.read_csv('data1.csv')
            x = data['atr_value']
            y = data['atr_amp']

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
    atr_value = 0
    atr_amp = 0

    fieldnames = ["atr_value", "atr_amp"]

    with open('data1.csv', 'w') as csv_file:
        csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        csv_writer.writeheader()

    while True:
        with open('data1.csv', 'a') as csv_file:
            csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)

            info = {
                "atr_value": atr_value,
                "atr_amp": atr_amp,
            }

            csv_writer.writerow(info)
            print(atr_value, atr_amp)

            atr_value += 1
            atr_amp = atr_amp + random.randint(-6, 8) #will come from serial communication

        time.sleep(0.5)
 #close serial
T = Thread(target = data_gen)
T.setDaemon(True)
T.start()
window()