#ifndef SECTIONCONFIGEDITOR_HPP
#define SECTIONCONFIGEDITOR_HPP

#include <QDialog>

struct SliceConfig;

class SectionConfigEditor : public QDialog
{
  Q_OBJECT;
  
public:

  explicit SectionConfigEditor(const SliceConfig& config,
                                QWidget* parent );
  ~SectionConfigEditor();

  const SliceConfig& config() const;

protected:

  virtual void accept();

private:

  class SectionConfigEditorPrivate;
  QScopedPointer<SectionConfigEditorPrivate>         _pd;
};

#endif // SECTIONCONFIGEDITOR_HPP
