import cv2
import imutils
import numpy as np

def FindSqare(zipcontour):
    c = zipcontour[0]
    h = zipcontour[1]
    indexs -= 1
    # cv2.drawContours(img, [c0], -1, (0, 255, 0), 4)
    # cv2.imwrite('b.jpg', img)
    peri = cv2.arcLength(c, True)
    approx = cv2.approxPolyDP(c, 0.02 * peri, True)
    if len(approx) >= 4 and h[2] < 0:
        # cv2.drawContours(img, [approx0], -1, (255, 255, 0), 2)
        M = cv2.moments(approx)
        if int(M['m00']) != 0:
            cX = int(M['m10'] / M['m00'])
            cY = int(M['m01'] / M['m00'])
        else:
            cX = 0
            cY = 0
    return cX,cY,h[3]