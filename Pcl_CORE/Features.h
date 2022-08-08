#pragma once
#include <pcl/point_types.h>
#include <pcl/features/normal_3d.h>


namespace PCL_CORE
{
	const int POINTXYZSIZE = 3;
	const int NORMALSIZE = 4;
	class Features {
		
	public:
		Features() {}
		pcl::PointCloud<pcl::Normal>::Ptr CalcNormals(const pcl::PointCloud<pcl::PointXYZ>& input, float searchRadius);
		float* CalcNormals(float* points, const int rows, float searchRadius);

		int test(float v) {
			return 1;
		}
	};
}