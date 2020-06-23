#pragma once

#include "NavmeshParameters.hpp"

namespace godot
{
class CachedNavmeshParameters : public NavmeshParameters
{
  GODOT_CLASS(CachedNavmeshParameters, NavmeshParameters);

 public:
  static void _register_methods();

  void _init();

  SETGET(max_obstacles, int);
};
} // namespace godot
