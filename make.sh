#!/bin/bash

PROJECT_ROOT="$(pwd)"
BUILD_DIR="build"
UNIT_DIR=unit
HOST_DIR=host
CROSS_DIR=arm
QT_BINDIR="$HOME/Documents/Qt-CrossCompile-RaspberryPi/raspberrypi4/qt5.15"  # Fixed tilde expansion

# Error handling function
log_error() {
    echo "ERROR: $1" >&2
}

# Validate arguments
if [[ $# -lt 1 ]]; then
    log_error "Missing required argument"
    echo "Usage: $0 <build_type>"
    echo "Available build types:"
    echo "  unit   - Build unit tests"
    echo "  host   - Build for host machine"
    echo "  arm    - Build for ARM architecture"
    exit 1
fi

main() {
    local build_type=$1
    local target_dir cmake_source_path

    # Create build directory
    mkdir -p "$BUILD_DIR"
    
    # Determine build parameters
    case "$build_type" in
        unit)
            target_dir="$UNIT_DIR"
            cmake_source_path="$PROJECT_ROOT/unittest"
            ;;
        host)
            target_dir="$HOST_DIR"
            cmake_source_path="$PROJECT_ROOT/source"
            ;;
        arm)
            target_dir="$CROSS_DIR"
            cmake_source_path="$PROJECT_ROOT/source"
            ;;
        *)
            log_error "Invalid build type: $build_type"
            exit 1
            ;;
    esac

    # Create target subdirectory
    local build_path="$BUILD_DIR/$target_dir"
    mkdir -p "$build_path"
    
    # Build process
    pushd "$build_path" > /dev/null
    echo "Building in: $(pwd)"
    echo "Source path: $cmake_source_path"

    case "$build_type" in
        unit)
            echo "Building unit tests..."
            cmake -DENABLE_COVERAGE=ON -DCMAKE_BUILD_TYPE=Debug "$cmake_source_path"
            make
            make gcov
            ;;
            
        host)
            echo "Building for host machine..."
            cmake "$cmake_source_path"
            make
            ;;
            
        arm)
            echo "Building for ARM architecture..."
            cmake \
                -DCMAKE_TOOLCHAIN_FILE="$cmake_source_path/toolchain-aarch64.cmake" \
                -DCMAKE_PREFIX_PATH="$QT_BINDIR" \
                "$cmake_source_path"
            make
            ;;
    esac
    
    local result=$?
    popd > /dev/null

    if [[ $result -eq 0 ]]; then
        echo "Build completed successfully in: $build_path"
    else
        log_error "Build failed with exit code $result"
        exit $result
    fi
}

main "$@"