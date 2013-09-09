#include "StandardItem.hpp"

StandardItem::StandardItem() : QStandardItem()
{
}

StandardItem::StandardItem( const QString& text ) : QStandardItem( text )
{
}

StandardItem::StandardItem( const QIcon& icon, const QString& text )
  : QStandardItem( icon, text )
{
}

StandardItem::StandardItem( int rows, int columns )
  : QStandardItem( rows, columns )
{
}
