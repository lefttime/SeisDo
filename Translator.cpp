#include "Translator.hpp"

#include <QDir>
#include <QTranslator>
#include <QApplication>

class Translator::TranslatorPrivate
{
public:

  TranslatorPrivate( Translator* me ) : m_self( me ) {

  }

  ~TranslatorPrivate() {
    qDeleteAll( m_translators );
  }

  void update() {
    unloadTranslators();

    QDir dir( ":/translations" );
    QStringList fileNames = dir.entryList( getNameFilter(),
                                           QDir::Files,
                                           QDir::Name );
    foreach( const QString& file, fileNames ) {
      QTranslator* translator = new QTranslator;
      if( translator->load( dir.filePath( file ) ) ) {
        m_translators << translator;
        qApp->installTranslator( translator );
      } else {
        delete translator;
      }
    }
  }

  void unloadTranslators() {
    foreach( QTranslator* translator, m_translators ) {
      qApp->removeTranslator( translator );
    }

    m_translators.clear();
  }

  QStringList getNameFilter() {
    switch( m_languageType ) {
    case Translator::Chinese: {
      return QStringList( "*_zh.qm" );
    } break;

    case Translator::English:
    default: {
      return QStringList( "*_en.qm" );
    } break;
    }
  }

  Translator*              m_self;
  Translator::LanguageType m_languageType;

  QList<QTranslator*>      m_translators;
};

Translator* Translator::instance()
{
  static Translator* selfObject = 0;
  if( !selfObject ) {
    selfObject = new Translator;
  }
  
  return selfObject;
}

Translator::~Translator()
{
}

Translator::LanguageType Translator::languageType() const
{
  return _pd->m_languageType;
}

void Translator::setLanguageType( Translator::LanguageType languageType )
{
  if( _pd->m_languageType != languageType ) {
    _pd->m_languageType = languageType;
    _pd->update();
  }
}

Translator::Translator() : QObject( 0 ), _pd( new TranslatorPrivate( this ) )
{
}
