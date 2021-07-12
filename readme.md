# Sandpiles Simulation

## Requirements and Installation

### Requirements

Project is based on C++20

1. CMake https://cmake.org/install/
2. OpenCV from: https://docs.opencv.org/4.5.2/df/d65/tutorial_table_of_content_introduction.html

### How to run?

This is a **CMake-Project**. Compilation and building is pretty easy. Simply run in main folder via terminal:

<code>
cmake --build ./cmake-build-release --target SandPiles -- -j 6
</code>

The executable can be found in `./cmake-build-release/bin/SandPiles`.

## Results

Main idea from https://www.hiskp.uni-bonn.de/uploads/media/sandpiles.pdf.

**SandPiles** is a simple cellular-automaton where one can observe the collective behavior of falling sand on a field.
The boundary conditions are open in these implementations. You can start with a random distribution of piles of sand or
define one on your own.

The collapse condition of a sand pile is, when the max difference in height to a *von Neumann neighbour* exceeds the
specified `criticalSlope`. So different systems can be simulated.

The program shows a GUI generated with OpenCV. Single frames ov a view can be saved.

If one would like to create an animation this can be achieved by commandline via
`ffmpeg -framerate 10 -pattern_type glob -i './cmake-build-release/bin/results/*.png' -vf "scale=iw/2:ih/2" ./results/out.mp4`
which generates a `.mp4`or`.gif` from all `.png` files in the folder.

A small impression as gif with a random initial setting and always add one sand in the middle of the field. There are
more simulations, also in better quality (`mp4`) in `./results`.

![Example Image](./results/impression1.gif)

### Color-scale

Thanks to https://gka.github.io/palettes/#/7|d|ff006a,ffffff,ffffff|ffffff,ffffff,0088d7|1|1
for the really nice color scale.

Blue is a valley, red is a mountain, white is the mean height. The color scheme is regularly adjusted at runtime.