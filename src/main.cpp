#include "Examples/UserConfiguration.h"

#ifdef TESTHARDWARE
#include "Examples/Protogen/ProtogenHardwareTest.h"
#endif

//#include "Examples\Commissions\UnicornZhenjaAnimation.h"
//#include "Examples/Protogen/ProtogenHUB75Project.h"
//#include "Examples/Protogen/ProtogenWS35Project.h"
//#include "Examples\VerifyEngine.h"

//#include "Examples/Commissions/ArrowAnimation.h"
//#include "../lib/ProtoTracer/Examples/Protogen/BetaProject.h"


// #include "Examples/Protogen/ProtogenWS35Project.h"
// ProtogenWS35Project project;

#include "../lib/ProtoTracer/raas_source/project/RaasProject.h"
RaasProject project;


void setup() {
    Serial.begin(115200);
    Serial.println("\nStarting...");
    
    #ifndef TESTHARDWARE
    project.Initialize();
    delay(500);
    #else
    while(true){
        Serial.println("Hardware test...");
       // HardwareTest::ScanDevices();
       // HardwareTest::TestNeoTrellis();
        HardwareTest::TestBoopSensor();
      //  HardwareTest::TestHUD();
      //  HardwareTest::TestMicrophone(15);
    }
    #endif
}

void loop() {
    float ratio = (float)(millis() % 5000) / 5000.0f;

    project.Animate(ratio); 

    project.Render();

    project.Display();

   // project.PrintStats();
}