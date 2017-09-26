#!/opt/local/bin/python
#-*- coding: utf-8 -*-

import cv2
import numpy as np
faceCascade = cv2.CascadeClassifier()
faceCascade.load('/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_alt.xml')
img = cv2.imread('red.jpg')
gray = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
faces = faceCascade.detectMultiScale(gray,scaleFactor = 1.1, minNeighbors = 2,minSize = (30,30),flags =cv2.CASCADE_SCALE_IMAGE)

print "Found {0} FACES!".format(len(faces))
for (x,y,w,h) in faces:
    cv2.rectangle(img,(x,y),(x+w,y+h),(0,255,0),2)

cv2.imshow('Face',img)
cv2.waitKey(0)
cv2.destroyWindows()
cv2.waitKey(1)


