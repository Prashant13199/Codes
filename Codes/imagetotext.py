import pytesseract
import cv2

pytesseract.pytesseract.tesseract_cmd = r'/usr/local/Cellar/tesseract/4.1.1/bin/tesseract'

img = cv2.imread('img1.png')
text= pytesseract.image_to_string(img)
f = open('file.txt','w')
f.write(text)
f.close()

# print(text)