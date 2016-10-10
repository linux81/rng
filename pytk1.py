from Tkinter import *

import numpy as np

import matplotlib.pyplot as plt

#PATH=$PATH:$HOME/Dokumenty/test


import subprocess

master = Tk()


e1 = Entry(master)
e2 = Entry(master)
e3 = Entry(master)
e4 = Entry(master)



Label(master, text="Liczba wierszy").grid(row=0)
Label(master, text="Liczba kolumn").grid(row=1)
Label(master, text="Nr. algor.").grid(row=2)
Label(master, text="Nazwa pliku").grid(row=3)





e1.grid(row=0, column=1)
e2.grid(row=1, column=1)

e3.grid(row=2, column=1)
e4.grid(row=3, column=1)



def fun(a,b,c,d):
	z="rng2"
	e=z+" "+str(a)+" "+str(b)+" "+str(c)+" "+d
	return e



def gener():
	
	
	h=fun(e1.get(), e2.get(), e3.get(), e4.get())
	
	
	
	retcode = subprocess.call([h],shell=True)

def genimg():
	
	a=np.loadtxt(str(e4.get()))
	plt.imshow(a,cmap='gist_heat')
	plt.show()
	
	



Button(master, text='Quit', command=master.quit).grid(row=4, column=0, sticky=W, pady=4)
Button(master, text='Generate', command=gener).grid(row=4, column=1, sticky=W, pady=4)
Button(master, text='Gen img', command=genimg).grid(row=4, column=2, sticky=W, pady=4)

mainloop( )

