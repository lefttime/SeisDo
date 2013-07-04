#ifndef TRANSLATOR_HPP
#define TRANSLATOR_HPP

#include <QObject>

class Translator : public QObject
{
  Q_OBJECT;

public:

  enum LanguageType { Chinese, English };

  static Translator* instance();
  ~Translator();

  LanguageType languageType() const;
  void setLanguageType( LanguageType );

private:

  Translator();

  class TranslatorPrivate;
  QScopedPointer<TranslatorPrivate>         _pd;

};

#define theTranslator Translator::instance()

#endif // TRANSLATOR_HPP