import numpy
import random
from PIL import Image 
from imageio import imwrite, imread


def SimpleCountingSort(A):
    scope = max(A) + 1
    C = [0] * scope
    for x in A:
        C[x] += 1
    med=len(A)//2
    foundd=0
    left=0
    for i in range(scope):
        left=left+C[i]
        if left>med:
            return i


def srednee(H):
    l0=[]
    l1=[]
    l2=[]
    for i in H:
        l0.append(i[0])
        l1.append(i[1])
        l2.append(i[2])
    m0=SimpleCountingSort(l0)
    m1=SimpleCountingSort(l1)
    m2=SimpleCountingSort(l2)
    mm=[m0,m1,m2]
    return numpy.array(mm)


def median_filter(data, filter_size):
    temp = []
    lst = numpy.array([0,0,0,0]) 
    indexer = filter_size // 2

    data_final = []
    data_final = data
    for i in range(len(data)):
        for j in range(len(data[0])):
            for z in range(filter_size):
                if i + z - indexer < 0 or i + z - indexer > len(data) - 1:
                    for c in range(filter_size):
                        temp.append(lst)
                else:
                    if j + z - indexer < 0 or j + indexer > len(data[0]) - 1:
                        temp.append(lst)
                    else:
                        for k in range(filter_size):
                            temp.append(data[i + z - indexer][j + k - indexer])
            data_final[i][j] = srednee(temp)
            temp = []
    return data_final


def main():
    im=Image.open("1.bmp")
    arr = numpy.array(im)
    hh = arr.astype(numpy.uint8)
    removed_noise = median_filter(hh, 3) 
    img = Image.fromarray(removed_noise, 'RGB')
    imwrite('2.bmp', numpy.array(removed_noise))
main()
