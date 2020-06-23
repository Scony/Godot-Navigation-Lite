#pragma once

#include <Godot.hpp>
#include <OS.hpp>
#include <Resource.hpp>

#include "helpers.h"

namespace godot
{
class NavmeshParameters : public Resource
{
  GODOT_CLASS(NavmeshParameters, Resource);

 public:
  static void _register_methods();

  void _init();

  SETGET(tile_size, int);
  SETGET(cell_size, float);
  SETGET(cell_height, float);
  SETGET(partition_type, int);
  SETGET(agent_height, float);
  SETGET(agent_radius, float);
  SETGET(agent_max_climb, float);
  SETGET(agent_max_slope, float);
  SETGET(region_min_size, float);
  SETGET(region_merge_size, float);
  SETGET(edge_max_length, float);
  SETGET(edge_max_error, float);
  SETGET(detail_sample_distance, float);
  SETGET(detail_sample_max_error, float);
  SETGET(padding, Vector3);
  SETGET(max_layers, int);

  inline real_t get_tile_edge_length() { return get_tile_size() * get_cell_size(); };
};
} // namespace godot
