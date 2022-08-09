#pragma once

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

#include "Constants.h"

namespace PCL_CORE {

	class Util {
	public:
		static pcl::PointCloud<pcl::PointXYZ>::Ptr create_pointcloud(const float* points, const int numRows);
	};

}