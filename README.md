# UNIX_SIGNAL-with-Minitalk-Project  

This is a project I did for 42 Lisbon for the Common Core program.

It is a communication program in the form of a client and a server designed to run on a terminal configured with UTF-8

## Usage:
run make and/or make bonus_
```
../UNIX_SIGNAL-with-Minitalk-Project$ make 
../UNIX_SIGNAL-with-Minitalk-Project$ make bonus
```
first run the server. It will print its PID.
```
./server
```
Then, using that PID, run the client.
```
./client [SERVER PID] "any message"
```

## Project requirements/specifications:
The server must be started first. After its launch, it has to print its PID.

The client takes two parameters:  
	1. The server PID.  
	2. The string to send.  
 
The client must send the string passed as a parameter to the server.
Once the string has been received, the server must print it.

The server should be able to receive strings from several clients in a row without needing to restart.  

The communication between your client and your server has to be done only using UNIX signals.

And you can only use these two signals: SIGUSR1 and SIGUSR2.

There are a limited number of permitted functions.

## BONUS PART

#### 1. The server acknowledges every message received by sending back a signal to the client.
#### 2. Unicode characters support 👾