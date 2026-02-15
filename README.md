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
- Rotation with arrow keys
- Collision detection
- Map validation (closed walls required)
- Error handling with clear messages

---

## Installation & Compilation

### Requirements

- GCC
- Make
- MiniLibX (or MLX42 depending on your implementation)
- Linux or macOS

### Clone the repository

```bash
git clone https://github.com/<your_username>/cub3d.git
cd cub3d
