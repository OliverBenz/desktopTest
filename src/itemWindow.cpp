#include "itemWindow.hpp"

#include <QPicture>

itemWindow::itemWindow(QWidget* parent) : QWidget(parent) {
    m_layoutMain = new QVBoxLayout(this);

// ----- Setup top info view -----
    m_layoutTop = new QHBoxLayout(this);

    // Setup left info view.
    m_layoutTopInfo = new QVBoxLayout(this);
    m_labelName = new QLabel("Loading...", this);
    m_labelId = new QLabel("Loading...", this);
    m_labelLoc = new QLabel("Loading...", this);

    m_layoutTopInfo->addWidget(m_labelName);
    m_layoutTopInfo->addWidget(m_labelId);
    m_layoutTopInfo->addWidget(m_labelLoc);

    // TODO: Setup right image view.
    m_labelImage = new QLabel(this);
    QPicture picture;
    picture.load("../img/testImage.jpg");
    m_labelImage->setPicture(picture);

    // Add sub-layouts to top-view layout.
    m_layoutTop->addLayout(m_layoutTopInfo);
    m_layoutTop->addWidget(m_labelImage);

// ----- Set info selection bar -----
    m_layoutInfoBar = new QHBoxLayout(this);
    m_buttonGeneral = new QPushButton("General data", this);
    m_buttonLocation = new QPushButton("Loaction", this);
    m_buttonExtra = new QPushButton("Extra information", this);

    m_layoutInfoBar->addWidget(m_buttonGeneral);
    m_layoutInfoBar->addWidget(m_buttonLocation);
    m_layoutInfoBar->addWidget(m_buttonExtra);

// ----- Add components to main layout -----
    static constexpr int componentSpacing = 20;
    m_layoutMain->addLayout(m_layoutTop);
    m_layoutMain->addSpacing(componentSpacing);
    m_layoutMain->addLayout(m_layoutInfoBar);

    setLayout(m_layoutMain);
}

itemWindow::~itemWindow() noexcept {
    // Top info view
    delete m_labelLoc;
    delete m_labelId;
    delete m_labelName;
    delete m_layoutTopInfo;

    // Top general
    delete m_labelImage;
    delete m_layoutTop;

    // Info selection bar
    delete m_buttonExtra;
    delete m_buttonLocation;
    delete m_buttonGeneral;
    delete m_layoutInfoBar;

    // Main layout
    delete m_layoutMain;
}