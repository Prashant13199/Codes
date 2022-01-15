import urllib.request as request
from bs4 import BeautifulSoup




print('Welcome to Comic Scraper')


u = input('Enter Comic URL')
a = int(input('Enter start date'))
b = int(input('Enter till date'))
c = input('Enter Month')
d = input('Enter Year')



for i in range(a,b+1):
	aa = str(i)
	url = u+d+'/'+c+'/'+aa
	print("Getting URL:"+url)
	try:
		response = request.urlopen(url)
		soup = BeautifulSoup(response, 'html.parser')

		print("Getting Image")
		image = soup.find('picture',{'class':'item-comic-image'})


		print("Saving Image")
		request.urlretrieve(image.img['src'], image.img['alt'] + '.png')
	except:
		print("Not Found")

print("Done...Enjoy!!")

'''
url = 'https://www.gocomics.com/garfield/2020/05/14'
response = request.urlopen(url)
soup = BeautifulSoup(response, 'html.parser')

#print(soup)
image = soup.find('picture',{'class':'item-comic-image'})

request.urlretrieve(image.img['src'], image.img['alt'] + '.png')
'''