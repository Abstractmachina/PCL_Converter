#include "Util.h"

namespace PCL_CLI {

	//PCL_CLI::PointCloudNormal^ Util::CalcNormals(PCL_CLI::PointCloudXYZ% inputCloud, float searchRadius) {
	//	//pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	//	auto c = inputCloud.Instance;
	//	
	//	pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(c);

	//	// Create the normal estimation class, and pass the input dataset to it
	//	pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
	//	ne.setInputCloud(cloud);

	//	// Create an empty kdtree representation, and pass it to the normal estimation object.
	//	// Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
	//	pcl::search::KdTree<pcl::PointXYZ>::Ptr tree(new pcl::search::KdTree<pcl::PointXYZ>());
	//	ne.setSearchMethod(tree);

	//	// Output datasets
	//	pcl::PointCloud<pcl::Normal>::Ptr cloud_normals(new pcl::PointCloud<pcl::Normal>);

	//	// Use all neighbors in a sphere of search radius
	//	ne.setRadiusSearch(searchRadius);

	//	// Compute the features
	//	ne.compute(*cloud_normals);

	//	int ARRAY_SIZE = cloud_normals->size();
	//	array<PCL_CLI::Normal^>^ converted_normals
	//		= gcnew array<PCL_CLI::Normal^>(ARRAY_SIZE);

	//	auto normal_cloud = gcnew PCL_CLI::PointCloudNormal();

	//	for (int i = 0; i < ARRAY_SIZE; i++) {

	//		auto n = (*cloud_normals)[i];
	//		auto converted = gcnew PCL_CLI::Normal(
	//			n.normal_x, n.normal_y,
	//			n.normal_z, n.curvature);

	//		normal_cloud->Pushback(converted);
	//	}

	//	return normal_cloud;

	//	//		//auto cloud_converted = gcnew PCL_CLI::PointCloudNormal();
	//	//		//return cloud_converted;
	//	//		//return cloud_normals;

	//	//		// cloud_normals->size () should have the same size as the input cloud->size ()*
	//}
}