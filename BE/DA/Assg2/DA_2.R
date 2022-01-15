library(e1071)
MyData <- read.csv(file="D:/DISK D/BE-SEM1/allcodes/allcodes/DA/Assg2/pima.csv", header=TRUE, sep=",")
bound <- floor((nrow(MyData)/4)*3) 
train <- MyData[1:bound,]
test <- MyData[(bound+1):nrow(MyData),]
fit <- naiveBayes(diabetes~., data=train)
print(fit)
predictions <- predict(fit, test[,1:8])
table(predictions, test$diabetes)

