#ifndef STANDARDITEMMODEL_HPP
#define STANDARDITEMMODEL_HPP

#include <QStandardItemModel>

class StandardItemModel : public QStandardItemModel
{
  Q_OBJECT;

public:

  explicit StandardItemModel( QObject* parent=0 );

};

#endif // STANDARDITEMMODEL_HPP
