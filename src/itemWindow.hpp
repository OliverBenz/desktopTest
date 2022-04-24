#pragma once

#include <QWidget>

#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class itemWindow : public QWidget {
    Q_OBJECT

public:
    explicit itemWindow(QWidget* parent = nullptr);
    ~itemWindow();

public slots:


private:
    QVBoxLayout* m_layoutMain;  //!< Main layout of class.

    // Top info view.
    QHBoxLayout* m_layoutTop;  //!< Layout for top view.

    QVBoxLayout* m_layoutTopInfo;  //!< Information at the top of window.
    QLabel* m_labelName;  //!< Display item name.
    QLabel* m_labelId;    //!< Display item id.
    QLabel* m_labelLoc;   //!< Display item location.

    QLabel* m_labelImage; //!< Display item image.

    // Setup info switch bar.
    QHBoxLayout* m_layoutInfoBar;   //!< Bar with the info switch buttons.
    QPushButton* m_buttonGeneral;   //!< Display item general info.
    QPushButton* m_buttonLocation;  //!< Display item location info.
    QPushButton* m_buttonExtra;     //!< Display item extra info.
};
