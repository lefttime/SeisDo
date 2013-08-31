#include "SeisUtil.hpp"

#include <QFile>
#include <QtDebug>
#include <qmath.h>

QTransform SeisUtil::generateTrans( const QRectF& srcRect, const QRect& targetRect )
{
  QTransform result;
  result.reset();

  qreal wScale = targetRect.width() / srcRect.width();
  qreal hScale = targetRect.height() / srcRect.height();
  result *= QTransform::fromTranslate( -srcRect.left(), -srcRect.top() );
  result *= QTransform::fromScale( wScale, hScale );
  result *= QTransform::fromTranslate( targetRect.left(), targetRect.top() );

  return result;
}

qint16 SeisUtil::readInt16At( QFile* hFile, qint32 offset )
{
  qint16 result;
  hFile->seek( offset );
  hFile->read( (char*)&result, 2 );
  return result;
}

qint32 SeisUtil::readInt32At( QFile* hFile, qint32 offset )
{
  qint32 result;
  hFile->seek( offset );
  hFile->read( (char*)&result, 4 );
  return result;
}

qint16 SeisUtil::swap_int16( qint16 val )
{
  return (val << 8) | ((val >> 8) & 0xFF);
}

qint32 SeisUtil::swap_int32(qint32 val)
{
  val = ((val << 8) & 0xFF00FF00) | ((val >> 8) & 0xFF00FF );
  return (val << 16) | ((val >> 16) & 0xFFFF);
}

qreal SeisUtil::ibm2num(qint32 dataUint32 )
{
  qreal result ;

  // gain sign from first bit
  double sign = (double)( dataUint32 >> 31) ;

  // gain exponent from first byte, last 7 bits
  double exp = (double)((dataUint32 >> 24) & 0x7f ) - 64;

  // gain mantissa from last 3 bytes
  double frac = (double)( dataUint32 & 0x00ffffff ) ;
  frac = frac / pow(2, 24);
  result = (1 - 2*sign) * pow(16,exp) * frac;

  return result;
}
