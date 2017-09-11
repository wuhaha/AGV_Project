import cv2
import numpy as np

#set yellow threshold

l_y = np.array([26,43,46])
h_y = np.array([34,255,255])

img = cv2.imread('/home/fern/Documents/opencv/road.jpg') 
hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)

mask = cv2.inRange(hsv, l_y, h_y)
cv2.imshow('Mask', mask)

res = cv2.bitwise_and(img, img, mask=mask)
cv2.imwrite('/home/fern/Documents/opencv/c1.jpg',img)
