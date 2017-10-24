import cv2
import imutils
import numpy as np

img = cv2.imread('img.jpg')
img2 = img.copy()

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

circles = cv2.HoughCircles(gray, cv2.cv.CV_HOUGH_GRADIENT, 1.5, 100)

if circles is not None:
	circles = np.round(circles[0, :]).astype("int")
	for (x, y, r) in circles:
		cv2.circle(img2, (x, y), r, (0, 255, 0), 4)
		cv2.rectangle(img2, (x - 5, y - 5), (x + 5, y + 5), (0, 128, 255), -1)

blur = cv2.GaussianBlur(gray, (3,3),0)

thresh = cv2.threshold(blur, 130, 200, cv2.THRESH_BINARY)[1]

cv2.imwrite('th.jpg',thresh)

cnts = cv2.findContours(thresh.copy(), cv2.RETR_LIST ,cv2.CHAIN_APPROX_SIMPLE)

cnts = cnts[0]
print len(cnts)

for c in cnts:

	M = cv2.moments(c)
	if M["m00"] != 0:
    		cX = int(M["m10"] / M["m00"])
    		cY = int(M["m01"] / M["m00"])
	else:
    		cX, cY = 0, 0
	
	cv2.drawContours(img, [c], -1, (0, 255, 0), 2)
	cv2.circle(img, (cX, cY), 7, (255, 0, 0), -1)
	cv2.putText(img, str(cX)+','+str(cY), (cX - 20, cY - 20),cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
	print str(cX) + ',' +str(cY)
	print [c]

cv2.imwrite('a.jpg',img)
