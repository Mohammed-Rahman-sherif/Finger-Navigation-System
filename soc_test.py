import socket

ip = '192.168.4.1'
port = 80

conn = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

conn.connect((ip,port))

while 1:
	data = ('F')
	if data == 'q' or data == 'Q':
		break
	else:
		conn.send(data.encode())