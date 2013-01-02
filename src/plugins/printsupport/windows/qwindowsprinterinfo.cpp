begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies). ** Contact: http://www.qt-project.org/legal ** ** This file is part of the QtGui module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and Digia.  For licensing terms and ** conditions see http://qt.digia.com/licensing.  For further information ** use the contact form at http://qt.digia.com/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 2.1 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU Lesser General Public License version 2.1 requirements ** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html. ** ** In addition, as a special exception, Digia gives you certain additional ** rights.  These rights are described in the Digia Qt LGPL Exception ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 3.0 as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL included in the ** packaging of this file.  Please review the following information to ** ensure the GNU General Public License version 3.0 requirements will be ** met: http://www.gnu.org/copyleft/gpl.html. ** ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_include
include|#
directive|include
file|"qprinterinfo.h"
end_include
begin_include
include|#
directive|include
file|"qprinterinfo_p.h"
end_include
begin_include
include|#
directive|include
file|<qstringlist.h>
end_include
begin_include
include|#
directive|include
file|<qt_windows.h>
end_include
begin_function_decl
name|QT_BEGIN_NAMESPACE
ifndef|#
directive|ifndef
name|QT_NO_PRINTER
specifier|extern
name|QPrinter
operator|::
name|PaperSize
name|mapDevmodePaperSize
parameter_list|(
name|int
name|s
parameter_list|)
function_decl|;
end_function_decl
begin_comment
comment|//QList<QPrinterInfo> QPrinterInfo::availablePrinters()
end_comment
begin_comment
comment|//{
end_comment
begin_comment
comment|//    QList<QPrinterInfo> printers;
end_comment
begin_comment
comment|//    DWORD needed = 0;
end_comment
begin_comment
comment|//    DWORD returned = 0;
end_comment
begin_comment
comment|//    if (!EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 4, 0, 0,&needed,&returned)) {
end_comment
begin_comment
comment|//        LPBYTE buffer = new BYTE[needed];
end_comment
begin_comment
comment|//        if (EnumPrinters(PRINTER_ENUM_LOCAL | PRINTER_ENUM_CONNECTIONS, NULL, 4, buffer, needed,&needed,&returned)) {
end_comment
begin_comment
comment|//            PPRINTER_INFO_4 infoList = reinterpret_cast<PPRINTER_INFO_4>(buffer);
end_comment
begin_comment
comment|//            QPrinterInfo defPrn = defaultPrinter();
end_comment
begin_comment
comment|//            for (uint i = 0; i< returned; ++i) {
end_comment
begin_comment
comment|//                QString printerName(QString::fromWCharArray(infoList[i].pPrinterName));
end_comment
begin_comment
comment|//                QPrinterInfo printerInfo(printerName);
end_comment
begin_comment
comment|//                if (printerInfo.printerName() == defPrn.printerName())
end_comment
begin_comment
comment|//                    printerInfo.d_ptr->isDefault = true;
end_comment
begin_comment
comment|//                printers.append(printerInfo);
end_comment
begin_comment
comment|//            }
end_comment
begin_comment
comment|//        }
end_comment
begin_comment
comment|//        delete [] buffer;
end_comment
begin_comment
comment|//    }
end_comment
begin_comment
comment|//    return printers;
end_comment
begin_comment
comment|//}
end_comment
begin_comment
comment|//QPrinterInfo QPrinterInfo::defaultPrinter()
end_comment
begin_comment
comment|//{
end_comment
begin_comment
comment|//    QString noPrinters(QLatin1String("qt_no_printers"));
end_comment
begin_comment
comment|//    wchar_t buffer[256];
end_comment
begin_comment
comment|//    GetProfileString(L"windows", L"device", (wchar_t*)noPrinters.utf16(), buffer, 256);
end_comment
begin_comment
comment|//    QString output = QString::fromWCharArray(buffer);
end_comment
begin_comment
comment|//    if (output != noPrinters) {
end_comment
begin_comment
comment|//        // Filter out the name of the printer, which should be everything before a comma.
end_comment
begin_comment
comment|//        QString printerName = output.split(QLatin1Char(',')).value(0);
end_comment
begin_comment
comment|//        QPrinterInfo printerInfo(printerName);
end_comment
begin_comment
comment|//        printerInfo.d_ptr->isDefault = true;
end_comment
begin_comment
comment|//        return printerInfo;
end_comment
begin_comment
comment|//    }
end_comment
begin_comment
comment|//    return QPrinterInfo();
end_comment
begin_comment
comment|//}
end_comment
begin_comment
comment|//QList<QPrinter::PaperSize> QPrinterInfo::supportedPaperSizes() const
end_comment
begin_comment
comment|//{
end_comment
begin_comment
comment|//    const Q_D(QPrinterInfo);
end_comment
begin_comment
comment|//    QList<QPrinter::PaperSize> paperSizes;
end_comment
begin_comment
comment|//    if (isNull())
end_comment
begin_comment
comment|//        return paperSizes;
end_comment
begin_comment
comment|//    DWORD size = DeviceCapabilities(reinterpret_cast<const wchar_t*>(d->name.utf16()),
end_comment
begin_comment
comment|//                                    NULL, DC_PAPERS, NULL, NULL);
end_comment
begin_comment
comment|//    if ((int)size != -1) {
end_comment
begin_comment
comment|//        wchar_t *papers = new wchar_t[size];
end_comment
begin_comment
comment|//        size = DeviceCapabilities(reinterpret_cast<const wchar_t*>(d->name.utf16()),
end_comment
begin_comment
comment|//                                  NULL, DC_PAPERS, papers, NULL);
end_comment
begin_comment
comment|//        for (int c = 0; c< (int)size; ++c)
end_comment
begin_comment
comment|//            paperSizes.append(mapDevmodePaperSize(papers[c]));
end_comment
begin_comment
comment|//        delete [] papers;
end_comment
begin_comment
comment|//    }
end_comment
begin_comment
comment|//    return paperSizes;
end_comment
begin_comment
comment|//}
end_comment
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QT_NO_PRINTER
end_comment
begin_macro
name|QT_END_NAMESPACE
end_macro
end_unit
