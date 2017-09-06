import socket
import sys
from thread import *
 

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print 'Socket created'
 
try:
    s.bind((HOST, PORT))
except socket.error , msg:
    print 'Bind failed. Error Code ;
    sys.exit()
     
 
s.listen(10)
print 'Socket now listening'
 

def clientthread(conn):

    conn.send('Welcome to the server. Type something and hit enter\n') #send only takes string
     
    #infinite loop so that function do not terminate .
    while True:
         
        #Receiving from client
        data = conn.recv(1024)
        reply = 'OK...' + data
        if not data: 
            break
     
        conn.sendall(reply)
     
    #came out of loop
    conn.close()
 
#now keep talking with the client
while 1:


    conn, addr = s.accept()
     
    start_new_thread(clientthread ,(conn,))
 
s.close()