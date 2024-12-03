#pragma once

#include "../../../Scene/Materials/Static/SimpleMaterial.h"
#include "../../../Scene/Objects/Object3D.h"

class BlushIcons{
private:
	Vector3D basisVertices[10] = {Vector3D(5.0000f,0.0000f,1200.0000f),Vector3D(2.50000f,2.5000f,1200.000f),Vector3D(0.0000f,5.0000f,1200.000f),Vector3D(0.0000f,10.000f,1200.000f),Vector3D(2.5000f,12.5000f,1200.000f),Vector3D(5.0000f,15.0000f,1200.000f),Vector3D(7.5000f,12.500f,1200.000f),Vector3D(9.000f,10.0000f,1200.000f),Vector3D(9.000f,5.0000f,1200.000f),Vector3D(7.500f,2.5000f,1200.000f)};
	IndexGroup basisIndexes[1] = {IndexGroup(0,1,2)};
	StaticTriangleGroup<3,1> triangleGroup = StaticTriangleGroup<3,1>(&basisVertices[0], &basisIndexes[0]);
	TriangleGroup<3,1> triangleGroupMemory = TriangleGroup<3,1>(&triangleGroup);
	SimpleMaterial simpleMaterial = SimpleMaterial(RGBColor(128, 128, 128));
	Object3D basisObj = Object3D(&triangleGroup, &triangleGroupMemory, &simpleMaterial);

public:
	BlushIcons(){}

	Object3D* GetObject(){
		return &basisObj;
	}
};
