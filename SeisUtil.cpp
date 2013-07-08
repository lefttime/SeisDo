#include "SeisUtil.hpp"

QTransform SeisUtil::generateTrans( const QRectF& srcRect, const QRect& targetRect )
{
  QTransform result;
  result.reset();

  float wScale = targetRect.width() / srcRect.width();
  float hScale = targetRect.height() / srcRect.height();
  result *= QTransform::fromTranslate( -srcRect.left(), -srcRect.top() );
  result *= QTransform::fromScale( wScale, hScale );
  result *= QTransform::fromTranslate( targetRect.left(), targetRect.top() );

  return result;
}
