
class Item:
	def __init__(self, title, price, city):
		self.title = title
		self.price = price
		if city is None:
			self.city = None
		self.city = city
