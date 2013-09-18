#ifndef SECTIONCONFIGEDITOR_HPP
#define SECTIONCONFIGEDITOR_HPP

#include <QDialog>

struct SliceConfig;

class SliceConfigEditor : public QDialog
{
  Q_OBJECT;
  
public:

  explicit SliceConfigEditor( const SliceConfig& config,
                              QWidget* parent );
  ~SliceConfigEditor();

  const SliceConfig& config() const;

signals:

  void configChanged( const SliceConfig& );

private slots:

  void on_btnApply_clicked();

protected:

  virtual void accept();

private:

  class SectionConfigEditorPrivate;
  QScopedPointer<SectionConfigEditorPrivate>         _pd;
};

#endif // SECTIONCONFIGEDITOR_HPP
