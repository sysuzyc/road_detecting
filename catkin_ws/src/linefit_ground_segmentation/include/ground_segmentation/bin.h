#ifndef GROUND_SEGMENTATION_BIN_H_
#define GROUND_SEGMENTATION_BIN_H_

#include <atomic>

#include <pcl/point_cloud.h>
#include <pcl/point_types.h>

class Bin {
public:
  /*设定了一个最小Z点的结构体，其中是一个二维结构，在x-y平面的线段长度，以及z轴上的数值*/
  struct MinZPoint {
    MinZPoint() : z(0), d(0) {}
    MinZPoint(const double& d, const double& z) : z(z), d(d) {}
    bool operator==(const MinZPoint& comp) {return z == comp.z && d == comp.d;}

    double z;
    double d;
  };

private:

  std::atomic<bool> has_point_;
  std::atomic<double> min_z;
  std::atomic<double> min_z_range;

public:

  Bin();

  /// \brief Fake copy constructor to allow vector<vector<Bin> > initialization.
  Bin(const Bin& segment);

  void addPoint(const pcl::PointXYZ& point);

  void addPoint(const double& d, const double& z);

  MinZPoint getMinZPoint();

  inline bool hasPoint() {return has_point_;}

};

#endif /* GROUND_SEGMENTATION_BIN_H_ */
