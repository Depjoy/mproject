#读取Text文件的内容
f1=read.table("E:\\Daily\\01_R\\RLearn\\data1.txt")
print(f1)

#读取空格分割的prn文件
f2<-read.table("E:\\Daily\\01_R\\RLearn\\data2.prn",header=T)
print(f2)


#读取剪切板中文本、excel文件的内容
#复制之后不要再执行选中代码行运行代码
f4<-read.table("clipboard",header=T)
print(f4)
f5<-read.table("clipboard",header=F)
print(f5)

#读取excel文件数据
#RODBC只支持32位，读取的excel不可以是xlsx格式的可以另存为xls的格式来进行读取                       failed?????????????? 32bit
library(RODBC)
x1<-odbcConnectExcel("E:\\Daily\\01_R\\RLearn\\data4.xls")
f6<-sqlFetch(x1,"Sheet1")
print(f6)

f7=read.table("E:\\Daily\\01_R\\RLearn\\data4.xls",header=F)
print(f7)



