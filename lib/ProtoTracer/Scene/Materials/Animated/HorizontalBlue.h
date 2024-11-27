#pragma once

#include "../AnimatedMaterial.h"
#include "../Static/GradientMaterial.h"
#include "../Static/SimplexNoise.h"

class HorizontalBlue : public AnimatedMaterial {
private:
    RGBColor noiseSpectrum[7] = {RGBColor(0, 0, 255), RGBColor(255, 255, 255),RGBColor(0, 0, 255),RGBColor(0, 0, 255),RGBColor(0, 0, 255),RGBColor(0, 0, 255),RGBColor(0, 0, 255)};
    GradientMaterial<7> gNoiseMat = GradientMaterial<7>(&noiseSpectrum[0], 2.0f, false, false);
    float positionOffset = 0.0f;

public:
    HorizontalBlue() {}

    void Update(float ratio);
    Material* GetMaterial();
    RGBColor GetRGB(const Vector3D& position, const Vector3D& normal, const Vector3D& uvw) override;
};
