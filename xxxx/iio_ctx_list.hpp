// Copyright 2023 Pedro Luis Castedo Cepeda
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

#if !defined(TEST_IIO_CTX_LIST_HPP)
#define TEST_IIO_CTX_LIST_HPP

#include <string>
#include <vector>

namespace xxxx
{
    struct IioCtxInfo
    {
    private:
        std::string desc_;
        std::string uri_;

    public:
        IioCtxInfo(const char *desc, const char *uri) : desc_{desc}, uri_{uri} {};
        const std::string &description() const { return desc_; }
        const std::string &uri() const { return uri_; }
    };

    std::vector<IioCtxInfo> scan_iio_contexts();
}

#endif // !defined(TEST_IIO_CTX_LIST_HPP)
