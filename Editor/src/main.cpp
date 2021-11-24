#include <Carnot.h>

class Editor : public Carnot::Application
{
public:
  Editor()
  {}
  
  ~Editor()
  {}
};

Carnot::Application* Carnot::CreateApplication()
{
  Carnot::fullscreen = false;
  Carnot::app_name = "Carnot Editor";
  return new Editor();
}
