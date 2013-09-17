#include "SectionConfigEditor.hpp"
#include "ui_SectionConfigEditor.h"

#include "Shared.hpp"

class SectionConfigEditor::SectionConfigEditorPrivate
{
public:

  SectionConfigEditorPrivate( SectionConfigEditor* me,
                              const SliceConfig& config )
    : m_self( me ), m_config( config ) {
    m_ui.setupUi( m_self );
  }

  void init() {
    m_ui.traceCount->setValue( m_config._traceCount );
    m_ui.startTime->setValue( m_config._timeRange.x() );
    m_ui.stopTime->setValue( m_config._timeRange.y() );
    m_ui.timeInterval->setValue( m_config._timeInterval );
  }

  void accept() {
    m_config._traceCount = m_ui.traceCount->value();
    m_config._timeRange = QVector2D(m_ui.startTime->value(),
                                    m_ui.stopTime->value());
    m_config._timeInterval = m_ui.timeInterval->value();
  }

  SectionConfigEditor*         m_self;
  Ui::SectionConfigEditor      m_ui;

  SliceConfig                  m_config;
};

SectionConfigEditor::SectionConfigEditor( const SliceConfig& config,
                                          QWidget* parent )
  : QDialog( parent ), _pd( new SectionConfigEditorPrivate( this, config ) )
{
  _pd->init();
}

SectionConfigEditor::~SectionConfigEditor()
{
}

const SliceConfig& SectionConfigEditor::config() const
{
  return _pd->m_config;
}

void SectionConfigEditor::accept()
{
  _pd->accept();
  QDialog::accept();
}
