import cv2
import imutils
import numpy as np
import picamera
from datetime import datetime
import time
import os
from FindSqare import FindSqare

fPath = '/home/pi/pipic/' + datetime.now().strftime('%m_%d_%y') + "/"

if not os.path.exists(fPath):
	os.makedirs(fPath)

pica = picamera.PiCamera()

pica.start_preview()
time.sleep(3)
tit = fPath + datetime.now().strftime('%m_%d_%Y_%H%M%S') + '.jpg'
pica.capture(tit)

img = cv2.imread('img.jpg')
img2 = img.copy()

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

blur = cv2.GaussianBlur(gray, (15,15),0)

edged = cv2.Canny(gray, 100, 250)
#cv2.imwrite("Edged.jpg", edged)

kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
closed = cv2.morphologyEx(edged, cv2.MORPH_CLOSE, kernel)
#cv2.imwrite("closed.jpg", closed)

cnts,hier = cv2.findContours(closed.copy(), cv2.RETR_TREE ,cv2.CHAIN_APPROX_SIMPLE)

z = zip(cnts,hier[0])

indexs = len(z) -1

while(indexs >= 0):
    FindSqare(z[indexs])

