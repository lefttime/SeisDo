#include "SliceConfigEditor.hpp"
#include "ui_SliceConfigEditor.h"

#include "Shared.hpp"

class SliceConfigEditor::SectionConfigEditorPrivate
{
public:

  SectionConfigEditorPrivate( SliceConfigEditor* me,
                              const SliceConfig& config )
    : m_self( me ), m_config( config ) {
    m_ui.setupUi( m_self );
  }

  void init() {
    m_ui.traceCount->setValue( m_config._traceCount );
    m_ui.startTime->setValue( m_config._timeRange.x() );
    m_ui.stopTime->setValue( m_config._timeRange.y() );
    m_ui.timeInterval->setValue( m_config._timeInterval );
    m_ui.traceScale->setValue( m_config._traceScale );
    m_ui.enabledFilled->setChecked( m_config._enabledFilled );
  }

  void accept() {
    m_config._traceCount   = m_ui.traceCount->value();
    m_config._timeRange    = QVector2D(m_ui.startTime->value(),
                                       m_ui.stopTime->value());
    m_config._timeInterval = m_ui.timeInterval->value();
    m_config._traceScale   = m_ui.traceScale->value();
    m_config._enabledFilled= m_ui.enabledFilled->isChecked();
  }

  SliceConfigEditor*         m_self;
  Ui::SliceConfigEditor      m_ui;

  SliceConfig                m_config;
};

SliceConfigEditor::SliceConfigEditor( const SliceConfig& config,
                                          QWidget* parent )
  : QDialog( parent ), _pd( new SectionConfigEditorPrivate( this, config ) )
{
  _pd->init();
}

SliceConfigEditor::~SliceConfigEditor()
{
}

const SliceConfig& SliceConfigEditor::config() const
{
  return _pd->m_config;
}

void SliceConfigEditor::on_btnApply_clicked()
{
  _pd->accept();
  emit configChanged( _pd->m_config );
}

void SliceConfigEditor::accept()
{
  on_btnApply_clicked();
  QDialog::accept();
}
