import serial
import struct

pi_ser_cmd= serial.Serial()
pi_ser_cmd.port = '/dev/ttyACM0'
pi_ser_cmd.baudrate = 115200
pi_ser_cmd.bytesize = serial.EIGHTBITS 
pi_ser_cmd.parity = serial.PARITY_NONE 
pi_ser_cmd.stopbits = serial.STOPBITS_ONE 
pi_ser_cmd.timeout = 1            
pi_ser_cmd.xonxoff = False     
pi_ser_cmd.rtscts = False    
pi_ser_cmd.dsrdtr = False      
pi_ser_cmd.writeTimeout = 2 

pi_ser_cmd.open()

pi_ser_cmd.write(struct('!B',1))

pi_ser_cmd.readall()

values = (2,2,1)

picmd = ''

for i in values:
    picmd += struct.pack('!B',i)

pi_ser_cmd.write(picmd)
pi_ser_cmd.readall()
