# Math Utils - Production-Ready C++ Project

A modular, production-ready C++ application demonstrating best practices in build systems, testing, containerization, and CI/CD deployment. This project implements a comprehensive math utilities library with full unit test coverage, automated build pipelines, and Docker integration.

## 📋 Project Overview

**MathUtils** is a complete C++ project that includes:
- **Modular Architecture**: Separate header and source files with clean namespacing
- **Multiple Math Functions**: Addition, subtraction, multiplication, division, and power operations
- **Comprehensive Unit Tests**: 20+ test cases with custom assertion framework
- **Dual Build Systems**: CMake for modern builds and Makefile for direct compilation
- **CI/CD Pipeline**: GitHub Actions for automated build, test, and deployment
- **Docker Integration**: Containerized application for easy deployment
- **Production Best Practices**: Error handling, documentation, and clean code

## 📁 Project Structure

```
C-Project_demo/
├── src/                          # Source files
│   ├── main.cpp                 # Application entry point
│   └── math_utils.cpp           # Math utilities implementation
├── include/                      # Header files
│   └── math_utils.h             # Public API declarations
├── tests/                        # Unit tests
│   └── test_math_utils.cpp      # Comprehensive test suite
├── build/                        # Build output (git-ignored)
│   ├── bin/                     # Executable binaries
│   └── lib/                     # Static libraries
├── .github/
│   └── workflows/
│       └── build.yml            # GitHub Actions CI/CD pipeline
├── CMakeLists.txt               # CMake configuration
├── Makefile                     # Traditional make build
├── Dockerfile                   # Docker container configuration
├── .gitignore                   # Git exclusion rules
└── README.md                    # This file
```

## 🚀 Quick Start

### Prerequisites
- **Linux/Unix System** (Ubuntu 20.04 or later recommended)
- **GCC/G++** (version 7.0 or later)
- **CMake** (version 3.10 or later)
- **Make** (GNU Make)
- **Docker** (optional, for containerization)

### Installation

1. **Clone the repository**
   ```bash
   git clone <repository-url>
   cd C-Project_demo
   ```

2. **Verify dependencies**
   ```bash
   gcc --version
   g++ --version
   cmake --version
   ```

## 🔨 Building the Project

### Method 1: Using CMake (Recommended)

```bash
# Create build directory
mkdir -p build
cd build

# Configure the project
cmake ..

# Build the project
cmake --build . --config Release

# Installation (optional)
cmake --install .
```

**Build outputs:**
- Executable: `build/bin/math_app`
- Library: `build/lib/libmathutils.a`
- Tests: `build/bin/run_tests`

### Method 2: Using Make (Direct GCC Compilation)

```bash
# Build everything
make all-targets

# Or build specific targets
make app          # Build application only
make test         # Build and run tests
make clean        # Remove build artifacts
make rebuild      # Clean and rebuild everything
```

**Makefile targets:**
```
make app          - Build the application executable
make test         - Build and run unit tests
make run          - Build and run the application
make clean        - Remove all build artifacts
make rebuild      - Clean and rebuild everything
make help         - Show help message
```

## ✅ Testing

### Run Tests with CMake

```bash
cd build
ctest --output-on-failure
```

### Run Tests with Make

```bash
make test
```

### Test Coverage

The test suite includes **20+ unit tests** covering:
- **Addition Tests** (4 tests)
  - Positive numbers
  - Negative numbers
  - Mixed numbers
  - Addition with zero

- **Subtraction Tests** (4 tests)
  - Positive numbers
  - Negative numbers
  - Same number subtraction
  - Subtraction with zero

- **Multiplication Tests** (5 tests)
  - Positive numbers
  - Negative numbers
  - Mixed signs
  - Multiplication by zero
  - Decimal numbers

- **Division Tests** (5 tests)
  - Positive numbers
  - Negative numbers
  - Mixed signs
  - Decimal results
  - Division by zero exception handling

- **Power Tests** (5 tests)
  - Positive exponents
  - Zero exponent
  - Large exponents
  - Negative base
  - Negative base with odd exponents

**Example test output:**
```
===== Math Utilities Unit Tests =====

--- Addition Tests ---
[PASS] add positive numbers
[PASS] add negative numbers
[PASS] add mixed numbers
[PASS] add with zero

--- Subtraction Tests ---
[PASS] subtract positive numbers
[PASS] subtract negative numbers
[PASS] subtract same number
[PASS] subtract with zero

--- Multiplication Tests ---
[PASS] multiply positive numbers
[PASS] multiply negative numbers
[PASS] multiply mixed signs
[PASS] multiply by zero
[PASS] multiply decimal numbers

--- Division Tests ---
[PASS] divide positive numbers
[PASS] divide negative numbers
[PASS] divide mixed signs
[PASS] divide decimal result
[PASS] divide by zero throws exception

--- Power Tests ---
[PASS] power positive exponent
[PASS] power zero exponent
[PASS] power large exponent
[PASS] power negative base
[PASS] power negative base odd exponent

======================================
Total Tests: 20
Passed: 20
Failed: 0
======================================
```

## 🐳 Docker Integration

### Build Docker Image

```bash
# Build the Docker image
docker build -t mathutils:latest .

# Build with custom tag
docker build -t mathutils:1.0 .
```

### Run Docker Container

```bash
# Run the application in a container
docker run --rm mathutils:latest

# Run with interactive terminal
docker run -it --rm mathutils:latest

# Run tests inside container
docker run --rm mathutils:latest /app/build/bin/run_tests
```

### Dockerfile Details

The Dockerfile:
- Uses Ubuntu 22.04 base image
- Installs GCC, G++, CMake, and Make
- Copies project source code
- Builds the project using CMake
- Sets the application as entrypoint
- Includes health check

## 🔄 CI/CD Pipeline (GitHub Actions)

The `.github/workflows/build.yml` file implements a complete CI/CD pipeline:

### Pipeline Stages

1. **Build and Test Stage**
   - Runs on: Ubuntu 22.04
   - Steps:
     - Checkout code
     - Install dependencies (gcc, g++, cmake)
     - Configure project with CMake
     - Build project (CMake)
     - Run unit tests (ctest)
     - Build with Make (alternative method)
     - Run tests with Make
     - Upload artifacts (binaries and libraries)

2. **Docker Build and Push Stage**
   - Depends on: Build and Test stage success
   - Steps:
     - Checkout code
     - Set up Docker Buildx
     - Log in to Container Registry (GHCR)
     - Extract metadata for tagging
     - Build and push Docker image
     - Test the built Docker image

3. **Code Quality Check Stage**
   - Runs: cppcheck for static analysis
   - Optional checks and reporting

4. **Summary Stage**
   - Aggregates results from all stages
   - Reports overall pipeline status

### Pipeline Triggers

The pipeline runs automatically on:
- **Push** to `main` or `develop` branches
- **Pull requests** to `main` or `develop` branches

### Example Workflow

```
Event: Push to main branch
  ↓
Checkout code
  ↓
Install dependencies
  ↓
Build with CMake
  ↓
Run tests (ctest)
  ↓
Build with Make (verification)
  ↓
Run tests (make test)
  ↓
Upload artifacts
  ↓
Build Docker image
  ↓
Push to GHCR
  ↓
Test Docker image
  ↓
Pipeline Complete ✓
```

## 📚 API Documentation

### Math Utils Namespace

#### `double add(double a, double b)`
Adds two numbers.
- **Parameters**: `a` - First number, `b` - Second number
- **Returns**: Sum of a and b
- **Example**: `add(5.0, 3.0)` → `8.0`

#### `double subtract(double a, double b)`
Subtracts two numbers.
- **Parameters**: `a` - First number, `b` - Second number
- **Returns**: Difference of a and b
- **Example**: `subtract(10.0, 3.0)` → `7.0`

#### `double multiply(double a, double b)`
Multiplies two numbers.
- **Parameters**: `a` - First number, `b` - Second number
- **Returns**: Product of a and b
- **Example**: `multiply(4.0, 5.0)` → `20.0`

#### `double divide(double a, double b)`
Divides two numbers.
- **Parameters**: `a` - Dividend, `b` - Divisor
- **Returns**: Quotient of a divided by b
- **Throws**: `std::invalid_argument` if b is zero
- **Example**: `divide(10.0, 2.0)` → `5.0`

#### `double power(double base, int exponent)`
Calculates base raised to the power of exponent.
- **Parameters**: `base` - Base number, `exponent` - Exponent
- **Returns**: base raised to the power of exponent
- **Example**: `power(2.0, 8)` → `256.0`

## 🛠️ Build System Details

### CMake Configuration

**CMakeLists.txt** features:
- C++11 standard enforcement
- Debug and Release build configurations
- Static library creation (`libmathutils.a`)
- Executable application (`math_app`)
- Unit test target (`run_tests`)
- Install targets
- Compiler-specific flags (MSVC and GCC)

**Build outputs:**
```
build/
├── bin/
│   ├── math_app          # Main application
│   └── run_tests         # Test executable
└── lib/
    └── libmathutils.a    # Static library
```

### Makefile Configuration

**Makefile** features:
- Multiple build targets
- Object file organization
- Static library creation
- Incremental compilation
- Clean and rebuild targets
- Help documentation

## 📋 Code Quality

The project follows C++ best practices:

1. **Header/Source Separation**
   - Header guards for include protection
   - Inline documentation with Doxygen-style comments
   - Forward declarations where appropriate

2. **Namespace Usage**
   - All functions in `MathUtils` namespace
   - Prevents naming conflicts

3. **Error Handling**
   - Exception throwing for invalid operations (division by zero)
   - Standard library exceptions
   - Clear error messages

4. **Documentation**
   - Function-level Doxygen comments
   - Parameter descriptions
   - Return value documentation
   - Exception documentation

5. **Code Style**
   - Consistent indentation (4 spaces)
   - Meaningful variable names
   - Clear function signatures

## 🔍 Running the Application

### From Command Line

```bash
# CMake build
cd build
./bin/math_app

# Make build
./build/bin/math_app
```

### Example Output

```
===== Math Utilities Application =====

Number 1: 10.5
Number 2: 3

Addition: 10.5 + 3 = 13.5
Subtraction: 10.5 - 3 = 7.5
Multiplication: 10.5 * 3 = 31.5
Division: 10.5 / 3 = 3.5
Power: 2 ^ 8 = 256

======================================
```

## 🐛 Troubleshooting

### Build Issues

**CMake not found:**
```bash
sudo apt-get update
sudo apt-get install -y cmake
```

**GCC/G++ not found:**
```bash
sudo apt-get update
sudo apt-get install -y build-essential
```

**Permission denied:**
```bash
chmod +x build/bin/math_app
```

### Docker Issues

**Docker daemon not running:**
```bash
sudo service docker start
```

**Permission denied when running Docker:**
```bash
sudo usermod -aG docker $USER
```

### Test Failures

If tests fail:
1. Verify the build succeeded without errors
2. Check that all dependencies are installed
3. Run tests with verbose output: `ctest --verbose`
4. Check test output for specific failure details

## 📝 Contributing

To contribute to this project:

1. Create a feature branch
2. Make your changes
3. Ensure all tests pass
4. Submit a pull request

The GitHub Actions CI/CD pipeline will automatically:
- Build your changes
- Run all tests
- Check code quality
- Build Docker image

## 📄 License

This project is provided as-is for educational and demonstration purposes.

## 📞 Support

For issues or questions:
1. Check the troubleshooting section
2. Review the build logs from GitHub Actions
3. Verify all dependencies are installed
4. Ensure you're using a compatible environment (Ubuntu 20.04+)

## 🎯 Next Steps

To extend this project:

1. **Add More Features**
   - Implement additional math functions
   - Add matrix operations
   - Include scientific functions

2. **Improve Testing**
   - Switch to Google Test framework
   - Add performance benchmarks
   - Implement code coverage reporting

3. **Enhance CI/CD**
   - Add security scanning
   - Implement automated releases
   - Add deployment to production environments

4. **Documentation**
   - Generate Doxygen documentation
   - Create API reference guide
   - Add architecture diagrams

5. **Containerization**
   - Push images to Docker Hub
   - Implement multi-stage builds
   - Add Kubernetes deployment files

---

**Version**: 1.0.0  
**Last Updated**: April 2026  
**Status**: Production Ready ✅
