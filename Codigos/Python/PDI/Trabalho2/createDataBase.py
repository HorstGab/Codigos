from cv2 import cv2
import numpy as np
import sys
import os
from matplotlib import pyplot as plt

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

        lbp(crop, count)
      
        
    
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

        if cv2.waitKey(10) == 27:
            break
        
def get_pixel(img, center, x, y):
    value = 0

    try:
        if img[x][y]>=center:
            value=1
    except:pass
    return value

def lbp(img, count):
    height, width, _ = img.shape

    img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) 
    img_lbp = np.zeros((height, width),np.uint8)

    for i in range(0, height):
        for j in range(0, width):
            img_lbp[i, j] = lbp_Aux(img_gray, i, j)

    #salva a imagem da região detectada
    cv2.imwrite(arg[1] + "/facetoframe%d.jpg" %count, img_lbp)
    print("facetoframe(LBP)%d.jpg salvo!" %count)


def lbp_Aux(img, x, y):
    center = img[x][y]
    valueArray = []
    
    # top_left
    valueArray.append(get_pixel(img, center, x-1, y-1))
    # top
    valueArray.append(get_pixel(img, center, x-1, y))
    # top_right
    valueArray.append(get_pixel(img, center, x-1, y + 1))
    # right
    valueArray.append(get_pixel(img, center, x, y + 1))
    # bottom_right
    valueArray.append(get_pixel(img, center, x + 1, y + 1))
    # bottom
    valueArray.append(get_pixel(img, center, x + 1, y))
    # bottom_left
    valueArray.append(get_pixel(img, center, x + 1, y-1))
    # left
    valueArray.append(get_pixel(img, center, x, y-1))

    power_val = [1, 2, 4, 8, 16, 32, 64, 128]
   
    val = 0
      
    for i in range(len(valueArray)):
        val += valueArray[i] * power_val[i]
          
    return val

if __name__ == '__main__':
    extractFrames(arg[1] +'.mp4')     
    print ("Done!")