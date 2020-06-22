#pragma once

#include "NavmeshParameters.hpp"

namespace godot
{
class CachedNavmeshParameters : public NavmeshParameters
{
  GODOT_CLASS(CachedNavmeshParameters, NavmeshParameters);

 public:
  CachedNavmeshParameters();
  ~CachedNavmeshParameters();

  void _init();

  void _ready();

  static void _register_methods();

  SETGET(max_obstacles, int);
};
} // namespace godot
