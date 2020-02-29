import serial
import struct
import RPi.GPIO as GPIO

class speed_ctl():

	def __init__():
		self.pi_ser_cmd= serial.Serial()
		self.pi_ser_cmd.port = '/dev/ttyAMA0'
		self.pi_ser_cmd.baudrate = 9600
		self.pi_ser_cmd.bytesize = serial.EIGHTBITS
		self.pi_ser_cmd.parity = serial.PARITY_NONE
		self.pi_ser_cmd.stopbits = serial.STOPBITS_ONE
		self.pi_ser_cmd.timeout = 3
		self.pi_ser_cmd.xonxoff = False
		self.pi_ser_cmd.rtscts = False
		self.pi_ser_cmd.dsrdtr = False
		self.pi_ser_cmd.writeTimeout = 2

		self.pi_ser_cmd.open()

	def _spd_constructor(spd):
		if spd < 0:
			print('speed out of range, set it to 0 instead')
			spd = 0
		elif spd > 255:
			print('speed out of range, set it to 255 instead')
			spd = 255
		return b"{}\n".format(str(spd))

	def send_serial(cmd, timeout=1):
		self.pi_ser_cmd.write(cmd)

	def set_spd(spd):
		cmd = self._spd_constructor(spd)
		self.send_serial(cmd)

	def close():
		self.pi_ser_cmd.close()


class mode_ctl():
	def __init__():
		GPIO.setmode(GPIO.BOARD)
		GPIO.setup(16, GPIO.OUT)
		GPIO.setup(18, GPIO.OUT)

	def forward():
		GPIO.output(16, GPIO.LOW)
		GPIO.output(18, GPIO.LOW)

	def turn_left():
		GPIO.output(16, GPIO.LOW)
		GPIO.output(18, GPIO.HIGH)

	def turn_right():
		GPIO.output(16, GPIO.HIGH)
		GPIO.output(18, GPIO.LOW)

	def backward():
		GPIO.output(16, GPIO.HIGH)
		GPIO.output(18, GPIO.HIGH)


mc = mode_ctl()
sc = speed_ctl()


# pi_ser_cmd.write(struct('!l',1))

# pi_ser_cmd.readall()

# values = (2,2,3)

# picmd = ''

# for i in values:
#     picmd += struct.pack('!lll',i)

# pi_ser_cmd.write(picmd)
# pi_ser_cmd.readall()


