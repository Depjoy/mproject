library(maps)
map("state",interior=FALSE)							#美国地图，内部无填充				
map("state",boundary=FALSE,col="green",add=TRUE)		      #美国地图，在内部添加边界
map("world",fill=TRUE,col=heat.colors(10))				#世界地图，并用热力颜色进行填充

map("state")
map("world")									#世界地图，并且在美国地图的内部添加边界

xlim<-c(-171.738281,-56.601563)
ylim<-c(12.039321,71.856229)
map("world",col="red",fill=TRUE,bg="white",
	lwd=5,xlim=xlim,ylim=ylim)						#设置坐标使得焦点集中在美国周边，且设置相关颜色

library(maps)
library(geosphere)
lat<-39.164141
lon<--121.64062
latMe<--45.21300
lonMe<--68.906250
inter<-gcIntermediate(c(lon,lat),c(lonMe,latMe),
	n=50,addStartEnd=TRUE)
map("world")
lines(inter,lwd=5,col="red")							#在世界地图上特定的两个坐标之间绘制曲线

lat2=-29.954835
lon2=-98.701172
inter2<-gcIntermediate(c(lon2,lat2),c(lonMe,latMe),
face
	n=50,addStartEnd=TRUE)
lines(inter2,lwd=3,col="blue")						#继续绘制线

#绘制多重联系，社交数据可视化
#http://flowingdata.com/2011/05/11/how-to-map-connections-with-great-circles/
library(maps)
library(geosphere)
airports<-read.csv("http://datasets.flowingdata.com/tuts/maparcs/airports.csv",header=TRUE)
flights<-read.csv("http://datasets.flowingdata.com/tuts/maparcs/flights.csv",header=TRUE,as.is=TRUE)
fsub<-flights[flights$airline=="AA",]
xlim<-c(min(airports$long),max(airports$long))
ylim<-c(min(airports$lat),max(airports$lat))
map("world",col="#f2f2f2",fill=TRUE,bg="white",lwd=0.05,xlim=xlim,ylim=ylim)
for(j in 1:length(fsub$airline)){
	air1<-airports[airports$iata == fsub[j,]$airport1,]
	air2<-airports[airports$iata == fsub[j,]$airport2,]
	inter2<-gcIntermediate(c(air1[1,]$long,air1[1,]$lat),c(air2[1,]$long,air2[1,]$lat),
	n=50,addStartEnd=TRUE)
	lines(inter2,lwd=0.1,col="blue")
}


