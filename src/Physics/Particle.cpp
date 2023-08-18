#include "Particle.h"
#include <stdio.h>

Particle::Particle(float x, float y, float mass) {
  this->position = Vec2(x, y);
  this->mass = mass;
}

Particle::~Particle() {
  puts("Particle destructor called!");
}
