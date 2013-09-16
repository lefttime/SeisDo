/********************************************************************************
** Form generated from reading UI file 'SectionConfigEditor.ui'
**
** Created: Mon Sep 16 15:12:57 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECTIONCONFIGEDITOR_H
#define UI_SECTIONCONFIGEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SectionConfigEditor
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSpinBox *traceCount;
    QLabel *label_2;
    QSpinBox *startTime;
    QFrame *frame;
    QSpinBox *stopTime;
    QLabel *label_3;
    QSpinBox *timeInterval;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;
    QPushButton *btnCancel;

    void setupUi(QDialog *SectionConfigEditor)
    {
        if (SectionConfigEditor->objectName().isEmpty())
            SectionConfigEditor->setObjectName(QString::fromUtf8("SectionConfigEditor"));
        SectionConfigEditor->resize(249, 139);
        gridLayout = new QGridLayout(SectionConfigEditor);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(SectionConfigEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        traceCount = new QSpinBox(groupBox);
        traceCount->setObjectName(QString::fromUtf8("traceCount"));
        traceCount->setMinimumSize(QSize(60, 0));
        traceCount->setMinimum(1);
        traceCount->setMaximum(999);
        traceCount->setValue(1);

        gridLayout_2->addWidget(traceCount, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        startTime = new QSpinBox(groupBox);
        startTime->setObjectName(QString::fromUtf8("startTime"));
        startTime->setMaximum(999999);

        gridLayout_2->addWidget(startTime, 1, 1, 1, 1);

        frame = new QFrame(groupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::HLine);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame, 1, 2, 1, 1);

        stopTime = new QSpinBox(groupBox);
        stopTime->setObjectName(QString::fromUtf8("stopTime"));
        stopTime->setMinimumSize(QSize(60, 0));
        stopTime->setMaximum(999999);

        gridLayout_2->addWidget(stopTime, 1, 3, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        timeInterval = new QSpinBox(groupBox);
        timeInterval->setObjectName(QString::fromUtf8("timeInterval"));
        timeInterval->setMinimum(1);
        timeInterval->setMaximum(9999);

        gridLayout_2->addWidget(timeInterval, 2, 1, 1, 1);


        gridLayout->addWidget(groupBox, 0, 0, 1, 3);

        horizontalSpacer = new QSpacerItem(66, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        btnOk = new QPushButton(SectionConfigEditor);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));

        gridLayout->addWidget(btnOk, 1, 1, 1, 1);

        btnCancel = new QPushButton(SectionConfigEditor);
        btnCancel->setObjectName(QString::fromUtf8("btnCancel"));

        gridLayout->addWidget(btnCancel, 1, 2, 1, 1);


        retranslateUi(SectionConfigEditor);
        QObject::connect(btnOk, SIGNAL(clicked()), SectionConfigEditor, SLOT(accept()));
        QObject::connect(btnCancel, SIGNAL(clicked()), SectionConfigEditor, SLOT(reject()));

        QMetaObject::connectSlotsByName(SectionConfigEditor);
    } // setupUi

    void retranslateUi(QDialog *SectionConfigEditor)
    {
        SectionConfigEditor->setWindowTitle(QApplication::translate("SectionConfigEditor", "Section Edit", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("SectionConfigEditor", "TraceCount", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SectionConfigEditor", "Time Range", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SectionConfigEditor", "Time Interval", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("SectionConfigEditor", "OK", 0, QApplication::UnicodeUTF8));
        btnCancel->setText(QApplication::translate("SectionConfigEditor", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SectionConfigEditor: public Ui_SectionConfigEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECTIONCONFIGEDITOR_H
