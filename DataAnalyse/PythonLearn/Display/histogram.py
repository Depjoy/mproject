import numpy
import matplotlib.mlab
import seaborn

from getIrisData import *

x = get_iris_column(0)
mu = numpy.mean(x)
sigma = numpy.std(x)

## matplotlib绘制直方图并添加拟合的频率直方图
'''
:param
    x:          x轴的值
    num_bin:    直方图柱子的数目
    normed:     概率密度
    facecolor： 颜色
    alpha:      色深
:return:
    n:          概率个数
    bins：      直方块左侧的X的值
    patches：    各个方块对象         
'''
num_bins = 30
matplotlib.pyplot.figure(1)
n, bins, patches = matplotlib.pyplot.hist(x, num_bins,normed=1,facecolor="blue",alpha=0.8)
"拟合最佳的正态分布曲线"
normpdf = matplotlib.mlab.normpdf(bins, mu, sigma)
matplotlib.pyplot.plot(bins, normpdf, 'r--')
matplotlib.pyplot.xlabel("sepal length")
matplotlib.pyplot.ylabel("Probility")
matplotlib.pyplot.title(r"Histogram: $\mu={0}$ $\sigma={1}$".format(round(mu,3),round(sigma,3)))
matplotlib.pyplot.subplots_adjust(left=0.15) # 调整左边距

matplotlib.pyplot.figure(2)
seaborn.set_palette("hls") #设置所有图的颜色，使用hls色彩空间
'''
:param:
    bins:   显示柱子的个数
    kde:    是否显示，拟合曲线
'''
seaborn.distplot(x,color="r", bins=30, kde=True, hist_kws={ "color": "b" })
matplotlib.pyplot.xlabel("sepal length")
matplotlib.pyplot.ylabel("Probility")

matplotlib.pyplot.figure(3)
'''
:param
    kde_kws:    拟合曲线设置
                lw:         线的粗细程度
    hist_kws:   柱子的设置
'''
seaborn.distplot(x,bins=30, kde_kws={"color":"green", "lw":3 }, hist_kws={ "color": "b" })
matplotlib.pyplot.show()
