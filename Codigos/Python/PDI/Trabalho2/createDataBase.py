from cv2 import cv2
import numpy as np

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
        #salva em um arquivo jpg cada frame
        cv2.imwrite("frame%d.jpg" %count, frame)

        if cv2.waitKey(10) == 27:
            break
        count += 1

def faceDetection (self):
    #carrega o arquivo com as informações de classificação
    face_cascate = cv2.CascadeClassifier('haarcascade_frontalface_default.xml')

    #enquanto houver frames
    #ESSE WHILE TALVEZ SEJA DESNECESSÁRIO KKKKK
    while True:
        #lê o frame 
        img = cv2.imread(self)
        #cconverte para escalas de cinza
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        #realiza a detecção e retorna os valores da localização do rosto
        faces = face_cascate.detectMultiScale(gray, 1.3, 5)

        #
        for(x,y,w,h) in faces:
            #guarda apenas as informações classificadas como face
            crop = img[y:y+h, x: x+w]
            #traça um box na região classificada como face
            img = cv2.rectangle(img, (x,y), (x+w, y+h), (255,0,0),2)

            #salva a imagem da região detectada
            cv2.imwrite("face.jpg", crop)
        
    
    #plota a imagem original com o box na região detectada
    cv2.imshow("img",img)
    cv2.waitKey(0)
    cv2.destroyAllWindows()


#extractFrames('libras.mp4')
#faceDetection('lula.jpg')