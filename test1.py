import serial
import struct
from time import sleep

 
st = struct.Struct('<BBBffffHHffB')

transmit = 1
mode = 3
Period = 80
A_Amplitude = 1.0
V_Amplitude = 1.0
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
uC = serial.Serial("COM5", baudrate=115200)
uC.write(serial_com)
    # unpacked = st.unpack(serial_com)
    # print(unpacked)
uC.close()

#### Recieve


rf = serial.Serial("COM5", baudrate=115200)

st = struct.Struct('<BBBffffHHffB')

transmit = 0
mode = 3
Period = 90
A_Amplitude = 1.0
V_Amplitude = 1.0
A_Pulse_Width = 0.2
V_Pulse_Width = 0.3
ARP = 500
VRP = 600
A_Sens = 0.25
V_Sens = 0.26
Response_Factor = 4

serial_com = st.pack(transmit, mode, Period, A_Amplitude, V_Amplitude, A_Pulse_Width, V_Pulse_Width, ARP, VRP, A_Sens, V_Sens, Response_Factor)

rf.write(serial_com)
sleep(0.1)

uC = struct.Struct('<BBBffffHHffB')
size = struct.calcsize('<BBHHffffff')
data = rf.read(size)
tup = struct.unpack('<BBHHffffff',data)
print(tup[0])
print(tup[1])
print(tup[2])
print(tup[3])
print(tup[4])
print(tup[8])
rf.close()
