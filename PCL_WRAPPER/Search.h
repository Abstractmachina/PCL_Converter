#pragma once

#include "..\PCL_CORE\Search.h"
#include "PointCloud.h"
#include "Conversions.h"

namespace PCL_CLI {

	public ref class Search {
	public:
		static array<int>^ KdTreeKNNSearch(const int searchPtIdx, PointCloudXYZ^ pointCloud,
			const int k, array<float>^% out_distances);
	};

}
