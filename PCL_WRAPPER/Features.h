#pragma once

#include "ManagedObject.h"
#include "../Pcl_CORE/Features.h"
#include "PointCloud.h"

namespace PCL_CLI {

	public ref class Features : ManagedObject<PCL_CORE::Features> {

	public:
		Features() : ManagedObject(new PCL_CORE::Features()) {}
		PointCloudNormal^ CalcNormals(PointCloudXYZ^ inputCloud, float searchRadius);

	};


	/*PCL_CLI::PointCloudNormal^ CalcNormals(PCL_CLI::PointCloudXYZ^ inputCloud, float searchRadius) {

		pcl::PointCloud<pcl::PointXYZ> cloud = *(inputCloud->Instance);

		auto v = PCL_CORE::Features::CalcNormals(cloud, searchRadius);
		return gcnew PointCloudNormal();
	};*/

}