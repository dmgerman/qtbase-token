/****************************************************************************
 **
 ** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
 ** All rights reserved.
 ** Contact: Nokia Corporation (qt-info@nokia.com)
 **
 ** This file is part of the plugins of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:LGPL$
 ** GNU Lesser General Public License Usage
 ** This file may be used under the terms of the GNU Lesser General Public
 ** License version 2.1 as published by the Free Software Foundation and
 ** appearing in the file LICENSE.LGPL included in the packaging of this
 ** file. Please review the following information to ensure the GNU Lesser
 ** General Public License version 2.1 requirements will be met:
 ** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
 **
 ** In addition, as a special exception, Nokia gives you certain additional
 ** rights. These rights are described in the Nokia Qt LGPL Exception
 ** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
 **
 ** GNU General Public License Usage
 ** Alternatively, this file may be used under the terms of the GNU General
 ** Public License version 3.0 as published by the Free Software Foundation
 ** and appearing in the file LICENSE.GPL included in the packaging of this
 ** file. Please review the following information to ensure the GNU General
 ** Public License version 3.0 requirements will be met:
 ** http://www.gnu.org/copyleft/gpl.html.
 **
 ** Other Usage
 ** Alternatively, this file may be used in accordance with the terms and
 ** conditions contained in a signed written agreement between you and Nokia.
 **
 **
 **
 **
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/
#include "qcocoaaccessibilityelement.h"
#include "qcocoaaccessibility.h"
#include "qcocoahelpers.h"

#include <QAccessible>
#include "QAccessibleActionInterface"

#import <AppKit/NSAccessibility.h>

static QAccessibleInterface *acast(void *ptr)
{
    return reinterpret_cast<QAccessibleInterface *>(ptr);
}

@implementation QCocoaAccessibleElement

- (id)initWithIndex:(int)aIndex parent:(id)aParent accessibleInterface:(void *)anQAccessibleInterface
{
    self = [super init];
    if (self) {
        index = aIndex;
        accessibleInterface = anQAccessibleInterface;
        role = macRole(acast(accessibleInterface)->role());
        parent = aParent;

    }

    return self;
}

+ (QCocoaAccessibleElement *)elementWithIndex:(int)aIndex parent:(id)aParent accessibleInterface:(void *)anQAccessibleInterface
{
    return [[[self alloc] initWithIndex:aIndex parent:aParent accessibleInterface:anQAccessibleInterface] autorelease];
}

- (void)dealloc {
    [super dealloc];
}

- (BOOL)isEqual:(id)object {
    if ([object isKindOfClass:[QCocoaAccessibleElement class]]) {
        QCocoaAccessibleElement *other = object;
        return (index == other->index) && [role isEqualToString:other->role] && [parent isEqual:other->parent];
    } else
        return NO;
}

- (NSUInteger)hash {
    return [parent hash] + index;
}

- (NSUInteger)index {
    return index;
}

//
// accessibility protocol
//

// attributes

- (NSArray *)accessibilityAttributeNames {
    static NSArray *attributes = nil;
    if (attributes == nil) {
        attributes = [[NSArray alloc] initWithObjects:
        NSAccessibilityRoleAttribute,
        NSAccessibilityRoleDescriptionAttribute,
        NSAccessibilityFocusedAttribute,
        NSAccessibilityParentAttribute,
        NSAccessibilityWindowAttribute,
        NSAccessibilityTopLevelUIElementAttribute,
        NSAccessibilityPositionAttribute,
        NSAccessibilitySizeAttribute,
        NSAccessibilityDescriptionAttribute,
        nil];
    }
    return attributes;
}

- (id)accessibilityAttributeValue:(NSString *)attribute {
    if ([attribute isEqualToString:NSAccessibilityRoleAttribute]) {
        return role;
    } else if ([attribute isEqualToString:NSAccessibilityRoleDescriptionAttribute]) {
        return NSAccessibilityRoleDescription(role, nil);
    } else if ([attribute isEqualToString:NSAccessibilityFocusedAttribute]) {
        // Just check if the app thinks we're focused.
        id focusedElement = [NSApp accessibilityAttributeValue:NSAccessibilityFocusedUIElementAttribute];
        return [NSNumber numberWithBool:[focusedElement isEqual:self]];
    } else if ([attribute isEqualToString:NSAccessibilityParentAttribute]) {
        return NSAccessibilityUnignoredAncestor(parent);
    } else if ([attribute isEqualToString:NSAccessibilityWindowAttribute]) {
        // We're in the same window as our parent.
        return [parent accessibilityAttributeValue:NSAccessibilityWindowAttribute];
    } else if ([attribute isEqualToString:NSAccessibilityTopLevelUIElementAttribute]) {
        // We're in the same top level element as our parent.
        return [parent accessibilityAttributeValue:NSAccessibilityTopLevelUIElementAttribute];
    } else if ([attribute isEqualToString:NSAccessibilityPositionAttribute]) {
        QPoint qtPosition = acast(accessibleInterface)->rect().topLeft();
        QSize qtSize = acast(accessibleInterface)->rect().size();
        return [NSValue valueWithPoint: NSMakePoint(qtPosition.x(), qt_mac_flipYCoordinate(qtPosition.y() + qtSize.height()))];
    } else if ([attribute isEqualToString:NSAccessibilitySizeAttribute]) {
        QSize qtSize = acast(accessibleInterface)->rect().size();
        return [NSValue valueWithSize: NSMakeSize(qtSize.width(), qtSize.height())];
    } else if ([attribute isEqualToString:NSAccessibilityDescriptionAttribute]) {
        return qt_mac_QStringToNSString(acast(accessibleInterface)->text(QAccessible::Name));
    }

    return nil;
}

- (BOOL)accessibilityIsAttributeSettable:(NSString *)attribute {
    if ([attribute isEqualToString:NSAccessibilityFocusedAttribute]) {
        return NO; // YES to handle keyboard input
    } else {
        return NO;
    }
}

- (void)accessibilitySetValue:(id)value forAttribute:(NSString *)attribute {
    Q_UNUSED(value);
    if ([attribute isEqualToString:NSAccessibilityFocusedAttribute]) {

    }
}

// actions

- (NSArray *)accessibilityActionNames {
    return [NSArray arrayWithObject:NSAccessibilityPressAction];
}

- (NSString *)accessibilityActionDescription:(NSString *)action {
    return NSAccessibilityActionDescription(action);
}

- (void)accessibilityPerformAction:(NSString *)action {
    Q_UNUSED(action);
    if (acast(accessibleInterface)->actionInterface())
        acast(accessibleInterface)->actionInterface()->doAction(0);
}

// misc

- (BOOL)accessibilityIsIgnored {
    return NO;
}

- (id)accessibilityHitTest:(NSPoint)point {
    Q_UNUSED(point);
    return NSAccessibilityUnignoredAncestor(self);
}

- (id)accessibilityFocusedUIElement {
    return NSAccessibilityUnignoredAncestor(self);
}

@end
