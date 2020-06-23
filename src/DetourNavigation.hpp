#pragma once

#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <thread>

#include <BoxShape.hpp>
#include <CapsuleMesh.hpp>
#include <CapsuleShape.hpp>
#include <CollisionShape.hpp>
#include <ConcavePolygonShape.hpp>
#include <ConvexPolygonShape.hpp>
#include <CubeMesh.hpp>
#include <CylinderMesh.hpp>
#include <CylinderShape.hpp>
#include <Engine.hpp>
#include <Godot.hpp>
#include <MeshInstance.hpp>
#include <PhysicsDirectSpaceState.hpp>
#include <PhysicsShapeQueryParameters.hpp>
#include <SceneTree.hpp>
#include <Spatial.hpp>
#include <SphereMesh.hpp>
#include <SphereShape.hpp>
#include <StaticBody.hpp>
#include <World.hpp>

#include "DetourNavMesh.h"
#include "Recast.h"
#include "RecastAlloc.h"
#include "RecastAssert.h"
#include "helpers.h"

#include "DetourNavigationMesh.hpp"
#include "DetourNavigationMeshCacheGenerator.hpp"
#include "DetourNavigationMeshCached.hpp"
#include "DetourNavigationMeshGenerator.hpp"

namespace godot
{
class DetourNavigation : public Spatial
{
  GODOT_CLASS(DetourNavigation, Spatial)
  enum // ParsedGeometryType
  {
    PARSED_GEOMETRY_STATIC_COLLIDERS = 0,
    PARSED_GEOMETRY_MESH_INSTANCES = 1,
  };

 public:
  static void _register_methods();

  DetourNavigation();
  ~DetourNavigation();

  // registered methods
  void _init();
  void _ready();
  void _enter_tree();
  void _process(float passed);
  void _exit_tree();
  void _on_tree_exiting();

  DetourNavigationMesh* create_navmesh(Ref<NavmeshParameters> np);
  DetourNavigationMeshCached* create_cached_navmesh(Ref<CachedNavmeshParameters> np);

  void _on_cache_collision_shape_added(Variant node);
  void _on_cache_collision_shape_removed(Variant node);
  void _on_collision_shape_added(Variant node);
  void _on_collision_shape_removed(Variant node);

  // exported properties
  SETGET(auto_object_management, bool)

  // stored properties
  SETGET(parsed_geometry_type, int);
  SETGET(dynamic_objects, bool);
  SETGET(dynamic_collision_mask, int);
  SETGET(collision_mask, int);

  // stuff
  void recalculate_masks();
  void fill_pointer_arrays();
  void manage_changes();
  void update_tilecache();
  void rebuild_dirty_debug_meshes();
  void add_box_obstacle_to_all(
      int64_t instance_id,
      Vector3 position,
      Vector3 extents,
      float rotationY,
      int collision_layer);
  void add_cylinder_obstacle_to_all(
      int64_t instance_id,
      Vector3 position,
      float radius,
      float height,
      int collision_layer);
  void remove_obstacle(CollisionShape* collision_shape);
  void save_collision_shapes(DetourNavigationMeshGenerator* generator);
  void build_navmesh(DetourNavigationMesh* navigation);
  void build_navmesh_cached(DetourNavigationMeshCached* navmesh);
  void _notification(int p_what);
  void _on_node_renamed(Variant v);
  int process_large_mesh(
      MeshInstance* mesh_instance,
      int64_t collision_id,
      std::vector<Ref<Mesh>>* meshes,
      std::vector<Transform>* transforms,
      std::vector<AABB>* aabbs,
      std::vector<int64_t>* collision_ids);
  void recognize_stored_collision_shapes();
  void collect_mappings(Dictionary& mappings, Array element);
  void map_collision_shapes(DetourNavigationMesh* nm, Dictionary& mappings);

  std::vector<DetourNavigationMesh*> navmeshes;
  std::vector<DetourNavigationMeshCached*> cached_navmeshes;

 private:
  float aggregated_time_passed = 0.f;

  void collect_geometry(
      Array geometries,
      std::vector<Ref<Mesh>>* meshes,
      std::vector<Transform>* transforms,
      std::vector<AABB>* aabbs,
      std::vector<int64_t>* collision_ids,
      DetourNavigationMesh* navmesh);

  void convert_collision_shape(
      CollisionShape* collision_shape,
      std::vector<Ref<Mesh>>* meshes,
      std::vector<Transform>* transforms,
      std::vector<AABB>* aabbs,
      std::vector<int64_t>* collision_ids);

  std::vector<PhysicsBody*> dyn_bodies_to_add;
  std::vector<StaticBody*> static_bodies_to_add;
  std::vector<int64_t> collisions_to_remove;
};

} // namespace godot
