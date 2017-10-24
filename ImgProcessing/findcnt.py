import cv2
import imutils
import numpy as np

img = cv2.imread('img.jpg')
img2 = img.copy()

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


blur = cv2.GaussianBlur(gray, (3,3),0)

thresh = cv2.threshold(blur, 130, 200, cv2.THRESH_BINARY)[1]

cv2.imwrite('th.jpg',thresh)

edged = cv2.Canny(gray, 10, 250)
cv2.imwrite("Edged.jpg", edged)

kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (7, 7))
closed = cv2.morphologyEx(edged, cv2.MORPH_CLOSE, kernel)
cv2.imwrite("closed.jpg", closed)

cnts = cv2.findContours(closed.copy(), cv2.RETR_LIST ,cv2.CHAIN_APPROX_SIMPLE)

cnts = cnts[0]
print len(cnts)

for c in cnts:
	peri = cv2.arcLength(c, True)
	approx = cv2.approxPolyDP(c, 0.02 * peri, True)
	if len(approx) == 4:
		M = cv2.moments(c)
		if M["m00"] != 0:
    			cX = int(M["m10"] / M["m00"])
    			cY = int(M["m01"] / M["m00"])
		else:
    			cX, cY = 0, 0
	
		cv2.drawContours(img, [approx], -1, (0, 255, 0), 4)	
	#cv2.drawContours(img, [c], -1, (0, 255, 0), 2)
	#cv2.circle(img, (cX, cY), 7, (255, 0, 0), -1)
		cv2.putText(img, str(cX)+','+str(cY), (cX - 20, cY - 20),cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)
		print str(cX) + ',' +str(cY)
		print str(approx)
		#print [c]

cv2.imwrite('a.jpg',img)
