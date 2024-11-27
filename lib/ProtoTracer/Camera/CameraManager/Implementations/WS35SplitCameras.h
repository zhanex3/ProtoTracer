#pragma once

#include "../CameraManager.h"
#include "../../Camera.h"
#include "../../Pixels/PixelGroup.h"
#include "../../Pixels/PixelGroups/WS35Pixels.h"
#include "../../Pixels/PixelGroups/SideDisplay.h"
#include "../../Pixels/PixelGroups/SideFins.h"
#include "../../Pixels/PixelGroups/LinearPixels.h"
#include "../../../Utils/Math/Transform.h"

class WS35SplitCameraManager : public CameraManager {
private:
    CameraLayout cameraLayout = CameraLayout(CameraLayout::ZForward, CameraLayout::YUp);
    Transform camRghtTransform = Transform(Vector3D(), Vector3D(-170, 0, -500.0f), Vector3D(1, 1, 1));
    Transform camLeftTransform = Transform(Vector3D(), Vector3D(0, 0, -500.0f), Vector3D(1, 1, 1));
    PixelGroup<571> camRghtPixels = PixelGroup<571>(WS35Pixels, IPixelGroup::ZEROTOMAX);
    PixelGroup<571> camLeftPixels = PixelGroup<571>(WS35Pixels, IPixelGroup::MAXTOZERO);
    Camera<571> camRght = Camera<571>(&camRghtTransform, &cameraLayout, &camRghtPixels);
    Camera<571> camLeft = Camera<571>(&camLeftTransform, &cameraLayout, &camLeftPixels);
    
    Transform transform = Transform(Vector3D(), Vector3D(0, 0, -500.0f), Vector3D(1, 1, 1));

    Transform ledFin = Transform(Vector3D(), Vector3D(0, -50, -500.0f), Vector3D(1, 1, 1));

    PixelGroup<17> camRightSideFinPixels = PixelGroup<17>(SideFins, IPixelGroup::ZEROTOMAX);
    PixelGroup<17> camLeftSideFinPixels = PixelGroup<17>(SideFins, IPixelGroup::ZEROTOMAX);
    Camera<17> camRightSideFin = Camera<17>(&transform, &camRightSideFinPixels);
    Camera<17> camLeftSideFin = Camera<17>(&transform, &camLeftSideFinPixels);

    PixelGroup<19> rightCamSideDisplayPixels = PixelGroup<19>(SideDisplay, IPixelGroup::ZEROTOMAX);
    PixelGroup<19> leftCamSideDisplayPixels = PixelGroup<19>(SideDisplay, IPixelGroup::ZEROTOMAX);
    Camera<19> camRightSideDisplay = Camera<19>(&transform, &rightCamSideDisplayPixels);
    Camera<19> camLeftSideDisplay = Camera<19>(&transform, &leftCamSideDisplayPixels);

public:
    WS35SplitCameraManager() : CameraManager(new CameraBase*[6]{ &camRght, &camLeft, &camRightSideFin,&camLeftSideFin, &camRightSideDisplay, &camLeftSideDisplay }, 6) {}
};
