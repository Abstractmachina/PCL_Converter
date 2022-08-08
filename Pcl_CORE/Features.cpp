#include "Features.h"

namespace PCL_CORE {
	pcl::PointCloud<pcl::Normal>::Ptr Features::CalcNormals(const pcl::PointCloud<pcl::PointXYZ>& inputCloud, float searchRadius) {
		//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZ>(inputCloud));


		//... read, pass in or create a point cloud ...

		// Create the normal estimation class, and pass the input dataset to it
		pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
		ne.setInputCloud(cloud_ptr);

		// Create an empty kdtree representation, and pass it to the normal estimation object.
		// Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
		pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());
		ne.setSearchMethod(tree);

		// Output datasets
		pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);

		// Use all neighbors in a sphere of radius 3cm
		ne.setRadiusSearch(searchRadius);

		// Compute the features
		ne.compute(*cloud_normals);

		return cloud_normals;

		// cloud_normals->size () should have the same size as the input cloud->size ()*
	}

	//for testing
	float* Features::CalcNormals(float* points, const int numRows, float searchRadius) {
		//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
		pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZ>());

		for (int r = 0; r < numRows; r++) {
			int curIdx = r * PCL_CORE::POINTXYZSIZE;
			float x = points[curIdx];
			float y = points[curIdx+1];
			float z = points[curIdx+2];
			auto p = new pcl::PointXYZ(x,y,z);
			cloud_ptr->push_back(*p);
		}

		// Create the normal estimation class, and pass the input dataset to it
		pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
		ne.setInputCloud(cloud_ptr);

		// Create an empty kdtree representation, and pass it to the normal estimation object.
		// Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
		pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());
		ne.setSearchMethod(tree);

		// Output datasets
		pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);

		// Use all neighbors in a sphere of radius 3cm
		ne.setRadiusSearch(searchRadius);

		// Compute the features
		ne.compute(*cloud_normals);
		float* normals = new float[numRows * NORMALSIZE];
		
		for (int i = 0; i < numRows; i++) {
			auto n = (*cloud_normals)[i];
			int curIdx = i * NORMALSIZE;

			normals[curIdx] = n.normal_x;
			normals[curIdx+1] = n.normal_y;
			normals[curIdx+2] = n.normal_z;
			normals[curIdx+3] = n.curvature;
		}

		return normals;
	}
}