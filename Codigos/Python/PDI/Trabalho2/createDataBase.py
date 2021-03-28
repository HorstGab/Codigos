from cv2 import cv2
import numpy as np
import sys

#carrega o arquivo com as informações de classificação
face_cascate = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

class DataBase:
    
    def faceDetection (self, count):
        #pega o frame 
        img = self
        #cconverte para escalas de cinza
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        #realiza a detecção e retorna os valores da localização do rosto
        faces = face_cascate.detectMultiScale(gray, 1.3, 5)

            
        for(x,y,w,h) in faces:
            #guarda apenas as informações classificadas como face
            crop = img[y:y+h, x: x+w]

            #salva a imagem da região detectada
            cv2.imwrite("facetoframe%d.jpg" %count, crop)
            if cv2.waitKey(10) == 27:
                break


    def extractFrames(self):
        #abrir o arquivo de video
        capturaVideo = cv2.VideoCapture(self)

        # lê o primeiro frame e retorna um bool se foi lido corretamente 
        retval, frame = capturaVideo.read()

        #contador de frames
        count = 0
        while retval:
            #lê os frames restantes a cada interação
            retval, frame = capturaVideo.read()
            
            if frame is not None:
                #a cada frame realiza a detecção da face
                DataBase.faceDetection(frame, count)
                count += 1
            else :
                break

            



DataBase.extractFrames('libras1.mp4')     
