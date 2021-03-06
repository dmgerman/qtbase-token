begin_unit
begin_comment
comment|/*  pcfdrivr.h      FreeType font driver for pcf fonts    Copyright 2000-2001, 2002 by   Francesco Zappa Nardelli  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|__PCFDRIVR_H__
end_ifndef
begin_define
DECL|macro|__PCFDRIVR_H__
define|#
directive|define
name|__PCFDRIVR_H__
end_define
begin_include
include|#
directive|include
file|<ft2build.h>
end_include
begin_include
include|#
directive|include
include|FT_INTERNAL_DRIVER_H
end_include
begin_decl_stmt
name|FT_BEGIN_HEADER
ifdef|#
directive|ifdef
name|FT_CONFIG_OPTION_PIC
error|#
directive|error
literal|"this module does not support PIC yet"
endif|#
directive|endif
name|FT_EXPORT_VAR
argument_list|(
specifier|const
name|FT_Driver_ClassRec
argument_list|)
name|pcf_driver_class
decl_stmt|;
end_decl_stmt
begin_macro
name|FT_END_HEADER
end_macro
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|/* __PCFDRIVR_H__ */
end_comment
begin_comment
comment|/* END */
end_comment
end_unit
