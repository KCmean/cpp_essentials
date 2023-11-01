import time
import socket
import sys
import random


print("\nGO BACK N\n")
print("Connecting...\n")
time.sleep(1)


s = socket.socket()
hostA = socket.gethostname()
ip = socket.gethostbyname(hostA)
print(hostA, "(", ip, ")\n")
host = input(str("Enter server address: "))
name = input(str("\nEnter your name: "))
port = 1234
print("\nTrying to connect to ", host, "(", port, ")\n")
time.sleep(1)
s.connect((host, port))
print("Connected...\n")


s.send(name.encode())
s_name = s.recv(1024)
s_name = s_name.decode()
print(s_name, " is online\nEnter [e] to stop\n")


ws = s.recv(1024)
ws = ws.decode()
print("Window size entered: ", ws)


while True:

    newstr = s.recv(1024)
    newstr = newstr.decode()

    print("Frames for transmission: ", newstr)

    if (newstr == "exit"):
        print("Transmission ends!")
        s.close()
        break

    t = random.randint(0, 1)
    if (t == 0):
        message = ""
        j = random.randint(0, int(ws))
        message = "ACK " + str(j)
        print("Input message: ", message)

    else:
        message = "NO ACK"
        print(message)
    s.send(message.encode())

    if newstr == "":
        break
