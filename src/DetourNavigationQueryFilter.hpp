#pragma once

#include <DetourNavMeshQuery.h>

namespace godot
{
class DetourNavigationQueryFilter
{
 public:
  dtQueryFilter* dt_query_filter;
  DetourNavigationQueryFilter();
  ~DetourNavigationQueryFilter();
};
} // namespace godot
