#include "viewing_ray.h"

void viewing_ray(
  const Camera & camera,
  const int i,
  const int j,
  const int width,
  const int height,
  Ray & ray)
{
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  // Compute the viewing ray given the pixel location (i,j) and the camera parameters
  // From the lecture slides, we know that the viewing ray is:
  // ray = e + (i - (width-1)/2) * u + (j - (height-1)/2) * v - d * w
  // where e is the camera position, u is the camera right vector, v is the camera up vector, w is the camera view vector, and d is the focal length.
  ray.origin = camera.e;
  // Left and bottom are negative because the origin is at the center of the image
  double left = -camera.width/2;
  double right = camera.width/2;
  double top = camera.height/2;
  double bottom = -camera.height/2;
  double focus = camera.d;

  // Compute the u, v, and w vectors
  // From equations in lecture
  double u = (right - left) * (j + 0.5) / width + left;
  double v = bottom + camera.height - (top - bottom) * (i + 0.5) / height;

  // Compute the direction vector
  // From equations in lecture
  ray.direction = -focus * camera.w + u * camera.u + v * camera.v;

  ////////////////////////////////////////////////////////////////////////////
}
