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
import multiprocessing
from multiprocessing import Process
import serialcomms

def data_gen():
    x_value = 0.5
    vent_amp = 1.648
    atr_amp = 1.648

    fieldnames = ["x_value","vent_amp","atr_amp"]

    with open('data.csv', 'w') as csv_file:
        csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)
        csv_writer.writeheader()

    while True:
        with open('data.csv', 'a') as csv_file:
            csv_writer = csv.DictWriter(csv_file, fieldnames=fieldnames)

            info = {
                "x_value": x_value,
                "vent_amp": vent_amp,
                "atr_amp": atr_amp,
            }

            csv_writer.writerow(info)
            print(x_value, vent_amp, atr_amp)

            x_value += 2
            val = serialcomms.egramreceive()
            vent_amp = val[4]*3.3 #will come from serial communication
            atr_amp = val[3]*3.3

        time.sleep(1)



plt.style.use('fivethirtyeight')

x_vals = []
y_vals = []

index = count()
signal_var = 1
ani = None
def graph1(signal_var):

    global ani  # Declare that we are using the global variable

    # Stop the previous animation if it exists
    if ani:
        ani.event_source.stop()
    def animate(i):
        data = pd.read_csv('data.csv')
        x = data['x_value']
        y1 = data['vent_amp']
        y2 = data['atr_amp']
        
        plt.cla()
        if (signal_var == 1):

            plt.plot(x,y2,color="blue", label = 'Atrial')
        
        elif (signal_var== 2):
            plt.plot(x,y1,color="red", label ='Ventricle')
        
        elif (signal_var == 3):
            plt.plot(x,y2,color="blue", label = 'Atrial')
            plt.plot(x,y1,color="red", label ='Ventricle')
        
        plt.legend(loc="upper left")
        plt.tight_layout()

    ani = FuncAnimation(plt.gcf(), animate, interval=100, cache_frame_data=False)

    plt.tight_layout()
    plt.show()

def egram_pic():
        plt.savefig('plot.png')

#generate data
T = Thread(target = data_gen)
T.setDaemon(True)
T.start()
#graph1()
