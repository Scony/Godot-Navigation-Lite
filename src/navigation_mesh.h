#pragma once

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include <ArrayMesh.hpp>
#include <CollisionShape.hpp>
#include <Geometry.hpp>
#include <Godot.hpp>
#include <Mesh.hpp>
#include <MeshInstance.hpp>
#include <Node.hpp>
#include <Ref.hpp>
#include <SceneTree.hpp>
#include <Spatial.hpp>
#include <SpatialMaterial.hpp>
#include <WeakRef.hpp>

#include "DetourNavMesh.h"
#include "DetourNavMeshBuilder.h"
#include "DetourTileCache.h"
#include "Recast.h"
#include "helpers.h"

#include "navigation_query.h"
#include "navmesh_generator.h"
#include "navmesh_parameters.h"
#include "serializer.h"
#include "tilecache_helpers.h"

namespace godot
{
class DetourNavigationMesh : public Spatial
{
  GODOT_CLASS(DetourNavigationMesh, Spatial);

 public:
  static void _register_methods();

  DetourNavigationMesh();
  ~DetourNavigationMesh();

  // registered functions
  void _init();
  void _ready();
  void _exit_tree();
  void _notification(int p_what);

  void build_navmesh();
  void save_mesh();
  void clear_navmesh();
  Dictionary find_path(Variant from, Variant to);

  // exported properties
  void set_collision_mask(int cm);
  int get_collision_mask() { return collision_mask; }

  void set_debug_mesh_color(Color dmc);
  Color get_debug_mesh_color() { return debug_mesh_color; }

  SETGET(group_name, String);

  // stored properties
  SETGET(input_meshes_storage, Array);
  SETGET(input_transforms_storage, Array);
  SETGET(input_aabbs_storage, Array);
  SETGET(collision_ids_storage, Array);
  SETGET(serialized_navmesh_data, PoolByteArray);
  SETGET(uuid, String);

  // stuff
  bool alloc();
  void release_navmesh();
  bool unsigned_int();
  bool load_mesh();
  void store_inputs();
  bool load_inputs();
  void build_debug_mesh(bool force_build);
  DetourNavigationMeshGenerator* init_generator(Transform global_transform);
  Ref<Material> get_debug_navigation_material();
  virtual dtTileCache* get_tile_cache() { return nullptr; };
  void set_generator(DetourNavigationMeshGenerator* g) { generator = g; }
  DetourNavigationMeshGenerator* get_generator() { return generator; }
  dtNavMesh* get_detour_navmesh() { return detour_navmesh; }
  void init_navigation_mesh_values();
  void clear_debug_mesh();
  Ref<ArrayMesh> get_debug_mesh();

  bool debug_navmesh_dirty = true;
  MeshInstance* debug_mesh_instance = nullptr;
  DetourNavigationQuery* nav_query = nullptr;
  DetourNavigationQueryFilter* query_filter = nullptr;
  DetourNavigationMeshGenerator* generator = nullptr;
  AABB bounding_box;
  dtNavMesh* detour_navmesh = nullptr;
  Ref<ArrayMesh> debug_mesh = nullptr;
  Transform global_transform;
  Ref<NavmeshParameters> navmesh_parameters = nullptr;
  std::string navmesh_name = "default";

 protected:
  int collision_mask;
  Color debug_mesh_color;

 private:
  bool _is_being_deleted = false;
};

} // namespace godot
