# Navy

## AUTHORIZED FUNCTIONS:
- open
- close
- read
- write
- lseek
- malloc
- free
- getpid
- kill
- signal
- sigaction
- sigemptyset
- setcontext
- getcontext
- usleep
- nanosleep
- pause
- getline
- fopen
- fclose

## SUBJECT:
You all know the very famous Battleship game. Well, I hope so.
You must code a terminal version of this game.
The two players are ONLY allowed to comunicate using the
signals SIGUSER1 and SIGUSER2.
The map size is 8x8. On each turn, you must display your positions, and then your enemy’s positions.
At the end of the game (when all the ships of a player have
been hit), you must display whether “I won” (and return 0) or
“Enemy won” (and return 1).

The file passed as parameter must contain lines formatted the following way:
**LENGTH : FIRST_SQUARE : LAST_SQUARE**
where **LENGTH** is the length of the ship, **FIRST_SQUARE** and **LAST_SQUARE** its first and last positions.
In this file, you must have 4 ships (of lengths 2,3,4 and 5).
If the navy file is invalid, you have to quit the program and consider it as an error.
## EXAMPLE :
````sh
$> cat pos1
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
````
````sh
$> cat pos2
2:C4:D4
3:H1:H3
4:E6:H6
5:B1:F1
````
````sh
./navy pos1
my_pid: 4242
waiting for enemy connection...
enemy connected
````
````sh
./navy 4242 pos2
my_pid: 4250
successfully connected
````