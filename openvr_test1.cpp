//#include <openvr/openvr_capi.h>
#include <openvr/openvr.h>
//#include <openvr/openvr_driver.h>
#include <iostream>

using namespace std;

int main() {
    vr::EVRInitError eError = vr::VRInitError_None; 
        // Many functions require this error object
    
    vr::IVROverlay *ov = vr::VROverlay();
        // I stands for interface class
            // This means this class lets us create, destroy... the overlay
        // Creating the overlay object

    if(!vr::VR_IsHmdPresent()) { // Test wether VR is even present
        cout << "NO VR" << endl;
    }

    vr::VR_Init(&eError, vr::VRApplication_Overlay); // Init VR

    if (eError != vr::VRInitError_None) {
        // If eError doesn't come back equalling the defined error none, throw error
        cout << "VR init error" << endl;
    }

    // Now we are going to create an overlay handle and set some properties

    vr::VROverlayHandle_t ovHandle;

    // VROverlay is mereley accessing the IVR instance, we are manipulating off of this handle
    vr::VROverlay()->CreateOverlay("glorp", "Glorp Overlay", &ovHandle);

    vr::Texture_t ovTexture;
    ovTexture.handle = static_cast<void*>(imgData); // Image data is what we are going to draw onto the ov
    ovTexture.eType = vr::TextureType_OpenGL; // Texture type is now opengl
    ovTexture.eColorSpace = vr::ColorSpace_Auto;

    vr::VROverlay()->SetOverlayTexture(ovHandle, &ovTexture);
        // Once again we are accessing the IVR through this function 
        // Set the overlay texture to what we setup with the Texure_t

    //vr::HmdMatrix34_t ovTransform;

    //vr::VROverlay()->SetOverlayTransformTrackedDeviceRelative(ovHandle)

}