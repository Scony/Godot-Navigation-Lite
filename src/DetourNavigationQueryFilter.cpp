#include "DetourNavigationQueryFilter.hpp"

namespace godot
{
DetourNavigationQueryFilter::DetourNavigationQueryFilter()
{
  dt_query_filter = new dtQueryFilter();
}

DetourNavigationQueryFilter::~DetourNavigationQueryFilter()
{
  delete dt_query_filter;
}

} // namespace godot
