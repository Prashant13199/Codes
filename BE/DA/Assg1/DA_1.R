iris = read.csv("D:/DISK D/BE-SEM1/allcodes/allcodes/DA/irisdata.csv", header=TRUE)
names(iris)
print("Features in dataset:")
dim(iris)
view(irisdata)
sepal_length<-iris$V1
sepal_width<-iris$V2
petal_length<-iris$V3
petal_width<-iris$V4

print("Minimum of Sepal Length: ")
print(min(sepal_length))
print("Minimum of Sepal Width: ")
print(min(sepal_width))
print("Minimum of Petal Length: ")
print(min(petal_length))
print("Minimum of Petal Width: ")
print(min(petal_width))

print("Maximum of Sepal Length: ")
print(max(sepal_length))
print("Maximum of Sepal Width: ")
print(max(sepal_width))
print("Maximum of Petal Length: ")
print(max(petal_length))
print("Maximum of Petal Width: ")
print(max(petal_width))

print("Mean of Sepal Length: ")
print(mean(sepal_length))
print("Mean of Sepal Width: ")
print(mean(sepal_width))
print("Mean of Petal Length: ")
print(mean(petal_length))
print("Mean of Petal Width: ")
print(mean(petal_width))

print("Range of Sepal Length: ")
print(range(sepal_length))
print("Range of Sepal Width: ")
print(range(sepal_width))
print("Range of Petal Length: ")
print(range(petal_length))
print("Range of Petal Width: ")
print(range(petal_width))

print("Range of Sepal Length: ")
print(var(sepal_length))
print("Range of Sepal Width: ")
print(quantile(sepal_width))
print("Range of Petal Length: ")
print(range(petal_length))
print("Range of Petal Width: ")
print(range(petal_width))

print("Standard Deviation of Sepal Length: ")
print(sd(sepal_length))
print("Standard Deviation of Sepal Width: ")
print(sd(sepal_width))
print("Standard Deviation of Petal Length: ")
print(sd(petal_length))
print("Standard Deviation of Petal Width: ")
print(sd(petal_width))

hist(sepal_length,main="Histogram of sepal_length(cm)",col="red",border)
hist(sepal_width,main="Histogram of sepal_width(cm)")
hist(petal_length,main="Histogram of petal_length(cm)")
hist(petal_width,main="Histogram of petal_width(cm)")



var<-boxplot(iris[,5])
var$out


boxplot(iris[,-5])

summary(sepal_length)

