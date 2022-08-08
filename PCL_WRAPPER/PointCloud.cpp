#include "PointCloud.h"

namespace PCL_CLI {

	int PointCloudXYZ::Size::get() {
		return Instance->size();
	}

	PointXYZ^ PointCloudXYZ::default::get(int idx) {
		float x = (*Instance)[idx].x;
		float y = (*Instance)[idx].y;
		float z = (*Instance)[idx].z;
		return gcnew PointXYZ(x,y,z);
	}

}