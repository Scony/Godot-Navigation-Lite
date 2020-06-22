#include "CachedNavmeshParameters.hpp"

namespace godot
{
// TODO: extract
static const int DEFAULT_TILE_SIZE = 64;
static const float DEFAULT_CELL_SIZE = 0.3f;
static const float DEFAULT_CELL_HEIGHT = 0.2f;
static const float DEFAULT_AGENT_HEIGHT = 2.0f;
static const float DEFAULT_AGENT_RADIUS = 0.6f;
static const float DEFAULT_AGENT_MAX_CLIMB = 0.9f;
static const float DEFAULT_AGENT_MAX_SLOPE = 45.0f;
static const float DEFAULT_REGION_MIN_SIZE = 8.0f;
static const float DEFAULT_REGION_MERGE_SIZE = 20.0f;
static const float DEFAULT_EDGE_MAX_LENGTH = 12.0f;
static const float DEFAULT_EDGE_MAX_ERROR = 1.3f;
static const float DEFAULT_DETAIL_SAMPLE_DISTANCE = 6.0f;
static const float DEFAULT_DETAIL_SAMPLE_MAX_ERROR = 1.0f;

static const int DEFAULT_MAX_OBSTACLES = 1000;
static const int DEFAULT_MAX_LAYERS = 8;

CachedNavmeshParameters::CachedNavmeshParameters() {}

CachedNavmeshParameters::~CachedNavmeshParameters() {}

void CachedNavmeshParameters::_init()
{
  NavmeshParameters::_init();
  max_obstacles = DEFAULT_MAX_OBSTACLES;
  max_layers = DEFAULT_MAX_LAYERS;
}

void CachedNavmeshParameters::_ready() {}

void CachedNavmeshParameters::_register_methods()
{
  register_property<CachedNavmeshParameters, real_t>(
      "cell_size",
      &CachedNavmeshParameters::set_cell_size,
      &CachedNavmeshParameters::get_cell_size,
      DEFAULT_CELL_SIZE);
  register_property<CachedNavmeshParameters, int>(
      "tile_size",
      &CachedNavmeshParameters::set_tile_size,
      &CachedNavmeshParameters::get_tile_size,
      DEFAULT_TILE_SIZE);
  register_property<CachedNavmeshParameters, real_t>(
      "cell_height",
      &CachedNavmeshParameters::set_cell_height,
      &CachedNavmeshParameters::get_cell_height,
      DEFAULT_CELL_HEIGHT);

  register_property<CachedNavmeshParameters, real_t>(
      "agent_height",
      &CachedNavmeshParameters::set_agent_height,
      &CachedNavmeshParameters::get_agent_height,
      DEFAULT_AGENT_HEIGHT);
  register_property<CachedNavmeshParameters, real_t>(
      "agent_radius",
      &CachedNavmeshParameters::set_agent_radius,
      &CachedNavmeshParameters::get_agent_radius,
      DEFAULT_AGENT_RADIUS);
  register_property<CachedNavmeshParameters, real_t>(
      "agent_max_climb",
      &CachedNavmeshParameters::set_agent_max_climb,
      &CachedNavmeshParameters::get_agent_max_climb,
      DEFAULT_AGENT_MAX_CLIMB);
  register_property<CachedNavmeshParameters, real_t>(
      "agent_max_slope",
      &CachedNavmeshParameters::set_agent_max_slope,
      &CachedNavmeshParameters::get_agent_max_slope,
      DEFAULT_AGENT_MAX_SLOPE);

  register_property<CachedNavmeshParameters, real_t>(
      "region_min_size",
      &CachedNavmeshParameters::set_region_min_size,
      &CachedNavmeshParameters::get_region_min_size,
      DEFAULT_REGION_MIN_SIZE);
  register_property<CachedNavmeshParameters, real_t>(
      "region_merge_size",
      &CachedNavmeshParameters::set_region_merge_size,
      &CachedNavmeshParameters::get_region_merge_size,
      DEFAULT_REGION_MERGE_SIZE);
  register_property<CachedNavmeshParameters, real_t>(
      "edge_max_length",
      &CachedNavmeshParameters::set_edge_max_length,
      &CachedNavmeshParameters::get_edge_max_length,
      DEFAULT_EDGE_MAX_LENGTH);
  register_property<CachedNavmeshParameters, real_t>(
      "edge_max_error",
      &CachedNavmeshParameters::set_edge_max_error,
      &CachedNavmeshParameters::get_edge_max_error,
      DEFAULT_EDGE_MAX_ERROR);

  register_property<CachedNavmeshParameters, real_t>(
      "detail_sample_distance",
      &CachedNavmeshParameters::set_detail_sample_distance,
      &CachedNavmeshParameters::get_detail_sample_distance,
      DEFAULT_DETAIL_SAMPLE_DISTANCE);
  register_property<CachedNavmeshParameters, real_t>(
      "detail_sample_max_error",
      &CachedNavmeshParameters::set_detail_sample_max_error,
      &CachedNavmeshParameters::get_detail_sample_max_error,
      DEFAULT_DETAIL_SAMPLE_MAX_ERROR);
  // register_property<CachedNavmeshParameters, Vector3>("padding", &NavmeshParameters::set_padding,
  // &NavmeshParameters::get_padding, Vector3(1.0f, 1.0f, 1.0f));

  register_property<CachedNavmeshParameters, int>(
      "max_obstacles",
      &CachedNavmeshParameters::set_max_obstacles,
      &CachedNavmeshParameters::get_max_obstacles,
      DEFAULT_MAX_OBSTACLES);
  register_property<CachedNavmeshParameters, int>(
      "max_layers",
      &CachedNavmeshParameters::set_max_layers,
      &CachedNavmeshParameters::get_max_layers,
      DEFAULT_MAX_LAYERS);
}
} // namespace godot
