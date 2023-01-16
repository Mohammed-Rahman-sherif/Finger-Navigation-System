import cv2
import urllib.request
import numpy as np
import HandTrackingModule as htm
import time

##########################
wCam, hCam = 1080, 1080
frameR = 100 # Frame Reduction
smoothening = 7
#########################

pTime = 0
plocX, plocY = 0, 0
clocX, clocY = 0, 0

root_url = "http://192.168.146.106"

cap = cv2.VideoCapture(0)
detector = htm.handDetector(maxHands=1)

while True:
    try:
        success, img = cap.read()
        img = cv2.resize(img, (1080, 900))
        cv2.rectangle(img, (400, 250), (650, 500),
        (255, 100, 255), 2)

        #cTime = time.time()
        #fps = 1 / (cTime - pTime)
        #pTime = cTime
        #cv2.putText(img, str(int(fps)), (20, 50), cv2.FONT_HERSHEY_PLAIN, 3,
        #(255, 0, 0), 3)

        img = detector.findHands(img)
        lmList, bbox = detector.findPosition(img)
        a1, b1 = lmList[8][1:]
        #cv2.putText(img, ("a1: " + str(int(a1))), (20, 80), cv2.FONT_HERSHEY_PLAIN, 1,(255, 0, 0), 1)
        #cv2.putText(img, ("b1: " + str(int(b1))), (20, 100), cv2.FONT_HERSHEY_PLAIN, 1,(255, 0, 0), 1)

        if len(lmList) != 0:
            x1, y1 = lmList[8][1:]
            #print(x1, y1)
            cv2.circle(img, (x1, y1), 15, (255, 0, 255), cv2.FILLED)
        #fingers = detector.fingersUp()
        # print(fingers) 

        if b1 < 250:# and b1 > 500:
            fnt = cv2.FONT_HERSHEY_SIMPLEX
            cv2.putText(img,("FORWARD:"),(470,40),fnt,1,(0,0,255),2)
            try:    
                urllib.request.urlopen(root_url+"/FORWARD")
                #print("GOING FORWARD!\n\n")
            except Exception as e :
                pass

        elif b1 > 500: #b1 < 250: and b1 > 500:
            fnt = cv2.FONT_HERSHEY_SIMPLEX
            cv2.putText(img,("BACKWARD:"),(470,40),fnt,1,(0,0,255),2)
            try:
                urllib.request.urlopen(root_url+"/BACKWARD")
                #print("GOING BACKWARD!\n\n")
            except Exception as e :
                pass

        elif a1 > 650:# and b1 < 250:# and b1 > 500:
            if b1 > 250:
                fnt = cv2.FONT_HERSHEY_SIMPLEX
                cv2.putText(img,("LEFT:"),(470,40),fnt,1,(0,0,255),2)
                try:
                    urllib.request.urlopen(root_url+"/LEFT")
                    #print("GOING LEFT!\n\n")
                except Exception as e :
                    pass
 
        elif a1 < 400:# and b1 < 250:# and b1 > 500:
            if b1 > 250:
                fnt = cv2.FONT_HERSHEY_SIMPLEX
                cv2.putText(img,("RIGHT:"),(470,40),fnt,1,(0,0,255),2)
                try:
                    urllib.request.urlopen(root_url+"/RIGHT")
                    #print("GOING RIGHT!\n\n")
                except Exception as e :
                    pass

        else:
            fnt = cv2.FONT_HERSHEY_SIMPLEX
            cv2.putText(img,("CENTER:"),(470,40),fnt,1,(0,0,255),2)
            try:
                urllib.request.urlopen(root_url+"/CENTER")
                #print("ENGINE OFF!\n\n")
            except Exception as e :
                pass

    except Exception as e :
        pass
    
    cv2.imshow("Image", img)
    if cv2.waitKey(100) & 0xff == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()