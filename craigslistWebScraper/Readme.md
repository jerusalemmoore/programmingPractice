Craigslist webscraper currently accesses the sports items page on craigslist
and creates a list of entries with a matching word to query, a max price, and a max number of products 
to save to the list. This list includes the item name, price, and location if available.
This list is saved to a txt file, on multiple executions, the script will see if a change in the 
top 5 list entries has taken place and if so will send an email to my corresponding 
account. 

usage: python3 scraper.py [query] [maxPrice] [numProducts]

To do:
-implement user input for nonhardcoded craigslist page urls
-apply user input to choose address to email list changes
-create default for query arg that just outputs all entries with matching url
  if keyword "[all]" is entered 
-create default for maxPrice and numProducts which has creates a list with no 
  limits on price or number of items if corresponding keywords "[any]" and "[all]"
  are entered in their respective cmdline args
