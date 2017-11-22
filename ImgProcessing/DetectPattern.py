import cv2
import imutils
import numpy as np

class findpattern:

	def __init__(self,captured_img):
		self.captured_img = captured_img
		self.indexs = 0
		self.layers = 5

	def preprocessing:
		img = cv2.imread(self.captured_img)
		gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
		#blur = cv2.GaussianBlur(gray, (15,15),0)
		edged = cv2.Canny(gray, 100, 250)
		#cv2.imwrite("Edged.jpg", edged)
		#kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
		closed = cv2.morphologyEx(edged, cv2.MORPH_CLOSE, kernel)
		#cv2.imwrite("closed.jpg", closed)
		#thresh = cv2.threshold(blur, 100, 200, cv2.THRESH_BINARY)[1]
		#cv2.imwrite('th.jpg',thresh)
		cnts,hier = cv2.findContours(closed.copy(), cv2.RETR_TREE ,cv2.CHAIN_APPROX_SIMPLE)
		z = zip(cnts,hier[0])
		self.indexs = len(z) -1

	def find_pattern_squares:
		CrtContours =

while(indexs >= 0):
	c0 = z[indexs][0]
	h0 = z[indexs][1]
	indexs -= 1
	#cv2.drawContours(img, [c0], -1, (0, 255, 0), 4)
	#cv2.imwrite('b.jpg', img)
	peri0 = cv2.arcLength(c0, True)
	approx0 = cv2.approxPolyDP(c0, 0.02 * peri0, True)
	if len(approx0) >= 4 and h0[2] < 0:
		#cv2.drawContours(img, [approx0], -1, (255, 255, 0), 2)
		M0 = cv2.moments(approx0)
		if int(M0['m00']) != 0:
			cX0 = int(M0['m10']/M0['m00'])
			cY0 = int(M0['m01']/M0['m00'])
		else:
			cX0 = 0
			cY0 = 0
		if h0[3] < 0:
			continue
		else:
			#cv2.drawContours(img, [approx0], -1, (0, 255, 0), 4)
			index1 = h0[3]
			c1 = z[index1][0]
			h1 = z[index1][1]
			peri1 = cv2.arcLength(c1, True)
			approx1 = cv2.approxPolyDP(c1, 0.02 * peri1, True)
			if len(approx1) == 4:
				M1 = cv2.moments(approx1)
				cX1 = int(M1['m10']/M1['m00'])
				cY1 = int(M1['m01']/M1['m00'])	
				#cv2.drawContours(img, [approx1], -1, (0, 255, 0), 4)
				if cX0 - cX1 > 5 or cY0 - cY1 > 5 or h1[3] < 0:
					continue
				else:
					index2 = h1[3]	
					c2 = z[index2][0]
					h2 = z[index2][1]
					peri2 = cv2.arcLength(c2, True)
					approx2 = cv2.approxPolyDP(c2, 0.02 * peri2, True)
					if len(approx2) >= 4:
						M2 = cv2.moments(approx2)
						cX2 = int(M2['m10']/M2['m00'])
						cY2 = int(M2['m01']/M2['m00'])	
						#cv2.drawContours(img, [approx2], -1, (0, 255, 0), 4)
						if cX2 - cX1 > 5 or cY2 - cY1 > 5:
							continue
						else:
							index3 = h2[3]	
							c3 = z[index3][0]
							h3 = z[index3][1]
							peri3 = cv2.arcLength(c3, True)
							approx3 = cv2.approxPolyDP(c3, 0.02 * peri3, True)
							if len(approx3) >= 4:
								M3 = cv2.moments(approx3)
								cX3 = int(M3['m10']/M3['m00'])
								cY3 = int(M3['m01']/M3['m00'])	
								#cv2.drawContours(img, [approx3], -1, (0, 255, 0), 4)
								if cX3 - cX2 > 5 or cY3 != cY2 > 5:
									continue
								else:
									cX = cX2
									cY = cY2
									cv2.drawContours(img, [approx0], -1, (0, 255, 255), 4)
									cv2.drawContours(img, [approx1], -1, (255, 255, 0), 4)
									#cv2.drawContours(img, [approx2], -1, (0, 0, 255), 4)
									#cv2.drawContours(img, [approx3], -1, (0, 255, 0), 4)
									cv2.imwrite('b.jpg', img)

	#print indexs
	#cv2.drawContours(img, [c0], -1, (0, 255, 0), 4)
	#indexs -= 1
	#peri0 = cv2.arcLength(c0, True)
	#approx0 = cv2.approxPolyDP(c0, 0.02 * peri0, True)
	#if len(approx0) == 4 and h0[2] < 0:
		#print h0[2]
		#cv2.drawContours(img, [approx0], -1, (0, 255, 0), 4)
#print str(cX) + ',' + str(cY)
cv2.imwrite('b.jpg',img)
