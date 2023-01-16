""" PY TO ESP (LED CONTROLLER) """
# Written by Junicchi - https://github.com/Kebablord

import urllib.request
import numpy as np
import time
import cv2

face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

root_url = "http://192.168.77.106"  # ESP's url, ex: http://192.168.102 (Esp prints it to serial console when connected to wifi)

cap = cv2.VideoCapture(0)

while True:
	ret, img = cap.read()
#	cv2.rectangle(img,(250, 180),(400,350),(255,0,0),5)
	cv2.rectangle(img,(240,170),(400,330),(255,0,255),3)

	gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
	faces = face_cascade.detectMultiScale(gray,1.1, 10)

	for (x,y,w,h) in faces:
		cv2.rectangle(img,(x,y),(x+w,y+h),(255,255,0),1)
		center = (x+w/2, y+h/2)
		cv2.circle(img,(int(x+w/2), int(y+h/2)),(5),(0,0,255),-1)
		#print(z)
		if center <= (214, 480):
			fnt = cv2.FONT_HERSHEY_SIMPLEX
			cv2.putText(img,("LEFT:"),(0,40),fnt,1,(0,0,255),2)
			try:
				urllib.request.urlopen(root_url+"/LEFT")
				print("GOING LEFT!\n\n")
			except Exception as e :
				pass

		if center[0] > (428):
			fnt = cv2.FONT_HERSHEY_SIMPLEX
			cv2.putText(img,("RIGHT:"),(0,40),fnt,1,(0,0,255),2)
			try:
				urllib.request.urlopen(root_url+"/RIGHT")
				print("GOING RIGHT!\n\n")
			except Exception as e :
				pass

		if center[1] < (170) :
			fnt = cv2.FONT_HERSHEY_SIMPLEX
			cv2.putText(img,("FORWARD:"),(0,40),fnt,1,(0,0,255),2)
			try:	
				urllib.request.urlopen(root_url+"/FORWARD")
				print("GOING FORWARD!\n\n")
			except Exception as e :
				pass

		if center[1] > (330):
			fnt = cv2.FONT_HERSHEY_SIMPLEX
			cv2.putText(img,("BACKWARD:"),(0,40),fnt,1,(0,0,255),2)
			try:
				urllib.request.urlopen(root_url+"/BACKWARD")
				print("GOING BACKWARD!\n\n")
			except Exception as e :
				pass

		if (center > (214, 480)) and (center[0] < (428)) and (center[1] > (170)) and (center[1] < (330)):
			fnt = cv2.FONT_HERSHEY_SIMPLEX
			cv2.putText(img,("CENTER:"),(0,40),fnt,1,(0,0,255),2)
			try:
				urllib.request.urlopen(root_url+"/CENTER")
				print("ENGINE OFF!\n\n")
			except Exception as e :
				pass		

	cv2.imshow('img', img)

	if cv2.waitKey(1) & 0xff == ord('q'):
		break

cap.release()
cv2.destroyAllWindows()
