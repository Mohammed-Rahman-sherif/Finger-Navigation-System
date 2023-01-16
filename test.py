import urllib.request

root_url = "http://192.168.77.106"

#def sendRequest(url):
#	n = urllib.request.urlopen(url)

def a():
	try:
		urllib.request.urlopen(root_url+"/FORWARD")
		print("Led is on")
	except Exception as e :
		pass

def b():
	try:
		urllib.request.urlopen(root_url+"/RIGHT")
		print("Led is off")
	except Exception as e :
		pass

while 1:
	answer = input()
	if (answer=="FORWARD"):
		a()
	if (answer=="RIGHT"):
		b()