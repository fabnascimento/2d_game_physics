#include "Application.h"
#include "./Physics/Constants.h"
#include "Graphics.h"

bool Application::IsRunning() { return running; }

///////////////////////////////////////////////////////////////////////////////
// Setup function (executed once in the beginning of the simulation)
///////////////////////////////////////////////////////////////////////////////
void Application::Setup() {
  running = Graphics::OpenWindow();

  particle = new Particle(50, 100, 4.0);
  // TODO: setup objects in the scene
}

///////////////////////////////////////////////////////////////////////////////
// Input processing
///////////////////////////////////////////////////////////////////////////////
void Application::Input() {
  SDL_Event event;
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      running = false;
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_ESCAPE)
        running = false;
      break;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////
// Update function (called several times per second to update objects)
///////////////////////////////////////////////////////////////////////////////
void Application::Update() {
  static int previousFrameTime;
  // calculates deltaTime in seconds
  float deltaTime = (SDL_GetTicks() - previousFrameTime) / 1000.0;
  // TODO: clamp deltaTime ??

  int waitTime = MILLISECONDS_PER_FRAME - (SDL_GetTicks() - previousFrameTime);
  if (waitTime > 0) {
    SDL_Delay(waitTime);
  }

  previousFrameTime = SDL_GetTicks();
  particle->acceleration = Vec2(20, 98.8) * PIXELS_PER_METER;

  // integrate the acceleration and the velocity to find the new pos
  particle->velocity += particle->acceleration * deltaTime;
  particle->position += particle->velocity * deltaTime;

  // TODO: check the particle position and try to keep the particle
  // inside the boundaries of the window

  if (particle->position.x - particle->mass <= 0) {
    particle->position.x = particle->mass;
    particle->velocity.x *= -0.9;
  }
  if (particle->position.x + particle->mass >= Graphics::Width()) {
    particle->position.x = Graphics::Width() - particle->mass;
    particle->velocity.x *= -0.9;
  }
  if (particle->position.y + 4 >= Graphics::Height()) {
    particle->position.y = Graphics::Height() - particle->mass;
    particle->velocity.y *= -0.9;
  }
  if (particle->position.y - particle->mass <= 0) {
    particle->position.y = particle->mass;
    particle->velocity.y *= -0.9;
  }
}

///////////////////////////////////////////////////////////////////////////////
// Render function (called several times per second to draw objects)
///////////////////////////////////////////////////////////////////////////////
void Application::Render() {
  Graphics::ClearScreen(0xFF056263); // ARGB
  Graphics::DrawFillCircle(particle->position.x, particle->position.y,
                           particle->mass, 0xFFFFFFFF);
  Graphics::RenderFrame();
}

///////////////////////////////////////////////////////////////////////////////
// Destroy function to delete objects and close the window
///////////////////////////////////////////////////////////////////////////////
void Application::Destroy() {
  // TODO: destroy all objects in the scene
  delete particle;
  Graphics::CloseWindow();
}
