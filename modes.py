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
        enableAAI = tk.Button(aai_middleframe, text = "Enable AAI", bg='#FFFFFF', fg='#000000', font=("Arial", 12) ) #implement serial enable 
        welcome_message.grid(row = 0, column = 0)
        enableAAI.grid(row = 1, column=0, pady=10)
        backAAI.grid(row = 2, column = 0)
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
        enableAOO = tk.Button(aoo_middleframe, text = "Enable AOO", bg='#FFFFFF', fg='#000000', font=("Arial", 12) ) #implement serial enable 
        welcome_message.grid(row = 0, column = 0)
        enableAOO.grid(row = 1, column=0, pady=10)
        backAOO.grid(row = 2, column = 0)
        aoo_middleframe.pack()
        aoo.mainloop()

    def open_VOO(self):
        voo = tk.Tk()
        voo.geometry("500x400")
        voo.configure(bg='#4863A0')
        voo.title("VOO Page")
        voo_middleframe = tk.Frame(voo, bg = '#4863A0')
        welcome_message = tk.Label(voo_middleframe, text = "VOO", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backVOO = tk.Button(voo_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = voo.destroy)
        enableVOO = tk.Button(voo_middleframe, text = "Enable VOO", bg='#FFFFFF', fg='#000000', font=("Arial", 12) ) #implement serial enable 
        welcome_message.grid(row = 0, column = 0)
        enableVOO.grid(row = 1, column=0, pady=10)
        backVOO.grid(row = 2, column = 0)
        voo_middleframe.pack()
        voo.mainloop()

    def open_VVI(self):
        vvi = tk.Tk()
        vvi.geometry("500x400")
        vvi.configure(bg='#4863A0')
        vvi.title("VVI Page")
        vvi_middleframe = tk.Frame(vvi, bg = '#4863A0')
        welcome_message = tk.Label(vvi_middleframe, text = "VVI", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backVVI = tk.Button(vvi_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = vvi.destroy)
        enableVVI = tk.Button(vvi_middleframe, text = "Enable VVI", bg='#FFFFFF', fg='#000000', font=("Arial", 12) ) #implement serial enable 
        welcome_message.grid(row = 0, column = 0)
        enableVVI.grid(row = 1, column=0, pady=10)
        backVVI.grid(row = 2, column = 0)
        vvi_middleframe.pack()
        vvi.mainloop()

   

    def open_AOOR(self): 
        AOOR = tk.Tk()
        AOOR.geometry("500x400")
        AOOR.configure(bg='#4863A0')
        AOOR.title("AOOR Page")  
        AOOR_middleframe = tk.Frame(AOOR, bg = '#4863A0')
        welcome_message = tk.Label(AOOR_middleframe, text = "AOOR", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backAOOR = tk.Button(AOOR_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = AOOR.destroy)
        welcome_message.grid(row = 0, column = 0)
        backAOOR.grid(row = 1, column = 0)
        AOOR_middleframe.pack()
        AOOR.mainloop()

    def open_VOOR(self): 
        VOOR = tk.Tk() 
        VOOR.geometry("500x400")
        VOOR.configure(bg='#4863A0')
        VOOR.title("VOOR Page") 
        VOOR_middleframe = tk.Frame(VOOR, bg = '#4863A0')
        welcome_message = tk.Label(VOOR_middleframe, text = "VOOR", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backVOOR = tk.Button(VOOR_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = VOOR.destroy)
        welcome_message.grid(row = 0, column = 0)
        backVOOR.grid(row = 1, column = 0)
        VOOR_middleframe.pack()
        VOOR.mainloop() 

    def open_AAIR(self): 
        AAIR = tk.Tk()
        AAIR.geometry("500x400")
        AAIR.configure(bg='#4863A0')
        AAIR.title("AAIR Page")
        AAIR_middleframe = tk.Frame(AAIR, bg = '#4863A0')
        welcome_message = tk.Label(AAIR_middleframe, text = "AAIR", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backAAIR = tk.Button(AAIR_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = AAIR.destroy)
        welcome_message.grid(row = 0, column = 0)
        backAAIR.grid(row = 1, column = 0)
        AAIR_middleframe.pack()
        AAIR.mainloop() 
    
   

    def open_VVIR(self): 
        VVIR = tk.Tk()
        VVIR.geometry("500x400")
        VVIR.configure(bg='#4863A0')
        VVIR.title("VVIR Page") 
        VVIR_middleframe = tk.Frame(VVIR, bg = '#4863A0')
        welcome_message = tk.Label(VVIR_middleframe, text = "VVIR", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        backVVIR = tk.Button(VVIR_middleframe, text = "Back", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = VVIR.destroy)
        welcome_message.grid(row = 0, column = 0)
        backVVIR.grid(row = 1, column = 0)
        VVIR_middleframe.pack()
        VVIR.mainloop()
    
    
