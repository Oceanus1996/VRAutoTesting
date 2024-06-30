VR Controller Simulator

1. Project Overview
1.1 Project Name
VR Controller Simulator

1.2 Background
This project aims to simulate the behavior of VR controllers for automated testing of the GUI of VR applications.
Separate from Unity and other mature frameworks, it achieves pervasive control of VR-related functions, including but not limited to movement, click, drop-down, and other interactive behaviors.
Project Processing Logic: Achieve automated control of VR by writing drivers under the OpenVR framework.

2. System Requirements
2.1 Hardware Requirements
A pair of Oculus Quest2 VR glasses and controller grips.
A 3.0 USB cable for connection and communication.
2.2 Software Requirements
Meta Quest Link: Handles the interactive behavior between SteamVR and VR glasses, transferring information from Quest2 via data cable.
SteamVR: Handles and displays information related to Meta Quest Link and interacts with modified drivers.
OpenVR: Used to write the driver framework, requires QT5.X and CMake to be configured for compilation and proper operation https://github.com/ValveSoftware/openvr.
Unity: Used to write test cases. The project involves test cases from the Github open repository VR-Unity-Template-2023 https://github.com/Fist-Full-of-Shrimp/VR-Unity-Template-2023.
Visual Studio: For editing and compiling the driver code. VS 2022 is recommended for compatibility with SteamVR-related
requirements and handling C++ code.

3. Installation Guide
3.1 Environment Configuration
Use of OpenVR: The project relies on the OpenVR API, an API application that integrates a multi-architecture plug-in. Its main advantages are compatibility with a wide range of head-mounted displays and output of relatively uniform code formats and definitions.
Code Acquisition: The relevant code has been stored in a specific location (e.g., a Git repository or a shared drive).
4. Code Structure
4.1 Files and Directories
Driver Code Structure
css
Copy code
simplecontroller/
├── src/
│   ├── controller_device_driver.cpp
│   ├── controller_device_driver.h
│   ├── device_provider.cpp
│   ├── device_provider.h
│   └── hmd_driver_factory.cpp
├── resource/
│   ├── icons/
│   ├── settings/
│   │   └── default.vrsettings
│   ├── input/
│   │   ├── my_controller_profile.json
│   │   ├── legacy_bindings_simplecontroller.json
│   │   ├── simple_controller_remapping.json
│   │   └── localization/
│   │       └── localization.json
Script Structure
Copy code
scripts/
├── testipc.ipynb
└── testui.json
5. Usage Guide
5.1 Running Steps
Start the Script: First, start the testipc.ipynb script. This file contains a series of instructions written in Jupyter, defining the GameObject class and packing the relevant movement and click logic in testui.json. This is then transmitted to shared memory.
Driver Execution: The virtual controller (driver) processes the commands and displays the results on the SteamVR interface, simulating actions such as auto-movement.
6. Code Explanation
6.1 Key Parts - Driver Internal Processing
Driver Implementation: OpenVR drivers are implemented in C++ with a lot of pure virtual functions. The driver is compiled into a DLL in the Windows system. We place the driver DLL into SteamVR's folder, which automatically loads the DLL at runtime. The typical folder in the Windows system is "C:\Program Files(x86)\Steam\steamapps\common\SteamVR\drivers". We create the driver named driver_simplecontroller.dll and place it in the ....\drivers\simplecontroller\bin\win64 folder. The driver first reads the configuration file mycontroller_profile.json from the ....\drivers\simplecontroller\resources\input folder. The driver continuously reads commands from shared memory and displays them in SteamVR.
Connection Between Script and Driver: The external script and the internal driver communicate through shared memory, passing information and commands.

7. Testing
7.1 Testing Environment
Based on the VR open library for movement testing. This library is from the VR-Unity-Template-2023, simulating various button interaction scenarios in a 3D environment.
7.2 Test Cases
Confirm the specific position of the buttons.
Configure JSON files like:
{
    "explain": "click input field prepare to input",
    "x": -0.29,
    "y": 1.15,
    "z": -0.4,
    "ftime": 3,
    "bclick": true,
    "bdown": false,
    "bup": false
}
The x, y, z coordinates are relative coordinates based on the right-hand coordinate system. The script reads this file to achieve the corresponding movement and click operations.
8. FAQ

Q: Basic configuration options for SteamVR?
A: To be compatible with OpenVR, shared memory, and SteamVR, we use Virtual Studio 2022, Qt5.x, and Shared Memory for module communication and compatibility.
Q: How to ensure the JSON file is read and the new driver is configured in OpenVR?
A: Copy driver_simplecontroller.dll and mycontroller_profile.json to the relevant folders. You may also need to modify some configuration files. The file and folder structure must follow OpenVR's specifications. Refer to the OpenVR documentation for structure details: https://github.com/ValveSoftware/openvr/tree/master/samples/drivers/drivers/simplecontroller/simplecontroller
