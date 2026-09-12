### Install Project Components

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Executes the installation process, optionally filtering by specific components.

```bash
# Install only native libraries
cmake --install . --component mcpelauncher-bin-libs

# Install all components
cmake --install .
```

--------------------------------

### Define Installation Prefix

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Sets the base directory for installation of the built project.

```cmake
cmake -DCMAKE_INSTALL_PREFIX=/opt/mcpelauncher ..
```

--------------------------------

### Install Qt Framework Dependencies

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Commands to install the required Qt5 development packages.

```bash
# Ubuntu/Debian
sudo apt-get install qt5-qmake qtbase5-dev

# macOS
brew install qt5

# Fedora/RHEL
sudo dnf install qt5-qtbase-devel
```

--------------------------------

### Install component via CLI

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Executes the installation of a specific component to a defined prefix.

```bash
cmake --install . --component mcpelauncher-bin-libs --prefix /usr/local
# Installs to /usr/local/share/mcpelauncher/lib/
```

--------------------------------

### Install MSA Dependency System-Wide

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Installs the compiled MSA daemon and UI system-wide using 'make install'. Note that this method does not use the system package manager.

```bash
sudo make install
```

--------------------------------

### Start PulseAudio

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/architecture-overview.md

Command to start the PulseAudio server if sound is not detected.

```bash
pulseaudio --start
```

--------------------------------

### Install dependencies on Ubuntu 20.04 LTS

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Use apt-get to install build tools, libraries, and optional components for UI and testing.

```bash
# Development tools
sudo apt-get install build-essential cmake git

# Dependencies
sudo apt-get install libssl-dev libcurl4-openssl-dev
sudo apt-get install libegl-dev libgles2-dev
sudo apt-get install libpulse-dev

# Qt (if UI build)
sudo apt-get install qt5-qmake qtbase5-dev qtwebengine5-dev

# Testing
sudo apt-get install libgtest-dev

# 32-bit support
sudo apt-get install gcc-multilib g++-multilib libc6-i386
```

--------------------------------

### Install Git, CMake, and Pkg-config on Ubuntu

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Installs essential build tools for compiling from source on Ubuntu.

```bash
sudo apt-get install git cmake pkg-config
```

--------------------------------

### Install mcpelauncher-bin-libs component

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Configures the installation of native library files with specific permissions and destination paths.

```cmake
install(
    DIRECTORY ${NATIVES_PATH_LIB_DIR} 
    COMPONENT mcpelauncher-bin-libs 
    DESTINATION share/mcpelauncher 
    PATTERN "*"
    PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ
)
```

--------------------------------

### Install Google Test Dependencies

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Commands to install the Google Test framework for building tests.

```bash
# Ubuntu/Debian
sudo apt-get install libgtest-dev

# macOS
brew install googletest

# Fedora/RHEL
sudo dnf install gtest-devel
```

--------------------------------

### Configure full release build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Sets up a production-ready release build with UI, webview, and specific installation paths.

```bash
cmake \
    -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=ON \
    -DBUILD_WEBVIEW=ON \
    -DENABLE_DEV_PATHS=OFF \
    -DMSA_DAEMON_PATH="../lib" \
    -DCMAKE_INSTALL_PREFIX=/usr/local \
    ..
```

--------------------------------

### Install dependencies on Fedora 38+

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Use dnf to install build tools, libraries, and optional components for UI and testing.

```bash
# Development tools
sudo dnf install cmake gcc g++ git make

# Dependencies
sudo dnf install openssl-devel libcurl-devel
sudo dnf install mesa-libEGL-devel mesa-libGL-devel
sudo dnf install pulseaudio-libs-devel

# Qt (if UI build)
sudo dnf install qt5-qtbase-devel qt5-qtwebengine-devel

# Testing
sudo dnf install gtest-devel

# 32-bit support
sudo dnf install glibc-devel.i686 libgcc.i686
```

--------------------------------

### Install MCPelauncher Prerequisites on Ubuntu

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Enables i386 architecture and installs necessary 32-bit development libraries for compiling MCPelauncher on Ubuntu.

```bash
sudo dpkg --add-architecture i386
sudo apt-get install g++-multilib libpng-dev:i386 libx11-dev:i386 libxi-dev:i386 libcurl4-openssl-dev:i386 libudev-dev:i386 libevdev-dev:i386 libegl1-mesa-dev:i386 libasound2:i386
```

--------------------------------

### Installation Directory Structure

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/project-structure.md

Displays the standard file hierarchy under the CMAKE_INSTALL_PREFIX directory.

```text
${CMAKE_INSTALL_PREFIX}/
├── share/mcpelauncher/
│   └── lib/  (native libraries)
```

--------------------------------

### Install dependencies on Arch Linux

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Use pacman to install build tools, libraries, and optional components for UI and testing.

```bash
# Development tools
sudo pacman -S base-devel cmake git

# Dependencies
sudo pacman -S openssl curl
sudo pacman -S libxslt

# Qt (if UI build)
sudo pacman -S qt5-base qt5-webengine

# Testing
sudo pacman -S gtest

# 32-bit support
sudo pacman -S lib32-glibc lib32-gcc-libs
```

--------------------------------

### Install Native Libraries

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/CMakeLists.txt

Configures the installation of native library files with specific execution and read permissions.

```cmake
install(DIRECTORY ${NATIVES_PATH_LIB_DIR} COMPONENT mcpelauncher-bin-libs DESTINATION share/mcpelauncher PATTERN "*"
        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ)
```

--------------------------------

### Install dependencies on macOS

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Use Homebrew to install build tools and dependencies, with an option to install Xcode command line tools.

```bash
# Development tools
brew install cmake git

# Dependencies
brew install openssl curl
brew install mesa

# Qt (if UI build)
brew install qt5

# Testing
brew install googletest

# Alternative: use system clang (Xcode)
xcode-select --install
```

--------------------------------

### Install MCPelauncher Prerequisites on macOS

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Installs CMake and libpng using Homebrew for compiling MCPelauncher on macOS.

```bash
brew install cmake libpng
```

--------------------------------

### Install PulseAudio Dependencies

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Commands to install PulseAudio development libraries for Linux distributions.

```bash
# Ubuntu/Debian
sudo apt-get install libpulse-dev

# Fedora/RHEL
sudo dnf install pulseaudio-libs-devel

# Arch
sudo pacman -S libpulse
```

--------------------------------

### Install MSA Dependency Prerequisites on Ubuntu 16.04

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Installs necessary libraries and development packages for compiling the MSA dependency on Ubuntu 16.04, including adding a Qt 5.9+ repository.

```bash
You must add a Qt 5.9+ repository first (add-apt-repository ppa:beineri/opt-qt596-xenial && apt-get update) from which you should install apt-get install qt59base qt59webengine; also install apt-get install libssl-dev libcurl4-openssl-dev
```

--------------------------------

### Install OpenSSL dependencies

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Commands to install or link OpenSSL on Ubuntu and macOS systems.

```bash
# Ubuntu
sudo apt-get install libssl-dev

# macOS
brew link openssl
export OPENSSL_ROOT_DIR=$(brew --prefix openssl)
cmake ..
```

--------------------------------

### Verify Installation Configuration

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Displays the current CMAKE_INSTALL_PREFIX setting.

```bash
cmake . -L | grep CMAKE_INSTALL_PREFIX
```

--------------------------------

### Install EGL and GLESv2 dependencies

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Commands to install graphics development libraries on various Linux distributions and verify macOS installations.

```bash
# Ubuntu
sudo apt-get install libegl-dev libgles2-dev

# Arch
sudo pacman -S mesa-libgl

# macOS
# Usually pre-installed, verify with:
find /System/Library -name "*OpenGL*"
```

--------------------------------

### Install MSA Dependency Prerequisites on macOS

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Installs CMake and Qt using Homebrew for compiling the MSA dependency on macOS.

```bash
brew install cmake qt
```

--------------------------------

### Install OpenSSL Dependencies

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Commands to install OpenSSL development headers on common package managers.

```bash
# Ubuntu/Debian
sudo apt-get install libssl-dev

# macOS
brew install openssl

# Fedora/RHEL
sudo dnf install openssl-devel
```

--------------------------------

### Create and Install MSA .deb Packages on Ubuntu

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Generates .deb packages for the MSA daemon and UI, then installs them using dpkg and apt-get to resolve dependencies.

```bash
cpack --config msa-daemon/CPackConfig.cmake
sudo dpkg -i  ./msa-daemon-0.1.1-Linux.deb && sudo apt-get install -f
cpack --config msa-ui-qt/CPackConfig.cmake
sudo dpkg -i  ./msa-ui-qt-0.1.1-Linux.deb && sudo apt-get install -f
```

--------------------------------

### Install MSA Dependency Prerequisites on Ubuntu 18.04+

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Installs necessary libraries and development packages for compiling the MSA dependency on Ubuntu 18.04 and later.

```bash
sudo apt-get install libssl-dev libcurl4-openssl-dev qtbase5-dev qtwebengine5-dev
```

--------------------------------

### Install EGL and OpenGL ES Dependencies

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Commands to install Mesa development headers for EGL and OpenGL ES on Linux.

```bash
# Mesa implementation (open source, most Linux distributions)
sudo apt-get install libegl-dev libgles2-dev

# Proprietary driver implementations
# NVIDIA: libEGL.so from nvidia-driver
# AMD: libEGL.so from amdgpu-pro or mesa
```

--------------------------------

### Use nlohmann/json in C++

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

Basic example of including the header and serializing a JSON object.

```cpp
#include <nlohmann/json.hpp>
using json = nlohmann::json;

json data;
data["key"] = "value";
std::string serialized = data.dump();
```

--------------------------------

### Configure 32-bit Compatibility Build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Enables x86 support. Requires 32-bit development libraries to be installed on the system.

```bash
cmake -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_X86=ON \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=ON \
    -DUSE_OWN_CURL=ON \
    ..
```

--------------------------------

### Check Graphics Library Installation

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/architecture-overview.md

Verify if EGL or GLESv2 libraries are detected by the system.

```bash
pkg-config --list-all | grep -E egl|gles
```

--------------------------------

### Resolve 32-bit build failures on 64-bit systems

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Commands to verify and install necessary 32-bit multilib libraries on Linux distributions.

```bash
# Check if 32-bit libraries installed
dpkg -l | grep i386  # Ubuntu/Debian
rpm -qa | grep i686  # Fedora/RHEL

# Install missing packages
sudo apt-get install gcc-multilib g++-multilib libc6-i386
```

--------------------------------

### Set Build-Time Environment Variables

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Example of setting compiler and flag environment variables before running CMake.

```bash
export CC=gcc-11
export CXX=g++-11
export CXXFLAGS="-march=native -O3"
cmake ..
```

--------------------------------

### Linux Native Library Directory Structure

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/submodule-architecture.md

Displays the file layout for precompiled Linux libraries, which are installed to the share/mcpelauncher/lib/ directory.

```text
lib/
├── libEGL.so
├── libGLESv2.so
├── libGLESv3.so
├── libEGLv2.so
├── libzink.so (optional)
├── libvulkan.so (optional)
└── (other platform libraries)
```

--------------------------------

### Uninstall MCPelauncher Components

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Removes installed MCPelauncher binaries and directories from /usr/local/bin and /usr/local/share. Some commands may error if components were not installed.

```bash
rm /usr/local/bin/msa-daemon
rm /usr/local/bin/msa-ui-qt
rm /usr/local/bin/msa-ui-gtk
rm /usr/local/bin/mcpelauncher-client
rm -r /usr/local/share/mcpelauncher
rm /usr/local/bin/mcpelauncher-ui-qt
rm /usr/local/share/applications/mcpelauncher-ui-qt.desktop
rm /usr/local/share/pixmaps/mcpelauncher-ui-qt.png
```

--------------------------------

### Verify C++17 Compiler Support

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Use this command to verify that the installed GCC compiler supports the required C++17 standard.

```bash
g++ -std=c++17 -c test.cpp  # Must support -std=c++17
```

--------------------------------

### macOS Native Library Directory Structure

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/submodule-architecture.md

Displays the file layout for precompiled macOS libraries, which are installed to the share/mcpelauncher/lib/ directory.

```text
lib/
├── libEGL.dylib
├── libGLES.dylib
└── (macOS-specific libraries)
```

--------------------------------

### Verify OpenSSL Version

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/architecture-overview.md

Check the installed version of OpenSSL to ensure compatibility with CURL requirements.

```bash
pkg-config --modversion openssl
```

--------------------------------

### Configure Full Release Build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Creates a production-ready build including the UI and webview components.

```bash
cmake -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=ON \
    -DBUILD_WEBVIEW=ON \
    -DUSE_OWN_CURL=ON \
    -DENABLE_DEV_PATHS=OFF \
    -DCMAKE_INSTALL_PREFIX=/usr/local \
    ..
```

--------------------------------

### Build Client with All Features

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Configures a full release build including UI, webview, and custom curl support.

```bash
cmake -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=ON \
    -DBUILD_WEBVIEW=ON \
    -DUSE_OWN_CURL=ON \
    -DUSE_GAMECONTROLLERDB=ON \
    -DENABLE_DEV_PATHS=OFF \
    -DMSA_DAEMON_PATH="../lib" \
    ..
```

--------------------------------

### Configure minimal development build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Sets up a debug build with client support enabled and UI disabled.

```bash
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=OFF \
    -DENABLE_DEV_PATHS=ON \
    ..
```

--------------------------------

### Minimal Build (Headless)

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Configures a headless release build with UI and webview components disabled.

```bash
cmake -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=OFF \
    -DBUILD_WEBVIEW=OFF \
    -DUSE_OWN_CURL=ON \
    -DENABLE_DEV_PATHS=ON \
    ..
```

--------------------------------

### Select Graphics Backend

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Includes the build settings for the graphics windowing system and configures the appropriate backend.

```cmake
include(game-window/BuildSettings.cmake)

if (GAMEWINDOW_SYSTEM STREQUAL "EGLUT")
    add_subdirectory(eglut)
    add_subdirectory(linux-gamepad)
elseif (GAMEWINDOW_SYSTEM STREQUAL "GLFW")
    include(ext/glfw.cmake)
endif()
```

--------------------------------

### Configure Client Executable and Error Handling

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Includes the main client executable and error reporting UI based on build flags.

```cmake
if (BUILD_CLIENT)
    add_subdirectory(mcpelauncher-client)
endif()

if (BUILD_CLIENT OR BUILD_UI)
    add_subdirectory(mcpelauncher-errorwindow)
endif()
```

--------------------------------

### Configure Build Options and Paths

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/CMakeLists.txt

Sets project options and determines native library paths based on the host operating system.

```cmake
option(BUILD_CLIENT "Enables building of the client launcher." ON)
option(BUILD_UI "Enables building of the client ui requires qt." ON)
option(BUILD_TESTING "Build tests for cll-telemetry (requires GTest)" OFF)

if (APPLE)
    set(NATIVES_PATH_DIR "${CMAKE_SOURCE_DIR}/mcpelauncher-mac-bin")
    set(NATIVES_PATH_LIB_DIR "${NATIVES_PATH_DIR}/lib")
else()
    set(NATIVES_PATH_DIR "${CMAKE_SOURCE_DIR}/mcpelauncher-linux-bin")
    set(NATIVES_PATH_LIB_DIR "${NATIVES_PATH_DIR}/lib")
endif()
```

--------------------------------

### Configure Audio Subsystem

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Sets the audio backend to SDL3 if explicitly requested or required by the windowing system.

```cmake
option(USE_SDL3_AUDIO "Always use SDL audio" ON)

if (BUILD_CLIENT)
    # ... graphics system detection ...
    if (USE_SDL3_AUDIO OR GAMEWINDOW_SYSTEM STREQUAL "SDL3")
        # ... SDL3 configuration ...
        include(ext/sdl3.cmake)
    endif()
endif()
```

--------------------------------

### Configure GameController Database

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Downloads gamepad mappings when both the database option and client build are enabled.

```cmake
option(USE_GAMECONTROLLERDB "Downloads gamecontrollerdb.txt from gabomdq/SDL_GameControllerDB" ON)
if (USE_GAMECONTROLLERDB AND BUILD_CLIENT)
    include(ext/gamepad_mappings.cmake)
endif()
```

--------------------------------

### Compile Minecraft Launcher from Sources

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/ARM-support

After preparing the environment, compile the launcher from source using CMake and Make. This process involves creating a build directory and running the make command with parallel jobs.

```bash
mkdir -p build && cd build
cmake ..
make -j8
```

--------------------------------

### Configure Client and UI Build Options

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Defines core build flags for the client, UI, and testing infrastructure.

```cmake
option(BUILD_CLIENT "Enables building of the client launcher." ON)
option(BUILD_UI "Enables building of the client ui requires qt." ON)
option(BUILD_TESTING "Build tests for cll-telemetry (requires GTest)" OFF)
```

--------------------------------

### Initialize CMake and Language Support

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/CMakeLists.txt

Sets the minimum required CMake version and enables C, C++, and Assembly languages.

```cmake
cmake_minimum_required(VERSION 3.0...4.0)

enable_language(C CXX ASM)
```

--------------------------------

### Configure 32-bit build on 64-bit system

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Use this command to force 32-bit compilation when the BUILD_X86 option is enabled.

```bash
cmake -DBUILD_X86=ON ..  # Build for 32-bit on 64-bit system
```

--------------------------------

### Launch with Software Rendering

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Set the LIBGL_ALWAYS_SOFTWARE variable at runtime to force software rendering.

```bash
# Launch with software rendering
LIBGL_ALWAYS_SOFTWARE=1 ./mcpelauncher-client
```

--------------------------------

### Build MCPelauncher

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Clones the mcpelauncher-manifest repository, creates a build directory, configures the build with CMake, and compiles the launcher.

```bash
git clone --recursive https://github.com/minecraft-linux/mcpelauncher-manifest.git mcpelauncher && cd mcpelauncher
mkdir -p build && cd build
cmake ..
make -j12
```

--------------------------------

### Prepare Build Environment for ARM Hard-Float

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/ARM-support

Before building, switch to the 'armhf' branch and process headers using the provided Python script. Ensure you are in the correct directories.

```bash
cd mcpelauncher-linux-bin
git checkout armhf
cd ..
cd minecraft-symbols/tools
python3 process_headers.py --armhf
cd ..
```

--------------------------------

### Configure Performance Optimized Build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Enables snmalloc and native CPU instruction set optimizations. Requires hardware support for the native instruction set.

```bash
cmake -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_CLIENT=ON \
    -DUSE_SNMALLOC=ON \
    -DCMAKE_CXX_FLAGS="-march=native -O3" \
    ..
```

--------------------------------

### Configure Minimal Development Build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Builds the client only with development paths enabled for debugging purposes.

```bash
cmake -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=OFF \
    -DUSE_OWN_CURL=ON \
    -DENABLE_DEV_PATHS=ON \
    ..
```

--------------------------------

### Configure Package Build for Ubuntu/Debian

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Builds the project and generates a DEB package using system curl.

```bash
mkdir build && cd build

cmake -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=ON \
    -DUSE_OWN_CURL=OFF \
  # Use system curl
    -DENABLE_DEV_PATHS=OFF \
    -DDEB_OS_NAME=ubuntu-bionic \
    -DCMAKE_INSTALL_PREFIX=/usr \
    ..

make
cpack -G DEB
```

--------------------------------

### Development Build (32-bit Testing)

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Configures a debug build for 32-bit architecture testing with unit testing enabled.

```bash
cmake -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_X86=ON \
    -DBUILD_CLIENT=ON \
    -DBUILD_TESTING=ON \
    -DUSE_SNMALLOC=OFF \
    -DENABLE_DEV_PATHS=ON \
    ..
```

--------------------------------

### Configure Client Build Subdirectories

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/CMakeLists.txt

Adds subdirectories for the client build process, including platform-specific components and core launcher modules.

```cmake
if (BUILD_CLIENT)
    add_subdirectory(logger)
    add_subdirectory(base64)
    add_subdirectory(file-util)
    add_subdirectory(properties-parser)
    add_subdirectory(arg-parser)

    add_subdirectory(mcpelauncher-linker)
    add_subdirectory(libc-shim)
    # MSA is only required with the client
    add_subdirectory(simple-ipc)
    add_subdirectory(daemon-utils/client)
    add_subdirectory(daemon-utils/server)
    add_subdirectory(msa-daemon-client)

    add_subdirectory(file-picker)
    add_subdirectory(game-window)

    add_subdirectory(cll-telemetry)

    add_subdirectory(minecraft-imported-symbols)
    add_subdirectory(mcpelauncher-common)
    add_subdirectory(mcpelauncher-core)
    add_subdirectory(mcpelauncher-apkinfo)
    add_subdirectory(axml-parser)
endif()
```

--------------------------------

### Visualize the Build Dependency Graph

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/submodule-architecture.md

A tree-based representation of the project's internal and external module dependencies.

```text
mcpelauncher-client (executable)
├── arg-parser (CLI parsing)
├── logger (logging)
├── mcpelauncher-core
│   ├── mcpelauncher-common
│   │   ├── base64
│   │   ├── file-util
│   │   │   └── logger
│   │   ├── logger
│   │   ├── properties-parser
│   │   ├── mcpelauncher-apkinfo
│   │   │   ├── axml-parser
│   │   │   └── file-util
│   │   └── logger
│   ├── mcpelauncher-linker
│   │   └── minecraft-imported-symbols (headers)
│   ├── msa-daemon-client
│   │   ├── daemon-utils/client
│   │   │   ├── simple-ipc
│   │   │   └── logger
│   │   └── logger
│   ├── game-window
│   │   ├── [graphics backend: EGLUT/GLFW/SDL3]
│   │   ├── logger
│   │   └── file-util
│   └── file-util
├── game-window
├── msa-daemon-client
├── file-picker
│   ├── file-util
│   └── logger
├── cll-telemetry
│   └── logger
├── libjnivm
│   ├── android-support-headers (headers)
│   └── logger
└── libc-shim (optional linking/preload)

[Platform-Specific - macOS]
├── osx-elf-header (headers)
└── epoll-shim

[External Dependencies]
├── curl (HTTP)
├── nlohmann/json (JSON parsing)
├── SDL3 (audio/input)
├── GLFW (windowing)
├── OpenSSL (TLS)
└── PulseAudio (Linux audio)
```

--------------------------------

### Configure Webview for Xbox Live

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Enables the embedded webview component for authentication. Requires both BUILD_WEBVIEW and BUILD_UI to be enabled.

```cmake
option(BUILD_WEBVIEW "Build webview for xboxlive login" ON)
if (BUILD_WEBVIEW AND BUILD_UI)
    add_subdirectory(mcpelauncher-webview)
endif()
```

--------------------------------

### Build MCPelauncher with Custom MSA Daemon Path

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Configures the build with CMake, specifying a custom absolute path to the MSA daemon build directory.

```bash
cmake -DMSA_DAEMON_PATH=/absolute/path/to/daemon/build/dir/msa-daemon ..
make -j12
```

--------------------------------

### Configure Offline Build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Uses a pre-downloaded local source directory for curl dependencies.

```bash
# Download curl offline
wget https://curl.se/download/curl-8.21.0.tar.gz
tar xzf curl-8.21.0.tar.gz

# Build with local source
cmake -DUSE_OWN_CURL=ON \
    -DOWN_CURL_SOURCE_DIR="$(pwd)/curl-8.21.0" \
    ..
```

--------------------------------

### Configure offline build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Uses pre-downloaded local dependencies for curl instead of fetching them during the build process.

```bash
cmake \
    -DUSE_OWN_CURL=ON \
    -DOWN_CURL_SOURCE_DIR="/path/to/curl-8.21.0" \
    -DENABLE_DEV_PATHS=OFF \
    ..
```

--------------------------------

### Find PulseAudio Simple in CMakeLists.txt

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Standard usage pattern for finding and linking the simplified PulseAudio API library.

```cmake
find_package(PulseAudioSimple REQUIRED)

if (PULSEAUDIOSIMPLE_FOUND)
    target_include_directories(my_target PRIVATE ${PULSEAUDIOSIMPLE_INCLUDE_DIRS})
    target_link_libraries(my_target PRIVATE ${PULSEAUDIOSIMPLE_LIBRARIES})
endif()
```

--------------------------------

### Build MSA Dependency on macOS

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Configures the build with CMake, specifying the Qt prefix path for macOS.

```bash
cmake -DCMAKE_PREFIX_PATH=$(brew --prefix qt) -DENABLE_MSA_QT_UI=ON ..
make -j12
```

--------------------------------

### Integrate Core Library Submodules

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Includes essential utility libraries when building the client.

```cmake
if (BUILD_CLIENT)
    add_subdirectory(logger)
    add_subdirectory(base64)
    add_subdirectory(file-util)
    add_subdirectory(properties-parser)
    add_subdirectory(arg-parser)
endif()
```

--------------------------------

### CMake Module Load Order

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Visual representation of the CMake configuration phase and module inclusion hierarchy.

```text
1. CMakeLists.txt (root)
   ├─ enable_language(C CXX ASM)
   ├─ set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
   │  └─ Enables FindPulseAudio.cmake
   │
   ├─ find_program(GIT_EXEC git)
   ├─ function(git_commit_hash ...) - defined
   │
   ├─ if (BUILD_CLIENT)
   │  ├─ include(game-window/BuildSettings.cmake)
   │  │  └─ Sets GAMEWINDOW_SYSTEM
   │  │
   │  ├─ if (USE_SNMALLOC)
   │  │  └─ include(ext/snmalloc.cmake)
   │  │
   │  ├─ if (USE_SDL3_AUDIO OR GAMEWINDOW_SYSTEM=SDL3)
   │  │  └─ include(ext/sdl3.cmake)
   │  │
   │  ├─ if (GAMEWINDOW_SYSTEM=EGLUT)
   │  │  └─ add_subdirectory(eglut)
   │  │
   │  └─ if (GAMEWINDOW_SYSTEM=GLFW)
   │     └─ include(ext/glfw.cmake)
   │
   ├─ if (USE_OWN_CURL)
   │  └─ include(ext/curl.cmake)
   │     ├─ find_package(OpenSSL REQUIRED)
   │     ├─ ExternalProject_Add(curl_ext)
   │     ├─ add_library(curl STATIC IMPORTED)
   │     └─ file(WRITE FindCURL.cmake "")  # Stub
   │
   ├─ include(ext/json.cmake)
   │  ├─ FetchContent_Declare(nlohmann_json_ext)
   │  └─ add_library(nlohmann_json INTERFACE)
   │
   ├─ if (USE_GAMECONTROLLERDB AND BUILD_CLIENT)
   │  └─ include(ext/gamepad_mappings.cmake)
   │
   └─ add_subdirectory(...) - all submodules
```

--------------------------------

### Configure x86/x64 Optimization Flags

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Select the appropriate architecture flag based on the target CPU's instruction set support.

```bash
-march=core2  # SSE3 support
-march=nehalem  # SSE4 support
-march=native  # Auto-detect
```

--------------------------------

### Build MSA Dependency

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Clones the MSA manifest repository, creates a build directory, configures the build with CMake, and compiles the MSA dependency.

```bash
git clone --recursive https://github.com/minecraft-linux/msa-manifest.git msa && cd msa
mkdir -p build && cd build
cmake -DENABLE_MSA_QT_UI=ON ..
make -j12
```

--------------------------------

### Configure 32-bit testing build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Enables 32-bit architecture support and testing modules for debug builds.

```bash
cmake \
    -DCMAKE_BUILD_TYPE=Debug \
    -DBUILD_X86=ON \
    -DBUILD_CLIENT=ON \
    -DBUILD_TESTING=ON \
    ..
```

--------------------------------

### Force Dependency Re-download

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

Commands to clear the cached dependency directory and trigger a fresh configuration.

```bash
rm -rf ${CMAKE_BINARY_DIR}/_deps/nlohmann_json*
cmake ..
```

--------------------------------

### Execute Parallel Builds

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/architecture-overview.md

Commands to utilize all available CPU cores for faster compilation using Make or CMake.

```bash
make -j$(nproc)  # Use all CPU cores
cmake --build . --parallel $(nproc)
```

--------------------------------

### Configure Runtime Environment for ARM Launcher

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/ARM-support

Set the OPENSSL_armcap environment variable before running the launcher. Use '7' for optimal performance or '0' if experiencing crashes. The '--disable-fmod' option may also be necessary.

```bash
export OPENSSL_armcap=7
```

```bash
export OPENSSL_armcap=0
```

--------------------------------

### Configure ARM32 Optimization Flags

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Use these flags for armv7-a architectures with hardware floating-point support.

```bash
-march=armv7-a -mfpu=neon -mfloat-abi=hard
```

--------------------------------

### Integrate Graphics and Input Submodules

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Includes components for window management, file selection, and telemetry.

```cmake
if (BUILD_CLIENT)
    add_subdirectory(file-picker)
    add_subdirectory(game-window)
    add_subdirectory(cll-telemetry)
endif()
```

--------------------------------

### Include GameController Database

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

Conditional inclusion of the SDL GameController database for gamepad support.

```cmake
if (USE_GAMECONTROLLERDB AND BUILD_CLIENT)
    include(ext/gamepad_mappings.cmake)
endif()
```

--------------------------------

### Forward Compiler Settings to libcurl

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

Passes the current project's compiler and flag variables to the libcurl build process.

```cmake
"-DCMAKE_ASM_COMPILER=${CMAKE_ASM_COMPILER}"
"-DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}"
"-DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}"
"-DCMAKE_C_FLAGS=${CMAKE_C_FLAGS}"
"-DCMAKE_LINK_FLAGS=${CMAKE_LINK_FLAGS}"
"-DCMAKE_LIBRARY_ARCHITECTURE=${CMAKE_LIBRARY_ARCHITECTURE}"
```

--------------------------------

### Configure Native Library Paths

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Sets the root directory for platform-native libraries and the specific library subdirectory.

```cmake
if (APPLE)
    set(NATIVES_PATH_DIR "${CMAKE_SOURCE_DIR}/mcpelauncher-mac-bin")
else()
    set(NATIVES_PATH_DIR "${CMAKE_SOURCE_DIR}/mcpelauncher-linux-bin")
endif()
```

```cmake
set(NATIVES_PATH_LIB_DIR "${NATIVES_PATH_DIR}/lib")
```

--------------------------------

### Configure Linux 32-bit Architecture

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/project-structure.md

Specific architecture and target settings for building 32-bit binaries on Linux.

```cmake
CMAKE_LIBRARY_ARCHITECTURE: i386-linux-gnu
CMAKE_CXX_COMPILER_TARGET: i686-linux-gnu
```

--------------------------------

### Force Software Rendering

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/architecture-overview.md

Set the environment variable to use software rendering when hardware GPU drivers are unavailable or broken.

```bash
LIBGL_ALWAYS_SOFTWARE=1
```

--------------------------------

### Optional PulseAudio Integration

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Pattern for conditionally enabling audio support if PulseAudio is found, otherwise disabling it gracefully.

```cmake
find_package(PulseAudio)

if (PULSEAUDIO_FOUND)
    target_compile_definitions(my_target PRIVATE HAVE_PULSEAUDIO)
    target_link_libraries(my_target PRIVATE ${PULSEAUDIO_LIBRARIES})
else()
    message(WARNING "PulseAudio not found, audio support disabled")
endif()
```

--------------------------------

### Include PulseAudio Headers in C++

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Conditional inclusion of PulseAudio headers and initialization of the audio stream.

```cpp
#ifdef HAVE_PULSEAUDIO
#include <pulse/simple.h>
#include <pulse/error.h>

// PulseAudio audio output
pa_simple *s = pa_simple_new(
    NULL,          // server
    NULL,          // device
    PA_STREAM_PLAYBACK,
    NULL,          // device name
    "Minecraft",   // application name
    &ss,           // sample spec
    NULL,          // channel map
    NULL,          // buffering attributes
    &error
);
```

--------------------------------

### Include JSON Library

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Includes the header-only nlohmann/json library via FetchContent.

```cmake
include(ext/json.cmake)
```

--------------------------------

### Configure Development Path Definitions

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Enables source directory lookups for development builds and defines the DEV_EXTRA_PATHS macro.

```cmake
option(ENABLE_DEV_PATHS "Enables lookup in source directories for misc files 
    required by the launcher. This should be disabled for package builds." ON)

if (ENABLE_DEV_PATHS)
    add_definitions(-DDEV_EXTRA_PATHS="${NATIVES_PATH_DIR}:${CMAKE_BINARY_DIR}/gamecontrollerdb")
endif()
```

--------------------------------

### Integrate Runtime and Linker Submodules

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Includes JNI virtual machine, linker, and compatibility shims with specific cache overrides.

```cmake
if (BUILD_CLIENT)
    add_subdirectory(android-support-headers)
    set(JNIVM_ENABLE_RETURN_NON_ZERO ON CACHE BOOL "" FORCE)
    set(JNIVM_FAKE_JNI_MINECRAFT_LINUX_COMPAT ON CACHE BOOL "" FORCE)
    add_subdirectory(libjnivm)
    add_subdirectory(mcpelauncher-linker)
    add_subdirectory(libc-shim)
endif()
```

--------------------------------

### Configure MSA Daemon Path

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/CMakeLists.txt

Sets an optional path for the MSA daemon and applies it as a compile definition to the client target.

```cmake
option(MSA_DAEMON_PATH "Additional paths in which the MSA daemon should be looked in. Relative to the application directory." )
if (MSA_DAEMON_PATH)
    target_compile_definitions(mcpelauncher-client PRIVATE -DMSA_DAEMON_PATH="${MSA_DAEMON_PATH}")
endif()
```

--------------------------------

### find_package(PulseAudio)

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Use the find_package command to locate the PulseAudio library and include it in your project build configuration.

```APIDOC
## find_package(PulseAudio)

### Description
Locates the PulseAudio library and headers. If the REQUIRED keyword is used, CMake will throw an error if the package is not found.

### Usage
```cmake
find_package(PulseAudio [REQUIRED])
```

### Variables
- **PulseAudio_FOUND** (boolean) - Set to true if the package is found.
- **PulseAudio_NOT_FOUND_MESSAGE** (string) - Error message if the package is not found.
- **PULSEAUDIO_LIBRARIES** (list) - Libraries to link against.
- **PULSEAUDIO_INCLUDE_DIRS** (list) - Include directories for headers.

### Example
```cmake
find_package(PulseAudio)
if (PULSEAUDIO_FOUND)
    target_link_libraries(my_target PRIVATE ${PULSEAUDIO_LIBRARIES})
endif()
```
```

--------------------------------

### Configure ARM64 Optimization Flags

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Use these flags for aarch64 architectures, including specific settings for Apple Silicon.

```bash
-march=armv8-a  # Minimal
-march=native  # Auto-detect
```

```bash
-march=armv8.5-a  # Apple Silicon
```

--------------------------------

### Configure macOS 32-bit Architecture

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/project-structure.md

Specific architecture and target settings for building 32-bit binaries on macOS.

```cmake
CMAKE_LIBRARY_ARCHITECTURE: i386-apple-darwin
CMAKE_CXX_COMPILER_TARGET: i686-apple-darwin
```

--------------------------------

### Synchronize Git Submodules

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/architecture-overview.md

Initialize and update all submodules to ensure the repository is fully synchronized.

```bash
git submodule update --init --recursive
```

--------------------------------

### Grant Input Device Permissions

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/architecture-overview.md

Add the current user to the input group to resolve gamepad detection issues on Linux.

```bash
sudo usermod -a -G input $USER
```

--------------------------------

### Configure C++ Standard

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Sets the C++ standard version for the project.

```cmake
set(CMAKE_CXX_STANDARD 17)
```

--------------------------------

### Configure libjnivm build settings

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/submodule-architecture.md

Set CMake variables to enable non-zero exit codes and Minecraft-specific compatibility modes for the libjnivm library.

```cmake
set(JNIVM_ENABLE_RETURN_NON_ZERO ON)  # Force non-zero exit codes
set(JNIVM_FAKE_JNI_MINECRAFT_LINUX_COMPAT ON)  # Minecraft compatibility mode
```

--------------------------------

### Troubleshooting CMake Modules

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Commands to debug module discovery, inspect paths, and force cache regeneration.

```bash
cmake --debug-output 2>&1 | grep "cmake_find_package"
```

```cmake
message(STATUS "CMAKE_MODULE_PATH: ${CMAKE_MODULE_PATH}")
```

```bash
rm -rf CMakeCache.txt CMakeFiles/
cmake ..
```

--------------------------------

### Dependency Cache Path

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

The default directory where CMake FetchContent stores downloaded dependencies.

```cmake
${CMAKE_BINARY_DIR}/_deps/
```

--------------------------------

### GameController Database Format

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

The expected text format for the gamecontrollerdb.txt mapping file.

```text
CONTROLLER_GUID,CONTROLLER_NAME,BUTTON_MAPPING,AXIS_MAPPING,...
```

--------------------------------

### Find PulseAudio in CMakeLists.txt

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Standard usage pattern for finding and linking the PulseAudio library in a project.

```cmake
find_package(PulseAudio REQUIRED)

if (PULSEAUDIO_FOUND)
    target_include_directories(my_target PRIVATE ${PULSEAUDIO_INCLUDE_DIRS})
    target_link_libraries(my_target PRIVATE ${PULSEAUDIO_LIBRARIES})
endif()
```

--------------------------------

### Configure Debian Packaging OS

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Defines a cached string variable to specify the target Debian-based distribution for packaging.

```cmake
set(DEB_OS_NAME "none" CACHE STRING "Specifies the target OS for building the debs 
    (ubuntu-xenial, ubuntu-bionic, ubuntu-disco)")
mark_as_advanced(DEB_OS_NAME)
```

--------------------------------

### Integrate IPC and Daemon Submodules

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Includes inter-process communication and daemon management components for Xbox Live authentication.

```cmake
if (BUILD_CLIENT)
    add_subdirectory(simple-ipc)
    add_subdirectory(daemon-utils/client)
    add_subdirectory(daemon-utils/server)
    add_subdirectory(msa-daemon-client)
endif()
```

--------------------------------

### Configure CMake Minimum Version and Languages

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Sets the required CMake version, enables C, C++, and Assembly languages, and enforces the C++17 standard.

```cmake
cmake_minimum_required(VERSION 3.0...4.0)
enable_language(C CXX ASM)
set(CMAKE_CXX_STANDARD 17)
```

--------------------------------

### Configure libcurl Version Selection

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

Selects the appropriate libcurl source URL based on the CMake and OpenSSL versions available on the host system.

```cmake
if(CMAKE_VERSION VERSION_GREATER_EQUAL "3.18" AND OpenSSL_VERSION VERSION_GREATER_EQUAL "3.0.0")
    set(CURL_EXT_PROPERTIES URL "https://curl.se/download/curl-8.21.0.tar.gz")
else()
    set(CURL_EXT_PROPERTIES URL "https://curl.se/download/curl-8.0.1.tar.gz")
endif()
```

--------------------------------

### Include GLFW Window System

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

Conditional inclusion of the GLFW windowing system based on the GAMEWINDOW_SYSTEM build variable.

```cmake
if (GAMEWINDOW_SYSTEM STREQUAL "GLFW")
    include(ext/glfw.cmake)
endif()
```

--------------------------------

### Update Launcher Components

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/wiki/Compiling-from-sources

Updates the source code for launcher components (msa, mcpelauncher, mcpelauncher-ui) using git pull and submodule update, followed by recompilation.

```bash
git pull && git submodule update
```

--------------------------------

### Integrate Minecraft Engine Submodules

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Includes core engine components, APK parsing, and symbol definitions.

```cmake
if (BUILD_CLIENT)
    add_subdirectory(minecraft-imported-symbols)
    add_subdirectory(mcpelauncher-common)
    add_subdirectory(mcpelauncher-core)
    add_subdirectory(mcpelauncher-apkinfo)
    add_subdirectory(axml-parser)
endif()
```

--------------------------------

### Configure Docker Build

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Builds the project within a Linux container using standard paths.

```cmake
# In container, use standard Linux paths
cmake -DCMAKE_BUILD_TYPE=Release \
    -DBUILD_CLIENT=ON \
    -DBUILD_UI=ON \
    -DUSE_OWN_CURL=ON \
    -DCMAKE_INSTALL_PREFIX=/app/mcpelauncher \
    ..
make
cmake --install .
```

--------------------------------

### Configure OpenSSL Integration

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

Locates the OpenSSL package and appends the necessary CMake flags to enable OpenSSL support in libcurl.

```cmake
find_package(OpenSSL REQUIRED COMPONENTS SSL Crypto)
list(APPEND CURL_EXT_EXTRA_OPTIONS "-DCURL_USE_OPENSSL=ON")
```

--------------------------------

### Enable Apple SecTrust

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Pass this flag to the CMake configuration to enable SecTrust integration.

```cmake
-DUSE_APPLE_SECTRUST=ON
```

--------------------------------

### Configure Memory Allocator

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Allows replacing the system malloc with snmalloc when building the client.

```cmake
option(USE_SNMALLOC "Use the snmalloc allocator" OFF)
if (BUILD_CLIENT)
    if (USE_SNMALLOC)
        include(ext/snmalloc.cmake)
    endif()
endif()
```

--------------------------------

### Select C and C++ Compilers

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Specifies the C and C++ compilers to be used during the build process.

```cmake
cmake -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..
cmake -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ..
```

--------------------------------

### PulseAudio Standard Variables

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Variables available when using the REQUIRED flag in find_package.

```text
PulseAudio_FOUND - set to true if found
PulseAudio_NOT_FOUND_MESSAGE - error message if not found
```

--------------------------------

### Configure External CURL Dependency

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Controls whether to build libcurl from source or use the system-installed version.

```cmake
option(USE_OWN_CURL "Builds CURL as an ExternalProject dependency" ON)
if (USE_OWN_CURL)
    include(ext/curl.cmake)
endif()
```

--------------------------------

### Include External Projects

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Standard pattern for conditionally including external project configurations based on a user-defined option.

```cmake
option(USE_OWN_XXX "Build XXX as external project" ON)
if (USE_OWN_XXX)
    include(ext/xxx.cmake)
endif()
```

--------------------------------

### Link macOS Frameworks

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Explicitly link required system frameworks for CURL on macOS.

```cmake
target_link_libraries(curl PRIVATE
    -framework SystemConfiguration
    -framework Security
    -framework CoreFoundation
)
```

--------------------------------

### Set Release Compiler Flags

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/system-requirements.md

Use these flags for production builds to enable maximum optimization and link-time improvements.

```bash
-O3 -march=native -flto
```

--------------------------------

### Configure macOS Platform Dependencies

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/build-system.md

Adds platform-specific compatibility layers for macOS environments.

```cmake
if (APPLE)
    add_subdirectory(osx-elf-header)
    add_subdirectory(epoll-shim)
endif()
```

--------------------------------

### Integrate PulseAudio in CMakeLists.txt

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Use this pattern to conditionally link PulseAudio libraries when building on Linux platforms.

```cmake
# In launcher's CMakeLists.txt
if (UNIX AND NOT APPLE)
    find_package(PulseAudio)
    
    if (PULSEAUDIO_FOUND)
        add_definitions(-DHAVE_PULSEAUDIO)
        target_link_libraries(mcpelauncher-client PRIVATE ${PULSEAUDIO_LIBRARIES})
    endif()
endif()
```

--------------------------------

### Define libcurl Variables

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-api.md

Manually sets variables for libcurl library locations and targets.

```cmake
set(CURL_FOUND TRUE)
set(CURL_LIBRARIES curl)  # Target name, not library file
set(CURL_INCLUDE_DIRS ${CMAKE_BINARY_DIR}/ext/curl/include/)
```

--------------------------------

### CMake Dependency Resolution Strategy

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/external-dependencies.md

Visual representation of the conditional logic used during the CMake configuration and build phases.

```text
CMake Configure Phase
├─ Check OpenSSL version
├─ If OpenSSL 3.0+ and CMake 3.18+
│  └─ Plan curl 8.21.0 build
└─ Else
   └─ Plan curl 8.0.1 build

├─ Fetch nlohmann/json 3.7.3 (always)
│
├─ If BUILD_CLIENT=ON
│  ├─ If USE_GAMECONTROLLERDB=ON
│  │  └─ Plan gamecontrollerdb download
│  ├─ If USE_SNMALLOC=ON
│  │  └─ Plan snmalloc build
│  └─ If USE_SDL3_AUDIO=ON or GAMEWINDOW_SYSTEM=SDL3
│     └─ Plan SDL3 build
│
├─ If GAMEWINDOW_SYSTEM=EGLUT
│  └─ Use EGL/GLESv2 from system
│
└─ If GAMEWINDOW_SYSTEM=GLFW
   └─ Plan GLFW build

Build Phase
├─ Download/extract external sources
├─ Configure each ExternalProject
├─ Build (statically linked where applicable)
└─ Link into launcher binary
```

--------------------------------

### Custom Find Module Template

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/api-reference/cmake-modules.md

Standard boilerplate for creating a new Find*.cmake module, including path searching and standard argument handling.

```cmake
# FindMyLibrary.cmake
find_path(MYLIB_INCLUDE_DIR
    NAMES mylib.h
    PATHS /usr/include /usr/local/include
)

find_library(MYLIB_LIBRARY
    NAMES mylib
    PATHS /usr/lib /usr/local/lib
)

set(MYLIB_INCLUDE_DIRS ${MYLIB_INCLUDE_DIR})
set(MYLIB_LIBRARIES ${MYLIB_LIBRARY})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MyLibrary DEFAULT_MSG 
    MYLIB_LIBRARY MYLIB_INCLUDE_DIR)

mark_as_advanced(MYLIB_INCLUDE_DIRS MYLIB_LIBRARIES)
```

--------------------------------

### Configure Cross-Compilation Toolchain

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Points to a specific toolchain file for cross-compilation environments.

```cmake
cmake -DCMAKE_TOOLCHAIN_FILE=/path/to/toolchain.cmake ..
```

--------------------------------

### Inspect Generated CMake Variables

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Lists the first 50 generated CMake variables for inspection.

```bash
# Print all CMake variables
cmake . -L | head -50
```

--------------------------------

### Test Specific Build Option

Source: https://github.com/minecraft-linux/mcpelauncher-manifest/blob/ng/_autodocs/configuration.md

Tests the effect of setting a specific CMake flag on the build configuration.

```bash
# Test BUILD_X86 detection
cmake -DBUILD_X86=ON -L | grep CMAKE_LIBRARY_ARCHITECTURE
```
