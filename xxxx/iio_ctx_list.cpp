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

#include <xxxx/iio_ctx_list.hpp>

#include <iio.h>

#include <memory>
#include <stdexcept>
#include <cerrno>
#include <cstring>

std::vector<xxxx::IioCtxInfo> xxxx::scan_iio_contexts()
{
    std::vector<xxxx::IioCtxInfo> lst;

    std::unique_ptr<iio_scan_context, decltype(&iio_scan_context_destroy)>
        scan_ctx {iio_create_scan_context(nullptr, 0), iio_scan_context_destroy};
    if (!scan_ctx)
        throw std::runtime_error(std::strerror(errno));

    struct iio_context_info **ctxs;
    auto ctx_num = iio_scan_context_get_info_list(scan_ctx.get(), &ctxs);
    if (ctx_num < 0)
    {
        char buf[256];
        iio_strerror(ctx_num, buf, sizeof(buf));
        throw std::runtime_error(buf);
    }

    std::unique_ptr<iio_context_info *, decltype(&iio_context_info_list_free)>
        ctx_info{ctxs, iio_context_info_list_free};

    for (auto info = ctx_info.get(); ctx_num; --ctx_num, ++info)
    {
        lst.emplace_back(
            iio_context_info_get_description(*info),
            iio_context_info_get_uri(*info)
        );
    }

    return lst;
}
