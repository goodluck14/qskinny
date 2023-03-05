/******************************************************************************
 * QSkinny - Copyright (C) 2016 Uwe Rathmann
 * This file may be used under the terms of the QSkinny License, Version 1.0
 *****************************************************************************/

#ifndef QSK_PLATFORM_H
#define QSK_PLATFORM_H

#include "QskGlobal.h"

class QScreen;
class QPlatformIntegration;
class QRect;

QSK_EXPORT qreal qskGlobalScaleFactor();

QSK_EXPORT bool qskMaybeDesktopPlatform();
QSK_EXPORT const QPlatformIntegration* qskPlatformIntegration();
QSK_EXPORT QRect qskPlatformScreenGeometry( const QScreen* );

/*
    One dp is a virtual pixel unit that's roughly equal to one pixel
    on a medium-density screen ( 160 dpi ). 

    see: https://en.wikipedia.org/wiki/Device-independent_pixel
 */

QSK_EXPORT qreal qskDpToPixelsFactor();

inline qreal qskDpToPixels( qreal value )
{
    static qreal factor = -1.0;

    if ( factor < 0.0 )
        factor = qskDpToPixelsFactor();

    return value * factor;
}

#endif
