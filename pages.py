import tkinter as tk
import database
from tkinter import *
from tkinter import messagebox
from database import *
from modes import *
import serial
import egram_test
import serial.tools.list_ports
import time
from fpdf import FPDF
from datetime import datetime

db = database()
mode = modes()
'''
global login_name
global login_id
global login_LRL
global login_URL
global login_MSL
global login_AA
global login_VA
global login_APW
global login_VPW
global login_AS
global login_VS 
global login_VRP
global login_ARP
global login_PVARP 
global login_H
global login_RS 
global login_AT 
global login_RT 
global login_RF 
global login_recT
global login_M
'''
class pages():

    global login_name
    global login_id
    global login_LRL
    global login_URL
    global login_MSL
    global login_AA
    global login_VA
    global login_APW
    global login_VPW
    global login_AS
    global login_VS 
    global login_VRP
    global login_ARP
    global login_PVARP 
    global login_H
    global login_RS 
    global login_AT 
    global login_RT 
    global login_RF 
    global login_recT
    global login_M
    


    def welcome_screen(self):

        def open():

            def reopen():
                window.destroy()
                self.create_acct()
                open()

            def login():

                global login_name
                global login_id
                global login_LRL
                global login_URL
                global login_MSL
                global login_AA
                global login_VA
                global login_APW
                global login_VPW
                global login_AS
                global login_VS 
                global login_VRP
                global login_ARP
                global login_PVARP 
                global login_H
                global login_RS 
                global login_AT 
                global login_RT 
                global login_RF 
                global login_recT
                global login_M

                logins = db.query()
                loginSuccessful = False
        
                for login in logins:
                    if username_entry.get()==login[0] and password_entry.get()==login[1] and username_entry.get() == "admin":

                        self.admin_screen()
                        loginSuccessful = True
                        window.destroy()
                        self.open_profile()
                        open()

                    elif username_entry.get()==login[0] and password_entry.get()==login[1]: #need to pull from database
                        login_name = login_name = login[2] + " " + login[3]
                        login_id = login[23]
                        login_LRL = login[4]
                        login_URL = login[5]
                        login_MSL = login[6]
                        login_AA = login[7]
                        login_VA = login[8]
                        login_APW = login[9]
                        login_VPW = login[10]
                        login_AS = login[11]
                        login_VS  = login[12]
                        login_VRP = login[13]
                        login_ARP = login[14]
                        login_PVARP  = login[15]
                        login_H = login[16]
                        login_RS = login[17]
                        login_AT = login[18]
                        login_RT = login[19]
                        login_RF = login[20]
                        login_recT = login[21]
                        login_M = login[22]


                        '''
                        login_id = login[13]
                        login_LRL = login[4]
                        login_URL = login[5]
                        login_AA = login[6]
                        login_APW = login[7]
                        login_ARP = login[10]
                        login_VA = login[8]
                        login_VPW = login[9]
                        login_VRP = login[11]
                        login_M = login[12]
                        '''
                        loginSuccessful = True
                        window.destroy()
                        self.open_profile()
                        open()
                if (not loginSuccessful):
                    messagebox.showinfo(title="Invalid Login",message="Your login credentials are invalid.") #**need a way to link this to create account

            #make the window
            window = tk.Tk()
            window.title("Login")
            window.geometry('500x400')
            window.configure(bg='#4863A0')
                
            #frame for the widgets--makes it responsive when you change window size
            frame = tk.Frame(bg='#4863A0')

            #make widgets
            login_label = tk.Label(frame, text="Login", bg='#4863A0', fg='#FFFFFF', font=("Arial", 30))
            username_label = tk.Label(frame, text="Username", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
            password_label = tk.Label(frame, text="Password", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
            username_entry = tk.Entry(frame, font=("Arial", 12))
            password_entry = tk.Entry(frame, show="*", font=("Arial", 12))
            login_button = tk.Button(frame, text="Login", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=login)
            new_acct_button = tk.Button(frame, text="Create New Account", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=reopen)

            #place widgets
            login_label.grid(row=0, column=0, columnspan=2, sticky="news", pady=40)
            username_label.grid(row=1, column=0) 
            password_label.grid(row=2, column=0)
            username_entry.grid(row=1, column=1, pady=10) #spacing will affect everything in the same row
            password_entry.grid(row=2, column=1, pady=20) 
            login_button.grid(row=3, column=0, columnspan=2)
            new_acct_button.grid(row=4, column=0, columnspan=2, pady=10)

            frame.pack() #pack is responsive by default

            window.mainloop() #infinite loop that executes the app (stops when window is closed)

    def open_profile(self):

        global login_name
        global login_id
        global login_LRL
        global login_URL
        global login_MSL
        global login_AA
        global login_VA
        global login_APW
        global login_VPW
        global login_AS
        global login_VS 
        global login_VRP
        global login_ARP
        global login_PVARP 
        global login_H
        global login_RS 
        global login_AT 
        global login_RT 
        global login_RF 
        global login_recT
        global login_M

        page = pages()
        profile = tk.Tk()
        profile.geometry("600x750")
        profile.configure(bg='#4863A0')
        profile.title("Profile Page")

        profile_frame = tk.Frame(profile, bg='#4863A0')

        def reopen():
            profile.destroy()
            db.edit(str(login_id))
            page.open_profile()


        def temp_report():
            pdf = FPDF()

            # Add a page
            pdf.add_page()

            # set style and size of font 
            pdf.set_font("Arial", size = 10)

            # create a cell
            pdf.cell(200, 5, txt = "Temporary Report", 
                    ln = 1, align = 'L')

            # add another cell
            pdf.cell(200, 5, txt = "Patient: " + login_name, ln = 2, align = 'L')
            pdf.cell(200, 5, txt = "Institution: " + "McMaster University" ,ln = 2, align = 'L')
            pdf.cell(200, 5, txt = "Device Model: " + "12.0   Serial Number: 00395012" ,ln = 2, align = 'L')
            pdf.cell(200, 5, txt = "Software Version: " + "6.1v   DCM Serial Number: 30194892" ,ln = 2, align = 'L')
            now = datetime.now()
 
            # dd/mm/YY H:M:S
            dt_string = now.strftime("%d/%m/%Y %H:%M:%S")
            pdf.cell(200, 5, txt = "Date and Time: " + dt_string ,ln = 2, align = 'L')

            pdf.cell(200, 30, txt = "" ,ln = 2, align = 'C')

            pdf.cell(200, 10,  txt = "LRL: " + str(login_LRL) + "  URL: " + str(login_URL) + "  Max Sensor Limit: " + str(login_MSL), ln = 2, align = 'C')
            pdf.cell(200, 10,  txt = "Atrial Amplitude: " + str(login_AA) + "  Ventricular Amplitude: " + str(login_VA)  + "  Atrial Pulse Width: " + str(login_APW) + "  Ventricular Pulse Width: " + str(login_VPW), ln = 2, align = 'C')
            pdf.cell(200, 10,  txt = "Atrial Sensitivity: " + str(login_AS) + "  Ventricular Sensitivity: " + str(login_VS)  + "  ARP: " + str(login_ARP) + "  VRP: " + str(login_VRP)+ "  PVARP: " + str(login_PVARP), ln = 2, align = 'C')
            pdf.cell(200, 10,  txt = "Hysteresis: " + str(login_H) + "  Rate Smoothing: " + str(login_RS)  + "  Activity Threshold: " + str(login_AT), ln = 2, align = 'C')
            pdf.cell(200, 10,  txt = "Reaction Time: " + str(login_RT) + "  Response Factor: " + str(login_RF)  + "  Recovery Time: " + str(login_recT) + "  Pacing Mode: " + str(login_M), ln = 2, align = 'C')

            # save the pdf with name .pdf
            
            pdf.output(login_name + " temporary report.pdf")  
        
        def egram_win():
            window_e = tk.Tk()
            window_e.title("Login")
            window_e.geometry('200x100')
            window_e.configure(bg='#4863A0')
            mode_message = tk.Label(window_e, text="Red Line: Ventricular Signal\nBlue Line: Atrial Signal", bg='#4863A0', fg='#FFFFFF', font=("Arial",8))
            AS_b = tk.Button(window_e, text = "Atrial Signal", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_AOO)
            VS_b = tk.Button(window_e, text = "Ventricular Signal", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_AOO)
            BS_b = tk.Button(window_e, text = "Both Signals", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_AOO)
            mode_message.grid(row=0, column=0)
            egram_test.graph1()
        
        def open_about():

            about_window = tk.Tk()
            about_window.title("About")
            about_window.geometry("300x400")
            about_window.configure(bg='#4863A0')
            about_window.title("About Page")

            about_frame = tk.Frame(about_window, bg="#4863A0")
            about_frame.pack()

            #generate messages
            time = datetime.now()
            modelNumberMessage = "Model Number: 12.0"
            softwareNumberMessage = "Software Version: 6.1v"
            serialNumberMessage = "DCM Serial Number: 30194892"
            institutionMessage = "Institution: McMaster University"
            dateTimeString = "Date/Time: " + time.strftime("%d/%m/%Y %H:%M")

            #generate labels
            modelNumber_title = tk.Label(about_frame, text= modelNumberMessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
            softwareNumber_title = tk.Label(about_frame, text=softwareNumberMessage, bg='#4863A0', fg='#FFFFFF', font=("Arial",12))
            serialNumber_title = tk.Label(about_frame, text=serialNumberMessage, bg='#4863A0', fg='#FFFFFF', font=("Arial",12))
            institution_title = tk.Label(about_frame, text=institutionMessage, bg='#4863A0', fg='#FFFFFF', font=("Arial",12))
            dateTime_title = tk.Label(about_frame, text=dateTimeString, bg='#4863A0', fg='#FFFFFF', font=("Arial",12))

            #place labels

            modelNumber_title.grid(row=0,column=0)
            softwareNumber_title.grid(row=1,column=0)
            serialNumber_title.grid(row=2,column=0)
            institution_title.grid(row=3,column=0)
            dateTime_title.grid(row=4,column=0)
            




            
        message = "Welcome," + " " + login_name #matches username entered to name stored in database
        LRLmessage = "Lower Rate Limit: " + str(login_LRL)
        URLmessage = "Upper Rate Limit: " + str(login_URL)
        MSLmessage = "Maximum Sensor Limit: " + str(login_MSL)
        AAmessage = "Atrial amplitude: " + str(login_AA)
        VAmessage = "Ventricular Amplitude: " + str(login_VA)
        APWmessage = "Atrial Pulse Width: " + str(login_APW)
        VPWmessage = "Ventricular Pulse Width: " + str(login_VPW)
        ASmessage = "Atrial Sensitivity: " + str(login_AS)
        VSmessage = "Ventricular Sensitivity: " + str(login_VS)
        ARPmessage = "ARP: " + str(login_ARP)
        VRPmessage = "VRP: " + str(login_VRP)
        PVARPmessage = "PVARP: " + str(login_PVARP)
        Hmessage = "Hysteresis: " + str(login_H)
        RSmessage = "Rate Smoothing: " + str(login_RS)
        ATmessage = "Activity Threshold: " + str(login_AT)
        RTmessage = "Reaction Time: " + str(login_RT)
        RFmessge = "Response Factor: " + str(login_RF)
        recTmessage ="Recovery Time: " + str(login_recT)
        Mmessage = "Pacing Mode: " + str(login_M)

        initial = 0
        def connect_check():
            ports = serial.tools.list_ports.comports()
            global com
            for port, desc, hwid in sorted(ports):
                print("{}: {} [{}]".format(port,desc,hwid))
                if "JLink" in desc:
                    com = port
                    global initial
                    initial = time.time_ns()
                    return True
                else:
                    com = None
            return False

        if connect_check() == True:
            messagebox.showinfo(title="Connection Success",message="Pacemaker connected.")
            con_message = "Connection Status: Pacemaker connected\nPacemaker version: 1\nDate of implant: 01/01/2023"
        elif connect_check() == False:
            messagebox.showinfo(title="Connection Error",message="Pacemaker is not connected.")
            con_message = "Connection Status: Pacemaker not connected."


        #create info for corner of screen
        connection_message = tk.Label(profile, text=con_message, bg='#4863A0', fg='#FFFFFF', font=("Arial",8))
        welcome_message = tk.Label(profile_frame, text = message, bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        tracing_message = tk.Label(profile_frame, text = "Tracing Methods", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        sign_out = tk.Button(profile_frame, text = "Sign Out", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command = profile.destroy)
        '''
        aoo = tk.Button(profile_frame, text = "AOO", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_AOO)
        voo = tk.Button(profile_frame, text = "VOO", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_VOO)
        aai = tk.Button(profile_frame, text = "AAI", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_AAI)
        vvi = tk.Button(profile_frame, text = "VVI", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_VVI)
        aoor = tk.Button(profile_frame, text = "AOOR", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_AOOR)
        voor = tk.Button (profile_frame, text = "VOOR", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_VOOR)
        aair = tk.Button (profile_frame, text = "AAIR", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_AAIR)
        vvir = tk.Button (profile_frame, text = "VVIR", bg='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_VVIR)
        dddr = tk.Button (profile_frame, text = "DDDR", bg ='#FFFFFF', fg='#000000', font=("Arial", 12), command = mode.open_DDDR)
        '''

        profile_edit = tk.Button(profile_frame, text = "Edit Profile", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command = reopen)
        temp_reportb = tk.Button(profile_frame, text = "Reports", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command = temp_report)
        egram_b = tk.Button(profile_frame, text = "Egram", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command = egram_win) 
        about_b = tk.Button(profile_frame, text = "About", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command = open_about) 

        #pacing modes
        LRLmessage_title = tk.Label(profile_frame, text= LRLmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        URLmessage_title = tk.Label(profile_frame, text= URLmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        MSLmessage_title = tk.Label(profile_frame, text= MSLmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        AAmessage_title = tk.Label(profile_frame, text= AAmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        VAmessage_title = tk.Label(profile_frame, text= VAmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        APWmessage_title = tk.Label(profile_frame, text= APWmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        VPWmessage_title = tk.Label(profile_frame, text= VPWmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        ASmessage_title = tk.Label(profile_frame, text= ASmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        VSmessage_title = tk.Label(profile_frame, text= VSmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        ARPmessage_title = tk.Label(profile_frame, text= ARPmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        VRPmessage_title = tk.Label(profile_frame, text= VRPmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        PVARPmessage_title = tk.Label(profile_frame, text= PVARPmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        Hmessage_title = tk.Label(profile_frame, text= Hmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        RSmessage_title = tk.Label(profile_frame, text= RSmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        ATmessage_title = tk.Label(profile_frame, text= ATmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        RTmessage_title = tk.Label(profile_frame, text= RTmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        RFmessge_title = tk.Label(profile_frame, text= RFmessge, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        recTmessage_title = tk.Label(profile_frame, text= recTmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        Mmessage_title = tk.Label(profile_frame, text= Mmessage, bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
       
        #title alignment
        LRLmessage_title.grid(row=1,column=0)
        URLmessage_title.grid(row=2,column=0)
        MSLmessage_title.grid(row=3,column=0)
        AAmessage_title.grid(row=4,column=0)
        VAmessage_title.grid(row=5,column=0)
        APWmessage_title.grid(row=6,column=0)
        VPWmessage_title.grid(row=7,column=0)
        ASmessage_title.grid(row=8,column=0)
        VSmessage_title.grid(row=9,column=0)
        ARPmessage_title.grid(row=10,column=0, pady=5)
        VRPmessage_title.grid(row=11,column=0)
        PVARPmessage_title.grid(row=12,column=0, pady=5)
        Hmessage_title.grid(row=13,column=0)
        RSmessage_title.grid(row=14,column=0, pady=5)
        ATmessage_title.grid(row=15,column=0)
        RTmessage_title.grid(row=16,column=0, pady=5)
        RFmessge_title.grid(row=17,column=0)
        recTmessage_title.grid(row=18,column=0, pady=5)
        Mmessage_title.grid(row=19,column=0)

        connection_message.place(rely=1.0, relx=1.0, x=0, y=0, anchor=tk.SE)
        welcome_message.grid(row=0, column=0, columnspan=6, sticky="news", pady = 10)
        
        tracing_message.grid(row=1, column=2, padx=25)
        
        
        egram_b.grid(row=2, column=2)
        temp_reportb.grid(row=4, column=2)
        profile_edit.grid(row=6, column = 2)
        about_b.grid(row=8,column=2)
        sign_out.grid(row=10, column=2)
        '''
        aoo.grid(row=2, column=2)
        voo.grid(row=3, column=2)
        aai.grid(row=4, column=2)
        vvi.grid(row=5, column=2)
        aoor.grid(row=6, column=2) 
        voor.grid(row=7, column=2) 
        aair.grid(row=8, column=2) 
        vvir.grid(row=9, column=2) 
        dddr.grid(row=10, column=2) 
        '''

        profile_frame.pack()
        
        profile.mainloop()

    def admin_screen(self):
        admin_window = tk.Tk()
        admin_window.title("Admin Settings")
        admin_window.geometry('500x600')
        admin_window.configure(bg='#4863A0')
        
        #get admin id number
        records = db.query()
        for record in records:
            if(record[0] == "admin"):
                admin_id = record[13]
        
        #print records
        def show_users():
            print_records = ''
            records = db.query()
            for record in records:
                if record[0] == "admin":
                    pass
                else:
                    print_records+= str(record[0])+", "+str(record[13])+"\n"

            query_label = Label(admin_frame, text = print_records, bg='#4863A0', fg='#FFFFFF')
            query_label.grid(row=4, column=0, columnspan = 2)

        #frame for the widgets--makes it responsive when you change window size
        admin_frame = tk.Frame(admin_window, bg='#4863A0')

        #make widgets
        delete_user_entry = tk.Entry(admin_frame, font=("Arial", 12))
        delete_user_label = tk.Label(admin_frame, text="Enter ID", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        delete_user_button = tk.Button(admin_frame, text="Delete User", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=lambda: db.delete(delete_user_entry.get()))
        admin_label = tk.Label(admin_frame, text="Admin Settings", bg='#4863A0', fg='#FFFFFF', font=("Arial", 30))
        show_users_button = tk.Button(admin_frame, text="Show Usernames/IDs", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=show_users)
        password_entry = tk.Entry(admin_frame, font=("Arial",12))
        password_label = tk.Label(admin_frame, text="Admin Password", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        change_password_button = tk.Button(admin_frame, text="Change Password", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command= lambda: db.changePassword(admin_id,password_entry.get()))
        signout_button = tk.Button(admin_frame, text="Sign Out", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=admin_window.destroy)

        #place widgets
        admin_label.grid(row=0, column=0, columnspan=2, sticky="news", pady=30)
        delete_user_entry.grid(row=1, column=1, padx=10)
        delete_user_label.grid(row=1, column=0)
        delete_user_button.grid(row=2, column=0, columnspan=2, pady=10)
        show_users_button.grid(row=3, column=0, columnspan=2, pady=10)
        password_entry.grid(row=7, column=1, padx=10)
        password_label.grid(row=7,column=0)
        change_password_button.grid(row=8, column=0, columnspan=2, pady=10)
        signout_button.grid(row=9, column=0, columnspan=2)

        records = db.query()
        for record in records:
            if record[0] == "admin":
                current_password = record[1]
                password_entry.insert(0, current_password)

        admin_frame.pack() #pack is responsive by default

        admin_window.mainloop() #infinite loop that executes the app (stops when window is closed)

    def start(self):

        page = pages()

        def reopen():
            window.destroy()
            page.create_acct()
            page.welcome_screen()

        def login():
            logins = db.query()
            loginSuccessful = False
            
            global login_name
            global login_id
            global login_LRL
            global login_URL
            global login_MSL
            global login_AA
            global login_VA
            global login_APW
            global login_VPW
            global login_AS
            global login_VS 
            global login_VRP
            global login_ARP
            global login_PVARP 
            global login_H
            global login_RS 
            global login_AT 
            global login_RT 
            global login_RF 
            global login_recT
            global login_M
            
            for login in logins:
                if username_entry.get()==login[0] and password_entry.get()==login[1] and username_entry.get() == "admin":

                    page.admin_screen()
                    loginSuccessful = True
                    window.destroy()
                    page.open_profile()
                    page.start()

                elif username_entry.get()==login[0] and password_entry.get()==login[1]: #need to pull from database
                    login_name = login_name = login[2] + " " + login[3]
                    login_id = login[23]
                    login_LRL = login[4]
                    login_URL = login[5]
                    login_MSL = login[6]
                    login_AA = login[7]
                    login_VA = login[8]
                    login_APW = login[9]
                    login_VPW = login[10]
                    login_AS = login[11]
                    login_VS  = login[12]
                    login_VRP = login[13]
                    login_ARP = login[14]
                    login_PVARP  = login[15]
                    login_H = login[16]
                    login_RS = login[17]
                    login_AT = login[18]
                    login_RT = login[19]
                    login_RF = login[20]
                    login_recT = login[21]
                    login_M = login[22]

                    loginSuccessful = True
                    window.destroy()
                    page.open_profile()
                    page.start()
            if (not loginSuccessful):
                messagebox.showinfo(title="Invalid Login",message="Your login credentials are invalid.") #**need a way to link this to create account

        #make the window
        window = tk.Tk()
        window.title("Login")
        window.geometry('500x400')
        window.configure(bg='#4863A0')
            
        #frame for the widgets--makes it responsive when you change window size
        frame = tk.Frame(bg='#4863A0')

        #make widgets
        login_label = tk.Label(frame, text="Login", bg='#4863A0', fg='#FFFFFF', font=("Arial", 30))
        username_label = tk.Label(frame, text="Username", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        password_label = tk.Label(frame, text="Password", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        username_entry = tk.Entry(frame, font=("Arial", 12))
        password_entry = tk.Entry(frame, show="*", font=("Arial", 12))
        login_button = tk.Button(frame, text="Login", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=login)
        new_acct_button = tk.Button(frame, text="Create New Account", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=reopen)

        #place widgets
        login_label.grid(row=0, column=0, columnspan=2, sticky="news", pady=40)
        username_label.grid(row=1, column=0) 
        password_label.grid(row=2, column=0)
        username_entry.grid(row=1, column=1, pady=10) #spacing will affect everything in the same row
        password_entry.grid(row=2, column=1, pady=20) 
        login_button.grid(row=3, column=0, columnspan=2)
        new_acct_button.grid(row=4, column=0, columnspan=2, pady=10)

        frame.pack() #pack is responsive by default

        window.mainloop() #infinite loop that executes the app (stops when window is closed)

         #creates a new user and adds their information to database

    def create_acct(self):
        page = pages()

        #handles creating a new user after the "create account" is pressed
        def new_user():
            if not(firstname_entry.get()):
                messagebox.showinfo(title="Account Creation Error",message="Enter a valid first name.")
            elif not(lastname_entry.get()):
                messagebox.showinfo(title="Account Creation Error",message="Enter a valid last name.")
            elif not(new_username_entry.get()):
                messagebox.showinfo(title="Account Creation Error",message="Enter a valid username.")
            elif len(new_username_entry.get()) < 4:
                messagebox.showinfo(title="Account Creation Error",message="Username must be at least 4 characters.")
            elif not(new_password_entry.get()):
                messagebox.showinfo(title="Password Creation Error",message="Enter a valid password.")
            elif new_password_entry.get()!=confirm_password_entry.get():
                messagebox.showinfo(title="Password Creation Error",message="Password entries do not match.")
            elif len(new_password_entry.get()) < 8:
                messagebox.showinfo(title="Password Creation Error",message="Password must be at least 8 characters")
            else:
                #check usernames
                usernameExists = False
                logins = db.query()
                count = 0
                for login in logins:
                    count += 1
                    if (new_username_entry.get() == login[0]):
                        usernameExists = True
                        messagebox.showinfo(title="Username Creation Error",message="Username already exists.")
                if usernameExists:
                    messagebox.showinfo(title="Username Creation Error",message="Username already exists.")
                elif count > 10:
                    messagebox.showinfo(title="Account Creation Error",message="Too many existing users.")
                
                else:
                    db.submit(new_username_entry.get(),new_password_entry.get(),firstname_entry.get(),lastname_entry.get())
                    messagebox.showinfo(title="Account Creation Success",message="Account creation successful.")
                    create_window.destroy()
                    page.start()
            
        #window
        create_window = tk.Tk()
        create_window.title("Create Account")
        create_window.geometry('600x450')
        create_window.configure(bg='#4863A0')

        #frame to hold the widgets
        create_frame = tk.Frame(create_window, bg='#4863A0')

        #create widgets
        create_acct_label = tk.Label(create_frame, text="Create Account", bg='#4863A0', fg='#FFFFFF', font=("Arial", 30))
        firstname_label = tk.Label(create_frame, text="First Name", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        lastname_label = tk.Label(create_frame, text="Last Name", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        new_username_label = tk.Label(create_frame, text="Username", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        new_password_label = tk.Label(create_frame, text="Password", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        confirm_password_label = tk.Label(create_frame, text="Confirm Password", bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))
        firstname_entry = tk.Entry(create_frame, font=("Arial", 12))
        lastname_entry = tk.Entry(create_frame, font=("Arial", 12))
        new_username_entry = tk.Entry(create_frame, font=("Arial", 12))
        new_password_entry = tk.Entry(create_frame, show="*", font=("Arial", 12))
        confirm_password_entry = tk.Entry(create_frame, show="*", font=("Arial", 12))
        create_acct_button = tk.Button(create_frame, text="Create Account", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=new_user)
        back_button = tk.Button(create_frame, text="Back", bg='#FFFFFF', fg='#000000', font=("Arial", 10), command=create_window.destroy)

        #place widgets
        create_acct_label.grid(row=0, column=0, columnspan=2, sticky="news", pady=30)
        firstname_label.grid(row=1, column=0)
        lastname_label.grid(row=2, column=0)
        new_username_label.grid(row=3, column=0) 
        new_password_label.grid(row=4, column=0)
        confirm_password_label.grid(row=5, column=0)
        firstname_entry.grid(row=1,column=1, pady=10)
        lastname_entry.grid(row=2, column=1, pady=10)
        new_username_entry.grid(row=3, column=1, pady=10) #spacing will affect everything in the same row
        new_password_entry.grid(row=4, column=1, pady=10) 
        confirm_password_entry.grid(row=5, column=1, pady=10, padx=5)
        create_acct_button.grid(row=6, column=0, columnspan=2, pady=10)
        back_button.grid(row=7,column=0, columnspan=2)

        create_frame.pack() #pack is responsive by default

        create_window.mainloop() #infinite loop that executes the app

    def about_win(self):
            about_window = tk.Tk()
            about_window.title("About")
            about_window.geometry("300x400")
            about_window.configure(bg='#4863A0')

            about_frame = tk.Frame(about_window, bg='#4863A0')

            #generate messages
            time = datetime.now()
            modelNumberMessage = "Model Number: 12.0"
            softwareNumberMessage = "Software Version: 6.1v"
            serialNumberMessage = "DCM Serial Number: 30194892"
            institutionMessage = "Institution: McMaster University"
            dateTimeString = "Date/Time: " + time.strftime("%d/%m/%Y %H:%M")

            #generate labels
            modelNumber_title = tk.Label(about_frame, text=modelNumberMessage, bg='#4863A0', fg='#FFFFFF', font=("Arial",8))
            softwareNumber_title = tk.Label(about_frame, text=softwareNumberMessage, bg='#4863A0', fg='#FFFFFF', font=("Arial",8))
            serialNumber_title = tk.Label(about_frame, text=serialNumberMessage, bg='#4863A0', fg='#FFFFFF', font=("Arial",8))
            institution_title = tk.Label(about_frame, text=institutionMessage, bg='#4863A0', fg='#FFFFFF', font=("Arial",8))
            dateTime_title = tk.Label(about_frame, text=dateTimeString, bg='#4863A0', fg='#FFFFFF', font=("Arial",8))

            #place labels
            '''
            modelNumber_title.pack()
            softwareNumber_title.pack()
            serialNumber_title.pack()
            institution_title.pack()
            dateTime_title.pack()

            '''
            modelNumber_title.grid(row=0,column=0)
            softwareNumber_title.grid(row=1,column=0)
            serialNumber_title.grid(row=2,column=0)
            institution_title.grid(row=3,column=0)
            dateTime_title.grid(row=4,column=0)
            