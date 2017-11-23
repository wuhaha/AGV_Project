from DetectPattern import FindPattern

from picamera import PiCamera
from datetime import datetime
import time
import os

fPath = '/home/pi/livacapture/' + datetime.now().strftime('%m_%d_%y') + "/"

pica = PiCamera()


if not os.path.exists(fPath):
    os.makedirs(fPath)
pica.start_preview()

time.sleep(3)
tit = fPath + datetime.now().strftime('%m_%d_%Y_%H%M%S') + '.jpg'
pica.capture(tit)
pica.stop_preview()

img_path = tit
fp = FindPattern(img_path)
a, b, c = fp.match_squares()

print a, b, c
