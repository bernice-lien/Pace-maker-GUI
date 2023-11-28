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

SERIALPORT  = 'COM10'
BAUDRATE    = 115200
DATASIZE    = 8
TIMEOUT     = 1

def initializeSerial():
#   Initialize serial port with defined parameters
    ser = serial.Serial(port = SERIALPORT, baudrate = BAUDRATE, bytesize = DATASIZE, timeout = TIMEOUT, parity = 'N',stopbits = serial.STOPBITS_ONE)
    return ser

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
    VRP_s = struct.unpack('H', data[2:3])[0]
    ARP_s = struct.unpack('H', data[4:5])[0]
    Atr_PW_s = struct.unpack('f', data[6:9])[0]
    Vent_PW_s = struct.unpack('f', data[10:13])
    rf_factor_s = data[14]
    Atr_AMP_s = data[15]
    Vent_AMP_s = data[16]
    Vent_Sensitivity_s = data[17]
    Atr_Sensitivity_s = data[18]

    receive_packet = mode_s + period_s + VRP_s + ARP_s + Atr_PW_s + Vent_PW_s + rf_factor_s + Atr_AMP_s + Vent_AMP_s + Vent_Sensitivity_s + Atr_Sensitivity_s
    return receive_packet

def compareChecksum(transmit, receive):
    return int(transmit == int(receive))

def main():
    ser = initializeSerial()

    mode = 3
    period = 80
    VRP = 330
    ARP = 330
    Atr_PW = 1
    Vent_PW = 1
    rf_factor = 16
    Atr_Amp = 5
    Vent_AMP = 5
    Vent_sensitivity = 2
    Atr_sensitivity = 2



    count = 0 
    data = ser.read(4000)
    atr = [None] * 1000

    for i in range(0,4000,4):
        atr[count] = struct.unpack('f', data[i:i+4])[0]

        count = count+1
    for i in range(0, 1000):
        print(atr[i])