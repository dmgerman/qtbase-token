begin_unit
begin_comment
comment|/**************************************************************************** ** ** Copyright (C) 2016 The Qt Company Ltd. ** Contact: https://www.qt.io/licensing/ ** ** This file is part of the QtCore module of the Qt Toolkit. ** ** $QT_BEGIN_LICENSE:LGPL$ ** Commercial License Usage ** Licensees holding valid commercial Qt licenses may use this file in ** accordance with the commercial license agreement provided with the ** Software or, alternatively, in accordance with the terms contained in ** a written agreement between you and The Qt Company. For licensing terms ** and conditions see https://www.qt.io/terms-conditions. For further ** information use the contact form at https://www.qt.io/contact-us. ** ** GNU Lesser General Public License Usage ** Alternatively, this file may be used under the terms of the GNU Lesser ** General Public License version 3 as published by the Free Software ** Foundation and appearing in the file LICENSE.LGPL3 included in the ** packaging of this file. Please review the following information to ** ensure the GNU Lesser General Public License version 3 requirements ** will be met: https://www.gnu.org/licenses/lgpl-3.0.html. ** ** GNU General Public License Usage ** Alternatively, this file may be used under the terms of the GNU ** General Public License version 2.0 or (at your option) the GNU General ** Public license version 3 or any later version approved by the KDE Free ** Qt Foundation. The licenses are as published by the Free Software ** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3 ** included in the packaging of this file. Please review the following ** information to ensure the GNU General Public License requirements will ** be met: https://www.gnu.org/licenses/gpl-2.0.html and ** https://www.gnu.org/licenses/gpl-3.0.html. ** ** $QT_END_LICENSE$ ** ****************************************************************************/
end_comment
begin_ifndef
ifndef|#
directive|ifndef
name|QITERATOR_H
end_ifndef
begin_define
DECL|macro|QITERATOR_H
define|#
directive|define
name|QITERATOR_H
end_define
begin_include
include|#
directive|include
file|<QtCore/qglobal.h>
end_include
begin_expr_stmt
name|QT_BEGIN_NAMESPACE
DECL|macro|Q_DECLARE_SEQUENTIAL_ITERATOR
define|#
directive|define
name|Q_DECLARE_SEQUENTIAL_ITERATOR
parameter_list|(
name|C
parameter_list|)
define|\ \
value|template<class T> \ class Q##C##Iterator \ { \     typedef typename Q##C<T>::const_iterator const_iterator; \     Q##C<T> c; \     const_iterator i; \ public: \     inline Q##C##Iterator(const Q##C<T>&container) \         : c(container), i(c.constBegin()) {} \     inline Q##C##Iterator&operator=(const Q##C<T>&container) \     { c = container; i = c.constBegin(); return *this; } \     inline void toFront() { i = c.constBegin(); } \     inline void toBack() { i = c.constEnd(); } \     inline bool hasNext() const { return i != c.constEnd(); } \     inline const T&next() { return *i++; } \     inline const T&peekNext() const { return *i; } \     inline bool hasPrevious() const { return i != c.constBegin(); } \     inline const T&previous() { return *--i; } \     inline const T&peekPrevious() const { const_iterator p = i; return *--p; } \     inline bool findNext(const T&t) \     { while (i != c.constEnd()) if (*i++ == t) return true; return false; } \     inline bool findPrevious(const T&t) \     { while (i != c.constBegin()) if (*(--i) == t) return true; \       return false;  } \ };
DECL|macro|Q_DECLARE_MUTABLE_SEQUENTIAL_ITERATOR
define|#
directive|define
name|Q_DECLARE_MUTABLE_SEQUENTIAL_ITERATOR
parameter_list|(
name|C
parameter_list|)
define|\ \
value|template<class T> \ class QMutable##C##Iterator \ { \     typedef typename Q##C<T>::iterator iterator; \     typedef typename Q##C<T>::const_iterator const_iterator; \     Q##C<T> *c; \     iterator i, n; \     inline bool item_exists() const { return const_iterator(n) != c->constEnd(); } \ public: \     inline QMutable##C##Iterator(Q##C<T>&container) \         : c(&container) \     { i = c->begin(); n = c->end(); } \     inline QMutable##C##Iterator&operator=(Q##C<T>&container) \     { c =&container; i = c->begin(); n = c->end(); return *this; } \     inline void toFront() { i = c->begin(); n = c->end(); } \     inline void toBack() { i = c->end(); n = i; } \     inline bool hasNext() const { return c->constEnd() != const_iterator(i); } \     inline T&next() { n = i++; return *n; } \     inline T&peekNext() const { return *i; } \     inline bool hasPrevious() const { return c->constBegin() != const_iterator(i); } \     inline T&previous() { n = --i; return *n; } \     inline T&peekPrevious() const { iterator p = i; return *--p; } \     inline void remove() \     { if (c->constEnd() != const_iterator(n)) { i = c->erase(n); n = c->end(); } } \     inline void setValue(const T&t) const { if (c->constEnd() != const_iterator(n)) *n = t; } \     inline T&value() { Q_ASSERT(item_exists()); return *n; } \     inline const T&value() const { Q_ASSERT(item_exists()); return *n; } \     inline void insert(const T&t) { n = i = c->insert(i, t); ++i; } \     inline bool findNext(const T&t) \     { while (c->constEnd() != const_iterator(n = i)) if (*i++ == t) return true; return false; } \     inline bool findPrevious(const T&t) \     { while (c->constBegin() != const_iterator(i)) if (*(n = --i) == t) return true; \       n = c->end(); return false;  } \ };
DECL|macro|Q_DECLARE_ASSOCIATIVE_ITERATOR
define|#
directive|define
name|Q_DECLARE_ASSOCIATIVE_ITERATOR
parameter_list|(
name|C
parameter_list|)
define|\ \
value|template<class Key, class T> \ class Q##C##Iterator \ { \     typedef typename Q##C<Key,T>::const_iterator const_iterator; \     typedef const_iterator Item; \     Q##C<Key,T> c; \     const_iterator i, n; \     inline bool item_exists() const { return n != c.constEnd(); } \ public: \     inline Q##C##Iterator(const Q##C<Key,T>&container) \         : c(container), i(c.constBegin()), n(c.constEnd()) {} \     inline Q##C##Iterator&operator=(const Q##C<Key,T>&container) \     { c = container; i = c.constBegin(); n = c.constEnd(); return *this; } \     inline void toFront() { i = c.constBegin(); n = c.constEnd(); } \     inline void toBack() { i = c.constEnd(); n = c.constEnd(); } \     inline bool hasNext() const { return i != c.constEnd(); } \     inline Item next() { n = i++; return n; } \     inline Item peekNext() const { return i; } \     inline bool hasPrevious() const { return i != c.constBegin(); } \     inline Item previous() { n = --i; return n; } \     inline Item peekPrevious() const { const_iterator p = i; return --p; } \     inline const T&value() const { Q_ASSERT(item_exists()); return *n; } \     inline const Key&key() const { Q_ASSERT(item_exists()); return n.key(); } \     inline bool findNext(const T&t) \     { while ((n = i) != c.constEnd()) if (*i++ == t) return true; return false; } \     inline bool findPrevious(const T&t) \     { while (i != c.constBegin()) if (*(n = --i) == t) return true; \       n = c.constEnd(); return false; } \ };
DECL|macro|Q_DECLARE_MUTABLE_ASSOCIATIVE_ITERATOR
define|#
directive|define
name|Q_DECLARE_MUTABLE_ASSOCIATIVE_ITERATOR
parameter_list|(
name|C
parameter_list|)
define|\ \
value|template<class Key, class T> \ class QMutable##C##Iterator \ { \     typedef typename Q##C<Key,T>::iterator iterator; \     typedef typename Q##C<Key,T>::const_iterator const_iterator; \     typedef iterator Item; \     Q##C<Key,T> *c; \     iterator i, n; \     inline bool item_exists() const { return const_iterator(n) != c->constEnd(); } \ public: \     inline QMutable##C##Iterator(Q##C<Key,T>&container) \         : c(&container) \     { i = c->begin(); n = c->end(); } \     inline QMutable##C##Iterator&operator=(Q##C<Key,T>&container) \     { c =&container; i = c->begin(); n = c->end(); return *this; } \     inline void toFront() { i = c->begin(); n = c->end(); } \     inline void toBack() { i = c->end(); n = c->end(); } \     inline bool hasNext() const { return const_iterator(i) != c->constEnd(); } \     inline Item next() { n = i++; return n; } \     inline Item peekNext() const { return i; } \     inline bool hasPrevious() const { return const_iterator(i) != c->constBegin(); } \     inline Item previous() { n = --i; return n; } \     inline Item peekPrevious() const { iterator p = i; return --p; } \     inline void remove() \     { if (const_iterator(n) != c->constEnd()) { i = c->erase(n); n = c->end(); } } \     inline void setValue(const T&t) { if (const_iterator(n) != c->constEnd()) *n = t; } \     inline T&value() { Q_ASSERT(item_exists()); return *n; } \     inline const T&value() const { Q_ASSERT(item_exists()); return *n; } \     inline const Key&key() const { Q_ASSERT(item_exists()); return n.key(); } \     inline bool findNext(const T&t) \     { while (const_iterator(n = i) != c->constEnd()) if (*i++ == t) return true; return false; } \     inline bool findPrevious(const T&t) \     { while (const_iterator(i) != c->constBegin()) if (*(n = --i) == t) return true; \       n = c->end(); return false; } \ };
name|QT_END_NAMESPACE
end_expr_stmt
begin_endif
endif|#
directive|endif
end_endif
begin_comment
comment|// QITERATOR_H
end_comment
end_unit
