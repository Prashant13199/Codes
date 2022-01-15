# comicscrap7.py 
#download comics from a start date to end date 
import multiprocessing
from bs4 import BeautifulSoup
import requests
import json
import urllib
from datetime import datetime,date,timedelta
import time
from time import sleep 

import random

#################################
### sdate 1996/01/13

def spawnScraping(sdate,delta,num,edate):
	
	# days_difference = delta.days;
	# global sdate
	# sdate=sdate+timedelta(days=days_difference);
	#sdate=sdate+timedelta(days=delta);
	#sdate = date(1996, 1, 12)   # start date
	#edate = date(2020, 1, 28)   # end date

	#delta = edate - sdate       # as timedelta
	print("inside process : "+str(num)+" startDate - "+ str(sdate)+ "Delta is : "+str(delta))
	# converts '2020-01-29' to 2020/01/29
	#dass = '2020-01-29'
	#print(datetime.strptime((dass), '%Y-%m-%d').strftime('%Y/%m/%d'))

	datelist=[]
	for i in range(delta.days + 1):
	    day = sdate + timedelta(days=i)
	    converted_date=datetime.strptime((str(day)), '%Y-%m-%d').strftime('%Y/%m/%d')
	    datelist.append('https://www.gocomics.com/foxtrot/'+converted_date)
	    #print(datetime.strptime((str(day)), '%Y-%m-%d').strftime('%Y/%m/%d'))

	    ###print('https://www.gocomics.com/foxtrot/'+converted_date)

	#print(len(datelist))

	i=0
	#################################
	for link in datelist:
		i=i+1
		try:
			
			source = requests.get(link,timeout=10)
			source.raise_for_status()
			soup = BeautifulSoup(source.text,'lxml') 
			comic_container = soup.find_all('picture',class_='item-comic-image') # gets the picture tag in which comic is present

			#print(len(comic_container)) # contains everything (including)within <picture> to </picture> 

			for comic in comic_container:
				for comic_image in comic.find_all('img'):
				    if comic_image.parent.name == 'picture':
				    	comic_url = comic_image['src']
				    	#print(comic_image['src']) # this gests the url to download the comic 

			#print(i)
			#print(comic_url)

			date_element = soup.find_all('div',class_='gc-calendar-nav__select')
			for d in date_element:
				date = d.div['data-date']
				##print(d.div['data-date'])

			dt2 = datetime.strptime(date,"%Y/%m/%d")
			date=dt2.strftime('%Y-%m-%d')

			data=urllib.request.urlretrieve(comic_url, "Foxtrot - "+date+".png")
		except Exception as a:
			print(a)
			print(link)
			time.sleep(2)
			print("------------timeout maybe------------")
			#sleep(1+random.randint(0, 10)+random.randint(0, 10))
			continue

############################### 
# spawnScraping() ends here //



if __name__ == '__main__':

	requests.packages.urllib3.util.ssl_.DEFAULT_CIPHERS = 'DES-CBC3-SHA'

	sdate = date(1997, 1, 1)
	edate = date(1997, 4, 1)

	total_process = 20;
	delta = ((edate-sdate)/total_process); # gives time difference in days and time NOT in integer
	print(delta)
	startingDelta=delta
	
	days_difference = ((edate-sdate).days/total_process)	# becuse 4.5 would become 4 would leave out 0.5 comic per process
		
	
	#t=	days_difference										# in all 0.5*totalcomics = 10 comics woulde be left out 
	#print("here "+str(t-int(t)))
	
	for i in range(total_process):
		p = multiprocessing.Process(target=spawnScraping,args=(sdate, delta,i,edate ) )
		
		
		delta=delta+timedelta(days=days_difference)-timedelta(days=startingDelta.days)	# timedelta(days=days_difference) accounts for days in float also 
		startingDelta=delta
		sdate=sdate+timedelta(days=delta.days)		
		p.start()
		print(str(delta)+"  : "+str(sdate))



## NOTE : wow 1min 45 sec to download 30 comics without multithreading
##  	  with multiprocessing with 3 processes, in 1 min 45 sec 90 comics were downloaded. WOW !!!! 