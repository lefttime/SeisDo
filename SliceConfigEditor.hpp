#ifndef SECTIONCONFIGEDITOR_HPP
#define SECTIONCONFIGEDITOR_HPP

#include <QDialog>

struct SliceConfig;

class SliceConfigEditor : public QDialog
{
  Q_OBJECT;
  
public:

  explicit SliceConfigEditor(const SliceConfig& config,
                                QWidget* parent );
  ~SliceConfigEditor();

  const SliceConfig& config() const;

protected:

  virtual void accept();

private:

  class SectionConfigEditorPrivate;
  QScopedPointer<SectionConfigEditorPrivate>         _pd;
};

#endif // SECTIONCONFIGEDITOR_HPP
