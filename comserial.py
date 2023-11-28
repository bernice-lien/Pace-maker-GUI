import struct
import serial
import serial.tools.list_ports
import time
from database import database


""" myports = [tuple(p) for p in list(serial.tools.list_ports.comports())]
print (myports)
st = struct.Struct('<B')
ser = serial.Serial(port = 'COM5', baudrate = 115200)
mode = 3
serial_com = st.pack(mode)
print(serial_com)
print(len(serial_com))
ser.write(serial_com)
ser.close() """



def pack(mode, period, VRP, ARP, Atr_PW, Vent_PW, rf_factor, Atr_AMP, Vent_AMP, Vent_Sensitivity, Atr_Sensitivity):
    check = mode + period + VRP + ARP + Atr_PW + Vent_PW + rf_factor + Atr_AMP + Vent_AMP + Vent_Sensitivity + Atr_Sensitivity
    mode_s = struct.pack('B',mode)
    period_s = struct.pack('B',period)
    VRP_s = struct.pack('H',VRP)
    ARP_s = struct.pack('H',ARP)
    Atr_PW_s = struct.pack('f',Atr_PW)
    Vent_PW_s = struct.pack('f',Vent_PW)
    rf_factor_s = struct.pack('B',rf_factor)
    Atr_AMP_s = struct.pack('B',Atr_AMP)
    Vent_AMP_s = struct.pack('B',Vent_AMP)
    Vent_Sensitivity_s = struct.pack('B',Vent_Sensitivity)
    Atr_Sensitivity_s = struct.pack('B',Atr_Sensitivity)

    transmit_packet = b'\x10' + mode_s + period_s + VRP_s + ARP_s + Atr_PW_s + Vent_PW_s + rf_factor_s + Atr_AMP_s + Vent_AMP_s + Vent_Sensitivity_s + Atr_Sensitivity_s

    return transmit_packet, check

def unpack(data):
    mode_s = data[0]
    period_s = data[1]
    VRP_s = struct.unpack('H',)
    ARP_s = struct.unpack('H')
    Atr_PW_s = struct.unpack('f')
    Vent_PW_s = struct.unpack('f')
    rf_factor_s = data[15]
    Atr_AMP_s = data[16]
    Vent_AMP_s = data[17]
    Vent_Sensitivity_s = data[18]
    Atr_Sensitivity_s = data[19]