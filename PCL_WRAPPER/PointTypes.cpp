#include "PointTypes.h"

namespace PCL_CLI {
	PointXYZ::PointXYZ() : ManagedObject(new pcl::PointXYZ()) {}

	PointXYZ::PointXYZ(float x, float y, float z) :
		ManagedObject(new pcl::PointXYZ(x, y, z)) {}
	//X
	float PointXYZ::X::get() {
		return Instance->x;
	}
	void PointXYZ::X::set(float value) {
		Instance->x = value;
	}
	//Y
	float PointXYZ::Y::get() {
		return Instance->y;
	}
	void PointXYZ::Y::set(float value) {
		Instance->y = value;
	}
	//Z
	float PointXYZ::Z::get() {
		return Instance->z;
	}
	void PointXYZ::Z::set(float value) {
		Instance->z = value;
	}
}