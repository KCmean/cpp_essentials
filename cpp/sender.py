import time
import socket
import sys


print("\nGO BACK N\n")
print("Connecting...\n")
time.sleep(1)


s = socket.socket()
host = socket.gethostname()
ip = socket.gethostbyname(host)
port = 1234
s.bind((host, port))
print(host, "(", ip, ")\n")
name = input("Enter name: ")

s.listen(1)
print("\nWaiting for incoming connections...\n")
conn, addr = s.accept()
print("Received connection from ", addr[0], "(", addr[1], ")\n")


s_name = conn.recv(1024)
s_name = s_name.decode()
print(s_name, "is online\nEnter [e] to stop\n")
conn.send(name.encode())


x = int(input("\nEnter length of message"))  # 0123012
y = input("\nEnter window size: ")
conn.send(y.encode())
start = 0
end = int(y)


arr = [str(i % int(y)) for i in range(x)]
cnt = -1


while True:

    newarr = ""
    for i in range(start, end):
        newarr += arr[i]

    conn.send(newarr.encode())
    message = conn.recv(1024).decode()
    shift = 0

    for i in range(start, end):
        t = i % int(y)
        if ("ACK "+str(t)) in message:
            print("ACK "+str(t))
            if (newarr.rfind(str(t)) >= shift):  # 0123
                shift = newarr.rfind(str(t))+1
        else:
            continue

        print("Start index of frame: ", start)
        print("End index of frame: ", end)

        if (cnt == -2):
            break

    start += shift
    if (start >= x):
        cnt = -2
        break
    else:
        end += shift
        if (end > x):
            end = x

    if (cnt == -2):
        conn.send('exit'.encode())
        conn.close()
        break
