from tkinter import *
import tkinter as tk

class modes():

    def open_AAI(self):
        aai = tk.Tk()
        aai.geometry("500x400")
        aai.configure(bg='#4863A0')
        aai.title("AAI Page")
        aai_middleframe = tk.Frame(aai, bg = '#4863A0')
        welcome_message = tk.Label(aai_middleframe, text = "AAI", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backAAI = tk.Button(aai_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = aai.destroy)
        welcome_message.grid(row = 0, column = 0)
        backAAI.grid(row = 1, column = 0)
        aai_middleframe.pack()
        
        aai.mainloop()

    def open_AOO(self):
        aoo = tk.Tk()
        aoo.geometry("500x400")
        aoo.configure(bg='#4863A0')
        aoo.title("AOO Page")
        aoo_middleframe = tk.Frame(aoo, bg = '#4863A0')
        welcome_message = tk.Label(aoo_middleframe, text = "AOO", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backAOO = tk.Button(aoo_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = aoo.destroy)
        welcome_message.grid(row = 0, column = 0)
        backAOO.grid(row = 1, column = 0)
        aoo_middleframe.pack()
        aoo.mainloop()
    
    def open_VVI(self):
        vvi = tk.Tk()
        vvi.geometry("500x400")
        vvi.configure(bg='#4863A0')
        vvi.title("VVI Page")
        vvi_middleframe = tk.Frame(vvi, bg = '#4863A0')
        welcome_message = tk.Label(vvi_middleframe, text = "VVI", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backVVI = tk.Button(vvi_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = vvi.destroy)
        welcome_message.grid(row = 0, column = 0)
        backVVI.grid(row=1, column=0)
        vvi_middleframe.pack()
        vvi.mainloop()

    def open_VOO(self):
        voo = tk.Tk()
        voo.geometry("500x400")
        voo.configure(bg='#4863A0')
        voo.title("VOO Page")
        voo_middleframe = tk.Frame(voo, bg = '#4863A0')
        welcome_message = tk.Label(voo_middleframe, text = "VOO", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backVOO = tk.Button(voo_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = voo.destroy)
        welcome_message.grid(row = 0, column = 0)
        backVOO.grid(row = 1, column = 0)
        voo_middleframe.pack()
        voo.mainloop()