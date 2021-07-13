import socket

serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv.connect(('127.0.0.1', 1234)) 


request = 'POST /create HTTP/1.1\n'
name = 'name='
lang = '&lang='
code = '&code='

name += input("Name: ")
lang += input("Language: ")
file_name = input("Filename: ")

f = open(file_name, "r")
data = f.read()
code += str(data)

request += name+lang+code

serv.send(bytes(request, 'utf-8'))

