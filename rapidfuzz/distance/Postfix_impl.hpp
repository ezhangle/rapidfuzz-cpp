/* SPDX-License-Identifier: MIT */
/* Copyright © 2021 Max Bachmann */

#pragma once
#include <rapidfuzz/details/Range.hpp>
#include <rapidfuzz/details/common.hpp>
#include <rapidfuzz/details/distance.hpp>

namespace rapidfuzz {
namespace detail {

class Postfix : public SimilarityBase<Postfix, size_t, 0, std::numeric_limits<int64_t>::max()> {
    friend SimilarityBase<Postfix, size_t, 0, std::numeric_limits<int64_t>::max()>;
    friend NormalizedMetricBase<Postfix>;

    template <typename InputIt1, typename InputIt2>
    static size_t maximum(const Range<InputIt1>& s1, const Range<InputIt2>& s2)
    {
        return std::max(s1.size(), s2.size());
    }

    template <typename InputIt1, typename InputIt2>
    static size_t _similarity(Range<InputIt1> s1, Range<InputIt2> s2, size_t score_cutoff, size_t)
    {
        size_t dist = remove_common_suffix(s1, s2);
        return (dist >= score_cutoff) ? dist : 0;
    }
};

} // namespace detail
} // namespace rapidfuzz
