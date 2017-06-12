# Lem_in

### What is Lem_in?
The aim of this program is to find the fastest way to move N ants from the start room to the end room.
However, there are following constraints:
1. Ants can only move from one room to another room once per turn.
2. No two ants can stay in the same room unless it is the start room or the end room.
3. No two ants can move in the same tubes to avoid traffic jams.
4. We want to minimize the number of turns it takes for N ants to move from the start room to the end room.

### Input Format
Format:
1. number of ants
2. rooms (name x-coordinate y-coordinate)
3. tubes (room1-room2)
4. ##start before the start room
5. ##end before the end room
Example:
```
2
##start
0 0 0
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
##end
6 6 6
0-1
0-2
1-3
2-4
3-6
4-6
```

### Output Format
Format:
Entire map.
Plus, per each turn, it will print out L[ant number]-[room name of the destination] for every ant that moved during that turn.

Example:
```
2
##start
0 0 0
1 1 1
2 2 2
3 3 3
4 4 4
5 5 5
##end
6 6 6
0-1
0-2
1-3
2-4
3-6
4-6

L1-1 L2-2
L1-3 L2-4
L1-6 L2-6
```

### Algorithm
It is imperative to ensure that ants follow the all the constraints and swiftly reach the destination using Dijkstra's Shortest Path algorithm. In order to discourage ants from waiting for "the shortest route" with "traffic", we adjust the weight of the edges every time an ant moves to ensure correct movements.
