import cv2
import numpy as np

captured_img = ''
class FindPattern(object):
    def __init__(self, captured_img):
        self.captured_img = captured_img
        self.indexs = 0
        self.img = cv2.imread(self.captured_img)

    # self.layers = 5

    def preprocessing(self):
        #img = cv2.imread(self.captured_img)
        gray = cv2.cvtColor(self.img, cv2.COLOR_BGR2GRAY)
        # blur = cv2.GaussianBlur(gray, (15,15),0)
        edged = cv2.Canny(gray, 150, 250)
        # cv2.imwrite("Edged.jpg", edged)
        kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3))
        closed = cv2.morphologyEx(edged, cv2.MORPH_CLOSE, kernel)
        # thresh = cv2.threshold(blur, 100, 200, cv2.THRESH_BINARY)[1]
        # cv2.imwrite('th.jpg',thresh)
        cnts, hier = cv2.findContours(closed.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
        cv2.drawContours(self.img, cnts, -1, (255, 255, 0), 2)
        z = zip(cnts, hier[0])
        self.indexs = len(z) - 1
        return z

    def find_squares(self, zipcontour):
        c = zipcontour[0]
        h = zipcontour[1]
        peri = cv2.arcLength(c, True)
        approx = cv2.approxPolyDP(c, 0.02 * peri, True)
        if ((len(approx) >= 4) and (len(approx) <= 8)):
            rect = cv2.minAreaRect(approx)
            if h[2] < 0:
                return True, rect, True, h[3]
            else:
                return True, rect, False, h[3]
        else:
            return False, -1, False, -1

    def match_squares(self):
        zipcnts = self.preprocessing()
        while (self.indexs >= 0):
            squarecnt = 0
            print "index = " + str(self.indexs)
            is_square, rect, is_innermost, outer_shape = self.find_squares(zipcnts[self.indexs])
            self.indexs -= 1
            if not is_square:
                continue
            else:
                if is_innermost:
                    centerX0, centerY0 = rect[0]
                    width0, height0 = rect[1]
                    angle0 = rect[2]
                    if width0 - height0 > 5:
                        continue
                    centerX = centerX0
                    centerY = centerY0
                    angle = angle0
                    while (squarecnt < 6 and outer_shape >= 0):
                        is_square, rect, is_innermost, outer_shape = self.find_squares(zipcnts[outer_shape])
                        try:
                            centerX1, centerY1 = rect[0]
                        except:
                            print "wrong pattern"
                            break
                        width1, height1 = rect[1]
                        angle1 = rect[2]
                        if not is_square or centerX1 - centerX0 > 5 or centerY1 - centerY0 > 5:
                            break
                        else:
                            centerX += centerX1
                            centerY += centerY1
                            angle += angle1
                            squarecnt += 1
                            print "now is" + str(squarecnt)
                            print "now" + str(outer_shape)
                            cv2.drawContours(self.img, [zipcnts[outer_shape][0]], -1, (255, 255, 0), 2)
            if squarecnt == 6:
                centerX = int(centerX / 6)
                centerY = int(centerY / 6)
                angle = angle / 6
                return centerX, centerY, angle
        return 0,0,0

img_path = captured_img
fp = FindPattern(img_path)
a, b, c = fp.match_squares()

print a, b, c
           # self.indexs -= 1
        # cv2.drawContours(img, [c0], -1, (0, 255, 0), 4)
        # cv2.imwrite('b.jpg', img)
        # peri = cv2.arcLength(rect, True)
        # approx = cv2.approxPolyDP(rect, 0.02 * peri, True)
        # if len(approx) >= 4 and h[2] < 0:
        # 	# cv2.drawContours(img, [approx0], -1, (255, 255, 0), 2)
        # 	M = cv2.moments(approx)
        # 	if int(M['m00']) != 0:
        # 		cX = int(M['m10'] / M['m00'])
        # 		cY = int(M['m01'] / M['m00'])
        # 	else:
        # 		cX = 0
        # 		cY = 0
        # return cX, cY, h[3]

# cv2.imwrite('b.jpg',img)
