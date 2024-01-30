# sfml-gravity
Planetary Motion and Gravitational Forces Simulation Between Bodies

This is a very basics simulation to used to show and depict gravitational forces acting on bodies and how they interact with each other. This was a personnal project I took on to better learn C++. Integration is very lightweight and stable. At higher velocities, it loses some of its stability and better integration method (such as RK4) would be more suitable for higher accuracy.

# Example #
Click to watch
[![Video](https://img.youtube.com/vi/gFZx-7YeL3Q/maxresdefault.jpg)](https://youtu.be/gFZx-7YeL3Q)

# Pre-requisites 
This code requires the use of g++ v13.2.0 and SFML v2.6.1. More recent versions of those libraries should be compatible, but were not tested. This code also makes uses the C++ Standard CPP23 (previous versions should be compatible but again, weren't tested).

Both g++ and SFML will need to be added to PATH.

# Compiling #
## Using VS Code ##
To compile and run using VS Code, open the entire project in VS Code and press the 'Run C\C++ File' button inside the 'src\main.cpp' file (make sure to have the C\C++ extension installed on VS Code).

## Using cmd ##
* Navigate to the project directory,
* Enter to compile: 
```
g++ -I<SFML-PATH>\include -L<SFML-PATH>\lib -g src\core.cpp src\event.cpp src\physics.cpp src\math.cpp src\solver.cpp -o build\sfml-gravity.exe -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main
```
with \<SFML-PATH> being the path to your SFML library (e.g.: C:\SFML-2.6.1).
* Enter to run:
```
.\build\sfml-gravity.exe
```

# Usage #
* Escape exits the app.
* By default, planets are randomly generated.
