#ifndef STANDARDITEM_HPP
#define STANDARDITEM_HPP

#include <QStandardItem>

class StandardItem : public QStandardItem
{
public:

  explicit StandardItem();
  explicit StandardItem( const QString& text );
  explicit StandardItem( const QIcon& icon, const QString& text );
  explicit StandardItem( int rows, int columns=1 );

};

#endif // STANDARDITEM_HPP
