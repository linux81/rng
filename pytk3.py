from Tkinter import *

import numpy as np

import matplotlib.pyplot as plt

#PATH=$PATH:$HOME/Dokumenty/test
import test9



master = Tk()


e1 = Entry(master)
e2 = Entry(master)
e3 = Entry(master)
e4 = Entry(master)




Label(master, text="Liczba danych").grid(row=0)
Label(master, text="Nazwa pliku").grid(row=1)
Label(master, text="Liczba wierszy").grid(row=2)
Label(master, text="Liczba kolumn").grid(row=3)





e1.grid(row=0, column=1) #liczba danych
e2.grid(row=1, column=1) #nazwa pliku
e3.grid(row=2, column=1) #liczba wierszy
e4.grid(row=3, column=1) #liczba kolumn



def gener():
	
    f = open(str(e2.get()), 'w')


    for i in range(int(e1.get())):
	        a=test9.srd()
	 
	        z=str(a)
                f.write(z)
                f.write('\n')



    print(e1.get())
    print("Zrobione")

    f.close()

	 
	 

    

def genimg():
	
	a=np.loadtxt(str(e2.get()))

	
        if int(e3.get())*int(e4.get())!=int(e1.get()):
            print("zle dane wejsciowe")

        k=np.reshape(a,(int(e3.get()),int(e4.get())))
	plt.imshow(k,cmap='prism')
	plt.show()
	
	



Button(master, text='Quit', command=master.quit).grid(row=4, column=0, sticky=W, pady=4)
Button(master, text='Generate', command=gener).grid(row=4, column=1, sticky=W, pady=4)
Button(master, text='Generate img', command=genimg).grid(row=4, column=3, sticky=W, pady=4)

mainloop( )

