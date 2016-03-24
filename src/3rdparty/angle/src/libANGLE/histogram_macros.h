begin_unit
begin_comment
comment|//
end_comment
begin_comment
comment|// Copyright 2015 The ANGLE Project Authors. All rights reserved.
end_comment
begin_comment
comment|// Use of this source code is governed by a BSD-style license that can be
end_comment
begin_comment
comment|// found in the LICENSE file.
end_comment
begin_comment
comment|//
end_comment
begin_comment
comment|// histogram_macros.h:
end_comment
begin_comment
comment|//   Helpers for making histograms, to keep consistency with Chromium's
end_comment
begin_comment
comment|//   histogram_macros.h.
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|LIBANGLE_HISTOGRAM_MACROS_H_
end_ifndef
begin_define
DECL|macro|LIBANGLE_HISTOGRAM_MACROS_H_
define|#
directive|define
name|LIBANGLE_HISTOGRAM_MACROS_H_
end_define
begin_include
include|#
directive|include
file|<platform/Platform.h>
end_include
begin_define
DECL|macro|ANGLE_HISTOGRAM_TIMES
define|#
directive|define
name|ANGLE_HISTOGRAM_TIMES
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
value|ANGLE_HISTOGRAM_CUSTOM_TIMES( \     name, sample, 1, 10000, 50)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_MEDIUM_TIMES
define|#
directive|define
name|ANGLE_HISTOGRAM_MEDIUM_TIMES
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
value|ANGLE_HISTOGRAM_CUSTOM_TIMES( \     name, sample, 10, 180000, 50)
end_define
begin_comment
comment|// Use this macro when times can routinely be much longer than 10 seconds.
end_comment
begin_define
DECL|macro|ANGLE_HISTOGRAM_LONG_TIMES
define|#
directive|define
name|ANGLE_HISTOGRAM_LONG_TIMES
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
value|ANGLE_HISTOGRAM_CUSTOM_TIMES( \     name, sample, 1, 3600000, 50)
end_define
begin_comment
comment|// Use this macro when times can routinely be much longer than 10 seconds and
end_comment
begin_comment
comment|// you want 100 buckets.
end_comment
begin_define
DECL|macro|ANGLE_HISTOGRAM_LONG_TIMES_100
define|#
directive|define
name|ANGLE_HISTOGRAM_LONG_TIMES_100
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
value|ANGLE_HISTOGRAM_CUSTOM_TIMES( \     name, sample, 1, 3600000, 100)
end_define
begin_comment
comment|// For folks that need real specific times, use this to select a precise range
end_comment
begin_comment
comment|// of times you want plotted, and the number of buckets you want used.
end_comment
begin_define
DECL|macro|ANGLE_HISTOGRAM_CUSTOM_TIMES
define|#
directive|define
name|ANGLE_HISTOGRAM_CUSTOM_TIMES
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|,
name|bucket_count
parameter_list|)
define|\
value|ANGLE_HISTOGRAM_CUSTOM_COUNTS(name, sample, min, max, bucket_count)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_COUNTS
define|#
directive|define
name|ANGLE_HISTOGRAM_COUNTS
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
value|ANGLE_HISTOGRAM_CUSTOM_COUNTS( \     name, sample, 1, 1000000, 50)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_COUNTS_100
define|#
directive|define
name|ANGLE_HISTOGRAM_COUNTS_100
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
define|\
value|ANGLE_HISTOGRAM_CUSTOM_COUNTS(name, sample, 1, 100, 50)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_COUNTS_10000
define|#
directive|define
name|ANGLE_HISTOGRAM_COUNTS_10000
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
define|\
value|ANGLE_HISTOGRAM_CUSTOM_COUNTS(name, sample, 1, 10000, 50)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_CUSTOM_COUNTS
define|#
directive|define
name|ANGLE_HISTOGRAM_CUSTOM_COUNTS
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|,
name|min
parameter_list|,
name|max
parameter_list|,
name|bucket_count
parameter_list|)
define|\
value|ANGLEPlatformCurrent()->histogramCustomCounts(\       name, sample, min, max, bucket_count)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_PERCENTAGE
define|#
directive|define
name|ANGLE_HISTOGRAM_PERCENTAGE
parameter_list|(
name|name
parameter_list|,
name|under_one_hundred
parameter_list|)
define|\
value|ANGLE_HISTOGRAM_ENUMERATION(name, under_one_hundred, 101)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_BOOLEAN
define|#
directive|define
name|ANGLE_HISTOGRAM_BOOLEAN
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
define|\
value|ANGLEPlatformCurrent()->histogramBoolean(name, sample)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_ENUMERATION
define|#
directive|define
name|ANGLE_HISTOGRAM_ENUMERATION
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|,
name|boundary_value
parameter_list|)
define|\
value|ANGLEPlatformCurrent()->histogramEnumeration(name, sample, boundary_value)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_MEMORY_KB
define|#
directive|define
name|ANGLE_HISTOGRAM_MEMORY_KB
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
value|ANGLE_HISTOGRAM_CUSTOM_COUNTS( \     name, sample, 1000, 500000, 50)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_MEMORY_MB
define|#
directive|define
name|ANGLE_HISTOGRAM_MEMORY_MB
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
value|ANGLE_HISTOGRAM_CUSTOM_COUNTS( \     name, sample, 1, 1000, 50)
end_define
begin_define
DECL|macro|ANGLE_HISTOGRAM_SPARSE_SLOWLY
define|#
directive|define
name|ANGLE_HISTOGRAM_SPARSE_SLOWLY
parameter_list|(
name|name
parameter_list|,
name|sample
parameter_list|)
define|\
value|ANGLEPlatformCurrent()->histogramSparse(name, sample)
end_define
begin_comment
comment|// Scoped class which logs its time on this earth as a UMA statistic. This is
end_comment
begin_comment
comment|// recommended for when you want a histogram which measures the time it takes
end_comment
begin_comment
comment|// for a method to execute. This measures up to 10 seconds.
end_comment
begin_define
DECL|macro|SCOPED_ANGLE_HISTOGRAM_TIMER
define|#
directive|define
name|SCOPED_ANGLE_HISTOGRAM_TIMER
parameter_list|(
name|name
parameter_list|)
define|\
value|SCOPED_ANGLE_HISTOGRAM_TIMER_EXPANDER(name, false, __COUNTER__)
end_define
begin_comment
comment|// Similar scoped histogram timer, but this uses ANGLE_HISTOGRAM_LONG_TIMES_100,
end_comment
begin_comment
comment|// which measures up to an hour, and uses 100 buckets. This is more expensive
end_comment
begin_comment
comment|// to store, so only use if this often takes>10 seconds.
end_comment
begin_define
DECL|macro|SCOPED_ANGLE_HISTOGRAM_LONG_TIMER
define|#
directive|define
name|SCOPED_ANGLE_HISTOGRAM_LONG_TIMER
parameter_list|(
name|name
parameter_list|)
define|\
value|SCOPED_ANGLE_HISTOGRAM_TIMER_EXPANDER(name, true, __COUNTER__)
end_define
begin_comment
comment|// This nested macro is necessary to expand __COUNTER__ to an actual value.
end_comment
begin_define
DECL|macro|SCOPED_ANGLE_HISTOGRAM_TIMER_EXPANDER
define|#
directive|define
name|SCOPED_ANGLE_HISTOGRAM_TIMER_EXPANDER
parameter_list|(
name|name
parameter_list|,
name|is_long
parameter_list|,
name|key
parameter_list|)
define|\
value|SCOPED_ANGLE_HISTOGRAM_TIMER_UNIQUE(name, is_long, key)
end_define
begin_define
DECL|macro|SCOPED_ANGLE_HISTOGRAM_TIMER_UNIQUE
define|#
directive|define
name|SCOPED_ANGLE_HISTOGRAM_TIMER_UNIQUE
parameter_list|(
name|name
parameter_list|,
name|is_long
parameter_list|,
name|key
parameter_list|)
define|\
value|class ScopedHistogramTimer##key                                                          \     {                                                                                        \       public:                                                                                \         ScopedHistogramTimer##key() : constructed_(ANGLEPlatformCurrent()->currentTime()) {} \         ~ScopedHistogramTimer##key()                                                         \         {                                                                                    \             if (constructed_ == 0)                                                           \                 return;                                                                      \             double elapsed = ANGLEPlatformCurrent()->currentTime() - constructed_;           \             int elapsedMS = static_cast<int>(elapsed * 1000.0);                              \             if (is_long)                                                                     \             {                                                                                \                 ANGLE_HISTOGRAM_LONG_TIMES_100(name, elapsedMS);                             \             }                                                                                \             else                                                                             \             {                                                                                \                 ANGLE_HISTOGRAM_TIMES(name, elapsedMS);                                      \             }                                                                                \         }                                                                                    \                                                                                              \       private:                                                                               \         double constructed_;                                                                 \     } scoped_histogram_timer_##key
end_define
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// BASE_METRICS_HISTOGRAM_MACROS_H_
end_comment
end_unit
