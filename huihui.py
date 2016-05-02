#coding=utf-8
import cv2
#import numpy as np

img = cv2.imread('cactus.jpg', 0)
px1, py1, px2, py2 = 0, 0, 720, 1280       # 27.48231

#px1, py1, px2, py2 = 600, 270, 664, 334     # 4.63379
px1, py1, px2, py2 = 480, 750, 544, 814     # 37.09985
#px1, py1, px2, py2 = 152, 964, 216, 1028     # 24.99658
#py1, px1 = 964, 152
#py2, px2 = py1+64, px1+64
res = img[px1:px2, py1:py2]
#print res
x = cv2.Sobel(res, cv2.CV_16S, 1, 0)
y = cv2.Sobel(res, cv2.CV_16S, 0, 1)
absX = cv2.convertScaleAbs(x)
absY = cv2.convertScaleAbs(y)
dst = cv2.addWeighted(absX, 0.5, absY, 0.5, 0)

#print dst

for i in range(1, px2-px1-1):
    dst[i, 0] = dst[i, 1]
    dst[i, py2-py1-1] = dst[i, py2-py1-2]

for i in range(1, py2-py1-1):
    dst[0, i] = dst[1, i]
    dst[px2-px1-1, i] = dst[px2-px1-2, i]

dst[0, 0] = dst[1, 1]
dst[0, py2-py1-1] = dst[1, py2-py1-2]
dst[px2-px1-1, 0] = dst[px2-px1-2, 1]
dst[px2-px1-1, py2-py1-1] = dst[px2-px1-2, py2-py1-2]

#print dst

pixSum = 0
for i in range(px2-px1):
    for j in range(py2-py1):
        pixSum = pixSum + dst[i, j]

pixNum = (px2-px1)*(py2-py1)
pixAvg = pixSum/float(pixNum)
pixAvg = round(pixAvg, 5)
print str(pixSum) + '/' + str(pixNum) + '=' + str(pixAvg)

res = cv2.resize(dst, None, fx=1, fy=1, interpolation=cv2.INTER_CUBIC)
cv2.imshow("res", res)
#img = cv2.resize(img, None, fx=1, fy=1, interpolation=cv2.INTER_CUBIC)
#cv2.imshow("img", img)
#cv2.imwrite('cactus_sobel.png', dst)

cv2.waitKey(0)
cv2.destroyAllWindows()
