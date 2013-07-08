#ifndef SEISUTIL_HPP
#define SEISUTIL_HPP

#include <QTransform>

namespace SeisUtil
{
  QTransform generateTrans( const QRectF& srcRect, const QRect& targetRect );
};

#endif // SEISUTIL_HPP
