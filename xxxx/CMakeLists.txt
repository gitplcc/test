# Copyright 2023 vscode
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

set(XXXX_IIO_CTX_LIST_SRCS
    iio_ctx_list.cpp
    iio_ctx_list.hpp
)

add_executable(xxxx)
target_sources(xxxx
    PRIVATE
        xxxx.cpp
        ${XXXX_IIO_CTX_LIST_SRCS}
)
target_compile_features(xxxx PUBLIC cxx_std_17)
set_target_properties(xxxx PROPERTIES CXX_EXTENSIONS OFF)
target_include_directories(xxxx
    PRIVATE
        ${xxxx_SOURCE_DIR}
        ${xxxx_SOURCE_DIR}/extern
)
target_link_libraries(xxxx PkgConfig::libiio)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_executable(iio_ctx_list_test)
    target_sources(iio_ctx_list_test
        PRIVATE
            iio_ctx_list_test.cpp
            ${XXXX_IIO_CTX_LIST_SRCS}
    )
    target_compile_features(iio_ctx_list_test PUBLIC cxx_std_17)
    target_compile_definitions(iio_ctx_list_test PRIVATE BOOST_TEST_DYN_LINK)
    set_target_properties(iio_ctx_list_test PROPERTIES CXX_EXTENSIONS OFF)
    target_include_directories(iio_ctx_list_test PRIVATE ${xxxx_SOURCE_DIR})
    target_link_libraries(iio_ctx_list_test Boost::unit_test_framework PkgConfig::libiio)

    add_test(NAME iio_ctx_list_test COMMAND iio_ctx_list_test)
endif()
