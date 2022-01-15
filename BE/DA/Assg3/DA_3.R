install.packages('rpart.plot')
library(rpart)
a = read.csv("D:/DISK D/BE-SEM1/allcodes/allcodes/DA/Assg3/dataset",header=TRUE)
a=data.frame(a)
train=head(a,200)
testdata=tail(a,800)
train
testdata
mytree=rpart(Membertype~Startnumber+Endnumber,data=testdata,method="anova",maxdepth=3,minsplit=2,minbucket=1)
rpart.plot(mytree)
