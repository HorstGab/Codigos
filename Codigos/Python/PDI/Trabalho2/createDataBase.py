from cv2 import cv2
import numpy as np
import sys
import os

#carrega o arquivo com as informações de classificação
face_cascate = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

# captura os argumentos 
arg = sys.argv
os.makedirs(arg[1])

    
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

        # try:
            #salva a imagem da região detectada
        cv2.imwrite(arg[1] + "/facetoframe%d.jpg" %count, crop)
        print("facetoframe%d.jpg salvo!" %count)
        # except OSError:
            # print ("Erro ao salvar imagem")
        
    
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
            faceDetection(frame, count)
            count += 1
        

if __name__ == '__main__':
    extractFrames(arg[1] +'.mp4')     
    print ("Done!")