#/home/gabriel/Documentos/GitHub/Codigos/Codigos/Python/PDI
import PySimpleGUI as sg
import os
from PIL import Image, ImageTk
import io

# Get the folder containin:g the images from the user
folder = sg.popup_get_folder('Image folder to open', default_path='')
if not folder:
    sg.popup_cancel('Cancelling')
    raise SystemExit()


# PIL supported image types
img_types = (".png", ".jpg", "jpeg", ".tiff", ".bmp")



def get_img_data(f, maxsize=(800, 600), first=False):
    """Generate image data using PIL
    """
    img = Image.open(f)
    img.thumbnail(maxsize)
    if first:                     # tkinter is inactive the first time
        bio = io.BytesIO()
        img.save(bio, format="PNG")
        del img
        return bio.getvalue()
    return ImageTk.PhotoImage(img)
# ------------------------------------------------------------------------------

filename = os.path.join(folder) 
image_elem = sg.Image(data=get_img_data(filename, first=True))
filename_display_elem = sg.Text(filename, size=(80, 3))

window = sg.Window('Image Browser', return_keyboard_events=True,
                   location=(0, 0), use_default_focus=False)

window.close()