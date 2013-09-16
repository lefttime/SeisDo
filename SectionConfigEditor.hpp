#ifndef SECTIONCONFIGEDITOR_HPP
#define SECTIONCONFIGEDITOR_HPP

#include <QDialog>

struct SectionConfig;

class SectionConfigEditor : public QDialog
{
  Q_OBJECT;
  
public:

  explicit SectionConfigEditor( const SectionConfig& config,
                                QWidget* parent );
  ~SectionConfigEditor();

  const SectionConfig& config() const;

protected:

  virtual void accept();

private:

  class SectionConfigEditorPrivate;
  QScopedPointer<SectionConfigEditorPrivate>         _pd;
};

#endif // SECTIONCONFIGEDITOR_HPP
