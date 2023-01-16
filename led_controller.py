""" PY TO ESP (LED CONTROLLER) """
# Written by Junicchi - https://github.com/Kebablord

import urllib.request
root_url = "http://192.168.146.106"  # ESP's url, ex: http://192.168.102 (Esp prints it to serial console when connected to wifi)

def sendRequest(url):
	n = urllib.request.urlopen(url) # send request to ESP

# Example usage
while True:
	answer = input(""" To control the led, type "FORWARD" or "BACKWARD" or "RIGHT" or "LEFT": """)
	if (answer=="FORWARD"):
		sendRequest(root_url+"/FORWARD")
		print("GOING FORWARD!\n\n")
	if (answer=="BACKWARD"):
		sendRequest(root_url+"/BACKWARD")
		print("GOING BACKWARD!\n\n")
	if (answer=="RIGHT"):
		sendRequest(root_url+"/RIGHT")
		print("GOING RIGHT!\n\n")
	if (answer=="LEFT"):
		sendRequest(root_url+"/LEFT")
		print("GOING LEFT!\n\n")
