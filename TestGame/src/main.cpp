#include <Carnot.h>

class Game : public Carnot::Application
{
public:
  Game()
  {}
  
  ~Game()
  {}
};

Carnot::Application* Carnot::CreateApplication()
{
  return new Game();
}
