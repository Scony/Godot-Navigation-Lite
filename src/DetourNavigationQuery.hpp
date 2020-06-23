#pragma once

#include <string>

#include <DetourNavMeshQuery.h>
#include <Dictionary.hpp>
#include <Godot.hpp>

#include "DetourNavigationQueryFilter.hpp"

namespace godot
{
class DetourNavigationQuery
{
  dtNavMeshQuery* navmesh_query;
  godot::Transform transform;
  godot::Transform inverse;

 protected:
  static const int MAX_POLYS = 256;

  Dictionary _find_path(
      const Vector3& start,
      const Vector3& end,
      const Vector3& extents,
      DetourNavigationQueryFilter* filter);

 public:
  class QueryData
  {
   public:
    Vector3 path_points[MAX_POLYS];
    unsigned char path_flags[MAX_POLYS];
    dtPolyRef polys[MAX_POLYS];
    dtPolyRef path_polys[MAX_POLYS];
  };
  QueryData* query_data = nullptr;

  DetourNavigationQuery();
  ~DetourNavigationQuery();

  dtNavMesh* detour_navmesh = nullptr;

  void init(dtNavMesh* dtMesh, const Transform& xform);

  int get_max_polys() const { return MAX_POLYS; }
  Dictionary find_path(
      const Vector3& start,
      const Vector3& end,
      const Vector3& extents,
      DetourNavigationQueryFilter* filter);
};
} // namespace godot
