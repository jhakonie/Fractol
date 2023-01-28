## Fractol
Hive project where you create a program that displays fractals using 42 school's own minilibx graphics library.
<p align="left">
  <img src="https://github.com/jhakonie/Fractol/blob/master/mandelbrot_zoomed_in.png" width="35%" height="30%">
  <img src="https://github.com/jhakonie/Fractol/blob/master/Burning_ship.png" width="35%" height="45%">
</p>

### Deployment
```
  git clone git@github.com:jhakonie/Fractol.git fractol
  cd fractol
  make
```
mlx is included as sources in the root of the repository.
The Makefile will install it in the root of the repository. mlx can be deleted with 'make fclean'.

### Fractals
- It was mandatory to create mandelbrot and an interactive julia set.
- In addition I chose Newton's fractal and the burning ship.
- The most fun part of this project was experimenting so I created some of my own interactive fractals: flower, mandala, triangle, snowflake.
- Also made "tribrot" and "multijulia"

<p align="left">
  <img src="https://github.com/jhakonie/Fractol/blob/master/flower_green.png" width="25%" height="30%">
  <img src="https://github.com/jhakonie/Fractol/blob/master/triangle.png" width="35%" height="45%">
  <img src="https://github.com/jhakonie/Fractol/blob/master/mandala_dark.png" width="35%" height="45%">
</p>

### Usage
```
usage:
./fractol <name of 1 or 2 fractal sets>
julia
multijulia
mandelbrot
tribrot
burningship
mandala
flower
newton
triangle
snowflake
```
User can move the fractal, zoom, add/decrease iterations, activate and modify two motion loops, lock the fractal, change the color palette, activate a color loop and modify rgb.

<p align="left">
  <img src="https://github.com/jhakonie/Fractol/blob/master/newton.png" width="55%" height="50%">
</p>

