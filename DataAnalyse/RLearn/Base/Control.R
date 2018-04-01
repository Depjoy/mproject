#循环语句
a=0		#如果没有此处定义，报Error in print(a):找不到对象'a'错误
b=0         #如果没有此处定义，报Error in print(a):找不到对象'a'错误
for(i in 1:10){
    a[i]=i**2;
    b[i]=i*5-4
}
print(a)
print(b)