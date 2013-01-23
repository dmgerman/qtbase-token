/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the plugins of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#import <Cocoa/Cocoa.h>

#include "qcocoatheme.h"

#include <QtCore/QVariant>

#include "qcocoacolordialoghelper.h"
#include "qcocoafiledialoghelper.h"
#include "qcocoafontdialoghelper.h"
#include "qcocoasystemsettings.h"
#include "qcocoasystemtrayicon.h"
#include "qcocoamenuitem.h"
#include "qcocoamenu.h"
#include "qcocoamenubar.h"

#include <QtCore/qfileinfo.h>
#include <QtGui/private/qguiapplication_p.h>
#include <QtGui/qpainter.h>
#include <qpa/qplatformintegration.h>
#include <qpa/qplatformnativeinterface.h>

QT_BEGIN_NAMESPACE

const char *QCocoaTheme::name = "cocoa";

QCocoaTheme::QCocoaTheme()
    :m_systemPalette(0)
{

}

QCocoaTheme::~QCocoaTheme()
{
    delete m_systemPalette;
}

bool QCocoaTheme::usePlatformNativeDialog(DialogType dialogType) const
{
    if (dialogType == QPlatformTheme::FileDialog)
        return true;
#ifndef QT_NO_COLORDIALOG
    if (dialogType == QPlatformTheme::ColorDialog)
        return true;
#endif
#ifndef QT_NO_FONTDIALOG
    if (dialogType == QPlatformTheme::FontDialog)
        return true;
#endif
    return false;
}

QPlatformDialogHelper * QCocoaTheme::createPlatformDialogHelper(DialogType dialogType) const
{
    switch (dialogType) {
    case QPlatformTheme::FileDialog:
        return new QCocoaFileDialogHelper();
#ifndef QT_NO_COLORDIALOG
    case QPlatformTheme::ColorDialog:
        return new QCocoaColorDialogHelper();
#endif
#ifndef QT_NO_FONTDIALOG
    case QPlatformTheme::FontDialog:
        return new QCocoaFontDialogHelper();
#endif
    default:
        return 0;
    }
}

#ifndef QT_NO_SYSTEMTRAYICON
QPlatformSystemTrayIcon *QCocoaTheme::createPlatformSystemTrayIcon() const
{
    return new QCocoaSystemTrayIcon;
}
#endif

const QPalette *QCocoaTheme::palette(Palette type) const
{
    if (type == SystemPalette) {
        if (!m_systemPalette)
            m_systemPalette = qt_mac_createSystemPalette();
        return m_systemPalette;
    } else {
        if (m_palettes.isEmpty())
            m_palettes = qt_mac_createRolePalettes();
        return m_palettes.value(type, 0);
    }
    return 0;
}

const QFont *QCocoaTheme::font(Font type) const
{
    if (m_fonts.isEmpty()) {
        m_fonts = qt_mac_createRoleFonts();
    }
    return m_fonts.value(type, 0);
}

// Defined in qpaintengine_mac.mm
extern CGContextRef qt_mac_cg_context(const QPaintDevice *pdev);

//! \internal
QPixmap qt_mac_convert_iconref(const IconRef icon, int width, int height)
{
    QPixmap ret(width, height);
    ret.fill(QColor(0, 0, 0, 0));

    CGRect rect = CGRectMake(0, 0, width, height);

    CGContextRef ctx = qt_mac_cg_context(&ret);
    CGAffineTransform old_xform = CGContextGetCTM(ctx);
    CGContextConcatCTM(ctx, CGAffineTransformInvert(old_xform));
    CGContextConcatCTM(ctx, CGAffineTransformIdentity);

    ::RGBColor b;
    b.blue = b.green = b.red = 255*255;
    PlotIconRefInContext(ctx, &rect, kAlignNone, kTransformNone, &b, kPlotIconRefNormalFlags, icon);
    CGContextRelease(ctx);
    return ret;
}

QPixmap QCocoaTheme::standardPixmap(StandardPixmap sp, const QSizeF &size) const
{
    OSType iconType = 0;
    switch (sp) {
    case MessageBoxQuestion:
        iconType = kQuestionMarkIcon;
        break;
    case MessageBoxInformation:
        iconType = kAlertNoteIcon;
        break;
    case MessageBoxWarning:
        iconType = kAlertCautionIcon;
        break;
    case MessageBoxCritical:
        iconType = kAlertStopIcon;
        break;
    case DesktopIcon:
        iconType = kDesktopIcon;
        break;
    case TrashIcon:
        iconType = kTrashIcon;
        break;
    case ComputerIcon:
        iconType = kComputerIcon;
        break;
    case DriveFDIcon:
        iconType = kGenericFloppyIcon;
        break;
    case DriveHDIcon:
        iconType = kGenericHardDiskIcon;
        break;
    case DriveCDIcon:
    case DriveDVDIcon:
        iconType = kGenericCDROMIcon;
        break;
    case DriveNetIcon:
        iconType = kGenericNetworkIcon;
        break;
    case DirOpenIcon:
        iconType = kOpenFolderIcon;
        break;
    case DirClosedIcon:
    case DirLinkIcon:
        iconType = kGenericFolderIcon;
        break;
    case FileLinkIcon:
    case FileIcon:
        iconType = kGenericDocumentIcon;
        break;
    default:
        break;
    }
    if (iconType != 0) {
        QPixmap pixmap;
        IconRef icon;
        IconRef overlayIcon = 0;
        if (iconType != kGenericApplicationIcon) {
            GetIconRef(kOnSystemDisk, kSystemIconsCreator, iconType, &icon);
        } else {
            FSRef fsRef;
            ProcessSerialNumber psn = { 0, kCurrentProcess };
            GetProcessBundleLocation(&psn, &fsRef);
            GetIconRefFromFileInfo(&fsRef, 0, 0, 0, 0, kIconServicesNormalUsageFlag, &icon, 0);
            if (sp == MessageBoxCritical) {
                overlayIcon = icon;
                GetIconRef(kOnSystemDisk, kSystemIconsCreator, kAlertCautionIcon, &icon);
            }
        }

        if (icon) {
            pixmap = qt_mac_convert_iconref(icon, size.width(), size.height());
            ReleaseIconRef(icon);
        }

        if (overlayIcon) {
            QSizeF littleSize = size / 2;
            QPixmap overlayPix = qt_mac_convert_iconref(overlayIcon, littleSize.width(), littleSize.height());
            QPainter painter(&pixmap);
            painter.drawPixmap(littleSize.width(), littleSize.height(), overlayPix);
            ReleaseIconRef(overlayIcon);
        }

        return pixmap;
    }

    return QPlatformTheme::standardPixmap(sp, size);
}

QPixmap QCocoaTheme::fileIconPixmap(const QFileInfo &fileInfo, const QSizeF &size) const
{
    FSRef macRef;
    OSStatus status = FSPathMakeRef(reinterpret_cast<const UInt8*>(fileInfo.canonicalFilePath().toUtf8().constData()),
                                    &macRef, 0);
    if (status != noErr)
        return QPixmap();
    FSCatalogInfo info;
    HFSUniStr255 macName;
    status = FSGetCatalogInfo(&macRef, kIconServicesCatalogInfoMask, &info, &macName, 0, 0);
    if (status != noErr)
        return QPixmap();
    IconRef iconRef;
    SInt16 iconLabel;
    status = GetIconRefFromFileInfo(&macRef, macName.length, macName.unicode,
                                    kIconServicesCatalogInfoMask, &info, kIconServicesNormalUsageFlag,
                                    &iconRef, &iconLabel);
    if (status != noErr)
        return QPixmap();

    QPixmap pixmap = qt_mac_convert_iconref(iconRef, size.width(), size.height());
    ReleaseIconRef(iconRef);

    return pixmap;
}

QVariant QCocoaTheme::themeHint(ThemeHint hint) const
{
    switch (hint) {
    case QPlatformTheme::StyleNames:
        return QStringList(QStringLiteral("macintosh"));
    case QPlatformTheme::DialogButtonBoxLayout:
        return QVariant(1); // QDialogButtonBox::MacLayout
    case KeyboardScheme:
        return QVariant(int(MacKeyboardScheme));
    case TabAllWidgets:
        return QVariant(bool([[NSApplication sharedApplication] isFullKeyboardAccessEnabled]));
    case IconPixmapSizes: {
        QList<int> sizes;
        sizes << 16 << 32 << 64 << 128;
        return QVariant::fromValue(sizes);
    }
    default:
        break;
    }
    return QPlatformTheme::themeHint(hint);
}

QPlatformMenuItem *QCocoaTheme::createPlatformMenuItem() const
{
    return new QCocoaMenuItem();
}

QPlatformMenu *QCocoaTheme::createPlatformMenu() const
{
    return new QCocoaMenu();
}

QPlatformMenuBar *QCocoaTheme::createPlatformMenuBar() const
{
    static bool haveMenubar = false;
    if (!haveMenubar) {
        haveMenubar = true;
        QObject::connect(qGuiApp, SIGNAL(focusWindowChanged(QWindow*)),
            QGuiApplicationPrivate::platformIntegration()->nativeInterface(),
                SLOT(onAppFocusWindowChanged(QWindow*)));
    }

    return new QCocoaMenuBar();
}

QT_END_NAMESPACE
