#Title:-Twitter Data Analysis: Use Twitter data for sentiment analysis. The dataset is 3MB in
#size and has 31,962 tweets. Identify the tweets which are hate tweets and which are
#not. Sample Test data set available here
#https://datahack.analyticsvidhya.com/contest/practice-problem-twitter-sentiment-analysis/

install.packages('sentimentr')
library('sentimentr')

#data <- Twitter.sentiment.self.drive.DFE
data <- read.csv("C:/Users/USER/Downloads/ASSIGNMENTS/ASSIGNMENTS/Twitter sentiment analysis/Twitter-sentiment-self-drive-DFE.csv")
tweets <- data[,ncol(data)]
tweets

for(i in tweets){
  x <- sentiment(i)
  print(x)
  
}




