/********************************************************************************
** Form generated from reading UI file 'SeisDo.ui'
**
** Created: Wed Sep 18 10:38:07 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEISDO_H
#define UI_SEISDO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "Canvas.hpp"

QT_BEGIN_NAMESPACE

class Ui_SeisDoClass
{
public:
    QAction *actionChinese;
    QAction *actionEnglish;
    QAction *actionNext;
    QAction *actionPrevious;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionOption;
    QAction *actionEnablePicking;
    QAction *actionContent;
    QAction *actionIndex;
    QAction *actionContextHelp;
    QAction *actionTechnicalSupport;
    QAction *actionReportBug;
    QAction *actionAboutSeisDo;
    QAction *actionFullScreen;
    QAction *actionShowSliderBar;
    QAction *actionShowModeSelector;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QFrame *headerInfo;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *txtSurvey;
    QLabel *label_2;
    QLineEdit *txtInline;
    Canvas *plot;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_B;
    QMenu *menu_L;
    QMenu *menu_T;
    QMenu *menuLanguage;
    QMenu *menu_H;
    QMenu *menu_E;
    QMenu *menu_W;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SeisDoClass)
    {
        if (SeisDoClass->objectName().isEmpty())
            SeisDoClass->setObjectName(QString::fromUtf8("SeisDoClass"));
        SeisDoClass->resize(778, 562);
        QFont font;
        font.setFamily(QString::fromUtf8("Tahoma"));
        font.setPointSize(9);
        SeisDoClass->setFont(font);
        actionChinese = new QAction(SeisDoClass);
        actionChinese->setObjectName(QString::fromUtf8("actionChinese"));
        actionChinese->setCheckable(true);
        actionChinese->setAutoRepeat(true);
        actionEnglish = new QAction(SeisDoClass);
        actionEnglish->setObjectName(QString::fromUtf8("actionEnglish"));
        actionEnglish->setCheckable(true);
        actionEnglish->setChecked(true);
        actionEnglish->setAutoRepeat(true);
        actionNext = new QAction(SeisDoClass);
        actionNext->setObjectName(QString::fromUtf8("actionNext"));
        actionPrevious = new QAction(SeisDoClass);
        actionPrevious->setObjectName(QString::fromUtf8("actionPrevious"));
        actionOpen = new QAction(SeisDoClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionClose = new QAction(SeisDoClass);
        actionClose->setObjectName(QString::fromUtf8("actionClose"));
        actionClose->setEnabled(false);
        actionExit = new QAction(SeisDoClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSave = new QAction(SeisDoClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionSave->setEnabled(false);
        actionSaveAs = new QAction(SeisDoClass);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        actionSaveAs->setEnabled(false);
        actionOption = new QAction(SeisDoClass);
        actionOption->setObjectName(QString::fromUtf8("actionOption"));
        actionEnablePicking = new QAction(SeisDoClass);
        actionEnablePicking->setObjectName(QString::fromUtf8("actionEnablePicking"));
        actionEnablePicking->setCheckable(true);
        actionContent = new QAction(SeisDoClass);
        actionContent->setObjectName(QString::fromUtf8("actionContent"));
        actionIndex = new QAction(SeisDoClass);
        actionIndex->setObjectName(QString::fromUtf8("actionIndex"));
        actionContextHelp = new QAction(SeisDoClass);
        actionContextHelp->setObjectName(QString::fromUtf8("actionContextHelp"));
        actionTechnicalSupport = new QAction(SeisDoClass);
        actionTechnicalSupport->setObjectName(QString::fromUtf8("actionTechnicalSupport"));
        actionReportBug = new QAction(SeisDoClass);
        actionReportBug->setObjectName(QString::fromUtf8("actionReportBug"));
        actionAboutSeisDo = new QAction(SeisDoClass);
        actionAboutSeisDo->setObjectName(QString::fromUtf8("actionAboutSeisDo"));
        actionFullScreen = new QAction(SeisDoClass);
        actionFullScreen->setObjectName(QString::fromUtf8("actionFullScreen"));
        actionShowSliderBar = new QAction(SeisDoClass);
        actionShowSliderBar->setObjectName(QString::fromUtf8("actionShowSliderBar"));
        actionShowModeSelector = new QAction(SeisDoClass);
        actionShowModeSelector->setObjectName(QString::fromUtf8("actionShowModeSelector"));
        centralWidget = new QWidget(SeisDoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setFont(font);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(6, 6, 6, 6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        headerInfo = new QFrame(centralWidget);
        headerInfo->setObjectName(QString::fromUtf8("headerInfo"));
        headerInfo->setFrameShape(QFrame::Box);
        headerInfo->setFrameShadow(QFrame::Sunken);
        gridLayout = new QGridLayout(headerInfo);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(headerInfo);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tahoma"));
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        txtSurvey = new QLineEdit(headerInfo);
        txtSurvey->setObjectName(QString::fromUtf8("txtSurvey"));
        txtSurvey->setAlignment(Qt::AlignCenter);
        txtSurvey->setReadOnly(true);

        gridLayout->addWidget(txtSurvey, 0, 1, 1, 1);

        label_2 = new QLabel(headerInfo);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        txtInline = new QLineEdit(headerInfo);
        txtInline->setObjectName(QString::fromUtf8("txtInline"));
        txtInline->setAlignment(Qt::AlignCenter);
        txtInline->setReadOnly(true);

        gridLayout->addWidget(txtInline, 0, 3, 1, 1);


        gridLayout_2->addWidget(headerInfo, 0, 0, 1, 1);

        plot = new Canvas(centralWidget);
        plot->setObjectName(QString::fromUtf8("plot"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy);
        plot->setFrameShape(QFrame::Box);
        plot->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(plot, 1, 0, 1, 1);

        SeisDoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SeisDoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 778, 21));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_B = new QMenu(menuBar);
        menu_B->setObjectName(QString::fromUtf8("menu_B"));
        menu_L = new QMenu(menuBar);
        menu_L->setObjectName(QString::fromUtf8("menu_L"));
        menu_T = new QMenu(menuBar);
        menu_T->setObjectName(QString::fromUtf8("menu_T"));
        menuLanguage = new QMenu(menu_T);
        menuLanguage->setObjectName(QString::fromUtf8("menuLanguage"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        menu_E = new QMenu(menuBar);
        menu_E->setObjectName(QString::fromUtf8("menu_E"));
        menu_W = new QMenu(menuBar);
        menu_W->setObjectName(QString::fromUtf8("menu_W"));
        SeisDoClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(SeisDoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SeisDoClass->setStatusBar(statusBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_E->menuAction());
        menuBar->addAction(menu_B->menuAction());
        menuBar->addAction(menu_L->menuAction());
        menuBar->addAction(menu_T->menuAction());
        menuBar->addAction(menu_W->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(actionOpen);
        menu_F->addAction(actionClose);
        menu_F->addAction(actionSave);
        menu_F->addAction(actionSaveAs);
        menu_F->addSeparator();
        menu_F->addAction(actionExit);
        menu_T->addAction(menuLanguage->menuAction());
        menu_T->addSeparator();
        menu_T->addAction(actionPrevious);
        menu_T->addAction(actionNext);
        menu_T->addSeparator();
        menu_T->addAction(actionOption);
        menuLanguage->addAction(actionChinese);
        menuLanguage->addAction(actionEnglish);
        menu_H->addAction(actionContent);
        menu_H->addAction(actionIndex);
        menu_H->addAction(actionContextHelp);
        menu_H->addSeparator();
        menu_H->addAction(actionTechnicalSupport);
        menu_H->addAction(actionReportBug);
        menu_H->addSeparator();
        menu_H->addAction(actionAboutSeisDo);
        menu_E->addAction(actionEnablePicking);
        menu_W->addAction(actionFullScreen);
        menu_W->addAction(actionShowSliderBar);
        menu_W->addAction(actionShowModeSelector);

        retranslateUi(SeisDoClass);
        QObject::connect(actionExit, SIGNAL(triggered()), SeisDoClass, SLOT(close()));

        QMetaObject::connectSlotsByName(SeisDoClass);
    } // setupUi

    void retranslateUi(QMainWindow *SeisDoClass)
    {
        SeisDoClass->setWindowTitle(QApplication::translate("SeisDoClass", "SeisDo", 0, QApplication::UnicodeUTF8));
        actionChinese->setText(QApplication::translate("SeisDoClass", "&Chinese", 0, QApplication::UnicodeUTF8));
        actionEnglish->setText(QApplication::translate("SeisDoClass", "&English", 0, QApplication::UnicodeUTF8));
        actionNext->setText(QApplication::translate("SeisDoClass", "Next", 0, QApplication::UnicodeUTF8));
        actionNext->setShortcut(QApplication::translate("SeisDoClass", "F3", 0, QApplication::UnicodeUTF8));
        actionPrevious->setText(QApplication::translate("SeisDoClass", "Previous", 0, QApplication::UnicodeUTF8));
        actionPrevious->setShortcut(QApplication::translate("SeisDoClass", "F2", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("SeisDoClass", "&Open", 0, QApplication::UnicodeUTF8));
        actionClose->setText(QApplication::translate("SeisDoClass", "&Close", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("SeisDoClass", "E&xit", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("SeisDoClass", "&Save", 0, QApplication::UnicodeUTF8));
        actionSaveAs->setText(QApplication::translate("SeisDoClass", "Save &As...", 0, QApplication::UnicodeUTF8));
        actionOption->setText(QApplication::translate("SeisDoClass", "&Option", 0, QApplication::UnicodeUTF8));
        actionEnablePicking->setText(QApplication::translate("SeisDoClass", "Enable Picking", 0, QApplication::UnicodeUTF8));
        actionContent->setText(QApplication::translate("SeisDoClass", "Content", 0, QApplication::UnicodeUTF8));
        actionIndex->setText(QApplication::translate("SeisDoClass", "Index", 0, QApplication::UnicodeUTF8));
        actionContextHelp->setText(QApplication::translate("SeisDoClass", "Context &Help", 0, QApplication::UnicodeUTF8));
        actionTechnicalSupport->setText(QApplication::translate("SeisDoClass", "Technical Support", 0, QApplication::UnicodeUTF8));
        actionReportBug->setText(QApplication::translate("SeisDoClass", "Report Bug...", 0, QApplication::UnicodeUTF8));
        actionAboutSeisDo->setText(QApplication::translate("SeisDoClass", "&About SeisDo...", 0, QApplication::UnicodeUTF8));
        actionFullScreen->setText(QApplication::translate("SeisDoClass", "Full Screen", 0, QApplication::UnicodeUTF8));
        actionFullScreen->setShortcut(QApplication::translate("SeisDoClass", "Ctrl+Shift+F11", 0, QApplication::UnicodeUTF8));
        actionShowSliderBar->setText(QApplication::translate("SeisDoClass", "Show Sidebar", 0, QApplication::UnicodeUTF8));
        actionShowSliderBar->setShortcut(QApplication::translate("SeisDoClass", "Alt+0", 0, QApplication::UnicodeUTF8));
        actionShowModeSelector->setText(QApplication::translate("SeisDoClass", "Show Mode Selector", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SeisDoClass", "Survey", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SeisDoClass", "SurveyLine", 0, QApplication::UnicodeUTF8));
        menu_F->setTitle(QApplication::translate("SeisDoClass", "&File", 0, QApplication::UnicodeUTF8));
        menu_B->setTitle(QApplication::translate("SeisDoClass", "FirstArrival", 0, QApplication::UnicodeUTF8));
        menu_L->setTitle(QApplication::translate("SeisDoClass", "&Level", 0, QApplication::UnicodeUTF8));
        menu_T->setTitle(QApplication::translate("SeisDoClass", "&Tool", 0, QApplication::UnicodeUTF8));
        menuLanguage->setTitle(QApplication::translate("SeisDoClass", "&Language", 0, QApplication::UnicodeUTF8));
        menu_H->setTitle(QApplication::translate("SeisDoClass", "&Help", 0, QApplication::UnicodeUTF8));
        menu_E->setTitle(QApplication::translate("SeisDoClass", "&Edit", 0, QApplication::UnicodeUTF8));
        menu_W->setTitle(QApplication::translate("SeisDoClass", "&Window", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SeisDoClass: public Ui_SeisDoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEISDO_H
