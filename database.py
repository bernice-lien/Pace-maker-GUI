from tkinter import *
#from pages import *
import pages
import sqlite3
from tkinter import messagebox
import tkinter as tk
import serial
from serialcomms import *

'''
0 username 
1 password
2 firstName 
3 lastName 
4 lowerRateLimit 
5 upperRateLimit 
6 maxSensLimit 
7 atrialAmplitude 
8 ventricularAmplitude 
9 atrialPulseWidth 
10 ventricularPulseWidth 
11 atrialSens 
12 ventricularSens 
13 VRP 
14 ARP 
15 PVARP 
16 hysteresis 
17 rateSmoothing 
18 activityThreshold 
19 reactionTime 
20 responseFactor 
21 recoveryTime
22 Mode 
23 ID

#create database
conn = sqlite3.connect('login_list.db')

# Create cursor
c = conn.cursor()

c.execute("""CREATE TABLE login_info(
            username text, 
            password text, 
            firstName text, 
            lastName text, 
            lowerRateLimit integer,
            upperRateLimit integer,
            maxSensLimit integer,
            atrialAmplitude real,
            ventricularAmplitude real,
            atrialPulseWidth integer,
            ventricularPulseWidth integer,
            atrialSens real,
            ventricularSens real,
            VRP integer,
            ARP integer,
            PVARP integer,
            hysteresis integer,
            rateSmoothing integer,
            activityThreshold text,
            reactionTime integer,
            responseFactor integer,
            recoveryTime integer,
            Mode integer
          )""")
#close connection
conn.commit()
conn.close()
'''
class database():

    def changePassword(self,account_id, newPassword):

        #open connection
        conn = sqlite3.connect('login_list.db')
        c = conn.cursor()

        accounts = self.query()

        for account in accounts:
            if (account[23] == account_id):

                username = account[0]
                password = newPassword
                firstName = account[2] 
                lastName = account[3]
                lowerRateLimit = account[4]
                upperRateLimit = account[5]
                maxSensLimit = account[6]
                atrialAmplitude = account[7]
                ventricularAmplitude = account[8]
                atrialPulseWidth = account[9]
                ventricularPulseWidth = account[10]
                atrialSens = account[11]
                ventricularSens = account[12]
                VRP_ = account[13]
                ARP_ = account[14]
                PVARP_ = account[15]
                hysteresis = account[16]
                rateSmoothing = account[17]
                activityThreshold = account[18]
                reactionTime = account[19]
                responseFactor = account[20]
                recoveryTime = account[21]
                mode = account[22]

                '''
                username = account[0]
                password = newPassword
                firstName = account[2]
                lastName = account[3]
                lowerRateLimit = account[4]
                upperRateLimit = account[5]
                atrialAmplitude = account[6]
                atrialPulseWidth = account[7]8
                ventricularAmplitude = account[8]
                ventricularPulseWidth = account[9]
                VRP_ = account[10]
                ARP_ = account[11]
                mode = account[12]
                '''
        c.execute("""UPDATE login_info SET
                    username=:username,
                    password=:password,
                    firstName=:firstName,
                    lastName=:lastName,
                    lowerRateLimit=:lowerRateLimit,
                    upperRateLimit=:upperRateLimit,
                    maxSensLimit=:maxSensLimit,
                    atrialAmplitude=:atrialAmplitude,
                    ventricularAmplitude=:ventricularAmplitude,
                    atrialPulseWidth=:atrialPulseWidth,
                    ventricularPulseWidth=:ventricularPulseWidth,
                    atrialSens=:atrialSens,
                    ventricularSens=:ventricularSens,
                    VRP=:VRP,
                    ARP=:ARP,
                    PVARP=:PVARP,
                    hysteresis=:hysteresis,
                    rateSmoothing=:rateSmoothing,
                    activityThreshold=:activityThreshold,
                    reactionTime=:reactionTime,
                    responseFactor=:responseFactor,
                    recoveryTime=:recoveryTime,
                    mode=:mode

                    WHERE oid = :oid""",

                {   
                    'username':username,
                    'password':password,
                    'firstName':firstName,
                    'lastName':lastName,
                    'lowerRateLimit':lowerRateLimit,
                    'upperRateLimit':upperRateLimit,
                    'maxSensLimit':maxSensLimit,
                    'atrialAmplitude':atrialAmplitude,
                    'ventricularAmplitude':ventricularAmplitude,
                    'atrialPulseWidth':atrialPulseWidth,
                    'ventricularPulseWidth':ventricularPulseWidth,
                    'atrialSens':atrialSens,
                    'ventricularSens':ventricularSens,
                    'VRP':VRP_,
                    'ARP':ARP_,
                    'PVARP':PVARP_,
                    'hysteresis':hysteresis,
                    'rateSmoothing':rateSmoothing,
                    'activityThreshold':activityThreshold, 
                    'reactionTime':reactionTime,
                    'responseFactor':responseFactor,
                    'recoveryTime':recoveryTime,
                    'mode':mode,
                    'oid':account_id

            })
        #close connection
        conn.commit()
        conn.close()


    def update(self,record_id):
        #open connection
        conn = sqlite3.connect('login_list.db')
        c = conn.cursor()

        flag = True

        #name info
        if not(username_edit.get()):
            messagebox.showinfo(title="Invalid Username",message="Enter a valid username.")
        if len(username_edit.get()) < 4:
            messagebox.showinfo(title="Invalid Username",message="Username must be at least 4 characters.")
        if not(password_edit.get()):
            messagebox.showinfo(title="Invalid Password",message="Enter a valid password.")
        if len(password_edit.get()) < 8:
            messagebox.showinfo(title="Invalid Password",message="Password must be at least 8 characters.")
        if not(firstName_edit.get()):
            messagebox.showinfo(title="Invalid Name",message="Enter a valid first name.")
        if not(lastName_edit.get()):
            messagebox.showinfo(title="Invalid Name",message="Enter a valid last name.")

        #lower rate limit
        if not(lowerRateLimit_edit.get().isdigit()): #make sure input is whole and non-negative
            flag = False
            messagebox.showinfo(title="Invalid Lower Rate Limit",message="Lower rate limit must be a non-negative whole number.")
        if (int(lowerRateLimit_edit.get()) < 30) or int(float(lowerRateLimit_edit.get())) > 175: #check if lower rate limit is within range
            flag = False
            messagebox.showinfo(title="Invalid Lower Rate Limit",message="Lower rate limit must be between 30-175ppm.")
        if 30 <= int(lowerRateLimit_edit.get()) < 50: #check if correct incrementation for 30-50ppm
            if (int(lowerRateLimit_edit.get()) % 5) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Lower Rate Limit",message="Starting value must be incremented by 5ppm between 30-50ppm.")
        if 50 <= int(lowerRateLimit_edit.get()) < 90: #check if correct incrementation for 50-90ppm
            if not(isinstance(int(lowerRateLimit_edit.get()),int)):
                flag = False
                messagebox.showinfo(title="Invalid Lower Rate Limit",message="Lower rate limit must be a whole number.")
        if 90 <= int(lowerRateLimit_edit.get()) <= 175: #check if correct incrementation for 90-175ppm
            if (int(lowerRateLimit_edit.get()) % 5) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Lower Rate Limit",message="Starting value must be incremented by 5ppm between 90-175ppm.")

        #upper rate limit
        if not(upperRateLimit_edit.get().isdigit()):
            messagebox.showinfo(title="Invalid Upper Rate Limit",message="Upper rate limit must be a non-negative whole number.")
        if (int(upperRateLimit_edit.get()) < 50) or (int(upperRateLimit_edit.get()) > 175): #check if upper rate limit is within range
            flag = False
            messagebox.showinfo(title="Invalid Upper Rate Limit",message="Upper rate limit must be between 50-175ppm.")
        if 50 <= int(upperRateLimit_edit.get()) <= 175:
            if (int(upperRateLimit_edit.get()) % 5) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Upper Rate Limit",message="Starting value must be incremented by 5ppm.")

        if int(upperRateLimit_edit.get()) < int(lowerRateLimit_edit.get()):
            flag = False
            messagebox.showinfo(title="Rate Limit Error",message="Upper rate limit cannot be less than lower rate limit.")
            
        #max sensor rate
        if not(maxSensLimit_edit.get().isdigit()):
            messagebox.showinfo(title="Invalid Maximum Sensor Rate",message="Maximum sensor rate must be a non-negative whole number.")
        if (int(maxSensLimit_edit.get()) < 50) or (int(maxSensLimit_edit.get()) > 175): #out of range
            flag = False
            messagebox.showinfo(title="Invalid Maximum Sensor Rate",message="Maximum sensor rate must be between 50-175ppm.")
        if 50 <= int(maxSensLimit_edit.get()) <= 175: #within range
            if(int(maxSensLimit_edit.get()) % 5) != 0: #wrong step size
                flag = False
                messagebox.showinfo(title="Invalid Maximum Sensor Rate",message="Starting value must be incremented by 5ppm.")

        #atrial amplitude
        if not((atrialAmplitude_edit.get())[0].isdigit()):
            messagebox.showinfo(title="Invalid Atrial Amplitude",message="Atrial amplitude must be a non-negative decimal number.")
        if (float(atrialAmplitude_edit.get()) < 0) or (0 < float(atrialAmplitude_edit.get()) < 0.1) or (float(atrialAmplitude_edit.get()) > 5.0): #check if atrial amplitude is within range
            flag = False
            messagebox.showinfo(title="Invalid Atrial Amplitude",message="Atrial amplitude must be 0 or between 0.1-5.0V")
        if (0.1 <= float(atrialAmplitude_edit.get()) <= 5.0):
            if (int(100*float(atrialAmplitude_edit.get())) % 10) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Atrial Amplitude",message="Starting value must be incremented by 0.1V.")
        
        #ventricular amplitude
        if not((ventricularAmplitude_edit.get())[0].isdigit()):
            messagebox.showinfo(title="Invalid Ventricular Amplitude",message="Ventricular amplitude must be a non-negative decimal number.")
        if (float(ventricularAmplitude_edit.get()) < 0) or (0 < float(ventricularAmplitude_edit.get()) < 0.1) or (float(ventricularAmplitude_edit.get()) > 5.0): #check if ventricular amplitude is within range
            flag = False
            messagebox.showinfo(title="Invalid Ventricular Amplitude",message="Ventricular amplitude must be 0 or between 0.1-5.0V")
        if (0.1 <= float(ventricularAmplitude_edit.get()) <= 5.0): 
            if (int(100*float(ventricularAmplitude_edit.get())) % 10) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Ventricular Amplitude",message="Starting value must be incremented by 0.1V.")

        #atrial pulse width 
        if not(atrialPulseWidth_edit.get()[0].isdigit()):
            messagebox.showinfo(title="Invalid Atrial Pulse Width",message="Atrial pulse width must be a non-negative whole number.")
        if ((int(atrialPulseWidth_edit.get()) < 1) or (int(atrialPulseWidth_edit.get()) > 30)): #check if atrial pulse width is within range
            flag = False
            messagebox.showinfo(title="Invalid Atrial Pulse Width",message="Atrial pulse width must be between 1-30ms.")
        if (1 <= int(atrialPulseWidth_edit.get()) <= 30): #check if correct incrementation
            if not(isinstance(int(atrialPulseWidth_edit.get()),int)):
                flag = False
                messagebox.showinfo(title="Invalid Atrial Pulse Width",message="Atrial pulse width must be a whole number.")

        #ventricular pulse width
        if not(ventricularPulseWidth_edit.get()[0].isdigit()):
            messagebox.showinfo(title="Invalid Ventricular Pulse Width",message="Ventricular pulse width must be a non-negative whole number.")
        if ((int(ventricularPulseWidth_edit.get()) < 1) or (int(ventricularPulseWidth_edit.get()) > 30)): #check if ventricular pulse width is within range
            flag = False
            messagebox.showinfo(title="Invalid Ventricular Pulse Width",message="Ventricular pulse width must be between 1-30ms.")
        if (1 <= int(ventricularPulseWidth_edit.get()) <= 30): #check if correct incrementation
            if not(isinstance(int(ventricularPulseWidth_edit.get()),int)):
                flag = False
                messagebox.showinfo(title="Invalid Ventricular Pulse Width",message="Ventricular pulse width must be a whole number.")
            
        #atrial sensitivity
        if not(atrialSens_edit.get()[0].isdigit()):
            messagebox.showinfo(title="Invalid Atrial Sensitivity",message="Atrial sensitivity must be a non-negative whole number.")
        if ((float(atrialSens_edit.get()) < 0) or (float(atrialSens_edit.get()) > 5.0)): #check if atrial sensitivity width is within range
            flag = False
            messagebox.showinfo(title="Invalid Atrial Sensitivity",message="Atrial sensitivity must be between 0-5V.")
        if (0 <= float(atrialSens_edit.get()) <= 5.0): 
            if (int(100*float(atrialSens_edit.get())) % 10) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Atrial Sensitivity",message="Starting value must be incremented by 0.1V.") 

        #ventricular sensitivity
        if not(ventricularSens_edit.get()[0].isdigit()):
            messagebox.showinfo(title="Invalid Ventricular Sensitivity",message="Ventricular sensitivity must be a non-negative whole number.")
        if ((float(ventricularSens_edit.get()) < 0) or (float(ventricularSens_edit.get()) > 5)): #check if atrial sensitivity width is within range
            flag = False
            messagebox.showinfo(title="Invalid Ventricular Sensitivity",message="Ventricular sensitivity must be between 0-5V.")
        if (0 <= float(ventricularSens_edit.get()) <= 5.0): 
            if (int(100*float(ventricularSens_edit.get())) % 10) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Ventricular Sensitivity",message="Starting value must be incremented by 0.1V.") 
        
        #VRP
        if not(VRP_edit.get().isdigit()): #make sure input is whole and non-negative
            flag = False
            messagebox.showinfo(title="Invalid VRP",message="Ventricular refractory period must be a non-negative whole number.")
        if (int(VRP_edit.get()) < 150) or (int(VRP_edit.get()) > 500):
            flag = False
            messagebox.showinfo(title="Invalid VRP",message="Ventricular refractory period must be between 150-500ms.")
        if (150 < int(VRP_edit.get()) < 500):
            if (int(VRP_edit.get()) % 10) != 0:
                flag = False
                messagebox.showinfo(title="Invalid VRP",message="Starting value must be incremented by 10ms.")

        #ARP
        if not(ARP_edit.get().isdigit()): #make sure input is whole and non-negative
            flag = False
            messagebox.showinfo(title="Invalid ARP",message="Atrial refractory period must be a non-negative whole number.")
        if (int(ARP_edit.get()) < 150) or (int(ARP_edit.get()) > 500):
            flag = False
            messagebox.showinfo(title="Invalid ARP",message="Atrial refractory period must be between 150-500ms.")
        if (150 < int(ARP_edit.get()) < 500):
            if (int(ARP_edit.get()) % 10) != 0:
                flag = False
                messagebox.showinfo(title="Invalid ARP",message="Starting value must be incremented by 10ms.")

        #PVARP
        if not(PVARP_edit.get().isdigit()):
            messagebox.showinfo(title="Invalid PVARP",message="PVARP must be a non-negative whole number.")
        if (int(PVARP_edit.get()) < 150) or (int(PVARP_edit.get()) > 500): #out of range
            flag = False
            messagebox.showinfo(title="Invalid PVARP",message="PVARP must be between 150-500ms.")
        if 150 <= int(PVARP_edit.get()) <= 500: #within range
            if(int(PVARP_edit.get()) % 10) != 0: #wrong step size
                flag = False
                messagebox.showinfo(title="Invalid PVARP",message="Starting value must be incremented by 10ms.")

        #hysteresis rate limit
        if not(hysteresis_edit.get().isdigit()): #make sure input is whole and non-negative
            flag = False
            messagebox.showinfo(title="Invalid Hysteresis Rate Limit",message="Hysteresis rate limit must be a non-negative whole number.")
        if ((int(hysteresis_edit.get()) < 0) or (0 < int(hysteresis_edit.get()) < 30) or (int(float(hysteresis_edit.get())) > 175)): #out of range
            flag = False
            messagebox.showinfo(title="Invalid Hysteresis Rate Limit",message="Hysteresis rate limit must be between 30-175ppm.")
        if 30 <= int(hysteresis_edit.get()) <= 50: #check if correct incrementation for 30-50ppm
            if (int(hysteresis_edit.get()) % 5) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Hysteresis Rate Limit",message="Starting value must be incremented by 5ppm between 30-50ppm.")
        if 90 <= int(hysteresis_edit.get()) <= 175: #check if correct incrementation for 90-175ppm
            if (int(hysteresis_edit.get()) % 5) != 0:
                flag = False
                messagebox.showinfo(title="Invalid Hysteresis Rate Limit",message="Starting value must be incremented by 5ppm between 90-175ppm.")

        #rate smoothing
        if not(rateSmoothing_edit.get().isdigit()):
            messagebox.showinfo(title="Invalid Rate Smoothing",message="Rate smoothing must be a non-negative whole percentage.")
        i = 0
        flag3 = False
        for percent in [0,3,6,9,12,15,18,21,25]:
            if int(rateSmoothing_edit.get()) == percent:
                flag3 = True
        if flag3 == False:
            flag == False
            messagebox.showinfo(title="Invalid Rate Smoothing",message="Enter one of the following percentages: 0, 3, 6, 9, 12, 15, 18, 21, 25.")
            
        #activity threshold
        thresholds = ["V-Low","Low","Med-Low","Med","Med-High","High","V-High"]
        flag2 = False
        for threshold in thresholds:
            if activityThreshold_edit.get() == threshold:
                flag2 = True
        if flag2 == False:
            flag = False
            messagebox.showinfo(title="Invalid Activity Threshold",message="Enter one of the following thresholds: V-Low, Low, Med-Low, Med, Med-High, High, V-High.")

        #reaction time
        if not(reactionTime_edit.get().isdigit()):
            messagebox.showinfo(title="Invalid Reaction Time",message="Reaction time must be a non-negative whole number.")
        if (int(reactionTime_edit.get()) < 10) or (int(reactionTime_edit.get()) > 50): #out of range
            flag = False
            messagebox.showinfo(title="Invalid Reaction Time",message="Reaction time must be between 10-50sec.")
        if 10 <= int(PVARP_edit.get()) <= 50: #within range
            if(int(PVARP_edit.get()) % 10) != 0: #wrong step size
                flag = False
                messagebox.showinfo(title="Invalid Reaction Time",message="Starting value must be incremented by 10sec.")
        
        #response factor
        if not(responseFactor_edit.get().isdigit()):
            messagebox.showinfo(title="Invalid Response Factor",message="Response factor must be a non-negative whole number.")
        if (int(responseFactor_edit.get()) < 1) or (int(responseFactor_edit.get()) > 16): #out of range
            flag = False
            messagebox.showinfo(title="Invalid Response Factor",message="Response factor must be between 1-16.")
        if 1 <= int(responseFactor_edit.get()) <= 16: #within range
            if not(isinstance(int(responseFactor_edit.get()),int)):
                flag = False
                messagebox.showinfo(title="Invalid Response Factor",message="Response factor must be a whole number.")

        #recovery time
        if not(recoveryTime_edit.get().isdigit()):
            messagebox.showinfo(title="Invalid Recovery Time",message="Recovery time must be a non-negative whole number.")
        if (int(recoveryTime_edit.get()) < 2) or (int(recoveryTime_edit.get()) > 16): #out of range
            flag = False
            messagebox.showinfo(title="Invalid Recovery Time",message="Recovery time must be between 2-16min.")
        if 2 <= int(recoveryTime_edit.get()) <= 16: #within range
            if not(isinstance(int(recoveryTime_edit.get()),int)):
                flag = False
                messagebox.showinfo(title="Invalid Recovery Time",message="Recovery time must be a whole number.")

        #mode
        modes = ["AOO", "AAI", "VOO", "VVI", "AOOR", "VOOR", "AAIR", "VVIR"]
        flag2 = False
        for mode in modes:
            if mode_edit.get() == mode:
                flag2 = True
        
        if flag2 == False:
            flag = False
            messagebox.showinfo(title="Invalid Mode",message="Enter one of the following modes: AOO, AAI, VOO, VVI, AOOR, VOOR, AAIR, or VVIR.")

        if flag == True:
            numMode = 0
            if (mode_edit.get() == "VOO"):
                numMode = 1
            elif (mode_edit.get() == "AAI"):
                numMode = 2
            elif (mode_edit.get() == "AOO"):
                numMode = 3
            elif (mode_edit.get() == "VVI"):
                numMode = 4
            elif (mode_edit.get() == "AOOR"):
                numMode = 5
            elif (mode_edit.get() == "VOOR"):
                numMode = 6
            elif (mode_edit.get() == "AAIR"):
                numMode = 7
            elif (mode_edit.get() == "VVIR"):
                numMode = 8
            '''sendserials(numMode,
                        80,
                        atrialAmplitude_edit.get(),
                        ventricularAmplitude_edit.get(),
                        atrialPulseWidth_edit.get(),
                        ventricularPulseWidth_edit.get(),
                        ARP_edit.get(),
                        VRP_edit.get(),
                        atrialSens_edit.get(),
                        ventricularSens_edit.get(),
                        responseFactor_edit.get(),
                        lowerRateLimit_edit.get(),
                        upperRateLimit_edit.get()
                        )'''

            c.execute("""UPDATE login_info SET
                        username=:username,
                        password=:password,
                        firstName=:firstName,
                        lastName=:lastName,
                        lowerRateLimit=:lowerRateLimit,
                        upperRateLimit=:upperRateLimit,
                        maxSensLimit=:maxSensLimit,
                        atrialAmplitude=:atrialAmplitude,
                        ventricularAmplitude=:ventricularAmplitude,
                        atrialPulseWidth=:atrialPulseWidth,
                        ventricularPulseWidth=:ventricularPulseWidth,
                        atrialSens=:atrialSens,
                        ventricularSens=:ventricularSens,
                        VRP=:VRP,
                        ARP=:ARP,
                        PVARP=:PVARP,
                        hysteresis=:hysteresis,
                        rateSmoothing=:rateSmoothing,
                        activityThreshold=:activityThreshold,
                        reactionTime=:reactionTime,
                        responseFactor=:responseFactor,
                        recoveryTime=:recoveryTime,
                        mode=:mode

                        WHERE oid = :oid""",

                    {   
                        'username':username_edit.get(),
                        'password':password_edit.get(),
                        'firstName':firstName_edit.get(),
                        'lastName':lastName_edit.get(),
                        'lowerRateLimit':lowerRateLimit_edit.get(),
                        'upperRateLimit':upperRateLimit_edit.get(),
                        'maxSensLimit':maxSensLimit_edit.get(),
                        'atrialAmplitude':atrialAmplitude_edit.get(),
                        'ventricularAmplitude':ventricularAmplitude_edit.get(),
                        'atrialPulseWidth':atrialPulseWidth_edit.get(),
                        'ventricularPulseWidth':ventricularPulseWidth_edit.get(),
                        'atrialSens':atrialSens_edit.get(),
                        'ventricularSens':ventricularSens_edit.get(),
                        'VRP':VRP_edit.get(),
                        'ARP':ARP_edit.get(),
                        'PVARP':PVARP_edit.get(),
                        'hysteresis':hysteresis_edit.get(),
                        'rateSmoothing':rateSmoothing_edit.get(),
                        'activityThreshold':activityThreshold_edit.get(), 
                        'reactionTime':reactionTime_edit.get(),
                        'responseFactor':responseFactor_edit.get(),
                        'recoveryTime':recoveryTime_edit.get(),
                        'mode':mode_edit.get(),
                        'oid':record_id

                    })

            pages.login_name = str(firstName_edit.get() + " " + lastName_edit.get())
            pages.login_LRL = int(lowerRateLimit_edit.get())
            pages.login_URL = int(upperRateLimit_edit.get())
            pages.login_MSL = int(maxSensLimit_edit.get())
            pages.login_AA = float(atrialAmplitude_edit.get())
            pages.login_VA = float(ventricularAmplitude_edit.get())
            pages.login_APW = float(atrialPulseWidth_edit.get())
            pages.login_VPW = float(ventricularPulseWidth_edit.get())
            pages.login_AS = float(atrialSens_edit.get())
            pages.login_VS = float(ventricularSens_edit.get())
            pages.login_VRP = int(VRP_edit.get())
            pages.login_ARP = int(ARP_edit.get())
            pages.login_PVARP = int(PVARP_edit.get())
            pages.login_H = int(hysteresis_edit.get())
            pages.login_RS = int(rateSmoothing_edit.get())
            pages.login_AT = str(activityThreshold_edit.get())
            pages.login_RT = int(reactionTime_edit.get())
            pages.login_RF = int(responseFactor_edit.get())
            pages.login_recT = int(recoveryTime_edit.get())
            pages.login_M = str(mode_edit.get())
        
        #close connection
        conn.commit()
        conn.close()

    #edit function
    def edit(self,record_id):

        #open connection
        conn = sqlite3.connect('login_list.db')
        c = conn.cursor()

        #query the database
        c.execute("SELECT * FROM login_info WHERE oid = " + record_id)
        records = c.fetchall() # list of lists for each row

        #close connection
        conn.commit()
        conn.close() 

        #global variables for text box names (this is needed to pass the contents of the box to the update function)
        global username_edit 
        global password_edit
        global firstName_edit
        global lastName_edit
        global lowerRateLimit_edit 
        global upperRateLimit_edit 
        global maxSensLimit_edit 
        global atrialAmplitude_edit 
        global ventricularAmplitude_edit 
        global atrialPulseWidth_edit 
        global ventricularPulseWidth_edit 
        global atrialSens_edit 
        global ventricularSens_edit 
        global VRP_edit 
        global ARP_edit 
        global PVARP_edit 
        global hysteresis_edit 
        global rateSmoothing_edit 
        global activityThreshold_edit 
        global reactionTime_edit 
        global responseFactor_edit 
        global recoveryTime_edit
        global mode_edit

        editor = Tk()
        editor.title("Edit Profile")
        editor.geometry("500x800")
        editor.configure(bg='#4863A0')

        editor_frame = tk.Frame(editor, bg='#4863A0')

        edit_data_label = Label(editor_frame, text="Edit Profile",bg='#4863A0', fg='#FFFFFF', font=("Arial", 16))

        '''
        username_edit 
        password_edit
        firstName_edit
        lastName_edit
        lowerRateLimit_edit 
        upperRateLimit_edit 
        maxSensLimit_edit 
        atrialAmplitude_edit 
        ventricularAmplitude_edit 
        atrialPulseWidth_edit 
        ventricularPulseWidth_edit 
        atrialSens_edit 
        ventricularSens_edit 
        VRP_edit 
        ARP_edit 
        PVARP_edit 
        hysteresis_edit 
        rateSmoothing_edit 
        activityThreshold_edit 
        reactionTime_edit 
        responseFactor_edit 
        recoveryTime_edit
        mode_edit
        '''
        #input field
        username_edit = Entry(editor_frame, font=("Arial",12))
        password_edit = Entry(editor_frame, font=("Arial", 12))
        firstName_edit = Entry(editor_frame, font=("Arial", 12))
        lastName_edit = Entry(editor_frame, font=("Arial", 12))
        lowerRateLimit_edit = Spinbox(editor_frame, from_= 30, to= 175, increment = 5, font=("Arial", 12))
        upperRateLimit_edit = Spinbox(editor_frame, from_= 50, to= 175, increment = 5, font=("Arial", 12))
        maxSensLimit_edit = Spinbox(editor_frame, from_= 50, to= 175, increment = 5, font=("Arial", 12))
        atrialAmplitude_edit = Spinbox(editor_frame, from_= 0.1, to= 5.0, increment = 0.1, font=("Arial", 12))
        ventricularAmplitude_edit = Spinbox(editor_frame, from_= 0.1, to= 5.0, increment = 0.1, font=("Arial", 12))
        atrialPulseWidth_edit = Spinbox(editor_frame, from_= 1, to= 30, increment = 1, font=("Arial", 12))
        ventricularPulseWidth_edit = Spinbox(editor_frame, from_= 1, to= 30, increment = 1, font=("Arial", 12))
        atrialSens_edit = Spinbox(editor_frame, from_= 0, to= 5.0, increment = 0.1, font=("Arial", 12))
        ventricularSens_edit = Spinbox(editor_frame, from_= 0, to= 5.0, increment = 0.1, font=("Arial", 12))
        VRP_edit = Spinbox(editor_frame, from_= 150, to= 500, increment = 10, font=("Arial", 12))
        ARP_edit = Spinbox(editor_frame, from_= 150, to= 500, increment = 10, font=("Arial", 12))
        PVARP_edit = Spinbox(editor_frame, from_= 150, to= 500, increment = 10, font=("Arial", 12))
        hysteresis_edit = Spinbox(editor_frame, from_= 0, to= 175, increment = 1, font=("Arial", 12))
        rateSmoothing_edit = Spinbox(editor_frame, from_= 0, to= 24, increment = 3, font=("Arial", 12))
        activityThreshold_edit  = Entry(editor_frame, font=("Arial", 12))
        reactionTime_edit = Spinbox(editor_frame, from_= 10, to= 50, increment = 10, font=("Arial", 12))
        responseFactor_edit = Spinbox(editor_frame, from_= 1, to= 16, increment = 1, font=("Arial", 12))
        recoveryTime_edit = Spinbox(editor_frame, from_= 2, to= 16, increment = 1, font=("Arial", 12))
        mode_edit = Entry(editor_frame, font=("Arial", 12))

        #input labels
        username_edit_label = Label(editor_frame, text = "Username", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        password_edit_label = Label(editor_frame, text = "Password", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        firstName_edit_label = Label(editor_frame, text = "First Name", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        lastName_edit_label = Label(editor_frame, text = "Last Name", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        lowerRateLimit_edit_label = Label(editor_frame, text = "Lower Rate Limit", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        upperRateLimit_edit_label = Label(editor_frame, text = "Upper Rate Limit", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        maxSensLimit_edit_label = Label(editor_frame, text = "Max Sensor Limit", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        atrialAmplitude_edit_label = Label(editor_frame, text = "Atrial Amplitude", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        ventricularAmplitude_edit_label = Label(editor_frame, text = "Ventricular Amplitude", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        atrialPulseWidth_edit_label = Label(editor_frame, text = "Atrial Pulse Width", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        ventricularPulseWidth_edit_label = Label(editor_frame, text = "Ventricular Pulse Width", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        atrialSens_edit_label = Label(editor_frame, text = "Atrial Sensitivity", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        ventricularSens_edit_label = Label(editor_frame, text = "Ventricular Sensitivity", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        VRP_edit_label = Label(editor_frame, text = "VRP", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        ARP_edit_label = Label(editor_frame, text = "ARP", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        PVARP_edit_label = Label(editor_frame, text = "PVARP", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        hysteresis_edit_label = Label(editor_frame, text = "Hysteresis", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        rateSmoothing_edit_label = Label(editor_frame, text = "Rate Smoothing", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        activityThreshold_edit_label = Label(editor_frame, text = "Activity Threshold", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        reactionTime_edit_label = Label(editor_frame, text = "Reaction Time", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        responseFactor_edit_label = Label(editor_frame, text = "Response Factor", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12)) 
        recoveryTime_edit_label = Label(editor_frame, text = "Recovery Time", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))
        mode_edit_label = Label(editor_frame, text = "Mode", bg='#4863A0', fg='#FFFFFF', font=("Arial", 12))

        #buttons
        save_btn = Button(editor_frame, text = "Save Changes", command= lambda: self.update(pages.login_id))
        back_btn = Button(editor_frame, text = "Back", command= editor.destroy)

        #page title
        edit_data_label.grid(row=0, column=0, columnspan=2, sticky="news", pady=5)

        #place input boxes
        username_edit.grid(row=1,column=1,padx=20,pady=5)
        password_edit.grid(row=2,column = 1)
        firstName_edit.grid(row=3,column = 1,pady=5)
        lastName_edit.grid(row=4,column = 1)
        lowerRateLimit_edit.grid(row=5,column = 1,pady=5)
        upperRateLimit_edit.grid(row=6,column = 1)
        maxSensLimit_edit.grid(row=7,column = 1,pady=5)
        atrialAmplitude_edit.grid(row=8,column = 1)
        ventricularAmplitude_edit.grid(row=9,column = 1,pady=5)
        atrialPulseWidth_edit.grid(row=10,column = 1)
        ventricularPulseWidth_edit.grid(row=11,column = 1,pady=5)
        atrialSens_edit.grid(row=12,column = 1)
        ventricularSens_edit.grid(row=13,column = 1,pady=5)
        VRP_edit.grid(row=14,column = 1)
        ARP_edit.grid(row=15,column = 1,pady=5)
        PVARP_edit.grid(row=16,column = 1)
        hysteresis_edit.grid(row=17,column = 1,pady=5)
        rateSmoothing_edit.grid(row=18,column = 1)
        activityThreshold_edit.grid(row=19,column = 1,pady=5)
        reactionTime_edit.grid(row=20,column = 1)
        responseFactor_edit.grid(row=21,column = 1,pady=5)
        recoveryTime_edit.grid(row=22,column = 1)
        mode_edit.grid(row=23,column = 1,pady=5)
    
        #place input labels
        username_edit_label.grid(row=1,column=0)
        password_edit_label.grid(row=2,column=0)
        firstName_edit_label.grid(row=3,column=0)
        lastName_edit_label.grid(row=4,column=0)
        lowerRateLimit_edit_label.grid(row=5,column=0)
        upperRateLimit_edit_label.grid(row=6,column=0)
        maxSensLimit_edit_label.grid(row=7,column=0)
        atrialAmplitude_edit_label.grid(row=8,column=0)
        ventricularAmplitude_edit_label.grid(row=9,column=0)
        atrialPulseWidth_edit_label.grid(row=10,column=0)
        ventricularPulseWidth_edit_label.grid(row=11,column=0)
        atrialSens_edit_label.grid(row=12,column=0)
        ventricularSens_edit_label.grid(row=13,column=0)
        VRP_edit_label.grid(row=14,column=0)
        ARP_edit_label.grid(row=15,column=0)
        PVARP_edit_label.grid(row=16,column=0)
        hysteresis_edit_label.grid(row=17,column=0)
        rateSmoothing_edit_label.grid(row=18,column=0)
        activityThreshold_edit_label.grid(row=19,column=0)
        reactionTime_edit_label.grid(row=20,column=0)
        responseFactor_edit_label.grid(row=21,column=0)
        recoveryTime_edit_label.grid(row=22,column=0)
        mode_edit_label.grid(row=23,column=0)

        #place save button
        save_btn.grid(row=24, column = 0, pady=5)
        back_btn.grid(row=24, column = 1)

        #fill boxes with current info
        for record in records:
            
            username_edit.insert(0,record[0])
            password_edit.insert(0,record[1])
            firstName_edit.insert(0,record[2])
            lastName_edit.insert(0,record[3])
            lowerRateLimit_edit.delete(0,"end")
            lowerRateLimit_edit.insert(0,record[4])
            upperRateLimit_edit.delete(0,"end")
            upperRateLimit_edit.insert(0,record[5])
            maxSensLimit_edit.delete(0,"end")
            maxSensLimit_edit.insert(0,record[6])
            atrialAmplitude_edit.delete(0,"end")
            atrialAmplitude_edit.insert(0,record[7])
            ventricularAmplitude_edit.delete(0,"end")
            ventricularAmplitude_edit.insert(0,record[8])
            atrialPulseWidth_edit.delete(0,"end")
            atrialPulseWidth_edit.insert(0,record[9])
            ventricularPulseWidth_edit.delete(0,"end")
            ventricularPulseWidth_edit.insert(0,record[10])
            atrialSens_edit.delete(0,"end")
            atrialSens_edit.insert(0,record[11])
            ventricularSens_edit.delete(0,"end")
            ventricularSens_edit.insert(0,record[12])
            VRP_edit.delete(0,"end")
            VRP_edit.insert(0,record[13])
            ARP_edit.delete(0,"end")
            ARP_edit.insert(0,record[14])
            PVARP_edit.delete(0,"end")
            PVARP_edit.insert(0,record[15])
            hysteresis_edit.delete(0,"end")
            hysteresis_edit.insert(0,record[16])
            rateSmoothing_edit.delete(0,"end")
            rateSmoothing_edit.insert(0,record[17])
            activityThreshold_edit.delete(0,"end")
            activityThreshold_edit.insert(0,record[18])
            reactionTime_edit.delete(0,"end")
            reactionTime_edit.insert(0,record[19])
            responseFactor_edit.delete(0,"end")
            responseFactor_edit.insert(0,record[20])
            recoveryTime_edit.delete(0,"end")
            recoveryTime_edit.insert(0,record[21])
            mode_edit.insert(0,record[22])

        editor_frame.pack()
        editor.mainloop()


    #delete function
    def delete(self,idNum):

        #connect to database and create cursor
        conn = sqlite3.connect('login_list.db')
        c = conn.cursor()

        c.execute("DELETE from login_info WHERE oid =" + idNum)#use oid instead of username or password because there may be multiples

        conn.commit()
        conn.close()

    #submit function
    def submit(self, username, password, firstName, lastName,):

        #connect to database and create cursor
        conn = sqlite3.connect('login_list.db')
        c = conn.cursor()

        lowerRateLimit = 60
        upperRateLimit = 120
        maxSensLimit = 120
        atrialAmplitude = 5.0
        ventricularAmplitude = 5.0
        atrialPulseWidth = 1
        ventricularPulseWidth = 1
        atrialSens = 0
        ventricularSens = 0
        VRP = 320
        ARP = 250
        PVARP = 250
        hysteresis = 0
        rateSmoothing = 0
        activityThreshold = "Med" 
        reactionTime = 30
        responseFactor = 8
        recoveryTime = 5
        mode = "AOO"

        #insert into table
        c.execute("INSERT INTO login_info VALUES(:username,:password,:firstName,:lastName,:lowerRateLimit,:upperRateLimit,:maxSensLimit,:atrialAmplitude,:ventricularAmplitude,:atrialPulseWidth,:ventricularPulseWidth,:atrialSens,:ventricularSens,:VRP,:ARP,:PVARP,:hysteresis,:rateSmoothing,:activityThreshold,:reactionTime,:responseFactor,:recoveryTime,:mode)",
                {
                    'username':username,
                    'password':password,
                    'firstName':firstName,
                    'lastName':lastName,
                    'lowerRateLimit':lowerRateLimit,
                    'upperRateLimit':upperRateLimit,
                    'maxSensLimit':maxSensLimit,
                    'atrialAmplitude':atrialAmplitude,
                    'ventricularAmplitude':ventricularAmplitude,
                    'atrialPulseWidth':atrialPulseWidth,
                    'ventricularPulseWidth':ventricularPulseWidth,
                    'atrialSens':atrialSens,
                    'ventricularSens':ventricularSens,
                    'VRP':VRP,
                    'ARP':ARP,
                    'PVARP':PVARP,
                    'hysteresis':hysteresis,
                    'rateSmoothing':rateSmoothing,
                    'activityThreshold':activityThreshold, 
                    'reactionTime':reactionTime,
                    'responseFactor':responseFactor,
                    'recoveryTime':recoveryTime,
                    'mode':mode
                })

        conn.commit()
        conn.close()

    def query(self):

        #connect to database and create cursor (you need to do this inside the function as well, idk why)
        conn = sqlite3.connect('login_list.db')
        c = conn.cursor()

        #query the database
        c.execute("SELECT *, oid FROM login_info")
        records = c.fetchall() # list of lists for each row

        conn.commit()
        conn.close()

        return records