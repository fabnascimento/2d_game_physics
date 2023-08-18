# 2D Game Physics Engine

### Libs & Dependencies

- SDL
- SDL_image
- SDL_gfx


### Particle Physics

- These objects have *no shape* (they are simple `point-mass`)

#### Newtonian Physics / Mechanics

1. `Inertia`: If no force is applied on an object, its velocity shall `not` change.
2. `Force, Mass, Acceleration`: The force acting on a object is equal to the mass of the object multiplied by its acceleration (_rate of change of velocity_).
    This is given by the formula $F = ma$ 
    To find acceleration we can do $a = \frac{F}{m}$
3. `Action and Reaction`: "For every action there is an equal and opposite reaction". In other wrods, whenever one body exerts a force on another, the seconds body exerts a force of the same magnitude and opposite direction on the first.
