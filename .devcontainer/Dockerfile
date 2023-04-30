FROM mcr.microsoft.com/devcontainers/cpp:0-debian-10

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="3.22.2"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# [Optional] Uncomment this section to install additional vcpkg ports.
# RUN su vscode -c "${VCPKG_ROOT}/vcpkg install <your-port-name-here>"

# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
RUN dpkg --add-architecture armhf \
    && apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
    ccache \
    dpkg-cross \
    crossbuild-essential-armhf \
    libssl-dev:armhf \
    libcurl4-gnutls-dev:armhf \
    libusb-dev:armhf \
    libiio-dev:armhf \
    libboost-test-dev:armhf
    #   libpython3-dev:armhf \
    #   zlib1g-dev:armhf \
    #   libcereal-dev:armhf \
    #   liblua5.3-dev:armhf \
    #   uthash-dev:armhf \
