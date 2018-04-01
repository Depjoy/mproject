'''
    不传参数的函数定义
'''
def hello():
    print("Hello")
hello()

'''
    向函数传入参数信息
    @parm
        userName:       输入参数信息，形参
'''
def greetUser(userName):
    userName=userName.upper()
    print("Hello " + userName + "!")
userName="Python"
greetUser(userName)
print(userName)

'''
    位置实参，实参的顺序必须相同
'''
def describePet(type,name):
    print("I have a " + type +". It's name is " + name + ".")
print("\n位置实参示例")
describePet("dog","harry")

'''
    关键字实参，将形参的名字和值关联起来,可以设置默认参数
'''
def describePet2(type="dog",name="harry"):
    print("I have a " + type +". It's name is " + name + ".")
print("\n关键字实参示例")
describePet2()
describePet(type="cat",name="Marry")
'''
    混合位置和关键字实参，可以给部分实参传入默认的值
    此时位置实参对应的位置必须传入参数
'''
def describePet3(name,type="dog"):
    print("I have a " + type +". It's name is " + name + ".")
print("\n混合位置实参和关键字实参示例")
describePet3("Harry")
describePet3(name="Harry")
describePet3(name="Harry",type="Cat")


'''
    返回一个数值
'''
def getFullName(firstName,secondName):
    fullName = firstName + ' ' + secondName
    return fullName.title()
fullName = getFullName("jimi","hendrix")
print("\n返回一个值的函数示例")
print(fullName)

'''
    返回字典
'''
def getName(firstName,secondName):
    full = firstName + " "+ secondName
    name={"first":firstName,"sencond":secondName,"full": full.title()}
    return name
print("\n返回一个字典的函数示例")
name=getName("jimi","hendrix")
print(name)

'''
    支持输入获取name信息，输入q或Q结束name信息
'''
def getNameByInput():
    while True:
        print("\nPlease tell me your name: ")
        firstName=input("First Name: ")
        if firstName=='q' or  firstName == 'Q':
            print("enter q or Q,quit.")
            break
        sencondName=input("Second Name: ")
        if sencondName=="q" or sencondName == "Q":
            print("enter q or Q,quit.")
            break
        name=getName(firstName,sencondName)
        print("Full Name: " + name["full"] + "!")
#getNameByInput()

'''
    输入参数为列表
'''
def getNames(names):
    print("\nGet names' list info")
    for name in names:
        firstName = name["first"]
        sencondName = name["sencond"]
        fullName = name["full"]
        print("First Name: "+firstName+"\tSencond Name: "+sencondName + "\n\tFull Name:"+name["full"])
namesInfo=[
            {"first": "Harry", "sencond":"Bote","full": "Harry Bote"},
            {"first": "Marry", "sencond":"Lucy","full": "Marry Lucy"},
            ]
getNames(namesInfo)
'''
   函数中修改参数列表 
'''
def printModels(unprintedDesigns, completedModels):
    while unprintedDesigns:
        currentModel=unprintedDesigns.pop()
        print("Printing model: {0}".format(currentModel))
        completedModels.append(currentModel)
    if not unprintedDesigns:
        print("Unprinted model is NULL")
def showCompletedModels(completedModels):
    print("The following models have been printed: ")
    for completedModel in completedModels:
        print(completedModel)
unprintedModels=["Banana", "Apple", "Orange"]
completedModels=[]
printModels(unprintedModels,completedModels)
if not unprintedModels:
    print("Unprinted model is NULL,unprinted data have been changed")
showCompletedModels(completedModels)
'''
    禁止修改函数参数列表，函数传入参数list[:]，利用切片创建列表副本
'''
def printModels2(unprintedDesigns, completedModels):
    while unprintedDesigns:
        currentModel=unprintedDesigns.pop()
        print("Printing model: {0}".format(currentModel))
        completedModels.append(currentModel)
def showCompletedModels2(completedModels):
    print("The following models have been printed: ")
    for completedModel in completedModels:
        print(completedModel)
unprintedModels=["Banana", "Apple", "Orange"]
completedModels=[]
printModels2(unprintedModels[:], completedModels)
print("Try to get unprinted data again.")
for unprintedModel in unprintedModels:
    print("\tOriginal unprinted data: {0}".format(unprintedModel))
showCompletedModels2(completedModels)

'''
    传入任意数量的实参
    *food创建一个空的元组，并会将受到的数值封装到这个元组中
'''
def makeDinner(*food):
    print("tonight dinner is ")
    for f in food:
        print("\t- {0}".format(f))
makeDinner('Pizza')
makeDinner("Pizza", "Noodle", "Soup")

'''
    结合位置实参、任意数量实参
    关键字实参失效
'''
def showMeterialPizza(size,*food):
    print("Pizza is made of {0} kinds of meterial,such as ".format(size))
    for f in food:
        print("\t- {0}".format(f))
showMeterialPizza(3,"Mushrooms", "Peppers", "Cheese")

'''
    实现可接受任意数量的键-值对
'''
def buildProfile(firstName, secondName,**userInfo):
    profile={}
    profile['first']=firstName
    profile['sencond']=secondName
    for key, value in userInfo.items():
        profile[key]= value
    return profile
userProfile=buildProfile("albert", "einstein", location='princeton',
                         field='physics', age=30)
print(userProfile)



