import PySimpleGUI as sg
from cv2 import cv2
import numpy as np
from PIL import Image, ImageTk
import io


def main():
    def abrirImg():
        file = sg.popup_get_file('Image to open', save_as=False, file_types = ((".png", ".jpg", "jpeg", ".tiff", ".bmp"),))

        if not file:
            sg.popup_cancel('Cancelling')
            raise SystemExit()
        return file

    def get_img_data(f, maxsize=(400, 300), first=False):
        img = Image.open(f)
        img.thumbnail(maxsize)
        if first:                     # tkinter is inactive the first time
            bio = io.BytesIO()
            img.save(bio, format="PNG")
            del img
            return bio.getvalue()
        return ImageTk.PhotoImage(img)


    sg.theme('LightGreen')
    filename = abrirImg()
    frame = sg.Image(data=get_img_data(filename, first=True), key='-IMAGE-')

    # define the window layout
    layout = [
      [sg.Text('OpenCV Demo', size=(60, 1), justification='center')],
      [frame],
      [sg.Radio('None', 'Radio', True, size=(10, 1))],
      [sg.Radio('threshold', 'Radio', size=(10, 1), key='-THRESH-'),
       sg.Slider((0, 255), 128, 1, orientation='h', size=(40, 15), key='-THRESH SLIDER-')],
      [sg.Radio('canny', 'Radio', size=(10, 1), key='-CANNY-'),
       sg.Slider((0, 255), 128, 1, orientation='h', size=(20, 15), key='-CANNY SLIDER A-'),
       sg.Slider((0, 255), 128, 1, orientation='h', size=(20, 15), key='-CANNY SLIDER B-')],
      [sg.Radio('blur', 'Radio', size=(10, 1), key='-BLUR-'),
       sg.Slider((1, 11), 1, 1, orientation='h', size=(40, 15), key='-BLUR SLIDER-')],
      [sg.Radio('hue', 'Radio', size=(10, 1), key='-HUE-'),
       sg.Slider((0, 225), 0, 1, orientation='h', size=(40, 15), key='-HUE SLIDER-')],
      [sg.Radio('enhance', 'Radio', size=(10, 1), key='-ENHANCE-'),
       sg.Slider((1, 255), 128, 1, orientation='h', size=(40, 15), key='-ENHANCE SLIDER-')],
      [sg.Button('Exit', size=(10, 1))]
    ]

    # create the window and show it without the plot
    window = sg.Window('OpenCV Integration', layout)

    #cap = cv2.VideoCapture(0)

    while True:
        event, values = window.read(timeout=20)
        if event == 'Exit' or event == sg.WIN_CLOSED:
            break

        #ret, frame = cap.read()

        if values['-THRESH-']:
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2LAB)[:, :, 0]
            frame = cv2.threshold(frame, values['-THRESH SLIDER-'], 255, cv2.THRESH_BINARY)[1]
        elif values['-CANNY-']:
            frame = cv2.Canny(frame, values['-CANNY SLIDER A-'], values['-CANNY SLIDER B-'])
        elif values['-BLUR-']:
            frame = cv2.GaussianBlur(frame, (21, 21), values['-BLUR SLIDER-'])
        elif values['-HUE-']:
            frame = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
            frame[:, :, 0] += int(values['-HUE SLIDER-'])
            frame = cv2.cvtColor(frame, cv2.COLOR_HSV2BGR)
        elif values['-ENHANCE-']:
            enh_val = values['-ENHANCE SLIDER-'] / 40
            clahe = cv2.createCLAHE(clipLimit=enh_val, tileGridSize=(8, 8))
            lab = cv2.cvtColor(frame, cv2.COLOR_BGR2LAB)
            lab[:, :, 0] = clahe.apply(lab[:, :, 0])
            frame = cv2.cvtColor(lab, cv2.COLOR_LAB2BGR)

        imgbytes = cv2.imencode('.png', frame)[1]
        window['-IMAGE-'].update(data=imgbytes)

    window.close()


main()