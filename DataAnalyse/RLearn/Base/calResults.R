#模拟产生统计专业同学名单（学号区分）
#记录数学分析、线性代数、概率论的成绩
#然后进行统计分析

#分布函数
#rnorm()正态分布函数
#rpois() 泊松分布函数
#rexp() 指数分布函数
#rgamma()Gamma分布函数
#runif()均匀分布函数
#rbinnorm()二项分布函数
#rgeom()几何分布函数

num=seq(7102001,7102100)				#学号
mathRes=round(runif(100,min=80,max=100))		#产生符合均匀分布的数学成绩，round函数进行取整
lineRes=round(rnorm(100,mean=80,sd=7))
probabilityRes=round(rnorm(100,mean=85,sd=18))
probabilityRes[which(probabilityRes>100)]=100

res=data.frame(num,mathRes,lineRes,probabilityRes)
#将学生的成绩信息保存到excel文件中
#col.names: 列名称,F表示无
#row.names: 行名称，F表示无
write.table(res,file="E:\\Daily\\01_R\\RLearn\\mark.txt",col.names=c('学号','数学分析','线性代数','概率论'),row.names=F,sep=" ")

print(colMeans(res))								      #对学号、各科的成绩均求平均值

colMean=colMeans(res[c("mathRes","lineRes","probabilityRes")])	      #计算各科的平均值
print(colMean)

applyMean=apply(res[c("mathRes","lineRes","probabilityRes")],2,mean)	#利用apply计算各科的平均成绩，其中第二个参数2-列参数 1-行参数
print(applyMean)

applySum=apply(res[c("mathRes","lineRes","probabilityRes")],1,sum)      #计算每个学生的总成绩
print(applySum)

max=apply(res[c("mathRes","lineRes","probabilityRes")],2,max)	      #查找单科最高成绩
print(max)

min=apply(res[c("mathRes","lineRes","probabilityRes")],2,min)           #查找单科最低成绩
print(min)

maxSum=max(applySum)	                                                #查找最高成绩
print(maxSum)

numMaxSum=res$num[which.max(apply(res[c("mathRes","lineRes","probabilityRes")],1,sum))]  #总成绩最高的学号
print(numMaxSum)						      

hist(res$mathRes)										#绘制数学成绩直方图
hist(#模拟产生统计专业同学名单（学号区分）
#记录数学分析、线性代数、概率论的成绩
#然后进行统计分析

#分布函数
#rnorm()正态分布函数
#rpois() 泊松分布函数
#rexp() 指数分布函数
#rgamma()Gamma分布函数
#runif()均匀分布函数
#rbinnorm()二项分布函数
#rgeom()几何分布函数

num=seq(7102001,7102100)				#学号
mathRes=round(runif(100,min=80,max=100))		#产生符合均匀分布的数学成绩，round函数进行取整
lineRes=round(rnorm(100,mean=80,sd=7))
probabilityRes=round(rnorm(100,mean=85,sd=18))
probabilityRes[which(probabilityRes>100)]=100

res=data.frame(num,mathRes,lineRes,probabilityRes)
#将学生的成绩信息保存到excel文件中
#col.names: 列名称,F表示无
#row.names: 行名称，F表示无
write.table(res,file="E:\\Daily\\01_R\\RLearn\\mark.txt",col.names=c('学号','数学分析','线性代数','概率论'),row.names=F,sep=" ")

print(colMeans(res))								      #对学号、各科的成绩均求平均值

colMean=colMeans(res[c("mathRes","lineRes","probabilityRes")])	      #计算各科的平均值
print(colMean)

applyMean=apply(res[c("mathRes","lineRes","probabilityRes")],2,mean)	#利用apply计算各科的平均成绩，其中第二个参数2-列参数 1-行参数
print(applyMean)

applySum=apply(res[c("mathRes","lineRes","probabilityRes")],1,sum)      #计算每个学生的总成绩
print(applySum)

max=apply(res[c("mathRes","lineRes","probabilityRes")],2,max)	      #查找单科最高成绩
print(max)

min=apply(res[c("mathRes","lineRes","probabilityRes")],2,min)           #查找单科最低成绩
print(min)

maxSum=max(applySum)	                                                #查找最高成绩
print(maxSum)

numMaxSum=res$num[which.max(apply(res[c("mathRes","lineRes","probabilityRes")],1,sum))]  #总成绩最高的学号
print(numMaxSum)						      

#默认只有一个活动窗口，如果绘制多个直方图，我们只能看到最后一个活跃的窗口
hist(res$mathRes)										#绘制数学成绩直方图
#hist(res$lineRes)
#hist(res$probabilityRes)

plot(num,mathRes)										#绘制学号和数学成绩的散点图
plot(res$num,res$mathRes)								#绘制学号和数学成绩的散点图,效果同上一步
plot(res$mathRes,res$lineRes,main="数学成绩和线性代数成绩关系",
	xlab="数学成绩",ylab="线性代数成绩",xlim=c(0,100),ylim=c(0,100),
	xaxs="i",yaxs="i",#内置
	col="green",pch=19)								#散点图的进一步设置,pch=19圆盘

a=c(2,3,4,5,6)
b=c(4,7,8,9,12)
plot(a,b,type="l")									#连线图

plot(res$num,res$mathRes,type="l",col="red",ylim=c(0,100),
main="学生的各科成绩曲线",xlab="学号",ylab="成绩",lwd=3)				#lwd:线宽
lines(res$num,res$lineRes,type="l",col="blue",lwd="3")
lines(res$num,res$probabilityRes,type="l",col="green",lwd="3")		#一幅图绘制多条曲线

#par()来实现设备上输出多个散点图
par(mfrow=c(3,1))										#3行1列
plot(res$num,res$mathRes,type="l")
plot(res$num,res$lineRes,type="l")
plot(res$num,res$probabilityRes,type="l")						#散点图集，一张图绘制多个曲线

plot(res$num,res$mathRes,type="l",main="数学成绩")
dev.new()
plot(res$num,res$lineRes,type="l",main="线性代数")
dev.new()
plot(res$num,res$probabilityRes,type="l",main="概率论")			#多张图绘制多个数据曲线


plot(density(rnorm(1000)))								#density密度图


table(res$mathRes)									#列联函数
barplot(table(res$mathRes))								#柱状图

pie(table(res$mathRes))									#饼状图

#箱尾图，中间横线为样本中位数
#箱子的上下横线分别对应于样本的25%和75%分位数
#上下延伸线为尾线，尾线尽头分别对应于最高值和最低值
#o为异常值
boxplot(res$mathRes,res$lineRes,res$probabilityRes)				#箱尾图
boxplot(res$mathRes,res$lineRes,res$probabilityRes,horizontal=T)		#水平放置的箱尾图

boxplot(res[2:4],col=c("red","blue","green"),notch=T)				#箱线图

#每个观测单位的数值为一个单位，每个图的每个角表示一个变量，角线的长度表达数值的大小
stars(res[c("mathRes","lineRes","probabilityRes")])					#星相图
stars(res[c("mathRes","lineRes","probabilityRes")],full=T,draw.segment=T)	#星相图，全圆显示
stars(res[c("mathRes","lineRes","probabilityRes")],full=F,draw.segment=T)	#星相图，半圆显示

#脸谱图,用人脸五官的宽度和高度来描绘数据，适合于样本比较少的情况
#需要安装aplpack包，相应命令是install.packages("aplpack")
library(aplpack)
faces(res[c("mathRes","lineRes","probabilityRes")])

library(TeachingDemos)
faces2(res[c("mathRes","lineRes","probabilityRes")])					#脸谱图
faces2(res)

stem(res$mathRes)											#茎叶图


#可用于判断是否符合正态分布，点的散布越接近直线，越接近正太分布
#直线的斜率是标准差，截距是均值
qqnorm(res$mathRes)										#QQ图										
qqline(res$mathRes)

data()												#查看内置数据
heatmap(as.matrix(mtcars),Rowv=NA,Colv=NA,col=heat.colors(256),
scale="column",margins=c(2,8),main="Car characteristics by Model")		#热力图

iris													#鸢尾花数据集,sepal花萼 petal花瓣 species种属
#可以通过向日葵花瓣的数来表示重叠的数据的个数，克服了散点图中数据重叠的问题
sunflowerplot(iris[,3:4],col="gold",seg.col="gold")					#向日葵散点图

#遍历样本中的全部变量盘对画出二元图，便于直观连接所有元素之间的关系
pairs(iris[,1:4])											#散点图集
plot(iris[,1:4],pch=19,col="blue",cex=0.6)

library(scatterplot3d)
scatterplot3d(iris[,2:4])									#绘制三维散点图

x<-y<-seq(-2*pi,2*pi,pi/15)
f<-function(x,y) sin(x)*sin(y)
z<-outer(x,y,f)
contour(x,y,z,col="blue")									#三维作图，吐信类似于等高线
persp(x,y,z,theta=30,phi=30,expand=0.7,col="lightblue")

#调和曲线用于聚类判断很方便
#unison(iris[,2:4])										#调和曲线图，自定义，无unison函数




