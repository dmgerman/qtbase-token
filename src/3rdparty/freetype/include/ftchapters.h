begin_unit
begin_comment
comment|/***************************************************************************/
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/* This file defines the structure of the FreeType reference.              */
end_comment
begin_comment
comment|/* It is used by the python script that generates the HTML files.          */
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
comment|/*<Chapter>                                                               */
end_comment
begin_comment
comment|/*    general_remarks                                                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Title>                                                                 */
end_comment
begin_comment
comment|/*    General Remarks                                                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Sections>                                                              */
end_comment
begin_comment
comment|/*    header_inclusion                                                     */
end_comment
begin_comment
comment|/*    user_allocation                                                      */
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
comment|/*<Chapter>                                                               */
end_comment
begin_comment
comment|/*    core_api                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Title>                                                                 */
end_comment
begin_comment
comment|/*    Core API                                                             */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Sections>                                                              */
end_comment
begin_comment
comment|/*    version                                                              */
end_comment
begin_comment
comment|/*    basic_types                                                          */
end_comment
begin_comment
comment|/*    base_interface                                                       */
end_comment
begin_comment
comment|/*    glyph_variants                                                       */
end_comment
begin_comment
comment|/*    glyph_management                                                     */
end_comment
begin_comment
comment|/*    mac_specific                                                         */
end_comment
begin_comment
comment|/*    sizes_management                                                     */
end_comment
begin_comment
comment|/*    header_file_macros                                                   */
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
comment|/*<Chapter>                                                               */
end_comment
begin_comment
comment|/*    format_specific                                                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Title>                                                                 */
end_comment
begin_comment
comment|/*    Format-Specific API                                                  */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Sections>                                                              */
end_comment
begin_comment
comment|/*    multiple_masters                                                     */
end_comment
begin_comment
comment|/*    truetype_tables                                                      */
end_comment
begin_comment
comment|/*    type1_tables                                                         */
end_comment
begin_comment
comment|/*    sfnt_names                                                           */
end_comment
begin_comment
comment|/*    bdf_fonts                                                            */
end_comment
begin_comment
comment|/*    cid_fonts                                                            */
end_comment
begin_comment
comment|/*    pfr_fonts                                                            */
end_comment
begin_comment
comment|/*    winfnt_fonts                                                         */
end_comment
begin_comment
comment|/*    font_formats                                                         */
end_comment
begin_comment
comment|/*    gasp_table                                                           */
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
comment|/*<Chapter>                                                               */
end_comment
begin_comment
comment|/*    module_specific                                                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Title>                                                                 */
end_comment
begin_comment
comment|/*    Controlling FreeType Modules                                         */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Sections>                                                              */
end_comment
begin_comment
comment|/*    auto_hinter                                                          */
end_comment
begin_comment
comment|/*    cff_driver                                                           */
end_comment
begin_comment
comment|/*    tt_driver                                                            */
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
comment|/*<Chapter>                                                               */
end_comment
begin_comment
comment|/*    cache_subsystem                                                      */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Title>                                                                 */
end_comment
begin_comment
comment|/*    Cache Sub-System                                                     */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Sections>                                                              */
end_comment
begin_comment
comment|/*    cache_subsystem                                                      */
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
comment|/*<Chapter>                                                               */
end_comment
begin_comment
comment|/*    support_api                                                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Title>                                                                 */
end_comment
begin_comment
comment|/*    Support API                                                          */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/*<Sections>                                                              */
end_comment
begin_comment
comment|/*    computations                                                         */
end_comment
begin_comment
comment|/*    list_processing                                                      */
end_comment
begin_comment
comment|/*    outline_processing                                                   */
end_comment
begin_comment
comment|/*    quick_advance                                                        */
end_comment
begin_comment
comment|/*    bitmap_handling                                                      */
end_comment
begin_comment
comment|/*    raster                                                               */
end_comment
begin_comment
comment|/*    glyph_stroker                                                        */
end_comment
begin_comment
comment|/*    system_interface                                                     */
end_comment
begin_comment
comment|/*    module_management                                                    */
end_comment
begin_comment
comment|/*    gzip                                                                 */
end_comment
begin_comment
comment|/*    lzw                                                                  */
end_comment
begin_comment
comment|/*    bzip2                                                                */
end_comment
begin_comment
comment|/*    lcd_filtering                                                        */
end_comment
begin_comment
comment|/*                                                                         */
end_comment
begin_comment
comment|/***************************************************************************/
end_comment
end_unit
