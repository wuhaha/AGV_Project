import cv2
import numpy as np

img = cv2.imread('/home/fern/Documents/opencv/road.jpg') 
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
#ret, binary = cv2.threshold(gray,48,255,cv2.THRESH_BINARY)
edges = cv2.Canny(gray,150,250,apertureSize = 3)

lines = cv2.HoughLines(edges,1,np.pi/180,200)
for rho,theta in lines[0]:
    a = np.cos(theta)
    b = np.sin(theta)
    x0 = a*rho
    y0 = b*rho
    x1 = int(x0 + 1000*(-b))
    y1 = int(y0 + 1000*(a))
    x2 = int(x0 - 1000*(-b))
    y2 = int(y0 - 1000*(a))

    #cv2.line(img,(x1,y1),(x2,y2),(0,0,255),2)

#cv2.imwrite('/home/fern/Documents/opencv/h2.jpg',img)

ret, binary = cv2.threshold(edges,127,255,cv2.THRESH_BINARY)  
  
contours, hierarchy = cv2.findContours(binary,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)  
cv2.drawContours(img,contours,-1,(0,0,255),3)  
  
cv2.imshow("img", img)  
 
cv2.imwrite('/home/fern/Documents/opencv/h2.jpg',img)
