import cv2
import numpy as np
from matplotlib import pyplot as plt


def gx(row):
    for i in range(1, len(row)-1):
        row[i] = (row(i-1) + row(i+1)) / 2.0
        row[0] = 0.0
        row[-1] = 0.0
    # return row


def calc_gradient(window=8):
    img = cv2.imread("sea_floor_1.jpg", 0)
    img2 = cv2.normalize(img.astype('float'), None, 0.0, 1.0, cv2.NORM_MINMAX)

    for row in range(0, img2.rows):
        gx(row)


    plt.subplot(1, 1, 1)
    plt.imshow(img, cmap='gray')
    plt.show()


if __name__ == "__main__":
    calc_gradient()
