import serial
import struct
from time import sleep

def sendserials(mode, Period, A_Amplitude, V_Amplitude, A_Pulse_Width, V_Pulse_Width, ARP, VRP, A_Sens, V_Sens, Response_Factor, LRL, URL):
    transmit = 1
    rf = serial.Serial("COM6", baudrate=115200)
    st = struct.Struct('<BBBffffHHffBBB')
    rf.open()
    serial_com = st.pack(transmit, mode, Period, A_Amplitude, V_Amplitude, A_Pulse_Width, V_Pulse_Width, ARP, VRP, A_Sens, V_Sens, Response_Factor, LRL, URL)
    rf.write(serial_com)
    rf.close()

def egramreceive():
    rf = serial.Serial("COM6", baudrate=115200)


    st = struct.Struct('<BBBffffHHffBBB')

    transmit = 0
    mode = 3
    Period = 90
    A_Amplitude = 3.2
    V_Amplitude = 3.4
    A_Pulse_Width = 0.2
    V_Pulse_Width = 0.3
    ARP = 500
    VRP = 600
    A_Sens = 0.25
    V_Sens = 0.26
    Response_Factor = 4
    LRL = 70
    URL = 150


    serial_com = st.pack(transmit, mode, Period, A_Amplitude, V_Amplitude, A_Pulse_Width, V_Pulse_Width, ARP, VRP, A_Sens, V_Sens, Response_Factor, LRL, URL)

    rf.write(serial_com)

    size = struct.calcsize('<Bffdd')
    data = rf.read(size)
    tup = struct.unpack('<Bffdd',data)
    val = [tup[0],tup[1], tup[2],tup[3], tup[4]]
    rf.close()
    return val

    
transmit = 0
while transmit < 400:
    out = egramreceive()
    print(out[4], out[3])
    transmit +=1