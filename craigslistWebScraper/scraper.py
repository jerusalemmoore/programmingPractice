#!/usr/bin/python3.5
from bs4 import BeautifulSoup
from urllib.request import urlopen
import sys
from item import Item
from emailer import sendEmail
import os.path
import filecmp
#################################################################################################
#	Method for scraping all craigslist items on a BeautifulSoup page and return
# 	a list of those items including the name, price and corresponding city
#
#	args: Beautiful 
##################################################################################################
def processSoup(soup):
	global items
	for listing in soup.find_all('div', class_='result-info'):
		name= listing.find('a', class_='result-title hdrlnk')#tag for name of craigslist item
		result = listing.find_all('span', class_='result-meta')#metadata for craigslist item
		itemName = name.string#string version for 
		for tag in result:
			itemPrice = tag.find('span', class_='result-price').string# get price of item
			if itemPrice[0] == "$":
				itemPrice = itemPrice[1:]
			itemPrice = itemPrice.replace(',', '')
			if tag.find('span', class_='result-hood') is not None:#check if there is a corresponding city for listing
				city = tag.find('span', class_='result-hood').string#get name of city for item
			else:
				city = None#default to none for city name
			newItem = Item(itemName, itemPrice, city)#create craigslist item
			items.append(newItem)#add to list of entries
	return items
if len(sys.argv) != 4:
	print("Error, incorrect number of args[3]")
else:

	url ='http://chico.craigslist.org/search/sga/'#base craigslist url for first  page of items
	query=sys.argv[1]#word to include when searching item listings
	maxPrice =sys.argv[2] 
	numProducts=sys.argv[3]
	html = urlopen(url)#open url for soup
	soup = BeautifulSoup(html, "html.parser")#create soup of first page
	totItems = soup.find('span', class_='totalcount')#total listing present on craigslist
	totItemsAsInt = int(totItems.string)#int version of total items for if statement
	itemsOnPage = 120
	counter = 0
	items = []
	if os.path.isfile('oldFile.txt'):
		oldItemFile = open("oldFile.txt", "r")
	else:
		oldItemFile = open("oldFile.txt", "w")
	newItemFile = open("newFile.txt", "w")
	while True:
		processSoup(soup)
		url = 'http://chico.craigslist.org/search/sga?s=' + str(itemsOnPage) 
		html = urlopen(url)
		soup = BeautifulSoup(html, "html.parser")
		itemsOnPage += 120
		if itemsOnPage > totItemsAsInt:
			processSoup(soup)
			break
	#NOTE YOU STILL HAVE TO DEAL WITH PARAMETER PASSING FROM CMDLIN
	counter = 0
	items.sort(key=lambda Item: float(Item.price))
	for item in items:
		if float(item.price) <= float(maxPrice) and query.lower() in item.title.lower():
			if item.city is None:
				print(item.title + ",$" + item.price + "," + "None", file = newItemFile)
			else:
				print(item.title + ",$" + item.price + "," + item.city, file = newItemFile)
		counter += 1
		if counter >= int(numProducts):
			break
	newItemFile.close()
	newF = open("newFile.txt", "r")
	oldF = open("oldFile.txt", "r") 
	if not filecmp.cmp('newFile.txt', 'oldFile.txt', shallow = False):
		with open('newFile.txt', 'r') as file:
			message = file.read()
		sendEmail(message)
		with open('newFile.txt', 'r') as firstfile, open('oldFile.txt', 'w') as secondfile:
			for line in firstfile:
				secondfile.write(line)
