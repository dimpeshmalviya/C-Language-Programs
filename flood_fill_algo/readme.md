# Flood Fill Algorithm in C

## Description
This program demonstrates the Flood Fill algorithm (4-directional), which is used in many grid-based applications like image processing and games (e.g., paint fill tools).

## How it Works
- Given a 2D matrix (grid), starting coordinates, and a new color.
- Recursively fills all connected cells of the starting cell's original color with the new color.

## Example
Fills the region starting at (4, 4) with the color 9.

## Usage
Compile and run:
gcc flood_fill.c -o floodfill
./floodfill

## Contributed for Hacktoberfest 2025