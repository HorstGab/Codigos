# import the necessary packages
from tkinter import Button, Label, Radiobutton, StringVar, Tk
from tkinter.filedialog import askopenfilename

import numpy as np
from cv2 import cv2
from PIL import Image as Img
from PIL import ImageTk
from skimage import filters


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

	LoG = cv2.Laplacian(image, cv2.CV_16S)

	minLoG = cv2.morphologyEx(LoG, cv2.MORPH_ERODE, np.ones((3,3)))
	maxLoG = cv2.morphologyEx(LoG, cv2.MORPH_DILATE, np.ones((3,3)))

	edged = (np.logical_or(np.logical_and(minLoG < 0,  LoG > 0), np.logical_and(maxLoG > 0, LoG < 0)) * 255).astype('uint8')
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))


def grayScale():
	image = imageInit

	gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) 
	show_img(ImageTk.PhotoImage(Img.fromarray(cv2.cvtColor(gray, cv2.COLOR_RGB2BGR))))
	return gray

def threshold():
	image = imageInit

	ret, imthresh = cv2.threshold(image, 127, 255, cv2.THRESH_BINARY)
	show_img(ImageTk.PhotoImage(Img.fromarray(cv2.cvtColor(imthresh, cv2.COLOR_RGB2BGR))))

def canny():
	edged = cv2.Canny(grayScale(), 50, 100)
	show_img(ImageTk.PhotoImage(Img.fromarray(cv2.cvtColor(edged, cv2.COLOR_RGB2BGR))))

def sobel():
	image = imageInit

	edged = cv2.Sobel(image, cv2.CV_8U, 0, 1, ksize=3)
	show_img(ImageTk.PhotoImage(Img.fromarray(edged)))

 

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
		#gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
		#edged = cv2.Canny(gray, 50, 100)
		# OpenCV represents images in BGR order; however PIL represents
		# images in RGB order, so we need to swap the channels
		image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
		# convert the images to PIL format...
		image = Img.fromarray(image)
		#edged = Img.fromarray(edged)
		# ...and then to ImageTk format
		image = ImageTk.PhotoImage(image)
		#edged = ImageTk.PhotoImage(edged)


        # if the panels are None, initialize them
		if panelA is None or panelB is None:
			# the first panel will store our original image
			panelA = Label(image=image)
			panelA.image = image
			panelA.pack(side="left", padx=10, pady=10)
			# while the second panel will store the edge map
			#panelB = Label(image=edged)
			#panelB.image = edged
			#panelB.pack(side="right", padx=10, pady=10)
		# otherwise, update the image panels
		else:
			# update the pannels
			panelA.configure(image=image)
			#panelB.configure(image=edged)
			panelA.image = image
			#panelB.image = edged   

	

# initialize the window toolkit along with the two image panels
root = Tk()
root.title("Filtros")
panelA = None
panelB = None


btn_canny = Button(root, text="Canny",command=canny)
btn_canny.pack(side="bottom", fill="both", expand="yes", padx="10", pady="10")

btn_zeroCross = Button(root, text="Zero Cross",command=zeroCross)
btn_zeroCross.pack(side="bottom", fill="both", expand="yes", padx="10", pady="10")

btn_sobel = Button(root, text="Sobel",command=sobel)
btn_sobel.pack(side="bottom", fill="both", expand="yes", padx="10", pady="10")

btn_grayScale = Button(root, text="Escala de Cinza",command=grayScale)
btn_grayScale.pack(side="bottom", fill="both", expand="yes", padx="10", pady="10")

btn_threshold = Button(root, text="Threshold",command=threshold)
btn_threshold.pack(side="bottom", fill="both", expand="yes", padx="10", pady="10")




# create a button, then when pressed, will trigger a file chooser
# dialog and allow the user to select an input image; then add the
# button the GUI
btn = Button(root, text="Select an image", command=select_image)
btn.pack(side="bottom", fill="both", expand="yes", padx="10", pady="10")
# kick off the GUI
root.mainloop()
