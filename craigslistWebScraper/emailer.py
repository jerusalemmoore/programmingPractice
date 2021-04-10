import os, smtplib, ssl
def sendEmail(message):
	#sender and receiver of email addresses
	sender_email = "mytest749847@gmail.com"
	receiver_email = "jmoore3@mail.csuchico.edu"
	print("Please enter password for sender email account")
	password = input()
	port = 465 #smtp port num
	#email to send
	fullMessage = "Alert!!! Top 5 craigslist item contents have changed.\nUpdated List:\n########################\n" + message
	#os calls to bash for touching and writing into file
	os.system('touch file1')
	os.system('date >> file1')
	context = ssl.create_default_context()

	#configure smtp server connection
	with smtplib.SMTP_SSL("smtp.gmail.com", port, context = context) as server:
		server.login(sender_email, password)
	#send plain text email
		server.sendmail(sender_email, receiver_email, fullMessage)

