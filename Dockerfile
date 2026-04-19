FROM ubuntu:22.04

# Avoid interactive prompts
ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gcc \
    g++ \
    make \
    curl \
    git \
    && rm -rf /var/lib/apt/lists/*

# Verify installations
RUN gcc --version && cmake --version

# Set working directory
WORKDIR /app

# Copy project files
COPY . /app

# Create build directory and build the project
RUN mkdir -p build && \
    cd build && \
    cmake .. && \
    cmake --build . --config Release

# Verify the build was successful
RUN ls -la /app/build/bin/

# Set the entry point to run the application
ENTRYPOINT ["/app/build/bin/math_app"]

# Health check
HEALTHCHECK --interval=30s --timeout=3s --start-period=5s --retries=3 \
    CMD /app/build/bin/math_app > /dev/null 2>&1 || exit 1
