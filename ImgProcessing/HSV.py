import cv2
import numpy as np

img = cv2.imread('/home/fern/Documents/opencv/road.jpg') 
hsv = cv2.cvtColor(img,cv2.COLOR_BGR2HSV)

lower_hsv = np.array([24,150,150])
upper_hsv = np.array([38,255,255])

mask = cv2.inRange(hsv, lower_hsv, upper_hsv)
cv2.imwrite('/home/fern/Documents/opencv/mask.jpg',mask)




