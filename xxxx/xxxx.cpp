// Copyright 2023 vscode
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <boost/ext/di.hpp>

#include <xxxx/iio_ctx_list.hpp>

#include <memory>
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    auto ctx_list {xxxx::scan_iio_contexts()};

    std::cout << "Encontrados " << ctx_list.size() << " contextos IIO." << std::endl;
    for (const auto& e : ctx_list)
        std::cout << e.description() << " (" << e.uri() << ")" << std::endl;

    if (ctx_list.empty())
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
