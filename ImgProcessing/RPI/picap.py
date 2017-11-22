import picamera
from datetime import datetime
import time
import os

class cameractl:

	fPath = '/home/pi/livacapture/' + datetime.now().strftime('%m_%d_%y') + "/"

	def __init__(self):
		pass

	def caminit():
		if not os.path.exists(fPath):
			os.makedirs(fPath)

		pica = picamera.PiCamera()
		pica.start_preview()
	
	def taking_picture():
		time.sleep(3)
		tit = fPath + datetime.now().strftime('%m_%d_%Y_%H%M%S') + '.jpg'
		pica.capture(tit)
		return tit

	def camstop():
		pica.stop_preview()
