import serial
import struct


st = struct.Struct('<BBBffffHHffB')

transmit = 1
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



serial_com = st.pack(transmit, mode, Period, A_Amplitude, V_Amplitude, A_Pulse_Width, V_Pulse_Width, ARP, VRP, A_Sens, V_Sens, Response_Factor)

print(serial_com)
print(len(serial_com))
uC = serial.Serial("COM6", baudrate=115200)
uC.write(serial_com)
    # unpacked = st.unpack(serial_com)
    # print(unpacked)
uC.close()