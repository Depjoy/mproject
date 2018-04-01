import xlrd
import numpy
import matplotlib.pyplot

data=xlrd.open_workbook("./data.xls")
'''
get sheet data by name or index
equal to sheet=data.sheet_by_name("Sheet1")
equal to sheet=data.sheets()[0]
'''
sheet=data.sheet_by_index(0)
col=sheet.col_values(0)
cell_r10_c8 =sheet.cell(9,8)
print(cell_r10_c8,cell_r10_c8.value)
rows=sheet.row_values(1)[1:9]
print("Data at 1 column with index of 1-9 :{0}".format(rows))
cols=sheet.col_values(1)[1:9]
print ("Data at 0 column with index of 1-9 :{0}".format(cols))

row0=sheet.row_values(0)
row1=sheet.row_values(1)
print(row0)
print (row1)
col0=sheet.col_values(0)
col1=sheet.col_values(1)

figure=matplotlib.pyplot.figure(1,figsize=(12,16))
matplotlib.pyplot.plot(row0,row1,"g--",label="y=x^2+1")
matplotlib.pyplot.plot(col0,col1,"r-.",label="y=2x")
matplotlib.pyplot.xlabel("X")
matplotlib.pyplot.ylabel("Y")
matplotlib.pyplot.legend()
matplotlib.pyplot.title("Read Excle and Plot")

figure=matplotlib.pyplot.figure(2,figsize=(12,16))
matplotlib.pyplot.subplot(211)
matplotlib.pyplot.plot(row0,row1,"y--",label="y=x^2+1")
matplotlib.pyplot.subplot(212)
matplotlib.pyplot.plot(col0,col1,"b-.",label="y=2x")
matplotlib.pyplot.xlabel("X")
matplotlib.pyplot.ylabel("Y")
matplotlib.pyplot.legend()
matplotlib.pyplot.title("Read Excle and Plot in difference plots")
matplotlib.pyplot.xlim(0,10)
matplotlib.pyplot.ylim(0,20)

figure=matplotlib.pyplot.figure(3,figsize=(12,16))
matplotlib.pyplot.plot(row0,row1,"o",label="y=x^2+1")
matplotlib.pyplot.xlabel("X")
matplotlib.pyplot.ylabel("Y")
matplotlib.pyplot.legend()
matplotlib.pyplot.title("Read Excle and Plot in scatter")

matplotlib.pyplot.show()
#matplotlib.pyplot.savefig("./excelDataPlot.png",dpi=600)  #failed witout picture