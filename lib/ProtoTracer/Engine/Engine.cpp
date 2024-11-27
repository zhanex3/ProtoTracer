#include "Engine.h"

void RenderingEngine::Rasterize(Scene* scene, CameraManager* cameraManager) {
    for (int i = 0; i < cameraManager->GetCameraCount(); i++) {

        if (cameraManager->GetCameras()[i]->Is2D()) {
            Rasterizer::TwoDRasterize(scene, cameraManager->GetCameras()[i], i);
        }
        else 
        {
        Rasterizer::Rasterize(scene, cameraManager->GetCameras()[i]);
        }

        if (scene->UseEffect()) {
            scene->GetEffect()->ApplyEffect(cameraManager->GetCameras()[i]->GetPixelGroup());
        }
    }
}

void RenderingEngine::DisplayWhite(CameraManager* cameraManager) {
    for (int i = 0; i < cameraManager->GetCameraCount(); i++) {
        DisplayTest::FillWhite(cameraManager->GetCameras()[i]);
    }
}
