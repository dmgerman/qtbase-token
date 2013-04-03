begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  gxvmort.h                                                              */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*    TrueTypeGX/AAT common definition for mort table (specification).     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  Copyright 2004, 2005 by suzuki toshiya, Masatake YAMATO, Red Hat K.K., */
end_comment
begin_comment
comment|/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*  This file is part of the FreeType project, and may only be used,       */
end_comment
begin_comment
comment|/*  modified, and distributed under the terms of the FreeType project      */
end_comment
begin_comment
comment|/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
end_comment
begin_comment
comment|/*  this file you indicate that you have read the license and              */
end_comment
begin_comment
comment|/*  understand and accept it fully.                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* gxvalid is derived from both gxlayout module and otvalid module.        */
end_comment
begin_comment
comment|/* Development of gxlayout is supported by the Information-technology      */
end_comment
begin_comment
comment|/* Promotion Agency(IPA), Japan.                                           */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__GXVMORT_H__
end_ifndef
begin_define
DECL|macro|__GXVMORT_H__
define|#
directive|define
name|__GXVMORT_H__
end_define
begin_include
include|#
directive|include
file|"gxvalid.h"
end_include
begin_include
include|#
directive|include
file|"gxvcommn.h"
end_include
begin_include
include|#
directive|include
include|FT_SFNT_NAMES_H
end_include
begin_typedef
DECL|struct|GXV_mort_featureRec_
typedef|typedef
struct|struct
name|GXV_mort_featureRec_
block|{
DECL|member|featureType
name|FT_UShort
name|featureType
decl_stmt|;
DECL|member|featureSetting
name|FT_UShort
name|featureSetting
decl_stmt|;
DECL|member|enableFlags
name|FT_ULong
name|enableFlags
decl_stmt|;
DECL|member|disableFlags
name|FT_ULong
name|disableFlags
decl_stmt|;
block|}
DECL|typedef|GXV_mort_featureRec
DECL|typedef|GXV_mort_feature
name|GXV_mort_featureRec
operator|,
typedef|*
name|GXV_mort_feature
typedef|;
end_typedef
begin_define
DECL|macro|GXV_MORT_FEATURE_OFF
define|#
directive|define
name|GXV_MORT_FEATURE_OFF
value|{0, 1, 0x00000000UL, 0x00000000UL}
end_define
begin_define
DECL|macro|IS_GXV_MORT_FEATURE_OFF
define|#
directive|define
name|IS_GXV_MORT_FEATURE_OFF
parameter_list|(
name|f
parameter_list|)
define|\
value|( (f).featureType    == 0            || \             (f).featureSetting == 1            || \             (f).enableFlags    == 0x00000000UL || \             (f).disableFlags   == 0x00000000UL )
end_define
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_mort_featurearray_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|FT_ULong       nFeatureFlags
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_mort_coverage_validate
argument_list|(
argument|FT_UShort      coverage
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_mort_subtable_type0_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_mort_subtable_type1_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_mort_subtable_type2_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_mort_subtable_type4_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_macro
name|FT_LOCAL
argument_list|(
argument|void
argument_list|)
end_macro
begin_macro
name|gxv_mort_subtable_type5_validate
argument_list|(
argument|FT_Bytes       table
argument_list|,
argument|FT_Bytes       limit
argument_list|,
argument|GXV_Validator  valid
argument_list|)
end_macro
begin_empty_stmt
empty_stmt|;
end_empty_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __GXVMORT_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
