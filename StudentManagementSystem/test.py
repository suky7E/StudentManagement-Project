# Simple TCP client-server example

# Server
import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind(('0.0.0.0', 12345))  # Listen on port 12345 on all interfaces
server.listen(1)
print("Waiting for connection...")
conn, addr = server.accept()
print(f"Connected by {addr}")
while True:
    data = conn.recv(1024)
    if not data:
        break
    print("Received:", data.decode())
    conn.sendall(b"Message received")
conn.close()

# Client
import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('192.168.204.43', 12345))
client.sendall(b"Hello Server!")
response = client.recv(1024)
print("Server says:", response.decode())
client.close()