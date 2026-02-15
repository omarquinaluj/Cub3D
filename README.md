*This project has been created as part of the 42 curriculum by <your_login>.*

# Cub3D

## Description

Cub3D is a simple 3D game engine inspired by the legendary game Wolfenstein 3D.  
The objective of the project is to implement a raycasting engine in C capable of rendering a pseudo-3D environment from a 2D map.

The program reads a `.cub` configuration file that contains:

- Texture paths
- Floor and ceiling colors
- A 2D map description

Using this data, the engine renders a first-person perspective view of the map.  
The player can move inside the environment using keyboard controls.

This project focuses on:

- Raycasting fundamentals
- Parsing and validation of structured files
- Texture mapping
- Event handling
- Memory management
- Basic graphics programming using MiniLibX (or MLX42)

---

## Features

- Raycasting-based 3D rendering
- Textured walls (North, South, East, West)
- Floor and ceiling coloring
- Player movement (W, A, S, D)
- Rotation with arrow keys( < , >)
- Collision detection
- Map validation (closed walls required)
- Error handling with clear messages

---

## Installation & Compilation

### Requirements

- GCC
- Make
- MiniLibX
- Linux or macOS

### Clone the repository

```bash
git clone git@github.com:omarquinaluj/Cube3D.git
cd cub3d
```
To compile:
``` bash
make all
```
The prerequisite for making cub3D functional is passing it a map as an argument, for example:

``` bash
./cub3D /valid/map.cub
```

## Map Rules

The map must be surrounded by walls (1).
Valid map characters:
-> 0 → empty space
-> 1 → wall
N, S, E, W → player starting position
The map must be closed.
Only one player starting position is allowed.

If the file is invalid, the program exits with an error message.

## Technical Overview

Cub3D implements the Raycasting algorithm, which works by:
1º Casting a ray for each vertical stripe of the screen.
2º Detecting wall intersections using DDA (Digital Differential Analysis).
3º Calculating wall distance.

4ºRendering vertical textured slices accordingly.

The project is written in C and follows the 42 Norm.

