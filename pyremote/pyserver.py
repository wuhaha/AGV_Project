
import socket                                         
import time

serversocket = socket.socket(
	        socket.AF_INET, socket.SOCK_STREAM) 


host = socket.gethostname()                           

port = 9999                                           

serversocket.bind((host, port))                                  


serversocket.listen(5)                                           

while True:
    # establish a connection
    clientsocket,addr = serversocket.accept()      

    print("Got a connection from %s" % str(addr))
    currentTime = time.ctime(time.time()) + "\r\n"
    a=clientsocket.recv(1024)
    print a
    #clientsocket.send(currentTime.encode('ascii'))
    clientsocket.close()
