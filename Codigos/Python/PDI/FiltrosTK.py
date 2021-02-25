import random
from tkinter import Button, Label, Radiobutton, StringVar, Tk
from tkinter.filedialog import askopenfilename

import imutils
import numpy as np
from cv2 import cv2
from matplotlib import pyplot as plt
from PIL import Image as Img
from PIL import ImageTk
from scipy import ndimage
from skimage import filters
from skimage.feature import peak_local_max
from skimage.segmentation import watershed


def show_img(edged):
	global panelB
	if panelB is None:
		panelB = Label(image=edged)
		panelB.image = edged
		panelB.pack(side="right", padx=10, pady=10)
	else:
		panelB.configure(image=edged)
		panelB.image = edged

def zeroCross():
	image = imageInit
	image = grayScale()
	LoG = cv2.Laplacian(image, cv2.CV_16S)

	minLoG = cv2.morphologyEx(LoG, cv2.MORPH_ERODE, np.ones((2,2)))
	maxLoG = cv2.morphologyEx(LoG, cv2.MORPH_DILATE, np.ones((2,2)))

	edged = (np.logical_or(np.logical_and(minLoG < 0,  LoG > 0), np.logical_and(maxLoG > 0, LoG < 0)) * 255).astype('uint8')
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def grayScale():
	image = imageInit

	gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) 
	show_img(ImageTk.PhotoImage(Img.fromarray(cv2.cvtColor(gray, cv2.COLOR_RGB2BGR))))
	return gray

def threshold():
	ret, imthresh = cv2.threshold(grayScale(), 127, 255, cv2.THRESH_BINARY)
	show_img(ImageTk.PhotoImage(Img.fromarray(cv2.cvtColor(imthresh, cv2.COLOR_RGB2BGR))))
	return cv2.cvtColor(imthresh, cv2.COLOR_BGR2RGB)

def thresholdI():
	ret, imthresh = cv2.threshold(grayScale(), 127, 255, cv2.THRESH_BINARY_INV)
	show_img(ImageTk.PhotoImage(Img.fromarray(cv2.cvtColor(imthresh, cv2.COLOR_RGB2BGR))))
	return cv2.cvtColor(imthresh, cv2.COLOR_BGR2RGB)

def canny():
	edged = cv2.Canny(grayScale(), 50, 100)
	show_img(ImageTk.PhotoImage(Img.fromarray(cv2.cvtColor(edged, cv2.COLOR_RGB2BGR))))

def sobel():
	image = imageInit

	img_sobelx = cv2.Sobel(image,cv2.CV_8U,1,0,ksize=5)
	img_sobely = cv2.Sobel(image,cv2.CV_8U,0,1,ksize=5)
	edged = img_sobelx + img_sobely

	#edged = cv2.Sobel(image, cv2.CV_8U, 0, 1, ksize=3)
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def highpassB():
	image = imageInit
	image = grayScale()

	edged = image - cv2.GaussianBlur(image, (0,0),3)+127
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))
	return edged

def highpassAR():
	image = imageInit
	image = grayScale()

	reforco = 1.7
	edged = (image * (reforco - 1)).astype('uint8')  + (image - cv2.GaussianBlur(image, (0,0),3)+127)
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def lowpassB():
	image = imageInit
	image = threshold()

	edged = cv2.GaussianBlur(image, (0, 0), 3)
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def lowpassM():
	image = imageInit
	image = threshold()

	edged = cv2.medianBlur(image, 9)
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def prewitt():
	image = imageInit
	image = grayScale()

	edged_gaussian = cv2.GaussianBlur(image,(3,3),0)

	
	kernelx = np.array([[1,1,1],[0,0,0],[-1,-1,-1]])
	kernely = np.array([[-1,0,1],[-1,0,1],[-1,0,1]])
	img_prewittx = cv2.filter2D(edged_gaussian, -1, kernelx)
	img_prewitty = cv2.filter2D(edged_gaussian, -1, kernely)

	edged = img_prewittx + img_prewitty
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def log():
	image = imageInit
	image = grayScale()
	edged = cv2.Laplacian(image, cv2.CV_16S)

	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def sp():
	edged = grayScale()
	row , col = edged.shape

	number_of_pixels = random.randint(300,10000)
	for i in range(number_of_pixels): 
		y = random.randint(0, row - 1) 
		x = random.randint(0, col - 1)           
		edged[y][x] = 255

	number_of_pixels = random.randint(300,10000)
	for i in range(number_of_pixels): 
		y = random.randint(0, row - 1) 
		x = random.randint(0, col - 1)           
		edged[y][x] = 0

	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def watershedf():
	image = threshold()

	D = ndimage.distance_transform_edt(image)
	localMax = peak_local_max(D, indices=False, min_distance=20, labels=image)

	markers = ndimage.label(localMax, structure=np.ones((3, 3)))[0]
	labels = watershed((-1)*D, markers, mask=image)

	original_image = image

	for label in np.unique(labels):
		# if the label is zero, we are examining the 'background'
		# so simply ignore it
		if label == 0:
			continue
		# otherwise, allocate memory for the label region and draw
		# it on the mask
		mask = np.zeros(image.shape, dtype="uint8")
		mask[labels == label] = 255
		# detect contours in the mask and grab the largest one
		cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,
			cv2.CHAIN_APPROX_SIMPLE)
		cnts = imutils.grab_contours(cnts)
		c = max(cnts, key=cv2.contourArea)
		# draw a circle enclosing the object
		((x, y), r) = cv2.minEnclosingCircle(c)
		cv2.circle(original_image, (int(x), int(y)), int(r), (0, 255, 0), 2)
		cv2.putText(original_image, "#{}".format(label), (int(x) - 10, int(y)),
			cv2.FONT_HERSHEY_SIMPLEX, 0.6, (0, 0, 255), 2)
		
	image = original_image
	show_img(ImageTk.PhotoImage(Img.fromarray(image)))

def roberts():
	image = grayScale()

	roberts_cross_v = np.array([[ 0, 0, 0 ], [ 0, 1, 0 ], [ 0, 0,-1 ]])
	roberts_cross_h = np.array([[ 0, 0, 0 ], [ 0, 0, 1 ], [ 0,-1, 0 ]])

	vertical = ndimage.convolve( image, roberts_cross_v )
	horizontal = ndimage.convolve( image, roberts_cross_h )
	edged = np.sqrt( np.square(horizontal) + np.square(vertical))
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

def histograma():
	image = grayScale()

	equ = cv2.equalizeHist(image)
	res = np.hstack((image,equ)) 

	plt.hist(image.ravel(),256,[0,256])
	plt.hist(res.ravel(),256,[0,256])
	plt.ion()
	plt.show()
	"""
		bgr_planes = cv2.split(image)
		histSize = 256
		histRange = (0, 256) # the upper boundary is exclusive
		accumulate = False
		b_hist = cv2.calcHist(bgr_planes, [0], None, [histSize], histRange, accumulate=accumulate)
		g_hist = cv2.calcHist(bgr_planes, [1], None, [histSize], histRange, accumulate=accumulate)
		r_hist = cv2.calcHist(bgr_planes, [2], None, [histSize], histRange, accumulate=accumulate)
		hist_w = 512
		hist_h = 400
		bin_w = int(round( hist_w/histSize ))
		histImage = np.zeros((hist_h, hist_w, 3), dtype=np.uint8)

		cv2.normalize(b_hist, b_hist, alpha=0, beta=hist_h, norm_type=cv2.NORM_MINMAX)
		cv2.normalize(g_hist, g_hist, alpha=0, beta=hist_h, norm_type=cv2.NORM_MINMAX)
		cv2.normalize(r_hist, r_hist, alpha=0, beta=hist_h, norm_type=cv2.NORM_MINMAX)

		for i in range(1, histSize):
			cv2.line(histImage, ( bin_w*(i-1), hist_h - int(b_hist[i-1]) ),
					( bin_w*(i), hist_h - int(b_hist[i]) ),
					( 255, 0, 0), thickness=2)
			cv2.line(histImage, ( bin_w*(i-1), hist_h - int(g_hist[i-1]) ),
					( bin_w*(i), hist_h - int(g_hist[i]) ),
					( 0, 255, 0), thickness=2)
			cv2.line(histImage, ( bin_w*(i-1), hist_h - int(r_hist[i-1]) ),
					( bin_w*(i), hist_h - int(r_hist[i]) ),
					( 0, 0, 255), thickness=2)

		
		#show_img(ImageTk.PhotoImage(Img.fromarray(histImage)))
		cv2.imshow('calcHist Demo', histImage)
		cv2.waitKey()
	"""

def select_image():
	# grab a reference to the image panels
	global panelA, panelB, imageInit
	# open a file chooser dialog and allow the user to select an input
	# image
	path = askopenfilename()


    # ensure a file path was selected
	if len(path) > 0:
		# load the image from disk, convert it to grayscale, and detect
		# edges in it
		image = cv2.imread(path)
		image = cv2.resize(image, (640, 480))

		imageInit = image
		# OpenCV represents images in BGR order; however PIL represents
		# images in RGB order, so we need to swap the channels
		image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
		# convert the images to PIL format...
		image = Img.fromarray(image)
		# ...and then to ImageTk format
		image = ImageTk.PhotoImage(image)


        # if the panels are None, initialize them
		if panelA is None or panelB is None:
			# the first panel will store our original image
			panelA = Label(image=image)
			panelA.image = image
			panelA.pack(side="left", padx=10, pady=10)
			
		# otherwise, update the image panels
		else:
			# update the pannels
			panelA.configure(image=image)
			panelA.image = image

	

# initialize the window toolkit along with the two image panels
root = Tk()
root.title("Filtros")
panelA = None
panelB = None

btn_waltershed = Button(root, text="Contagem de Objetos",command=watershedf)
btn_waltershed.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_histograma = Button(root, text="Histograma",command=histograma)
btn_histograma.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_waltershed = Button(root, text="Watershed",command=watershedf)
btn_waltershed.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_SP = Button(root, text="Salt & Pepper",command=sp)
btn_SP.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_canny = Button(root, text="Canny",command=canny)
btn_canny.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_zeroCross = Button(root, text="Zero Cross",command=zeroCross)
btn_zeroCross.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_log = Button(root, text="Log",command=log)
btn_log.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_sobel = Button(root, text="Sobel",command=sobel)
btn_sobel.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_prewitt = Button(root, text="Prewitt",command=prewitt)
btn_prewitt.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_roberts = Button(root, text="Roberts",command=roberts)
btn_roberts.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_lowpassM = Button(root, text="Passa Baixa - Mediana",command=lowpassM)
btn_lowpassM.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_lowpassB = Button(root, text="Passa Baixa - Média",command=lowpassB)
btn_lowpassB.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_highpassAR = Button(root, text="Passa Alta - Alto Reforço",command=highpassAR)
btn_highpassAR.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_highpassB = Button(root, text="Passa Alta - Basico",command=highpassB)
btn_highpassB.pack(side="bottom", fill="both", expand="yes", padx="10") 

btn_grayScale = Button(root, text="Escala de Cinza",command=grayScale)
btn_grayScale.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_thresholdI = Button(root, text="Threshold Invertido",command=thresholdI)
btn_thresholdI.pack(side="bottom", fill="both", expand="yes", padx="10")

btn_threshold = Button(root, text="Threshold",command=threshold)
btn_threshold.pack(side="bottom", fill="both", expand="yes", padx="10")




# create a button, then when pressed, will trigger a file chooser
# dialog and allow the user to select an input image; then add the
# button the GUI
btn = Button(root, text="Select an image", command=select_image)
btn.pack(side="bottom", fill="both", expand="yes", padx="10")
# kick off the GUI
root.mainloop()
