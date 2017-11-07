import picamera
from datetime import datetime
import time
import os

fPath = '/home/pi/livacapture/' + datetime.now().strftime('%m_%d_%y') + "/"

if not os.path.exists(fPath):
	os.makedirs(fPath)

pica = picamera.PiCamera()

pica.start_preview()
time.sleep(3)
tit = fPath + datetime.now().strftime('%m_%d_%Y_%H%M%S') + '.jpg'
pica.capture(tit)
pica.stop_preview()
