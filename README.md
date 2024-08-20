# Project: So_Long - Creating a 2D Game

## Project Overview

The primary objective of So_Long was to develop a small 2D game where a player navigates through a map, collecting items and reaching an exit point. This project deepened my understanding of window management, event handling, colors, and textures.

## Key Features

### Game Mechanics

- Player movement (up, down, left, right)
- Collectible items
- Exit point
- Obstacles (walls)
- Move counter displayed in the shell

### Map Requirements

- Composed of only 5 possible characters:
  - '0' for an empty space
  - '1' for a wall
  - 'C' for a collectible
  - 'E' for the exit
  - 'P' for the player's starting position
- Map must be closed/surrounded by walls
- Must have at least one exit, one collectible, and one starting position

### Graphics

- Use of the MiniLibX library for rendering
- Smooth window management
- Displayed images for game elements

## Technical Implementation

### MiniLibX Usage

- Window creation and management
- Image loading and display
- Key press event handling

### Map Parsing

- Reading and validating the map from a `.ber` file
- Ensuring map meets all specified requirements

### Game Logic

- Player movement and collision detection
- Collectible gathering
- Win condition checking

## Technical Challenges

1. **Graphics Handling:** Learning to use MiniLibX for rendering and image management
2. **Event Management:** Implementing smooth key press detection and response
3. **Map Validation:** Ensuring all map requirements are met, including path validity
4. **Memory Management:** Proper allocation and deallocation of resources
5. **Game Loop:** Implementing an efficient game loop for smooth gameplay

## Implementation Approach

1. **Modular Design:** Separated the project into distinct modules (map parsing, rendering, game logic)
2. **Data Structures:** Used appropriate data structures to represent the game state
3. **Error Handling:** Implemented comprehensive error checking and graceful error handling

## Bonus Features (if implemented)

- Enemy patrols
- Sprite animations
- HUD (Heads Up Display) for score

## Testing and Validation

- Developed various test maps to cover different scenarios
- Tested edge cases in map design and player movement
- Verified proper memory management using tools like Valgrind
- Ensured smooth gameplay and correct win/lose conditions

## Key Learnings

- Basic game development concepts
- Graphics programming and the use of graphics libraries
- Event-driven programming
- File parsing and data validation
- Efficient algorithms for game logic

## Future Applications

- More complex game development
- GUI application development
- Computer graphics and visualization
- Event-driven programming in various contexts
