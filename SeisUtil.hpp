#ifndef SEISUTIL_HPP
#define SEISUTIL_HPP

#include <QTransform>

class QFile;

namespace SeisUtil
{
  QTransform generateTrans( const QRectF& srcRect, const QRect& targetRect );

  qint16 readInt16At( QFile* hFile, qint32 offset );
  qint32 readInt32At( QFile* hFile, qint32 offset );

  qint16 swap_int16( qint16 val );
  qint32 swap_int32( qint32 val );
  qreal ibm2num( qint32 dataUint32 );
};

#endif // SEISUTIL_HPP
