import base64

# convert image to binary
with open("a.png", "rb") as imageFile:
    str = base64.b64encode(imageFile.read())
    print(str)

# convert binary to image
with open("imageToSave.png", "wb") as fh:
    fh.write(base64.decodebytes(str))