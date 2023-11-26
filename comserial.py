import struct
import serial
import serial.tools.list_ports


myports = [tuple(p) for p in list(serial.tools.list_ports.comports())]
print (myports)
st = struct.Struct('<B')
ser = serial.Serial(port = 'COM5', baudrate = 115200)
mode = 3;
serial_com = st.pack(mode)
print(serial_com)
print(len(serial_com))
ser.write(serial_com)
ser.close()
