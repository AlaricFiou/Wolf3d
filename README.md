# Wolf3D – Raycasting Game Engine (Demo)

## Description

This project is a **raycasting-based 3D game engine**, inspired by *Wolfenstein 3D*, developed in C using the **SFML** graphics library.  
It features a first-person perspective, a basic combat system, enemy interactions, and persistent game saving.

## Project Structure

- `main.c`: Program entry point, game loop setup, and cleanup.
- `player/`: Player structure and controls (movement, rotation, shooting).
- `enemies/`: Basic enemy logic, movement, and interactions.
- `raycasting/`: Raycasting and wall rendering using DDA.
- `background/`: Sky and floor rendering.
- `save/`: Load and save game state (score, lives, position).
- `include/`: Header files and macros.
- `assets/`: Game textures (walls, etc.)
- `game.save`: Save file storing player progress.

## Finished Features

### 1. Player Mechanics
- Can **move** forward/backward and **look** up/down.
- Can **rotate** left/right using keyboard controls.
- Equipped with a **shotgun** that can shoot enemies.
- Tracks **score**, **position**, and **lives** (although lives aren't consumed yet).

### 2. Enemies
- Single enemy type (ID: `3` on the map).
- Move directly **toward the player**, but are **blocked by walls**.
- **Damage** the player when within **30 pixels** (1/3 tile).
- Can be **killed** after receiving enough hits.

### 3. Save System
- Loads from `game.save` at launch.
- Creates a new file if it doesn't exist.
- Saves and restores:
  - **Score**
  - **Lives**
  - **Player coordinates**

### 4. Rendering Engine
- Implements a basic **raycasting engine** enhanced by the **DDA algorithm**.
- Handles:
  - Wall detection
  - Distance-based scaling
  - Fish-eye correction
- Floor and sky are rendered separately with **pitch movement** support.

### 5. Sounds and music
- A music will start when the game is launch and can by **paused** using the **p** key
- A sound will start when the shotgun is used

## In Progress

- Handling **screen artifacts** caused by pitch offset (e.g., black bands).
- Extending save system to support **more advanced stats**.
- Improving rendering performance and **texture scaling**.
- Adding **audio feedback** for damage events.

## Next Steps

- Introduce **enemy AI** (pathfinding around walls).
- Add **multiple enemy types** with varied behavior and HP.
- Implement **HUD** with score, health bar, and weapon status.
- Support for **map editor** or external `.map` loading.
- Expand **weapon system** (cooldowns, animations, damage types).
- Optimize rendering for better performance.

## How to Run

### Requirements
- **SFML 2.5+** (Graphics, Window, Audio)

### Compilation
```bash
make
./wolf3d
```

| Action        | Key           |
| ------------- | ------------- |
| Move Forward  | `Z`           |
| Move Backward | `S`           |
| Move Left     | `Q`           |
| Move Right    | `D`           |
| Turn Left     | `Left Arrow`  |
| Turn Right    | `Right Arrow` |
| Look Up       | `Up Arrow`    |
| Look Down     | `Down Arrow`  |
| Shoot         | `Left CLick`  |

## Requirements
Make sure SFML is properly installed on your system.

To install on Debian-based systems:
```bash
sudo apt install libsfml-dev
```
