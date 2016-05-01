import cv2
#import numpy as np

img = cv2.imread('cactus_sobel.png', 1)

px1, py1, px2, py2 = 270, 600, 334, 664
res = img[px1:px2, py1:py2]
cv2.rectangle(img, (px1, py1), (px2, py2), (0, 255, 0), 4)

px1, py1, px2, py2 = 750, 480, 814, 544
res = img[px1:px2, py1:py2]
cv2.rectangle(img, (px1, py1), (px2, py2), (0, 255, 0), 4)

px1, py1, px2, py2 = 964, 152, 1028, 216
res = img[px1:px2, py1:py2]
cv2.rectangle(img, (px1, py1), (px2, py2), (0, 255, 0), 4)

#res = img[px1:px2, py1:py2]
#cv2.rectangle(img, (px1, py1), (px2, py2), (0, 255, 0))
#cv2.imshow("res", res)
img = cv2.resize(img, None, fx=0.5, fy=0.5, interpolation=cv2.INTER_CUBIC)
cv2.imshow("img", img)
cv2.waitKey(0)
cv2.destroyAllWindows()
